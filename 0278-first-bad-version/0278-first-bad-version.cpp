// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
      long long left = 0, right = n - 1;
      long long first = n;
      while (left <= right) {
        long long mid = (left + right) >> 1;
        if (isBadVersion(mid)) {
          right = mid - 1;
          first = mid;
        }
        else {
          left = mid + 1;
        }
      }
      return first;
    }
};