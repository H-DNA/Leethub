# @param {String[]} bank
# @return {Integer}
def number_of_beams(bank)
    res = 0
    prev = 0

    for str in bank
        cur = str.chars.filter { |c| c == '1' }.count
        if cur > 0
            res += prev * cur
            prev = cur
        end 
    end

    return res
end