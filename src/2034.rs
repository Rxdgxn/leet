use std::collections::{HashMap, BinaryHeap};
use std::cmp::Reverse;

struct StockPrice {
  min: BinaryHeap<Reverse<i32>>,
  max: BinaryHeap<i32>,
  map: HashMap<i32, i32>, // timestamp, price
  pq: BinaryHeap<i32>, // timestamps
  count: HashMap<i32, i32> // price, count
}

impl StockPrice {

    fn new() -> Self {
        Self {
          min: BinaryHeap::new(),
          max: BinaryHeap::new(),
          map: HashMap::new(),
          pq: BinaryHeap::new(),
          count: HashMap::new()
        }
    }
    
    fn update(&mut self, timestamp: i32, price: i32) {
        let old= self.map.get(&timestamp);

        if let Some(val) = old {
          self.count.insert(*val, self.count[val] - 1);
        }

        self.max.push(price);
        self.min.push(Reverse(price));

        self.map.insert(timestamp, price);
        self.count.insert(price, match self.count.get(&price) {
          None => 0,
          Some(x) => *x
        } + 1);

        self.pq.push(timestamp);
    }
    
    fn current(&self) -> i32 {
        self.map[self.pq.peek().unwrap()]
    }
    
    fn maximum(&mut self) -> i32 {
        while self.count[self.max.peek().unwrap()] == 0 {
          self.max.pop();
        }

        *self.max.peek().unwrap()
    }

    fn rev_to_i32(&self) -> i32 {
      match *self.min.peek().unwrap() {
        Reverse(x) => x
      }
    }
    
    fn minimum(&mut self) -> i32 {
        while self.count[&self.rev_to_i32()] == 0 {
          self.min.pop();
        }

        self.rev_to_i32()
    }
}