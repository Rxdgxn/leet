use std::collections::HashMap;

impl Solution {
    pub fn find_champion(n: i32, edges: Vec<Vec<i32>>) -> i32 {
        let mut degrees_in: HashMap<i32, i32> = HashMap::new();

        for edge in edges {
            *degrees_in.entry(edge[1]).or_insert(1) += 1;
        }

        let mut champ = -1;

        for i in 0 .. n {
            if !degrees_in.contains_key(&i) {
                if champ != -1 { return -1; }

                champ = i;
            }
        }

        return champ;
    }
}