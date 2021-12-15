use std::io;
use std::io::Read;
use std::convert::From;
use std::collections::hash_map::{HashMap};

fn read_inp() -> (String, HashMap<String, String>) {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut lines: Vec<String> = input.lines().map(|x| String::from(x)).collect();
    let head = lines.remove(0);
    lines.remove(0);
    let mp: HashMap<String, String> = lines.iter()
        .map(|x| x.split_once(" -> ").unwrap())
        .map(|(a,b)| (String::from(a), String::from(b)))
        .collect();
    (head, mp)
}

fn union(a: HashMap<String, i64>, b: HashMap<String, i64>) -> HashMap<String, i64> {
    let mut new: HashMap<String, i64> = HashMap::new();
    for (k, v) in a.into_iter().chain(b.into_iter()) {
        let nv: i64 = match new.get(&k) {
            Some(old) => old + v,
            None => v,
        };
        new.insert(k, nv);
    }
    new
}

fn base_map(l: &str, r: &str) -> HashMap<String, i64> {
    if l == r {
        return HashMap::from([(l.to_owned(),2)]);
    }
    HashMap::from([(l.to_owned(),1), (r.to_owned(),1)])
}

type Memo = HashMap<(String, String, i32), HashMap<String, i64>>;
fn solve_pair(memo: &mut Memo, prs: &HashMap<String, String>, l: &str, r: &str, d: i32) -> HashMap<String, i64> {
    let mk = (l.to_owned(), r.to_owned(), d);
    let mv = memo.get(&mk);
    if mv.is_some() {
        return mv.unwrap().clone();
    }
    let k: String = format!("{}{}", l, r);
    if !prs.contains_key(&k) || d == 0 {
        let b = base_map(l, r);
        return b;
    }
    let m_opt = prs.get(&k);
    if m_opt.is_none() {
        return base_map(l,r);
    }
    let m: &str = m_opt.unwrap();
    let mut u = union(solve_pair(memo, prs, l, m, d - 1), solve_pair(memo, prs, m, r, d - 1));
    u.insert(m.to_owned(), u.get(m).unwrap() - 1);
    memo.insert(mk, u.clone());
    return u;
}


fn solve_t(memo: &mut Memo, t: &str, prs: &HashMap<String, String>, d: i32) -> i64 {
    let mut u: HashMap<String, i64> = HashMap::new();
    for (i, (a, b)) in t.chars().zip(t.chars().skip(1)).enumerate() {
        let l = solve_pair(memo, prs, &a.to_string(), &b.to_string(), d);
        u = union(u, l);
        if i > 0 {
            u.insert(a.to_string(), u.get(&a.to_string()).unwrap() - 1);
        }
    }
    let mx: i64 = *u.values().max().unwrap();
    let mn: i64 = *u.values().min().unwrap();
    mx-mn
}

fn main() {
    let (strt, prs) = read_inp();
    let mut memo: Memo = HashMap::new();
    let a = solve_t(&mut memo, &strt, &prs, 10);
    let b = solve_t(&mut memo, &strt, &prs, 40);
    println!("Part 1: {}\nPart 2: {}", a, b);
}
