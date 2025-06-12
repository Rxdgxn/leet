impl Solution {
    pub fn max_adjacent_distance(nums: Vec<i32>) -> i32 {
        let mut max = -100;
        let n = nums.len();

        for i in 0 .. n {
            let diff = i32::abs(nums[i] - nums[(i + 1) % n]);
            if diff > max {
                max = diff;
            }
        }

        max
    }
}