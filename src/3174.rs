impl Solution {
    pub fn clear_digits(s: String) -> String {
        let mut stack = String::new();

        for ch in s.chars() {
            if ch.is_digit(10) {
                stack.pop();
            }
            else {
                stack.push(ch);
            }
        }

        return stack;
    }
}