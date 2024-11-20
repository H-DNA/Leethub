class NumArray {
private:
    long long n;
    std::vector<int> segTree;
public:
    NumArray(vector<int>& nums): n(nums.size()), segTree( 2 * n ) {
        for (long long i = 0; i < n; ++i)
            segTree[n + i] = nums[i];
        for (long long i = n - 1; i >= 1; --i)
            segTree[i] = segTree[i << 1] + segTree[i << 1 | 1];
    }
    
    void update(int index, int val) {
        index += n;
        int delta = val - segTree[index];
        while (index >= 1) {
            segTree[index] += delta;
            index >>= 1;
        }
    }
    
    int sumRange(int left, int right) {
        left += n;
        right += n;
        int sum = 0;
        for (;left <= right; left >>= 1, right >>= 1) {
            if (!(right & 1)) {
                sum += segTree[right];
                --right;
            }
            
            if (left & 1) {
                sum += segTree[left];
                ++left;
            }
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */