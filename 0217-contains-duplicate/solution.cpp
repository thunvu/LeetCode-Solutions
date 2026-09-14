class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int bsize = nums.size()*2+1;

        std::vector<std::list<int>> hash_table(bsize);

        for (int num:nums)
        {
            // hash funct
            int b_num = std::abs(num)% bsize;

            for(int value :hash_table[b_num])
            {
                if (value == num)
                    return true;
            }
            hash_table[b_num].push_back(num);
        }
        return false;
    }
};