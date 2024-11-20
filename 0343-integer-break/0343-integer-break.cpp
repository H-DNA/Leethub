class Solution {
public:
    int integerBreak(int n) {
        int maxprod = 0;
        for (int k = 2; k <= n; ++k) {
            int m = n / k;
            int a = n % k;
            int prod = pow(m + 1, a) * pow(m, k - a);
            if (prod > maxprod)
                maxprod = prod;
        }
        return maxprod;
    }
};