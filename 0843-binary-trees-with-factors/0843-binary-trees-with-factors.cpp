class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        constexpr unsigned long long mod = 1e9 + 7;
        unsigned long long res = 0;
        vector<unsigned long long> total(arr.size());
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); ++i) {
            ++total[i];
            int begin = 0, end = i - 1;
            while (begin <= end) {
                unsigned long long prod = (unsigned long long) arr[begin] * arr[end];
                if (prod < arr[i]) ++begin;
                else if (prod > arr[i]) --end;
                else {
                    if (begin == end) total[i] += total[begin] * total[end] % mod;
                    else total[i] += 2 * total[begin] * total[end] % mod;
                    ++begin;
                    --end;
                }
            }
            res = (res + total[i]) % mod;
        }
        return res;
    }
};