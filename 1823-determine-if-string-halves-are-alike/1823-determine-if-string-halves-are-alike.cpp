class Solution {
public:
    bool isVowel(char c) {
        switch (tolower(c)) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                return true;
            default:
                return false;
        }
    }
    bool halvesAreAlike(string s) {
        int leftHalfCount = 0;
        int rightHalfCount = 0;
        //const len = s.size();
        for (int i = 0; i < s.size(); ++i) {
            if (isVowel(s[i])) {
                if (i <= (s.size() - 1)/ 2) {
                    ++leftHalfCount;
                }
                if (i >= s.size() / 2) {
                    ++rightHalfCount;
                }
            }
        }

        return leftHalfCount == rightHalfCount;
    }
};