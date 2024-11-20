#include <map>

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::map<int, bool> map;

        for (int num: nums)
            map[num] = true;

        int max_count = 0;
        for (int num: nums) {
            if (map[num]) {
                int count = 1;

                map[num] = false;
                
                for (int i = num + 1; ; ++i)
                    if (map[i]) {
                        map[i] = false;
                        ++count;
                    } else break;
                
                for (int j = num - 1; ; --j)
                    if (map[j]) {
                        map[j] = false;
                        ++count;
                    } else break;
                
                if (count > max_count)
                    max_count = count;
            }
        }        

        return max_count;
    }
};