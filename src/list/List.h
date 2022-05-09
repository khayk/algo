#pragma once

#include <initializer_list>
#include <charconv>
#include <memory>
#include <list>
#include <array>
#include <string>
#include <limits>

namespace alg {

template <typename T>
struct SNode {
  T data;
  SNode* next{nullptr};
};


template <typename T>
SNode<T>* createNode(const T data) {
  return new SNode<T>{data};
}


template <typename T>
void deleteNode(SNode<T>*& node) {
  if (node) {
    node->next = nullptr;
    delete node;
    node = nullptr;
  }
}


template <typename T>
SNode<T>* appendNode(SNode<T>* curr, SNode<T>* node) {
  if (curr) {
    deleteNode(curr->next);
    curr->next = node;
  }

  return node;
}


template <typename T>
SNode<T>* append(SNode<T>* curr, const T& value) {
  return appendNode(curr, createNode(value));
}


template <typename T>
SNode<T>* createList(std::initializer_list<T> ini) {
  if (ini.begin() == ini.end()) {
    return nullptr;
  }

  auto it = ini.begin();
  SNode<T>* head = createNode<T>(*it);
  SNode<T>* curr = head;

  while (++it != ini.end()) {
    curr = appendNode(curr, createNode<T>(*it));
  }

  return head;
}


template <typename T>
void deleteList(SNode<T>*& node) {
  while (node) {
    auto* tmp = node->next;
    deleteNode(node);
    node = tmp;
  }
}


template <typename T>
size_t length(const SNode<T>* node) {
  size_t len{};

  while (node) {
    ++len;
    node = node->next;
  }

  return len;
}


template <typename T>
void dumpList(const SNode<T>* node, const char separator, std::string& dest) {
  dest.clear();
  dest.reserve(2 * length(node) + 1);
  std::array<char, std::numeric_limits<T>::digits10 + 2> str;

  while (node) {
    if (auto [ptr, ec] =
            std::to_chars(str.data(), str.data() + str.size(), node->data);
        ec == std::errc()) {
      dest.append(std::string_view(str.data(), ptr - str.data()));
    }

    dest.push_back(separator);
    node = node->next;
  }

  while (!dest.empty() && dest.back() == separator) {
    dest.pop_back();
  }
}


template <typename T>
std::string dumpList(const SNode<T>* node, const char separator) {
  std::string dest;
  dumpList(node, separator, dest);

  return dest;
}


template <typename T>
SNode<T>* reverseList(SNode<T>* const head) {
  SNode<T>* prev = nullptr;
  SNode<T>* next = nullptr;
  SNode<T>* curr = head;

  while (curr) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }

  return prev;
}


} // namespace alg