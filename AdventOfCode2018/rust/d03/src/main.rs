use std::collections::HashMap;

#[derive(Debug, Eq, Hash, PartialEq)]
struct Point(i32, i32);

#[derive(Debug)]
struct InpSquare {
    id: i32,
    tl: Point,
    h: i32,
    w: i32,
}

fn proc_inp(inp: &str) -> Vec<InpSquare> {
    let mut out: Vec<InpSquare> = Vec::new();
    for (i, ln) in inp.lines().enumerate() {
        let sp: Vec<&str> = ln.split(' ').collect();
        let mut tl = sp[2]
            .strip_suffix(':')
            .unwrap()
            .split(',')
            .map(|x| x.parse::<i32>().unwrap());
        let x = tl.next().unwrap();
        let y = tl.next().unwrap();
        let mut sz = sp[3].split('x').map(|x| x.parse::<i32>().unwrap());
        let w = sz.next().unwrap();
        let h = sz.next().unwrap();
        let sq = InpSquare {
            id: (i as i32) + 1,
            tl: Point(x, y),
            w: w,
            h: h,
        };
        out.push(sq);
    }
    return out;
}

fn hit_count(inp: &Vec<InpSquare>) -> HashMap<Point, i32> {
    let mut cnt: HashMap<Point, i32> = HashMap::new();
    for sq in inp {
        for dx in 0..sq.w {
            for dy in 0..sq.h {
                let pt = Point(sq.tl.0 + dx, sq.tl.1 + dy);
                let entry = cnt.entry(pt).or_default();
                *entry += 1;
            }
        }
    }
    return cnt;
}

fn p2(inp: &Vec<InpSquare>, hits: &HashMap<Point, i32>) {
    for sq in inp {
        if (sq.tl.0 .. sq.tl.0 + sq.w)
            .flat_map(|x| (sq.tl.1 .. sq.tl.1 + sq.h).map(move |y| Point(x,y)))
            .all(|pt| *hits.get(&pt).unwrap() == 1) {
            println!("Part 2: {}", sq.id);
            return;
        }
    }
}

fn p1(hits: &HashMap<Point, i32>) {
    let ans = hits.values().filter(|x| **x > 1).count();
    println!("Part 1: {}", ans);
}

fn main() {
    let inp = proc_inp(include_str!("../input.txt"));
    let hits = hit_count(&inp);
    //let inp = proc_inp(include_str!("../sample.txt"));
    p1(&hits);
    p2(&inp, &hits);
}
