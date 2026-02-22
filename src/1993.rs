use std::collections::{HashMap, VecDeque};

struct LockingTree {
    descendants: HashMap<i32, Vec<i32>>,
    ancestor: HashMap<i32, i32>,
    locked_by: HashMap<i32, i32>
}

impl LockingTree {
    fn new(parent: Vec<i32>) -> Self {
        let mut descendants: HashMap<i32, Vec<i32>> = HashMap::new();
        let mut ancestor: HashMap<i32, i32> = HashMap::new();

        for i in 1 .. parent.len() {
            descendants.entry(parent[i]).or_insert(Vec::new()).push(i as i32);
            ancestor.insert(i as i32, parent[i]);
        }

        Self { descendants, ancestor, locked_by: HashMap::new() }
    }
    
    fn lock(&mut self, num: i32, user: i32) -> bool {
        if self.locked_by.contains_key(&num) {
            return false;
        }

        self.locked_by.insert(num, user);

        true
    }
    
    fn unlock(&mut self, num: i32, user: i32) -> bool {
        if !self.locked_by.contains_key(&num) {
            return false;
        }

        if self.locked_by[&num] == user {
            self.locked_by.remove(&num);
            return true;
        }

        false
    }
    
    fn upgrade(&mut self, num: i32, user: i32) -> bool {
        if self.locked_by.contains_key(&num) {
            return false;
        }

        if !self.descendants.contains_key(&num) {
            return false;
        }

        let mut locked_desc = false;

        let mut q: VecDeque<i32> = VecDeque::new();
        q.push_back(num);

        while !q.is_empty() {
            let n = q.pop_front().unwrap();

            if self.locked_by.contains_key(&n) && n != num {
                locked_desc = true;
                break;
            }

            if let Some(dscs) = self.descendants.get(&n) {
                for child in dscs {
                    q.push_back(*child);
                }
            }
        }

        if !locked_desc {
            return false;
        }

        let mut it = num;

        while let Some(a) = self.ancestor.get(&it) {
            if self.locked_by.contains_key(a) {
                return false;
            }

            it = *a;
        }

        q.clear();
        q.push_back(num);

        while !q.is_empty() {
            let n = q.pop_front().unwrap();

            self.locked_by.remove(&n);

            if let Some(dscs) = self.descendants.get(&n) {
                for child in dscs {
                    q.push_back(*child);
                }
            }
        }

        self.locked_by.insert(num, user);

        true
    }
}