# 0217. Contains Duplicate

### Approach
- Implement a manual hash table using `vector<list<int>>` with separate chaining to avoid built-in `unordered_set`.
- Allocate bucket count as `nums.size() * 2 + 1` to keep the load factor below `0.5` and minimize collisions.
- Map each number to a bucket index via `abs(num) % bsize`.
- Traverse the target bucket: return `true` if the value already exists, otherwise append it to the chain.

### Complexity
- **Time:** $O(N)$ average - constant-time lookups when elements distribute evenly across buckets; $O(N^2)$ worst case if all elements collide.
- **Space:** $O(N)$ - stores $N$ elements across the bucket lists.

### Notes & Edge Cases
- `abs(INT_MIN)` causes signed integer overflow in C++ - cast to `long long` before taking the absolute value in production code.
- Standard interview solution typically uses `unordered_set` for concise code, but custom chaining demonstrates the underlying hash table mechanics.