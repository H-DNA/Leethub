class Solution {
public:
    int minSetSize(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int count = -1;
        int cur = INT_MIN;
        vector<int> occ;
        for (auto n: arr) 
            if (cur != n) {
                if (count != -1) occ.push_back(count);
                count = 1;
                cur = n;
            } else ++count;
        occ.push_back(count);
        sort(occ.rbegin(), occ.rend());
        
        int n_nums = 0;
        int n_occs = 0;
        for (auto n: occ) {
            n_occs += n;
            n_nums += 1;
            if (n_occs >= (arr.size() + 1) / 2)
                return n_nums;
        }
        return -1;
    }
};