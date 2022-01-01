#![allow(dead_code)]
#![allow(unused_variables)]
#![allow(unused_imports)]

use std::ops::RangeInclusive;
use std::collections::LinkedList;
use std::collections::HashMap;
use std::collections::HashSet;

fn ns(pt: (i32, i32)) -> Vec<(i32, i32)> {
    return [(0, 1), (1, 0), (-1, 0), (0, -1)].iter()
        .map(|(dx, dy)| (pt.0 + dx, pt.1 + dy))
        .collect();
}

fn closest((x, y): (i32, i32), coords: &Vec<(i32, i32)>) -> Option<usize> {
    let mut mn = 1000 * 1000;
    let mut res = 0;
    let mut tie = false;
    for (i, (cx, cy)) in coords.iter().enumerate() {
        let d = (x - cx).abs() + (y - cy).abs();
        if d > mn {
            continue;
        }
        if d == mn {
            tie = true;
            continue;
        }

        mn = d;
        res = i;
        tie = false;
    }
    if tie {
        return None;
    }
    return Some(res);
}

fn dist_to_all((x, y): (i32, i32), coords: &Vec<(i32, i32)>) -> i32 {
    return coords.iter().map(|(cx, cy)| (x - *cx).abs() + (y - *cy).abs()).sum();
}

fn p1(coords: &Vec<(i32, i32)>, xrng: &RangeInclusive<i32>, yrng: &RangeInclusive<i32>) {
    let mut area: HashMap<usize, i32> = HashMap::new();
    let mut infs: HashSet<usize> = HashSet::new();

    for x in xrng.clone() {
        for y in yrng.clone() {
            if let Some(pt) = closest((x, y), coords) {
                *area.entry(pt).or_default() += 1;

                if x == *xrng.start() || x == *xrng.end() || y == *yrng.start() || y == *yrng.end() {
                    infs.insert(pt);
                }
            }
        }
    }

    let ans = area.iter().filter(|(k, v)| !infs.contains(k)).map(|(k, v)| v).max().unwrap();
    println!("Part 1: {}", ans);
}

fn p2(coords: &Vec<(i32, i32)>, xrng: &RangeInclusive<i32>, yrng: &RangeInclusive<i32>) {
    let st = coords[0];

    let mut q: LinkedList<(i32, i32)> = LinkedList::from([st]);
    let mut vis: HashSet<(i32, i32)> = HashSet::new();
    vis.insert(st);

    let mut cnt = 1;

    while q.len() > 0 {
        let hd = q.pop_front().unwrap();
        for n in ns(hd) {
            if vis.contains(&n) {
                continue;
            }
            vis.insert(n);
            let d = dist_to_all(n, coords);
            if d >= 10000 {
                continue;
            }
            cnt += 1;
            q.push_back(n);
        }
    }
    println!("Part 2: {}", cnt);
}

fn main() {
    let inp: Vec<(i32, i32)> = include_str!("../input.txt")
        .lines()
        .map(|x| x.split(", ").map(|x| x.parse::<i32>().unwrap()))
        .map(|mut x| (x.next().unwrap(), x.next().unwrap()))
        .collect();

    let mnx = inp.iter().map(|(x, _)| x).min().unwrap();
    let mxx = inp.iter().map(|(x, _)| x).max().unwrap();
    let mny = inp.iter().map(|(_, y)| y).min().unwrap();
    let mxy = inp.iter().map(|(_, y)| y).max().unwrap();

    let xrng = *mnx..=*mxx;
    let yrng = *mny..=*mxy;

    p1(&inp, &xrng, &yrng);
    p2(&inp, &xrng, &yrng);
}
