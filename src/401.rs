impl Solution {
    pub fn parse(clock: i32) -> String {
        let mut m = 0;
        let mut h = 0;

        for i in 0 .. 6 {
            m += clock & (1 << i);
        }

        for i in 6 .. 10 {
            h += ((clock >> i) & 1) << (i - 6);
        }

        if m >= 60 || h >= 12 {
            return String::new();
        }

        let mut ret = String::new();

        ret.push_str(&h.to_string());
        ret.push(':');

        if m < 10 {
            ret.push('0');
        }

        ret.push_str(&m.to_string());

        ret
    }

    pub fn back(mut clock: i32, v: &mut Vec<String>, leds: i32, bit: i32) {
        if bit == 10 && leds == 0 {
            v.push(Self::parse(clock));

            if v.last().unwrap().is_empty() {
                v.pop();
            }

            return;
        }
        if bit >= 10 { return; }

        clock |= 1 << bit;
        Self::back(clock, v, leds - 1, bit + 1);

        clock &= !(1 << bit);
        Self::back(clock, v, leds, bit + 1);
    }

    pub fn read_binary_watch(turned_on: i32) -> Vec<String> {
        let mut ret = Vec::new();

        if turned_on == 0 {
            return Vec::from([String::from("0:00")]);
        }

        Self::back(0, &mut ret, turned_on, 0);

        ret
    }
}