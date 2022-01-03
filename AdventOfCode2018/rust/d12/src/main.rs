use std::collections::HashSet;
use itertools::Itertools;
use std::collections::hash_map::DefaultHasher;
use std::hash::{Hash, Hasher};

fn parse_inp(lines: &Vec<&str>) -> (HashSet<i32>, Vec<[bool; 5]>) {
    let pts: HashSet<i32> = lines[0].split(' ').nth(2).unwrap()
        .chars().enumerate().filter(|(_, x)| *x == '#').map(|(i, _)| i as i32).collect();

    let lns: Vec<[bool; 5]> = (&lines[2..]).iter().map(|l| -> ([bool; 5], bool) {
            let (a, b) = l.split(" => ").collect_tuple().unwrap();
            let (v, w, x, y, z) = a.chars().map(|x| x == '#').collect_tuple().unwrap();
            return ([v, w, x, y, z], b == "#");
        })
        .filter(|(_, res)| *res)
        .map(|(pat, _)| pat)
        .collect();

    return (pts, lns);
}

fn next_hs(hs: HashSet<i32>, rules: &Vec<[bool; 5]>) -> HashSet<i32> {
    let mut nhs: HashSet<i32> = HashSet::new();
    let mn = hs.iter().min().unwrap();
    let mx = hs.iter().max().unwrap();
    for x in (mn - 5)..=(mx + 5) {
        for pat in rules {
            if pat.iter().enumerate().all(|(i, b)| *b == hs.contains(&(x + (i as i32) - 2))) {
                nhs.insert(x);
                break;
            }
        }
    }
    return nhs;
}

fn p1(init: &HashSet<i32>, rules: &Vec<[bool; 5]>) {
    let hs = (0..20).fold(init.clone(), |hs, _| next_hs(hs, rules));
    println!("Part 1: {}", hs.iter().sum::<i32>());
}

fn p2(init: &HashSet<i32>, rules: &Vec<[bool; 5]>) {
    let mut trt = init.clone(); 
    let mut p = trt.iter().sum::<i32>();
    let mut ds = [0; 3];
    let mut t = 0;
    loop {
        t += 1;
        trt = next_hs(trt, rules);
        let s = trt.iter().sum::<i32>();
        let d = s - p;
        p = s;
        ds[0] = ds[1];
        ds[1] = ds[2];
        ds[2] = d;
        if ds.iter().all(|x| *x == ds[0]) {
            break;
        }
    }
    let d = ds[0];

    let sm: i64 = (p as i64) + (50000000000 - (t as i64)) * (d as i64);
    println!("Part 2: {}", sm);
}

fn main() {
    let inp: Vec<&str> = include_str!("../input.txt").lines().collect();
    let (init, rules) = parse_inp(&inp);
    p1(&init, &rules);
    p2(&init, &rules);
}
