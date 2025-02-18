class Solution {
public:
    string smallestNumber(string pattern) {
        vector<uint8_t> digits;
        digits.reserve(pattern.size() + 1);
        bool remaining_digits[] = {true, true, true, true, true, true, true, true, true};
        for (int i = 1; i <= 9; ++i) {
            digits.push_back(i);
            remaining_digits[i - 1] = false;
            if (smallestNumberRecur(pattern, 0, digits, i, remaining_digits)) {
                break;
            }
            remaining_digits[i - 1] = true;
            digits.pop_back();
        }
        string res;
        for (const uint8_t digit: digits) {
            res += digit + '0';
        }
        return res;
    }

    bool smallestNumberRecur(const string& pattern, int index, vector<uint8_t>& digits, uint8_t last_digit, bool* remaining_digits) {
        if (index == pattern.size()) return true;
        uint8_t c = pattern[index];
        if (c == 'I') {
            for (int i = 1; i <= 9; ++i) {
                if (i <= last_digit || !remaining_digits[i - 1]) {
                    continue;
                } else {
                    digits.push_back(i);
                    remaining_digits[i - 1] = false;
                    if (smallestNumberRecur(pattern, index + 1, digits, i, remaining_digits)) {
                        return true;
                    }
                    remaining_digits[i - 1] = true;
                    digits.pop_back();
                }
            }
            return false;
        } else {
            for (int i = 1; i <= 9; ++i) {
                if (i >= last_digit || !remaining_digits[i - 1]) {
                    continue;
                } else {
                    digits.push_back(i);
                    remaining_digits[i - 1] = false;
                    if (smallestNumberRecur(pattern, index + 1, digits, i, remaining_digits)) {
                        return true;
                    }
                    remaining_digits[i - 1] = true;
                    digits.pop_back();
                }
            }
            return false;
        }
    }
};