impl Solution {
    pub fn remove_occurrences(s: String, part: String) -> String {
        let part_size = part.len();

        let mut stack = String::new();

        for ch in s.chars() {
            stack.push(ch);
            let i = stack.len();

            if i >= part_size && &stack[i - part_size .. i] == part {
                for _ in 0 .. part_size {
                    stack.pop();
                }
            }
        }

        return stack;
    }
}