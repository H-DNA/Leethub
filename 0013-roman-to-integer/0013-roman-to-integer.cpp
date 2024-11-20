class Solution {
public:
    bool less(char i1, char i2) {
        switch (i1) {
            case 'I': return true;
            case 'V': return (i2 != 'I');
            case 'X': return (i2 != 'V') && (i2 != 'I');
            case 'L': return (i2 != 'I') && (i2 != 'V') && (i2 != 'X');
            case 'C': return (i2 == 'D') || (i2 == 'M');
            case 'D': return (i2 == 'M');
            case 'M': return false;
        }
        return false;
    }
    int val(char i1) {
        switch(i1) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
        return 0;
    }
    int romanToInt(string s) {
        int num = 0;
        for (int i = 0; i < s.size() - 1; ++i)
            if (s[i] != s[i + 1] && less(s[i], s[i + 1]))
                num -=  val(s[i]);
            else num += val(s[i]);
        num += val(s[s.size() - 1]);
        return num;
    }
};