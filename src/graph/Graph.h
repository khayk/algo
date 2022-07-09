#include <string>
#include <unordered_map>
#include <unordered_set>

namespace alg {

template <typename T>
struct Node {
  template <typename Other>
  Node(const Other& lid) : id(lid) {}
  T id;
};

template <typename T>
inline bool operator==(const Node<T>& lhs, const Node<T>& rhs) {
  return lhs.id == rhs.id;
}

struct NodeHash {
  template <typename T>
  auto operator()(const Node<T>& node) const -> size_t {
    return std::hash<T>{}(node.id);
  }
};

template <typename T>
struct GraphTraits {
  using NodeType = typename Node<T>;
  using Neighbours = std::unordered_set<NodeType, NodeHash>;
  using Edges = std::unordered_map<NodeType, Neighbours, NodeHash>;
};


template <typename T>
void addEdge(const typename GraphTraits<T>::NodeType& start,
             const typename GraphTraits<T>::NodeType& end,
             typename GraphTraits<T>::Edges& edges) {
  edges[start].insert(end);
}


template <typename T>
void readGraph(std::istream& in, typename GraphTraits<T>::Edges& edges) {
  int edgeCount;
  in >> edgeCount;

  T start{};
  T end{};

  while (edgeCount--) {
    in >> start >> end;
    addEdge(start, end, edges);
  }
}

}  // namespace alg