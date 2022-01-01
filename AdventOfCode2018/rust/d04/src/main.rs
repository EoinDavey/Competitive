#![allow(dead_code)]
#![allow(unused_variables)]
use std::collections::HashMap;
use std::ops::Range;
use regex::Regex;

fn parse_inp(inp: &Vec<&str>) -> HashMap<i32, Vec<Range<i32>>> {
    let shift_start = Regex::new(r"Guard #([0-9]+) begins shift").unwrap();
    let sleeps = Regex::new(r"\[.*:([0-9]+)\] falls asleep").unwrap();
    let wakes = Regex::new(r"\[.*:([0-9]+)\] wakes up").unwrap();

    let mut slp_map: HashMap<i32, Vec<Range<i32>>> = HashMap::new();

    let mut guard: i32 = -1;
    let mut sleep_time: i32 = -1;
    for ln in inp {
        if let Some(caps) = shift_start.captures(ln) {
            let id: i32 = caps.get(1).unwrap().as_str().parse().unwrap();
            guard = id;
        }
        if let Some(caps) = wakes.captures(ln) {
            let minute: i32 = caps.get(1).unwrap().as_str().parse().unwrap();
            let rng = sleep_time..minute;
            let ent = slp_map.entry(guard).or_insert_with(|| Vec::new());
            ent.push(rng);
        }
        if let Some(caps) = sleeps.captures(ln) {
            let minute: i32 = caps.get(1).unwrap().as_str().parse().unwrap();
            sleep_time = minute;
        }
    }

    return slp_map;
}

fn p2(slp_map: &HashMap<i32, Vec<Range<i32>>>) {
    let mut mx = 0;
    let mut ans = 0;
    for (g, v) in slp_map {
        let mut cnt = [0; 60];
        for rng in v {
            for x in rng.clone() {
                cnt[x as usize] += 1;
            }
        }
        let (mn, slps) = cnt.iter().enumerate().max_by_key(|(i, x)| *x).unwrap();
        if *slps < mx {
            continue;
        }
        mx = *slps;
        ans = g * (mn as i32);
    }
    println!("Part 2: {}", ans);
}

fn p1(slp_map: &HashMap<i32, Vec<Range<i32>>>) {
    let mut mx = 0;
    let mut ans = 0;
    for (g, v) in slp_map {
        let t: i32 = v.iter().map(|r| r.end - r.start).sum();
        if t < mx {
            continue;
        }
        mx = t;
        let mut cnt = [0; 60];
        for rng in v {
            for x in rng.clone() {
                cnt[x as usize] += 1;
            }
        }
        let (mn, _) = cnt.iter().enumerate().max_by_key(|(i, x)| *x).unwrap();
        ans = g * (mn as i32);
    }
    println!("Part 1: {}", ans);
}

fn main() {
    let mut inp: Vec<&str> = include_str!("../input.txt").lines().collect();
    inp.sort();
    let slp_map = parse_inp(&inp);
    p1(&slp_map);
    p2(&slp_map);
}
