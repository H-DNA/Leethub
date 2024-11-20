class KthLargest {
public:
    int k;
    priority_queue<int, std::vector<int>, std::greater<int>> q;
  
    KthLargest(int k, vector<int>& nums) {
      this->k = k;
      for (auto i: nums) {
        add(i);
      }
    }
  
    int add(int val) {
      if (q.size() < k) q.push(val);
      else {
        if (q.top() < val) {
          q.pop();
          q.push(val);
          return q.top();
        }
        return q.top();
      }
      return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */