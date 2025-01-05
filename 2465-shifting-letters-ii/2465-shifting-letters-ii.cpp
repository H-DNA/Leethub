#define ALPHA_COUNT 26

class Solution {
public:
  string shiftingLetters(string s, vector<vector<int>>& shifts) {
    std::vector<long int> scatteredShifts(s.length()); // s[i] would be shifted by scatteredShifts[i] + ... + scatteredShifts[len - 1]
    for (const vector<int> shift: shifts) {
      long int inc = shift[2] ? 1 : -1;
      if (shift[0] > 0) {
        scatteredShifts[shift[0] - 1] -= inc;
      }
      scatteredShifts[shift[1]] += inc;
    }
    const unsigned int len = s.length();
    long int curShift = 0;
    for (long int i = len - 1; i >= 0; --i) {
      curShift += scatteredShifts[i];
      s[i] = ((s[i] - 'a' + curShift) % 26 + 26) % 26 + 'a';
    }
    return s;
  }
};