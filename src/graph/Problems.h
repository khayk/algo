#pragma once

#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>

namespace alg {

using Neighbours = std::unordered_set<std::string>;
using Graph = std::unordered_map<std::string, Neighbours>;
using Path = std::vector<std::string>;
using Paths = std::vector<Path>;
using Visited = std::unordered_set<std::string>;

template <typename Cb>
void dfs(const Graph& graph, const std::string& node, Visited& visited,
         Path& currentPath, const Cb& cb) {
  currentPath.push_back(node);
  cb(currentPath);

  if (visited.count(node) > 0) {
    currentPath.pop_back();
    return;
  }

  visited.insert(node);

  const auto it = graph.find(node);

  if (it != graph.end()) {
    for (const auto& n : it->second) {
      dfs(graph, n, visited, currentPath, cb);
    }
  }

  currentPath.pop_back();
}

void findPaths(const Graph& graph, const std::string& start,
               const std::string& destination, Paths& paths) {
  Path currentPath;
  Visited visited;

  std::ignore = paths;

  std::unordered_map<std::string, std::unordered_set<std::string>> hoops;

  dfs(graph, start, visited, currentPath,
      [&destination, &hoops](const Path& path) {
        if (path.back() == destination) {
          for (auto it = path.rbegin(); it != path.rend(); ++it) {
            if (!hoops.try_emplace(*it).second) {
              break;
            }
          }
        } else {
          for (auto it = path.rbegin(); it != path.rend(); ++it) {
            auto hit = hoops.try_emplace(*it);
            std::ignore = hit;
          }
        }

      });
}

}  // namespace alg
