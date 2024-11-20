# @param {Integer[]} nums
# @return {Void} Do not return anything, modify nums in-place instead.
def sort_colors(nums)
    s = 0
    e = nums.length - 1
    i = 0
    while i <= e
        if nums[i] == 0
            nums[i], nums[s] = nums[s], nums[i]
            s += 1
            i += 1
        elsif nums[i] == 2
            nums[i], nums[e] = nums[e], nums[i]
            e -= 1
        else
            i += 1
        end
    end
end