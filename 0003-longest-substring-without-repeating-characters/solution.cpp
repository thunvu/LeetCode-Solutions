class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::vector<int> seen(128,-1);
        int result = 0;
        int left = 0;

        for(int right = 0; right < s.length();right++)
        {
            char c = s[right];
            if(seen[c] >= left)
                left = seen[c]+1;
            seen[c] = right;
            result = std::max(result, right - left +1);
        }
        return result;
    }
};

