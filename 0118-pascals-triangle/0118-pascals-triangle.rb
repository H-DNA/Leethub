def generate_next_rows(prev_rows)
    new_rows = Array[1];
    for i in 1...prev_rows.size
        new_rows.append(prev_rows[i] + prev_rows[i - 1]);
    end
    new_rows.append(1);
    return new_rows;
end

# @param {Integer} num_rows
# @return {Integer[][]}
def generate(num_rows)
    res = Array[Array[1]];
    for i in 1...num_rows
        res.append(generate_next_rows(res[i - 1]));
    end
    return res;
end