use std::env;
use std::fs::File;
use std::io::{self, BufRead, Write};

fn larrysArray(a: &[i32]) -> String {
    let mut invs = 0;

    for i in 0 .. a.len() {
        for j in i + 1 .. a.len() {
            if a[i] > a[j] { invs += 1; }
        }
    }

    if invs % 2 == 0 { return String::from("YES"); }
    return String::from("NO")
}

fn main() {
    let stdin = io::stdin();
    let mut stdin_iterator = stdin.lock().lines();

    let mut fptr = File::create(env::var("OUTPUT_PATH").unwrap()).unwrap();

    let t = stdin_iterator.next().unwrap().unwrap().trim().parse::<i32>().unwrap();

    for _ in 0..t {
        let _ = stdin_iterator.next().unwrap().unwrap().trim().parse::<i32>().unwrap();

        let a: Vec<i32> = stdin_iterator.next().unwrap().unwrap()
            .trim_end()
            .split(' ')
            .map(|s| s.to_string().parse::<i32>().unwrap())
            .collect();

        let result = larrysArray(&a);

        writeln!(&mut fptr, "{}", result).ok();
    }
}
