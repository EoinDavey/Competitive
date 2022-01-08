use std::collections::{HashMap, VecDeque};
use itertools::Itertools;
use std::fmt::Debug;

type Pt = (i32, i32);

#[derive(Clone, Debug, PartialEq, Eq)]
struct Unit {
    symb: char,
    id: i32,
    hp: i32,
}

#[derive(Clone, PartialEq, Eq)]
enum Elem {
    U(Unit),
    Free,
    Wall,
}
use self::Elem::{U, Free, Wall};

impl Elem {
    fn get_unit(self) -> Unit {
        match self {
            U(u) => u,
            _ => panic!("How did we get here?"),
        }
    }
}

type Board = HashMap<Pt, Elem>;

fn elf_count(b: &Board) -> usize {
    return b.values()
        .filter_map(|v| match v {
            U(u) => if u.symb == 'E' { Some(u) } else { None },
            _ => None
        })
        .count();
}

const POWER: i32 = 3;

fn parse_inp(s: &str) -> Board {
    let mut b = HashMap::new();
    let mut id = 0;
    for (x, l) in s.lines().enumerate() {
        for (y, c) in l.chars().enumerate() {
            b.insert((x as i32, y as i32),
                if c == '#' {
                    Wall
                } else if c == '.' {
                    Free
                } else {
                    U(Unit{id: id, symb: c, hp: 200})
                });
            id += 1;
        }
    }

    return b;
}

fn ns((x, y): Pt) -> Vec<Pt> {
    return [(0, 1), (1, 0), (-1, 0), (0, -1)]
        .iter().map(|(dx, dy)| (x + dx, y + dy)).collect();
}

fn move_pt(pt: Pt, b: &mut Board, tgt_pts: &Vec<Pt>) -> Option<Pt> {
    let mut q: VecDeque<Pt> = VecDeque::new();
    let mut dists: HashMap<Pt, i32> = HashMap::new();
    q.push_back(pt);
    dists.insert(pt, 0);

    while let Some(hd) = q.pop_front() {
        let d = dists[&hd];
        for n in ns(hd) {
            if *b.get(&n).unwrap_or(&Wall) != Free {
                continue;
            }
            if dists.contains_key(&n) {
                continue;
            }
            dists.insert(n, d + 1);
            q.push_back(n);
        }
    }

    let tgt_dists: Vec<(Option<i32>, Pt)> = tgt_pts.iter()
        .map(|pt| (dists.get(pt).map(|d| *d), *pt))
        .collect();

    if tgt_dists.iter().all(|(d, _)| d.is_none()) {
        return None;
    }

    let (mn_dist, closest): (i32, Pt) = tgt_dists.into_iter()
        .filter_map(|(d, pt)| d.map(|x| (x, pt)))
        .min()
        .unwrap();

    let mut frontier: Vec<Pt> = vec![closest];
    let mut d = mn_dist;

    loop {
        d -= 1;
        if d == 0 {
            break;
        }
        let nf = frontier.into_iter()
            .flat_map(|f| ns(f))
            .sorted()
            .dedup()
            .filter(|pt| dists.get(&pt).map_or(false, |dst| *dst == d))
            .collect();
        frontier = nf;
    }

    let step = frontier.into_iter().min().unwrap();

    let unit = b.remove(&pt).unwrap();
    b.insert(step, unit);
    b.insert(pt, Free);

    return Some(step);
}

fn tick(b: &mut Board, elf_attack: i32) -> bool {
    let units: Vec<(Pt, i32)> = b.iter()
        .filter_map(|(k, v)| {
            match v {
                U(u) => Some((*k, u.id)),
                _ => None,
            }
        })
        .sorted()
        .collect();

    for (pt, id) in units {
        match &b[&pt] {
            Wall => continue,
            Free => continue,
            U(unit) => {
                if unit.hp == 0 || unit.id != id {
                    // This unit has died in this round or has died and was replaced.
                    continue;
                }
                let power = if unit.symb == 'E' { elf_attack } else { POWER };
                let ut_ns = ns(pt);
                let tgts: Vec<Pt> = b.iter()
                    .filter_map(|(k, v)| {
                        match v {
                            U(u) => if u.symb != unit.symb { Some(*k) } else { None },
                            _ => None,
                        }
                    })
                    .sorted()
                    .collect();

                if tgts.len() == 0 {
                    return false
                }

                let tgt_in_range: Vec<Pt> = tgts.iter()
                    .flat_map(|tgt| ns(*tgt))
                    .filter(|pt| *b.get(pt).unwrap_or(&Wall) == Free)
                    .collect();

                let in_range_of_pt: Vec<Pt> = tgts.iter()
                    .filter(|pt| ut_ns.contains(pt)).map(|pt| *pt)
                    .sorted()
                    .collect();

                if tgt_in_range.len() == 0 && in_range_of_pt.len() == 0 {
                    continue;
                }

                let mut npos = pt;
                if in_range_of_pt.len() == 0 {
                    match move_pt(pt, b, &tgt_in_range) {
                        Some(new_pt) => {
                            npos = new_pt;
                        },
                        None => continue,
                    }
                }

                let closest = ns(npos).into_iter()
                    .filter(|pos| tgts.contains(pos))
                    .filter_map(|x| {
                        match b.get(&x).unwrap_or(&Wall) {
                            U(unit) => Some((unit.hp, x)),
                            _ => None,
                        }
                    })
                    .min()
                    .map(|(_, pos)| pos);

                if closest.is_none() {
                    continue;
                }

                let closest: Pt = closest.unwrap();
                let mut defender = b.remove(&closest).unwrap().get_unit();
                
                defender.hp -= power;

                if defender.hp <= 0 {
                    b.insert(closest, Free);
                } else {
                    b.insert(closest, U(defender));
                }
            },
        }
    }
    return true;
}

fn score(mut b: Board, elf_attack: i32) -> i32 {
    let mut rounds = 0;
    loop {
        if !tick(&mut b, elf_attack) {
            break;
        }
        rounds += 1;
    }

    let hp = b
        .values().filter_map(|v| match v {
            U(u) => Some(u.hp),
            _ => None,
        })
        .sum::<i32>();
    return rounds * hp;
}

fn p1(b: Board) {
    println!("Part 1: {}", score(b, 3));
}

fn p2(base: Board) {
    let start_count = elf_count(&base);
    let (mut l, mut r) = (4, 100);

    while l < r {
        let m = (l + r + 1) / 2;
        let mut b = base.clone();
        loop {
            if !tick(&mut b, m) {
                break;
            }
        }

        let elves = elf_count(&b);
        if elves == start_count {
            r = m
        } else {
            l = m + 1
        }
    }
    println!("Part 2: {}", score(base, l));
}

fn main() {
    let inp = include_str!("../input.txt");
    let b = parse_inp(&inp);

    p1(b.clone());
    p2(b.clone());
}
