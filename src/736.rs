use core::panic;
use std::{collections::{HashMap, HashSet}, iter::Peekable, str::Chars};

#[derive(PartialEq)]
enum ExprType {
    Let,
    Add,
    Mult,
}

type VariableRegistry = HashMap<String, Vec<(i32, usize)>>; // variable has (value, scope_depth)

impl Solution {
    fn get_value(input: &String, variables: &VariableRegistry) -> i32 {
        if let Ok(n) = input.parse::<i32>() {
            n
        }
        else {
            variables.get(&input[..]).unwrap().last().unwrap().0
        }
    }

    fn add_variable(varname: String, val: i32, variables: &mut VariableRegistry, scope_depth: usize) {
        let values = variables.entry(varname).or_insert(Vec::new());

        if values.is_empty() || values.last().unwrap().1 != scope_depth {
            values.push((val, scope_depth));
        }
        else {
            values.last_mut().unwrap().0 = val;
        }
    }

    fn helper(chars: &mut Peekable<Chars<'_>> , variables: &mut VariableRegistry, operations: &mut Vec<ExprType>, values: &mut Vec<i32>, scope_depth: usize) -> i32 {
        let mut curr_word = String::new();

        assert!(chars.next().unwrap() == '(');

        // First get the type of operation
        let mut op = ExprType::Let; // default

        while let Some(ch) = chars.next() {
            if ch == ' ' {
                op = match &curr_word[..] {
                    "let" => ExprType::Let,
                    "add" => ExprType::Add,
                    "mult" => ExprType::Mult,
                    _ => panic!("Invalid expression type: `{}`", curr_word)
                };

                curr_word.clear();
                break;
            }

            curr_word.push(ch);
        }

        let mut used_variables: HashSet<String> = HashSet::new();

        // Then match on it
        if op != ExprType::Let {
            // Get first operand
            if *chars.peek().unwrap() == '(' {
                let val = Self::helper(chars, variables, operations, values, scope_depth + 1);
                values.push(val);
            }
            else {
                while *chars.peek().unwrap() != ' ' {
                    curr_word.push(chars.next().unwrap());
                }
                values.push(Self::get_value(&curr_word, variables));
                curr_word.clear();
            }

            assert!(chars.next().unwrap() == ' ');

            // Get second operand
            if *chars.peek().unwrap() == '(' {
                let val = Self::helper(chars, variables, operations, values, scope_depth + 1);
                values.push(val);
            }
            else {
                while *chars.peek().unwrap() != ')' {
                    curr_word.push(chars.next().unwrap());
                }
                values.push(Self::get_value(&curr_word, variables));
            }

            assert!(chars.next().unwrap() == ')');

            let b = values.pop().unwrap();
            let a = values.pop().unwrap();

            return match op {
                ExprType::Add => a + b,
                ExprType::Mult => a * b,
                _ => unreachable!()
            };
        }

        // First sequentially bind variables, then check for 2 scenarios:
        // 1, expr is another complex expression, with '()', or just a variable/number

        let mut is_name = true;
        let mut varname = String::new();

        while *chars.peek().unwrap() != ')' {
            let ch = *chars.peek().unwrap();

            if ch == ' ' {
                if !is_name {
                    // The value could be a complex expression, which means that curr_word is empty
                    if !curr_word.is_empty() { 
                        let val = Self::get_value(&curr_word, variables);
                        Self::add_variable(varname, val, variables, scope_depth);
                        varname = String::new(); // to shup up the borrow checker
                    }
                    else {
                        Self::add_variable(varname, values.pop().unwrap(), variables, scope_depth);
                        varname = String::new();
                    }
                }
                else {
                    varname = curr_word.clone();
                    used_variables.insert(curr_word);
                }

                is_name = !is_name;
                curr_word = String::new();

                chars.next();
            }
            else if ch == '(' {
                let val = Self::helper(chars, variables, operations, values, scope_depth + 1);
                values.push(val);
            }
            else {
                curr_word.push(ch);
                chars.next();
            }
        }

        assert!(chars.next().unwrap() == ')' && is_name);

        if !curr_word.is_empty() {
            values.push(Self::get_value(&curr_word, variables));
        }

        // Pop all variables out of their scope
        for var in used_variables {
            variables.get_mut(&var).unwrap().pop();
        }

        values.pop().unwrap()
    }

    pub fn evaluate(expression: String) -> i32 {
        let mut variables: VariableRegistry = HashMap::new();
        let mut chars = expression.chars().peekable();
        let mut operations: Vec<ExprType> = Vec::new();
        let mut values: Vec<i32> = Vec::new();
        
        Self::helper(&mut chars, &mut variables, &mut operations, &mut values, 0)
    }
}