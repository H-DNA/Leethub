class Solution {
public:
    int minSteps(string s, string t) {
        int* dmap = new int[256]{};
        for (const auto c: s) {
            ++dmap[c];
        }
        for (const auto c: t) {
            --dmap[c];
        }
        int steps = 0;
        for (int i = 0; i < 256; ++i) {
            const int diff = dmap[i];
            steps += diff > 0 ? diff : 0;
        }
        
        delete[] dmap;
        return steps;
    }
};