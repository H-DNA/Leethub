class Solution {
public:
    string getSmallestString(int n, int k) {
      std::string ostr;
      while (ostr.length() < n) {
        ostr += "a";
        --k;
      }
      int last = n - 1;
      while (k > 0) {
        ostr[last--] += min(25, k);
        k -= min(25, k);
      }
      return ostr;
    }
};