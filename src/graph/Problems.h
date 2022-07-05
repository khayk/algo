#pragma once

#include <unordered_map>
#include <unordered_set>

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
  Path path;
  Visited visited;

  dfs(graph, start, visited, path,
      [&destination, &paths](const Path& currentPath) {
        if (!currentPath.empty() && currentPath.back() == destination) {
          paths.push_back(currentPath);
        }
      });
}

}  // namespace alg
