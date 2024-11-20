# @param {Integer[]} nums
# @return {Integer}
def special_array(nums)
    nums.sort!
    len = nums.length
    return len if len < nums[0]
    (nums[0]..nums[-1]).reduce(0) { |index, n; pos|
        pos = len - index
        return n if n == pos
        index += 1 while n == nums[index]
        next index
    }
    return -1
end