#include <unordered_map>

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        std::unordered_map<char, int> map;
        for (char c: magazine) {
            ++map[c];
        }
        for (char c: ransomNote) {
            --map[c];
            if (map[c] < 0) {
                return false;
            }
        }
        return true;
    }
};