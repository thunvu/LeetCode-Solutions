# 0002. Add Two Numbers

### Approach
- Recursively traverse both lists digit by digit.
- Pad shorter lists with `ListNode(0)` to keep addition aligned.
- Handle carry by adding `1` directly to `l1->next`. If `l1->next` doesn't exist, allocate a new `ListNode(1)`.
- Link current result node to the recursive call `addTwoNumbers(l1->next, l2->next)`.

### Complexity
- **Time:** $O(\max(N, M))$ - visits each node once.
- **Space:** $O(\max(N, M))$ - call stack depth and output list.

### Notes & Edge Cases
- Watch out for null pointer dereferences before calling `->next`.
- Carry on the last digit (e.g., `[5] + [5] = [0, 1]`) must create a new trailing node.