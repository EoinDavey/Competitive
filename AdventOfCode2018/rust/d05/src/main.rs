fn collapse(a: char, b: char) -> bool {
    if a < b {
        return (b as i32) - ('a' as i32) == (a as i32) - ('A' as i32);
    }
    return (a as i32) - ('a' as i32) == (b as i32) - ('A' as i32);
}

fn rem(p: &str, c: char) -> String {
    return p.replace(&c.to_string(), "")
        .replace(&(((c as u8) - ('a' as u8) + ('A' as u8)) as char).to_string(), "");
}

fn solve(p: &str) -> usize {
    let mut stck: Vec<char> = Vec::new();
    for c in p.chars() {
        match stck.pop() {
            Some(hd) => {
                if collapse(c, hd) {
                    continue;
                }
                stck.push(hd);
                stck.push(c);
            },
            None => stck.push(c),
        }
    }
    return stck.len();
}

fn p1(p: &str) {
    println!("Part 1: {}", solve(p));
}

fn p2(p: &str) {
    let ans: usize = ('a'..='z').map(|c| solve(&rem(p, c))).min().unwrap();
    println!("Part 2: {}", ans);
}

fn main() {
    let inp = include_str!("../input.txt").strip_suffix('\n').unwrap();
    p1(&inp);
    p2(&inp);
}
