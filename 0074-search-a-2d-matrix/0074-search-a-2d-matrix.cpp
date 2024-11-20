class Solution {
public:
    int rowSearch(const vector<vector<int>>& matrix, int target) {
      int left = 0;
      int right = matrix.size() - 1;
      while (left <= right) {
        int mid = (left + right) >> 1;
        const int midval = matrix[mid][0];
        if (midval > target) right = mid - 1;
        else if (midval < target) left = mid + 1;
        else return mid;
      }
      return left - 1;
    }
  
    bool celSearch(const vector<int>& row, int target) {
      int left = 0;
      int right = row.size() - 1;
      while (left <= right) {
        int mid = (left + right) >> 1;
        if (row[mid] > target) right = mid - 1;
        else if (row[mid] < target) left = mid + 1;
        else return true;
      }
      return false;
    }
  
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int r = rowSearch(matrix, target);
      return r >= 0 && celSearch(matrix[r], target);
    }
};