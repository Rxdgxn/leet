impl Solution {
    pub fn count_largest_group(n: i32) -> i32 {
        let mut map = vec![0; 37];
        let mut max = 0;
        let mut count = 0;

        for mut i in 1 ..= n {
            let mut s = 0;

            while i != 0 {
                s += i % 10;
                i /= 10;
            }

            let index = s as usize;
            map[index] += 1;

            if map[index] > max {
                max = map[index];
                count = 1;
            }
            else if map[index] == max {
                count += 1;
            }
        }

        count
    }
}