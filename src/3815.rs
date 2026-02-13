use std::collections::{BTreeMap, BTreeSet, HashMap};

struct Item {
    value_to_bidder: BTreeMap<i32, BTreeSet<i32>>,
    bidder_to_value: HashMap<i32, i32>
}

impl Item {
    fn new() -> Self {
        Self { value_to_bidder: BTreeMap::new(), bidder_to_value: HashMap::new() }
    }
}

struct AuctionSystem {
    items: HashMap<i32, Item>
}

impl AuctionSystem {
    fn new() -> Self {
        Self { items: HashMap::new() }
    }
    
    fn add_bid(&mut self, user_id: i32, item_id: i32, bid_amount: i32) {
        match self.items.get_mut(&item_id) {
            None => {
                let mut new_item = Item::new();
                new_item.bidder_to_value.insert(user_id, bid_amount);
                new_item.value_to_bidder.insert(bid_amount, BTreeSet::from([user_id]));

                self.items.insert(item_id, new_item);
            }
            Some(item) => {
                if item.bidder_to_value.contains_key(&user_id) {
                    self.update_bid(user_id, item_id, bid_amount);
                }
                else {
                    item.bidder_to_value.insert(user_id, bid_amount);
                    
                    let user_set = item.value_to_bidder.entry(bid_amount).or_insert(BTreeSet::new());
                    user_set.insert(user_id);
                }
            }
        }
    }
    
    fn update_bid(&mut self, user_id: i32, item_id: i32, new_amount: i32) {
        let item = self.items.get_mut(&item_id).unwrap();

        let user_set = item.value_to_bidder.get_mut(&item.bidder_to_value[&user_id]).unwrap();
        user_set.remove(&user_id);

        if user_set.is_empty() {
            item.value_to_bidder.remove(&item.bidder_to_value[&user_id]);
        }

        item.bidder_to_value.insert(user_id, new_amount);
        
        let user_set = item.value_to_bidder.entry(new_amount).or_insert(BTreeSet::new());
        user_set.insert(user_id);
    }
    
    fn remove_bid(&mut self, user_id: i32, item_id: i32) {
        let item = self.items.get_mut(&item_id).unwrap();

        let user_set = item.value_to_bidder.get_mut(&item.bidder_to_value[&user_id]).unwrap();
        user_set.remove(&user_id);

        if user_set.is_empty() {
            item.value_to_bidder.remove(&item.bidder_to_value[&user_id]);
        }

        item.bidder_to_value.remove(&user_id);
    }
    
    fn get_highest_bidder(&self, item_id: i32) -> i32 {
        match self.items.get(&item_id) {
            None => return -1,
            Some(item) => {
                if item.value_to_bidder.is_empty() {
                    return -1;
                }

                *item.value_to_bidder.values().rev().next().unwrap().iter().rev().next().unwrap()
            }
        }
    }
}