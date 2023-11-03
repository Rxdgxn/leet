use std::env;
use std::fs::File;
use std::io::{self, BufRead, Write};


fn absolutePermutation(n: i32, k: i32) -> Vec<i32> {
    // |i - x| = k
    let mut perm: Vec<i32> = Vec::new();

    use std::collections::HashMap;
    let mut hm: HashMap<i32, bool> = HashMap::new();

    for i in 1 ..= n {
        if i - k > 0 && !hm.contains_key(&(i - k)) {
            perm.push(i - k);
            hm.insert(i - k, true);
        }
        else if i + k <= n && !hm.contains_key(&(i + k)) {
            perm.push(i + k);
            hm.insert(i + k, true);
        }
        else { return [-1].to_vec(); }
    }

    perm
}

fn main() {
    let stdin = io::stdin();
    let mut stdin_iterator = stdin.lock().lines();

    let mut fptr = File::create(env::var("OUTPUT_PATH").unwrap()).unwrap();

    let t = stdin_iterator.next().unwrap().unwrap().trim().parse::<i32>().unwrap();

    for _ in 0..t {
        let first_multiple_input: Vec<String> = stdin_iterator.next().unwrap().unwrap()
            .split(' ')
            .map(|s| s.to_string())
            .collect();

        let n = first_multiple_input[0].trim().parse::<i32>().unwrap();

        let k = first_multiple_input[1].trim().parse::<i32>().unwrap();

        let result = absolutePermutation(n, k);

        for i in 0..result.len() {
            write!(&mut fptr, "{}", result[i]).ok();

            if i != result.len() - 1 {
                write!(&mut fptr, " ").ok();
            }
        }

        writeln!(&mut fptr).ok();
    }
}