# @param {String} s
# @return {Integer}
def longest_valid_parentheses(s)
    longest = 0
    n_lefts = 0
    pair_stack = []
    s.each_char.with_index { |c, i|
        case c
        when "("
            n_lefts += 1
            pair_stack << [i, -1]
        when ")"
            if n_lefts > 0
                while pair_stack.length > 0 and pair_stack[-1][1] != -1
                    pair_stack.pop
                end
                if pair_stack.length > 0
                    pair_stack[-1][1] = i
                end
                while pair_stack.length > 1 and pair_stack[-2][1] == pair_stack[-1][0] - 1
                    first = pair_stack.pop
                    second = pair_stack.pop
                    pair_stack << [second[0], first[1]] 
                end
                n_lefts -= 1
            end
        end
    }

    
    pair_stack.select { |_, e2| e2 != -1 }
              .map { |e1, e2| e2 - e1 + 1 }
              .max or 0
end