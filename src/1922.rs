impl Solution {
    const MOD: i64 = 1000000007;

    pub fn qmul(a: i32, mut n: i64) -> i32 {
        let mut ret = 1;
        let mut mul = a;

        while n > 0 {
            if n % 2 == 1 {
                ret = ((ret as i64) * (mul as i64) % Self::MOD) as i32;
            }
            mul = ((mul as i64) * (mul as i64) % Self::MOD) as i32;

            n /= 2;
        }

        ret
    }

    pub fn count_good_numbers(n: i64) -> i32 {
        ((Self::qmul(5, (n + 1) / 2) as i64) * (Self::qmul(4, n / 2) as i64) % Self::MOD) as i32
    }
}