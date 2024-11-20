struct Node {
  int val;
  int id;
  bool operator<(const Node& other){
    return val < other.val;
  } 
  bool operator==(const Node& other) {
    return val == other.val;
  }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       std::vector<Node> nodes;
       for (int i = 0; i < nums.size(); ++i)
         nodes.push_back(Node{nums[i], i});
       int left = 0;
       int right = nodes.size() - 1;
       sort(nodes.begin(), nodes.end() );
       while (left < right) {
        while (nodes[left].val + nodes[right].val > target)
          --right;
        if (nodes[left].val + nodes[right].val == target) return {nodes[left].id , nodes[right].id};
        ++left;
      }
      return {};
    }
};