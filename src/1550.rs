impl Solution {
    pub fn three_consecutive_odds(arr: Vec<i32>) -> bool {
        let size = arr.len() as i32 - 2;
        if size < 0 {
            return false;
        }

        let size = size as usize;
 
        for i in 0 .. size {
            if arr[i] % 2 == 1 && arr[i + 1] % 2 == 1 && arr[i + 2] % 2 == 1 {
                return true;
            }
        }

        false
    }
}