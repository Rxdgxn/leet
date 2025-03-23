use std::{env, i32};
use std::fs::File;
use std::io::{self, BufRead, Write};

/*
 * Complete the 'hackerlandRadioTransmitters' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY x
 *  2. INTEGER k
 */

fn hackerlandRadioTransmitters(x: &[i32], k: i32) -> i32 {
    let mut transmitters = 0;

    let mut sorted = Vec::from(x);
    sorted.sort();

    let mut i = 1usize;
    let mut prev = sorted[0];
    let mut last_ok = sorted[0];

    sorted.push(i32::MAX);

    while i < sorted.len() {
        if sorted[i] - prev <= k {
            last_ok = sorted[i];
            i += 1;
        }
        else {
            transmitters += 1;
            prev = last_ok;

            while sorted[i] - prev <= k {
                i += 1;
            }

            prev = sorted[i];
        }
    }

    transmitters
}

fn main() {
    let stdin = io::stdin();
    let mut stdin_iterator = stdin.lock().lines();

    let mut fptr = File::create(env::var("OUTPUT_PATH").unwrap()).unwrap();

    let first_multiple_input: Vec<String> = stdin_iterator.next().unwrap().unwrap()
        .split(' ')
        .map(|s| s.to_string())
        .collect();

    let n = first_multiple_input[0].trim().parse::<i32>().unwrap();

    let k = first_multiple_input[1].trim().parse::<i32>().unwrap();

    let x: Vec<i32> = stdin_iterator.next().unwrap().unwrap()
        .trim_end()
        .split(' ')
        .map(|s| s.to_string().parse::<i32>().unwrap())
        .collect();

    let result = hackerlandRadioTransmitters(&x, k);

    writeln!(&mut fptr, "{}", result).ok();
}
