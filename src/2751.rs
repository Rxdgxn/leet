struct Robot {
    x: i32,
    health: i32,
    dir: i32,
    original_idx: usize
}

impl Solution {
    pub fn survived_robots_healths(positions: Vec<i32>, healths: Vec<i32>, directions: String) -> Vec<i32> {
        let mut ret: Vec<Robot> = Vec::new();
        let mut robots: Vec<Robot> = Vec::new();
        let dirs: Vec<i32> = directions.chars().map(|ch| if ch == 'L' { -1 } else { 1 }).collect();

        let n = positions.len();

        for i in 0 .. n {
            robots.push(Robot {
                x: positions[i],
                health: healths[i],
                dir: dirs[i],
                original_idx: i
            });
        }

        robots.sort_by_key(|r| r.x);

        let mut stack: Vec<Robot> = Vec::new();

        for mut curr_robot in robots {
            if curr_robot.dir < 0 {
                while !stack.is_empty() && curr_robot.health > stack.last().unwrap().health {
                    stack.pop();
                    curr_robot.health -= 1;
                }

                if stack.is_empty() {
                    ret.push(curr_robot);
                    continue;
                }

                let mut last = stack.pop().unwrap();

                if last.health == curr_robot.health {
                    continue;
                }

                last.health -= 1;

                stack.push(last);
            }
            else {
                stack.push(curr_robot);
            }
        }

        for remaining in stack {
            ret.push(remaining);
        }

        ret.sort_by_key(|r| r.original_idx);
        ret.iter().map(|r| r.health).collect()
    }
}