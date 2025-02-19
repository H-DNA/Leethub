fn get_happy_string_trail_count_of_len(len: i32) -> i32 {
    (2 as i32).pow(len as u32)
}

fn get_happy_string_count_of_len(len: i32) -> i32 {
    3 * ((2 as i32).pow(len as u32 - 1))
}

impl Solution {
    pub fn get_happy_string(n: i32, k: i32) -> String {
        let mut k = k - 1;
        if get_happy_string_count_of_len(n) <= k {
            return String::from("");
        }
        let mut bytes = vec![];
        let trail_count = get_happy_string_trail_count_of_len(n - 1);
        let c_order = k / trail_count;
        k = k % trail_count;
        let mut last_char;
        match c_order {
            0 => {
                last_char = String::from("a");
            }
            1 => {
                last_char = String::from("b");
            }
            2 => {
                last_char = String::from("c");
            }
            default => panic!("Unreachable"),
        }
        bytes.push(last_char.clone());
        for i in 1..n {
            let trail_count = get_happy_string_trail_count_of_len(n - i - 1);
            let c_order = k / trail_count;
            k = k % trail_count;
            match c_order {
                0 => {
                    last_char = if last_char == "a" {
                        String::from("b")
                    } else {
                        String::from("a")
                    };
                }
                1 => {
                    last_char = if last_char == "c" {
                        String::from("b")
                    } else {
                        String::from("c")
                    };
                }
                default => panic!("Unreachable"),
            }
            bytes.push(last_char.clone());
        }
        bytes.join("")
    }
}