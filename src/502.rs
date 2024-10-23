use std::collections::BinaryHeap;

impl Solution {
    pub fn find_maximized_capital(k: i32, w: i32, profits: Vec<i32>, capital: Vec<i32>) -> i32 {
      let mut projects: Vec<(i32, i32)> = Vec::new();
      let mut total_capital = w;
      
      let n = profits.len();

      for i in 0 .. n {
        projects.push((capital[i], profits[i]));
      }

      projects.sort();

      let mut i = 0usize;
      
      let mut heap: BinaryHeap<i32> = BinaryHeap::new();

      for _ in 0 .. k {
        while i < n && projects[i].0 <= total_capital {
          heap.push(projects[i].1);
          i += 1;
        }

        if heap.is_empty() {
          break;
        }

        total_capital += heap.peek().unwrap();
        heap.pop();
      }

      return total_capital;
    }
}