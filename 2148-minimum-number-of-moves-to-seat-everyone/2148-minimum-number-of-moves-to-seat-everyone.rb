# @param {Integer[]} seats
# @param {Integer[]} students
# @return {Integer}
def min_moves_to_seat(seats, students)
    seats.sort
         .zip(students.sort)
         .reduce(0) do |acc, (seat, student)|
            acc + (seat - student).abs
         end
end