# @param {Integer[]} nums
# @return {Integer[][]}
def find_matrix(nums)
    map = Array.new(201, 0)
    res = []

    for n in nums
        map[n] += 1
        if map[n] > res.length()
            res.append([n])
        else
            res[map[n] - 1].append(n)
        end
    end
    
    return res
end