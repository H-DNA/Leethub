impl Solution {
    pub fn is_vowel(c: char) -> bool {
        match (c) {
            'a' | 'e' | 'o' | 'i' | 'u' | 'A' | 'E' | 'O' | 'I' | 'U' => true,
            _ => false
        }
    }

    pub fn halves_are_alike(s: String) -> bool {
        let mut leftHalf = 0;
        let mut rightHalf = 0;
        let len = s.len();
        for (i, c) in s.chars().enumerate() {
            if Solution::is_vowel(c) {
                if i <= (len - 1) / 2 {
                    leftHalf += 1;
                }
                if i >= len / 2 {
                    rightHalf += 1;
                }
            }
        }

        leftHalf == rightHalf
    }
}