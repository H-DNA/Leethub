-spec is_palindrome(X :: integer()) -> boolean().
is_palindrome(X) ->
  Digits = integer_to_list(X),
  Reversed_digits = [lists:nth(I, Digits) || I <- lists:seq(length(Digits), 1, -1)],
  Digits == Reversed_digits.