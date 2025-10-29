impl Solution {
    pub fn smallest_number(n: i32) -> i32 {
        let mut p = 2;

        while p <= n {
            p *= 2;
        }

        p - 1
    }
}