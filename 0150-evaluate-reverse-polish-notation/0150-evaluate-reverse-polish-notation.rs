impl Solution {
    pub fn eval_rpn(tokens: Vec<String>) -> i32 {
        let mut stack = vec![];

        for token in tokens {
            match token.as_str() {
                "+" => {
                    let op1 = stack.pop().unwrap();
                    let op2 = stack.pop().unwrap();
                    stack.push(op1 + op2);
                },
                "-" => {
                    let op1 = stack.pop().unwrap();
                    let op2 = stack.pop().unwrap();
                    stack.push(op2 - op1);
                },
                "*" => {
                    let op1 = stack.pop().unwrap();
                    let op2 = stack.pop().unwrap();
                    stack.push(op1 * op2);
                },
                "/" => {
                    let op1 = stack.pop().unwrap();
                    let op2 = stack.pop().unwrap();
                    stack.push(op2 / op1);
                },
                number => stack.push(number.parse().unwrap())
            }
        }
        stack.pop().unwrap()
    }
}