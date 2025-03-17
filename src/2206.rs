impl Solution {
    pub fn divide_array(nums: Vec<i32>) -> bool {
        let mut map: Vec<i32> = vec![0; 501];

        for num in &nums {
            map[*num as usize] += 1;
        }

        for i in 1 ..= 500 {
            if map[i] % 2 == 1 {
                return false;
            }
        }

        return true;
    }
}