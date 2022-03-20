#pragma once

#include "List.h"

namespace alg {

using Node = SNode<int>;

/**
 * @brief  You are given a singly-linked list that contains N integers. A
 * subpart of the list is a contiguous set of even elements, bordered either by
 * either end of the list or an odd element. For example, if the list is
 * [1, 2, 8, 9, 12, 16], the subparts of the list are [2, 8] and [12, 16].
 * Then, for each subpart, the order of the elements is reversed. In the
 * example, this would result in the new list, [1, 8, 2, 9, 16, 12].
 *
 * Given a resulting list, determine the original order of the elements.
 *
 * @param head The head of the list
 * @return The new head
 */
Node* reverseOperation(Node* head);

}  // namespace alg
