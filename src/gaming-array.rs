use std::env;
use std::fs::File;
use std::io::{self, BufRead, Write};

fn gamingArray(arr: &[i32]) -> String {
    let n = arr.len();
    let mut cnt = false;

    let mut original: Vec<(usize, i32)> = Vec::new();
    for i in 0 .. n { original.push((i, arr[i])); }

    let mut sorted = original.clone();
    sorted.sort_by(|a, b| b.1.cmp(&a.1));

    for (i, x) in sorted {
        if original.contains(&(i, x)) {
            if i == 0 { break; }

            original = Vec::from(&original[0 .. i]);

            cnt = !cnt;
        }
    }

    if cnt { return String::from("ANDY"); }
    return String::from("BOB");
}

fn main() {
    let stdin = io::stdin();
    let mut stdin_iterator = stdin.lock().lines();

    let mut fptr = File::create(env::var("OUTPUT_PATH").unwrap()).unwrap();

    let g = stdin_iterator.next().unwrap().unwrap().trim().parse::<i32>().unwrap();

    for _ in 0..g {
        let _arr_count = stdin_iterator.next().unwrap().unwrap().trim().parse::<i32>().unwrap();

        let arr: Vec<i32> = stdin_iterator.next().unwrap().unwrap()
            .trim_end()
            .split(' ')
            .map(|s| s.to_string().parse::<i32>().unwrap())
            .collect();

        let result = gamingArray(&arr);

        writeln!(&mut fptr, "{}", result).ok();
    }
}
