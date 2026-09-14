# 0003. Longest Substring Without Repeating Characters

### Problem Summary
Given a string `s`, find the length of the longest substring without repeating characters.

---

### Approach: Optimized Sliding Window (Direct Lookup Table)
Maintain a dynamic window `[left, right]` containing only distinct characters:

1. **Lookup Table:** Use a fixed-size array `last_seen(128, -1)` instead of a hash table to store the most recent 0-indexed position of each ASCII character.
2. **Window Expansion:** Iterate `right` from `0` to `n - 1`.
3. **Window Shrink / Jump:** If character `s[right]` was seen previously at index `idx` and `idx >= left` (meaning it lies within the active window), jump `left = idx + 1`.
4. **Update State:** Record `last_seen[s[right]] = right` and update `max_len = max(max_len, right - left + 1)`.

---

### Complexity
- **Time Complexity:** $O(N)$ — each character is visited exactly once by `right`; `left` only jumps forward, never backward.
- **Space Complexity:** $O(1)$ — the lookup table uses fixed $128 \times \text{sizeof}(int) \approx 512$ bytes, completely independent of string length $N$.

---

### Notes & Edge Cases
- **Why `idx >= left` is required:** Characters outside the active window remain stored in `last_seen`. For example, in `"abba"`, when reaching the second `'a'` at index `3`, the previous `'a'` at index `0` is ignored because `0 < left` (`left` is already at `2`).
- **Range-based for loop trap:** Modifying a loop counter inside `for (int i = 0; char c : s)` does **not** rewind the underlying iterator.
- **Empty string / Single character:**
  - `s = ""` $\rightarrow$ returns `0`.
  - `s = " "` $\rightarrow$ returns `1` (spaces are valid ASCII 32 characters handled by the 128-element table).
- **All identical characters (`"bbbbb"`):** The window size resets to `1` at every step, yielding `1`.