# @param {String} expression
# @return {Boolean}
class String
    def split_param
        res = []
        n_lefts = 0
        last_comma = 0
        self.each_char.with_index { |c, i| 
            case c
            when "("
                n_lefts += 1
            when ")"
                n_lefts -= 1
            when ","
                if n_lefts == 0
                    res << self[last_comma...i]
                    last_comma = i + 1
                end
            end
        }
        res << self[last_comma...self.length]
        res
    end
end

def parse_bool_expr(expression)
    case expression[0]
    when "t"
        true
    when "f"
        false
    when "!"
        !(parse_bool_expr expression[2..-1])
    when "&"
        expression[2...-1].split_param.map { |sub| parse_bool_expr sub }
                                      .all?
    when "|"
        expression[2...-1].split_param.map { |sub| parse_bool_expr sub }
                                      .any?
    else
        puts expression[0]
    end
end