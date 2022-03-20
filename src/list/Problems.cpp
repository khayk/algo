#include "Problems.h"

namespace alg {

Node* reverseOperation(Node* head) {
  Node* prev = nullptr;
  Node* succ = nullptr;
  Node* curr = head;

  while (curr) {
    while (curr && curr->data % 2 != 0) {
      prev = curr;
      curr = curr->next;
    }

    while (curr && curr->data % 2 == 0) {
      succ = curr;
      curr = curr->next;
    }

    Node* joint = nullptr;
    if (succ) {
      joint = succ->next;
      succ->next = nullptr;
    }

    Node* subpartTail = nullptr;

    if (prev) {
      subpartTail = prev->next;
      prev->next = reverseList(prev->next);
    } else {
      subpartTail = head;
      head = reverseList(head);
    }

    if (subpartTail) {
      subpartTail->next = joint;
    }
  }

  return head;
}

}  // namespace alg
