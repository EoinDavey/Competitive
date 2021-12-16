use std::io;
use std::io::Read;
use std::convert::From;
use std::collections::hash_map::{HashMap};

type PairsMap = HashMap<(char, char), char>;
fn read_inp() -> (String, PairsMap) {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut lines = input.lines();
    let head = lines.next().unwrap().to_string();
    let mp: HashMap<(char,char), char> = lines.skip(1)
        .map(|x| x.split_once(" -> ").unwrap())
        .map(|(a, b)| {
            let va: Vec<char> = a.chars().collect();
            return ((va[0],va[1]), b.chars().next().unwrap());
        })
        .collect();
    return (head, mp);
}

type CharCount = HashMap<char, i64>;
fn union(a: CharCount, b: CharCount) -> CharCount {
    let mut new: CharCount = HashMap::new();
    for (k, v) in a.into_iter().chain(b.into_iter()) {
        *new.entry(k).or_default() += v
    }
    return new;
}

fn base_map(l: char, r: char) -> CharCount {
    return if l == r {
        HashMap::from([(l,2)])
    } else {
        HashMap::from([(l,1), (r,1)])
    }
}

type Memo = HashMap<(char, char, i32), CharCount>;
fn solve_pair(memo: &mut Memo, prs: &PairsMap, l: char, r: char, d: i32) -> CharCount {
    let mk = (l, r, d);
    let mv = memo.get(&mk);
    if let Some(x) = mv {
        return x.clone();
    }
    let k: (char,char) = (l, r);
    if !prs.contains_key(&k) || d == 0 {
        return base_map(l, r);
    }
    if let Some(m) = prs.get(&k) {
        let mut u = union(solve_pair(memo, prs, l, *m, d - 1), solve_pair(memo, prs, *m, r, d - 1));
        u.insert(*m, u[m] - 1);
        memo.insert(mk, u.clone());
        return u;
    }
    return base_map(l,r);
}

fn solve_t(memo: &mut Memo, t: &str, prs: &PairsMap, d: i32) -> i64 {
    let mut u: CharCount = HashMap::new();
    for (i, (a, b)) in t.chars().zip(t.chars().skip(1)).enumerate() {
        let l = solve_pair(memo, prs, a, b, d);
        u = union(u, l);
        if i > 0 {
            u.insert(a, u[&a] - 1);
        }
    }
    let mx: i64 = *u.values().max().unwrap();
    let mn: i64 = *u.values().min().unwrap();
    return mx-mn;
}

fn main() {
    let (strt, prs) = read_inp();
    let mut memo: Memo = HashMap::new();
    let a = solve_t(&mut memo, &strt, &prs, 10);
    let b = solve_t(&mut memo, &strt, &prs, 40);
    println!("Part 1: {}\nPart 2: {}", a, b);
}
