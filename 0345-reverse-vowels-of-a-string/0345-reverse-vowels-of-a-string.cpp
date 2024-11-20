class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }

    void reverse(string& s, int left, int right) {
        if (left >= right)
            return;

        if (!isVowel(s[left]))
            return reverse(s, left + 1, right);
        
        if (!isVowel(s[right]))
            return reverse(s, left, right - 1);
        
        swap(s[left], s[right]);
        return reverse(s, left + 1, right - 1);
    }

    string reverseVowels(string s) {
        return reverse(s, 0, s.size() - 1), s;
    }
};