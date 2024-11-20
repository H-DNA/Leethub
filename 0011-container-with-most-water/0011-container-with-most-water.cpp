struct Terminals {
  int val;
  int first;
  int last;
};
struct Node {
  int val;
  int id;
  bool operator<(const Node& other) {
    return val < other.val || (val == other.val && id < other.id);
  }
  bool operator==(const Node& other) {
    return val == other.val && id == other.id;
  }
};

class Solution {
public:
    
    void find_first_and_last(vector<Node>& height_with_id, vector<Terminals>& terms){
      for (int i = 0; i < height_with_id.size(); ++i) {
        auto point = height_with_id[i];
        if (i == 0 || point.val != height_with_id[i - 1].val)
          terms.push_back(Terminals{point.val, point.id, point.id});
        terms.back().first = min(terms.back().first, point.id);
        terms.back().last = max(terms.back().last, point.id);
      }
    }
  
    int maxArea(vector<int>& height) {
      vector<Node> height_with_id;
      for (int i = 0; i < height.size(); ++i) height_with_id.push_back({height[i], i});
      sort(height_with_id.begin(), height_with_id.end());
      vector<Terminals> terms;
      find_first_and_last(height_with_id, terms);
      int last = -1;
      int first = height_with_id.size();
      int maxA = -1;
      for (int i = terms.size() - 1; i >= 0; --i) {
        last = max(last, terms[i].last);
        first = min (first, terms[i].first);
        maxA = max(maxA, terms[i].val * max(abs(terms[i].last - first), abs(terms[i].first - last)));
      }
      return maxA;
    }
};