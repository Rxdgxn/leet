use std::env;
use std::fs::File;
use std::io::{self, BufRead, Write};

/*
 * Complete the 'weightedUniformStrings' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER_ARRAY queries
 */

fn weightedUniformStrings(s: &str, queries: &[i32]) -> Vec<String> {
    let mut ret: Vec<String> = Vec::new();

    use std::collections::HashMap;
    let mut ws: Vec<(i32, i32)> = Vec::new();
    let mut apps = 1;

    let mut last = s.chars().nth(0).unwrap();

    for i in 1 .. s.len() {
        let curr = s.chars().nth(i).unwrap();
        
        if curr == last {
            apps += 1;
        }
        else {
            ws.push((i32::from(last as u8 - 96), apps));
            apps = 1;
        }

        last = curr;
    }
    ws.push((i32::from(last as u8 - 96), apps));

    for q in queries {
        let mut ok = false;
        
        
        for (w, a) in &ws {
            if q / w <= *a && q % w == 0 {
                ok = true;
                break;
            }
        }

        if ok { ret.push(String::from("Yes")); }
        else { ret.push(String::from("No")); }
    }

    ret
}

fn main() {
    let stdin = io::stdin();
    let mut stdin_iterator = stdin.lock().lines();

    let mut fptr = File::create(env::var("OUTPUT_PATH").unwrap()).unwrap();

    let s = stdin_iterator.next().unwrap().unwrap();

    let queries_count = stdin_iterator.next().unwrap().unwrap().trim().parse::<i32>().unwrap();

    let mut queries: Vec<i32> = Vec::with_capacity(queries_count as usize);

    for _ in 0..queries_count {
        let queries_item = stdin_iterator.next().unwrap().unwrap().trim().parse::<i32>().unwrap();
        queries.push(queries_item);
    }

    let result = weightedUniformStrings(&s, &queries);

    for i in 0..result.len() {
        write!(&mut fptr, "{}", result[i]).ok();

        if i != result.len() - 1 {
            writeln!(&mut fptr).ok();
        }
    }

    writeln!(&mut fptr).ok();
}
