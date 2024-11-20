# @param {String} a
# @param {String} b
# @return {Integer}
def convert_cost(a, b)
    (a.each_byte { |c| break c; } - b.each_byte { |c| break c; }).abs
end

# @param {String} s
# @param {String} t
# @param {Integer} max_cost
# @return {Integer}
def equal_substring(s, t, max_cost)
    end_id = 0
    max_len = 0
    cur_cost = 0
    len = s.length
    (0...len).each_with_index { |start_id|
        while end_id < len
            new_cost = cur_cost + convert_cost(s[end_id], t[end_id])
            break if new_cost > max_cost
            cur_cost = new_cost
            end_id += 1
        end
        max_len = [max_len, end_id - start_id].max
        cur_cost -= convert_cost(s[start_id], t[start_id]) if cur_cost > 0
        end_id = start_id + 1 if cur_cost == 0
    }
    max_len
end