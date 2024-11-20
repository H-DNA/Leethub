# @param {String} s
# @return {Integer}
def num_steps(s)
    s = s.to_i 2
    count = 0
    while s != 1
        mod = s % 2
        count += mod
        s += mod
        s /= 2
        count += 1
    end
    count
end