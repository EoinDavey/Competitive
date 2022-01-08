#![allow(unused_variables)]
#![allow(dead_code)]
use std::collections::{HashMap, HashSet};
use itertools::Itertools;

type Sample = [[i32; 4]; 3];

type Op = fn(reg: &mut [i32; 4], args: [i32; 4]);

const OPS: [Op; 16] = [
    // addr
    |reg, [_, a, b, c]| {
        reg[c as usize] = reg[a as usize] + reg[b as usize];
    },
    // addi
    |reg, [_, a, b, c]| {
        reg[c as usize] = reg[a as usize] + b;
    },
    // mulr
    |reg, [_, a, b, c]| {
        reg[c as usize] = reg[a as usize] * reg[b as usize];
    },
    // muli
    |reg, [_, a, b, c]| {
        reg[c as usize] = reg[a as usize] * b;
    },
    // banr
    |reg, [_, a, b, c]| {
        reg[c as usize] = reg[a as usize] & reg[b as usize];
    },
    // bani
    |reg, [_, a, b, c]| {
        reg[c as usize] = reg[a as usize] & b;
    },
    // borr
    |reg, [_, a, b, c]| {
        reg[c as usize] = reg[a as usize] | reg[b as usize];
    },
    // bori
    |reg, [_, a, b, c]| {
        reg[c as usize] = reg[a as usize] | b;
    },
    // setr
    |reg, [_, a, _, c]| {
        reg[c as usize] = reg[a as usize];
    },
    // seti
    |reg, [_, a, _, c]| {
        reg[c as usize] = a;
    },
    // gtir
    |reg, [_, a, b, c]| {
        reg[c as usize] = if a > reg[b as usize] { 1 } else { 0 };
    },
    // gtri
    |reg, [_, a, b, c]| {
        reg[c as usize] = if reg[a as usize] > b { 1 } else { 0 };
    },
    // gtrr
    |reg, [_, a, b, c]| {
        reg[c as usize] = if reg[a as usize] > reg[b as usize] { 1 } else { 0 };
    },
    // eqir
    |reg, [_, a, b, c]| {
        reg[c as usize] = if a == reg[b as usize] { 1 } else { 0 };
    },
    // eqri
    |reg, [_, a, b, c]| {
        reg[c as usize] = if reg[a as usize] == b { 1 } else { 0 };
    },
    // eqrr
    |reg, [_, a, b, c]| {
        reg[c as usize] = if reg[a as usize] == reg[b as usize] { 1 } else { 0 };
    },
];

fn parse_inp(inp: &str) -> (Vec<Sample>, Vec<[i32; 4]>) {
    let lines = inp.lines().collect_vec();
    let mut samples: Vec<Sample> = Vec::new();
    for chnk in lines.chunks(4) {
        if chnk[0] == "" {
            break;
        }
        let bef: Vec<i32> = chnk[0].strip_prefix("Before: [")
            .and_then(|x| x.strip_suffix(']'))
            .and_then(|x| x.split(", ").map(|y| y.parse::<i32>().ok()).collect())
            .unwrap();

        let op = chnk[1].split(" ").map(|x| x.parse::<i32>().unwrap()).collect_vec();
        let aft: Vec<i32> = chnk[2].strip_prefix("After:  [")
            .and_then(|x| x.strip_suffix(']'))
            .and_then(|x| x.split(", ").map(|y| y.parse::<i32>().ok()).collect())
            .unwrap();
        samples.push([bef.try_into().unwrap(), op.try_into().unwrap(), aft.try_into().unwrap()]);
    }

    let prog = lines.iter().skip(samples.len() * 4 + 2)
        .map(|x|
            x.split(' ').map(|n| n.parse::<i32>().unwrap()).collect_vec().try_into().unwrap()
        )
        .collect_vec();

    return (samples, prog);
}

fn match_sample(sample: &Sample) -> Vec<usize> {
    let mut out = Vec::new();
    for (i, op) in OPS.iter().enumerate() {
        let mut r = sample[0].clone();
        op(&mut r, sample[1]);
        if r == sample[2] {
            out.push(i);
        }
    }
    return out;
}

fn match_samples(samples: &Vec<Sample>) -> HashMap<i32, usize> {
    let matches = samples.iter().map(|x| (x, match_sample(x))).collect_vec();

    let mut assgn: HashMap<i32, usize> = HashMap::new();
    let mut assgnd_ops: HashSet<usize> = HashSet::new();

    while assgn.len() != OPS.len() {
        for (s, mtch) in matches.iter() {
            let id = s[1][0];
            if assgn.contains_key(&id) {
                continue;
            }
            let unmtched = mtch.iter().filter(|x| !assgnd_ops.contains(x)).collect_vec();
            if unmtched.len() > 1 {
                continue;
            }
            let op = *unmtched[0];
            assgn.insert(id, op);
            assgnd_ops.insert(op);
        }
    }
    for s in samples {
        let id = s[1][0];
        let op = OPS[assgn[&id]];
        let mut r = s[0].clone();
        op(&mut r, s[1]);
        if r != s[2] {
            panic!("Nope");
        }
    }
    return assgn;
}

fn p1(s: &Vec<Sample>) {
    let ans = s.iter().filter(|x| match_sample(x).len() >= 3).count();
    println!("Part 1: {}", ans);
}

fn p2(s: &Vec<Sample>, prog: &Vec<[i32; 4]>) {
    let assgn = match_samples(s);
    let mut r = [0, 0, 0, 0];

    for l in prog {
        let id = l[0];
        let op = OPS[assgn[&id]];
        op(&mut r, *l);
    }
    println!("Part 2: {}", r[0]);
}

fn main() {
    let inp = include_str!("../input.txt");
    let (samples, prog) = parse_inp(&inp);
    p1(&samples);
    p2(&samples, &prog);
}
