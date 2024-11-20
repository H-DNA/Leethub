class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t bm = 1;
        int cnt = 0;
        while (n) {
            if (n & bm) ++cnt;
            n = n & (~bm);
            bm <<= 1;
        }
        return cnt;
    }
};