class Solution {
public:
    int climbStairs(int n) {
        static int steps[46]{};
        steps[1] = 1;
        steps[0] = 1;
        for (int i = 2; i <= n; ++i)
            steps[i] = steps[i - 1] + steps[i - 2];
        return steps[n];
    }
};