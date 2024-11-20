# @param {Integer[]} nums
# @param {Integer} k
# @return {Boolean}
def check_subarray_sum(nums, k)
    modMap = Hash.new
    curMod = 0
    modMap[0] = -1
    nums.each_with_index do |v, i|
        curMod = (curMod + v) % k
        if modMap.include? curMod then
            return true if i - modMap[curMod] > 1
        else 
            modMap[curMod] = i
        end
    end
    false
end