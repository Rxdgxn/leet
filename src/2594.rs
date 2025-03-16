impl Solution {
    pub fn repair_cars(ranks: Vec<i32>, cars: i32) -> i64 {
        let mut low = 1i64;
        let c = cars as i64;
        let mut high = (*ranks.iter().min().unwrap() as i64) * c * c;

        while low < high {
            let mid = (low + high) / 2;
            let mut fixed = 0i64;

            for r in &ranks {
                fixed += (mid / (*r as i64)).isqrt();

                if fixed >= c {
                    break;
                }
            }

            if fixed < c {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }

        return low;
    }
}