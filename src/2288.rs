impl Solution {
    pub fn discount_prices(sentence: String, discount: i32) -> String {
        let discount = (discount as f64) / 100.0;

        let discounted: Vec<String> = sentence.split_whitespace().map(|word| {
            if word.chars().nth(0).unwrap() == '$' {
                let non_numbers: Vec<char> = word.chars().filter(|ch| !ch.is_numeric()).collect();

                if non_numbers.len() > 1 || word.len() == 1 {
                    word.to_string()
                }
                else {
                    let mut price = word[1 ..].parse::<f64>().unwrap();
                    price -= discount * price;

                    String::from(format!("${:.2}", price))
                }
            }
            else {
                word.to_string()
            }
        }).collect();

        discounted.join(" ")
    }
}