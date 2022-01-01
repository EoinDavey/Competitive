use std::collections::HashMap;

fn count(wrd: &str) -> HashMap<char, i32> {
    let mut cnt: HashMap<char, i32> = HashMap::new();
    for c in wrd.chars() {
        let l = cnt.entry(c).or_default();
        *l += 1;
    }
    return cnt;
}

fn common(a: &str, b: &str) -> String {
    return a.chars().zip(b.chars()).filter(|(a, b)| a == b).map(|(a, _)| a).collect();
}

fn p2(lns: &Vec<&str>) {
    for a in lns {
        for b in lns {
            if a == b {
                continue
            }
            let mut d = 0;
            for (a, b) in a.chars().zip(b.chars()) {
                if a != b {
                    d += 1;
                }
            }
            if d == 1 {
                println!("Part 2: {}", common(a, b));
                return;
            }
        }
    }
}

fn p1(cnts: &Vec<HashMap<char, i32>>) {
    let mut twos = 0;
    let mut threes = 0;
    for ln in cnts {
        if ln.values().find(|v| **v == 2).is_some() {
            twos += 1;
        }
        if ln.values().find(|v| **v == 3).is_some() {
            threes += 1;
        }
    }
    println!("Part 1: {}", twos * threes);
}

fn main() {
    let inp: Vec<&str> = include_str!("../input.txt").lines().collect();
    let cnts: Vec<HashMap<char, i32>> = inp.iter().map(|x| count(x)).collect();
    p1(&cnts);
    p2(&inp);
}
