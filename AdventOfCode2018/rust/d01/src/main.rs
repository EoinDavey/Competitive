use std::collections::HashSet;

fn p1(fs: &Vec<i32>) {
    println!("Part 1: {}", fs.iter().sum::<i32>());
}

fn p2(fs: &Vec<i32>) {
    let mut hs: HashSet<i32> = HashSet::new();
    let mut sm: i32 = 0;
    for v in fs.iter().cycle() {
        sm += v;
        if !hs.insert(sm)  {
            break;
        }
    }
    println!("Part 2: {}", sm);
}

fn main() {
    let inp: Vec<i32> = include_str!("../input.txt")
        .lines()
        .map(|x| x.parse::<i32>().unwrap())
        .collect();
    p1(&inp);
    p2(&inp);
}
