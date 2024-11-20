class Solution {
public:
    int countVowelPermutation(int n) {
        long long a = 1, e = 1, o = 1, u = 1, i = 1;
        constexpr long long mod = 1e9 + 7;
        for (long long j = 2; j <= n; ++j) {
            const long long a_next = (e + u + i) % mod;
            const long long e_next = (a + i) % mod;
            const long long o_next = i % mod;
            const long long u_next = (o + i) % mod;
            const long long i_next = (e + o) % mod;
            a = a_next;
            e = e_next;
            o = o_next;
            u = u_next;
            i = i_next;
        }
        return (a + e + o + u + i) % mod;
    }
};