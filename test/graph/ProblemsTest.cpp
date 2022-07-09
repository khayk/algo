#include "graph/Problems.h"

#include <gtest/gtest.h>
#include <fstream>

using namespace alg;

const std::string_view input0 = R"(
a c
4
a b
b c
a d
d c
)";

void readGraph(std::istream& in, Graph& graph) {
  int edgeCount;
  in >> edgeCount;

  std::string start{};
  std::string end{};

  while (edgeCount--) {
    in >> start >> end;
    graph[start].insert(end);
  }
}

void printPaths(const Paths& paths) {
  for (const auto& path : paths) {
    bool first = true;

    for (const auto& n : path) {
      std::cout << (first ? "" : " -> ") << n;
      first = false;
    }

    std::cout << '\n';
  }
}

TEST(GraphTests, FindPaths) {
  std::string start;
  std::string destination;
  std::stringstream ss;

  ss << input0;

  Graph graph;
  ss >> start >> destination;
  readGraph(ss, graph);

  Paths paths;
  findPaths(graph, start, destination, paths);
  EXPECT_EQ(paths.size(), 2);

  Path expected;

  expected = {"a", "b", "c"};
  EXPECT_EQ(paths[0], expected);

  expected = {"a", "d", "c"};
  EXPECT_EQ(paths[1], expected);
}