# @param {Integer} n
# @return {Integer}
def count_digit_one(n)
    if n == 0
        return 0
    end
    total = 0
    order = 1
    n.to_s.length.times do
        if n.to_i % 10 == 1
            residual = n / 10.0
            residual = (residual * 10 - (residual * 10).to_i) * 10
            total += 1
        elsif n.to_i % 10 != 0
            residual = 10
        else
            residual = 0
        end
        total += (n / 10.0).floor * order + residual * order / 10
        puts total
        order *= 10
        n /= 10.0
    end
    total.round
end