# @param {Integer[]} nums
# @param {Integer} k
# @return {Integer}
def subarrays_div_by_k(nums, k)
    total = 0
    prefixMod = { 0 => 1 }
    prefixMod.default = 0
    nums.reduce(0) do |acc, n|
        curAcc = (acc + n) % k
        total += prefixMod[curAcc]
        prefixMod[curAcc] += 1
        curAcc
    end
    total
end