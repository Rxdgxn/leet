impl Solution {
    pub fn zero_filled_subarray(nums: Vec<i32>) -> i64 {
        let mut ret = 0i64;
        let mut cont = 0i64;
        
        for n in nums {
            if n != 0 {
                let n: i64 = cont as i64;
                ret += n * (n + 1) / 2;
                cont = 0;
            }
            else {
                cont += 1;
            }
        }

        let n: i64 = cont as i64;
        ret += n * (n + 1) / 2;

        ret
    }
}