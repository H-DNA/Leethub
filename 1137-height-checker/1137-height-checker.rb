# @param {Integer[]} heights
# @return {Integer}
def height_checker(heights)
    heights.sort
           .zip(heights)
           .reduce(0) do |acc, (h1, h2)|
                acc += (h1 != h2) ? 1 : 0
           end
end