class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
       sort(nums1.begin(), nums1.end());
       sort(nums2.begin(), nums2.end());
       std::vector<int> v;
       int ptr1 = 0, ptr2 = 0;
       while (ptr1 < nums1.size() && ptr2 < nums2.size()) {
         if (nums1[ptr1] < nums2[ptr2]) ++ptr1;
         else if (nums2[ptr2] < nums1[ptr1]) ++ptr2;
         else if (nums2[ptr2] == nums1[ptr1]) {
           v.push_back(nums2[ptr2]);
           ++ptr2; ++ptr1;
         }
       }
      return v;
    }
};