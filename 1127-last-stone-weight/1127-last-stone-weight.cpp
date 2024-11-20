class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
      std::multiset<int, std::greater<int>> seq;
      for (int s: stones) seq.insert(s);
      while (seq.size() > 1) {
        auto tmp1 = seq.extract(seq.begin()).value();
        auto tmp2 = seq.extract(seq.begin()).value();
        seq.insert(tmp1 - tmp2);
      }
      auto tmp = seq.extract(seq.begin()).value();
      return tmp;
    }
};