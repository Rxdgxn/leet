impl Solution {
    pub fn three_sum_closest(mut nums: Vec<i32>, target: i32) -> i32 {
        nums.sort();

        let size = nums.len();
        let mut i = 0usize;

        let mut min_dif = i32::MAX;
        let mut best_match = 0;

        while i < size - 1 {
            let t = target - nums[i];

            let mut st = i + 1;
            let mut dr = size - 1;

            while st < dr {
                let s = nums[st] + nums[dr];
                let diff = i32::abs(t - s);

                if diff < min_dif {
                    min_dif = diff;
                    best_match = s + nums[i];
                }

                if s < t {
                    st += 1;
                }
                else if s > t {
                    dr -= 1;
                }
                else {
                    return target;
                }
            }

            i += 1;
        }

        best_match
    }
}