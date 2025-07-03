class Solution {
public:
    char kthCharacter(int k) {
        int c = 0;
        k -= 1;
        while (k > 0) {
            if (k % 2 == 1) ++c;
            k /= 2;
        }
        return c % 26 + 'a';
    }
};