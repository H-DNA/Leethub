class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        return findDifferentBinaryString_recur(nums, nums.size(), 0);
    }

    string findDifferentBinaryString_recur(vector<string>& nums, int length, int index) {
        if (length == 0) {
            return "";
        }
        if (length == 1 && nums.size() == 1) {
            return nums[0][index] == '1' ? "0" : "1";
        }
        if (nums.size() == 0) {
            std::string res = "";
            for (int i = 0; i < length; ++i) {
                res += "0";
            }
            return res;
        }
        std::vector<string> left;
        std::vector<string> right;
        for (const string& num: nums) {
            if (num[index] == '0') {
                left.push_back(num);
            } else {
                right.push_back(num);
            }
        }
        const string left_res = findDifferentBinaryString_recur(left, length - 1, index + 1);
        if (left_res != "") {
            return std::string("0") + left_res;            
        }
        const string right_res = findDifferentBinaryString_recur(right, length - 1, index + 1);
        if (right_res != "") {
            return std::string("1") + right_res;
        }
        return "";
    }
};