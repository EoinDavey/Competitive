use regex::Regex;
use itertools::Itertools;
use std::collections::HashSet;

struct Inp {
    x: i32,
    y: i32,
    dx: i32,
    dy: i32,
}

fn parse_inp(lines: &Vec<&str>) -> Vec<Inp> {
    let extract = Regex::new(r"position=<\s*(-?[0-9]+),\s*(-?[0-9]+)> velocity=<\s*(-?[0-9]+),\s*(-?[0-9]+)>")
        .unwrap();
    return lines.iter().map(|l| {
        let (x, y, dx, dy) = extract.captures(l).unwrap()
            .iter()
            .skip(1)
            .map(|x| x.map(|x| x.as_str())
                      .map(|x| x.parse::<i32>().unwrap())
                      .unwrap())
            .collect_tuple().unwrap();
        return Inp{x, y, dx, dy};
    }).collect();
}

fn bound_box(pts: &Vec<(i32, i32)>) -> (i32, i32, i32, i32) {
    let mnx = *pts.iter().map(|(x, _)| x).min().unwrap();
    let mxx = *pts.iter().map(|(x, _)| x).max().unwrap();
    let mny = *pts.iter().map(|(_, y)| y).min().unwrap();
    let mxy = *pts.iter().map(|(_, y)| y).max().unwrap();
    return (mnx, mxx, mny, mxy);
}

fn solve(inp: &Vec<Inp>) {
    let mut positions: Vec<(i32, i32)> = inp.iter().map(|x| (x.x, x.y)).collect();

    let mut prv_perim = -1;

    let mut t = 0;
    loop {
        positions = positions.into_iter()
            .enumerate()
            .map(|(i, pos)| (pos.0 + &inp[i].dx, pos.1 + &inp[i].dy))
            .collect();

        let (mnx, mxx, mny, mxy) = bound_box(&positions);
        let perim = (mxx - mnx) + (mxy - mny);
        if prv_perim != -1 && perim > prv_perim {
            break;
        }
        prv_perim = perim;
        t += 1;
    }

    positions = positions.into_iter()
        .enumerate()
        .map(|(i, pos)| (pos.0 - &inp[i].dx, pos.1 - &inp[i].dy))
        .collect();

    let (mnx, mxx, mny, mxy) = bound_box(&positions);
    let pts: HashSet<(i32, i32)> = positions.into_iter().collect();

    println!("Part 1:");
    for y in mny..=mxy {
        for x in mnx..=mxx {
            if pts.contains(&(x, y)) {
                print!("#");
            } else {
                print!(" ");
            }
        }
        println!("");
    }
    println!("Part 2: {}", t);
}

fn main() {
    let inp: Vec<&str> = include_str!("../input.txt").lines().collect();
    let lines = parse_inp(&inp);
    solve(&lines);
}
