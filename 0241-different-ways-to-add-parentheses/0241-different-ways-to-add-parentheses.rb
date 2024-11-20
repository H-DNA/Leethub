def f(left, right, op)
    case op
    when "+"
        left + right
    when "-"
        left - right
    when "*"
        left * right
    end
end

# @param {String} expression
# @return {Integer[]}
def diff_ways_to_compute(expression)
    if (expression.rindex /[*+-]/) == nil
        return [expression.to_i]
    end
    res = []
    last_op_index = expression.length
    while (op_index = expression.rindex /[*+-]/, last_op_index - 1) != nil
        left_sub_expr = expression[0...op_index]
        right_sub_expr = expression[op_index + 1...expression.length]
        op = expression[op_index]
        (diff_ways_to_compute left_sub_expr).each { |l|
            (diff_ways_to_compute right_sub_expr).each { |r|
                res << f(l, r, op)
            }
        }
        last_op_index = op_index
    end
    res
end