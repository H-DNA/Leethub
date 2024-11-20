# @param {Integer[]} arr
# @return {Integer}
def count_triplets(arr)
    map = Hash.new
    map.default_proc = proc { |hash, key| hash[key] = [] }
    total = 0
    cur_xor = 0
    map[cur_xor] << -1
    arr.each_with_index { |v, i|
        cur_xor ^= v
        map[cur_xor].each { |j|
            acc = i - j - 1
            total += acc if acc > 0 
        }
        map[cur_xor] << i
    }
    total
end