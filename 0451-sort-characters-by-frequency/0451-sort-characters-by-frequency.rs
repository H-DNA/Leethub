struct Record {
    c: char,
    freq: usize,
}

fn init(v: &mut Vec<Record>) {    
    for c in 'a'..='z' {
        v.push(Record { c, freq: 0 });
    }

    for c in 'A'..='Z' {
        v.push(Record { c, freq: 0 });
    }

    for c in '0'..='9' {
        v.push(Record { c, freq: 0 });
    }
}

fn build(v: &Vec<Record>) -> String {
    let mut res = String::new();

    for record in v {
        res.push_str(String::from_utf8(vec![record.c as u8; record.freq]).unwrap().as_str());
    }

    res
}

impl Solution {
    pub fn frequency_sort(s: String) -> String {
        let mut freq = vec![];
        init(&mut freq);

        for c in s.chars() {
            if c >= 'a' && c <= 'z' {
                freq[c as usize - 'a' as usize].freq += 1;
            } else if c >= 'A' && c <= 'Z' {
                freq[c as usize - 'A' as usize + 26].freq += 1;
            } else {
                freq[c as usize - '0' as usize + 52].freq += 1;
            }
        }

        freq.sort_by(|a, b| b.freq.partial_cmp(&a.freq).unwrap());

        build(&freq)
    }
}