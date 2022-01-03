use itertools::iproduct;

const SIZE: usize = 300_usize;

fn power(x: usize, y: usize, inp: i32) -> i64 {
    let rid = (x as i64) + 10;
    let mut p = rid * (y as i64);
    p += inp as i64;
    p *= rid;
    let hun = (p / 100) % 10;
    return hun - 5;
}

fn p1(inp: i32) {
    let ans = iproduct!((1..=SIZE-3), (1..=SIZE-3))
        .max_by_key(|(x, y)| -> i64 {
            return iproduct!((0..3), (0..3))
                .map(|(i, j)| power(x + i, y + j, inp))
                .sum();
        }).unwrap();

    println!("Part 1: {},{}", ans.0, ans.1);
}

fn p2(inp: i32) {
    let mut pref_sum: [[i64; SIZE]; SIZE] = [[0; SIZE]; SIZE];
    for (x, y) in iproduct!((0..SIZE), (0..SIZE)) {
        pref_sum[x][y] = power(x + 1, y + 1, inp);
        if x > 0 {
            pref_sum[x][y] += pref_sum[x - 1][y];
        }
        if y > 0 {
            pref_sum[x][y] += pref_sum[x][y - 1];
        }
        if x > 0 && y > 0 {
            pref_sum[x][y] -= pref_sum[x - 1][y - 1];
        }
    }

    let ans = iproduct!((1..=SIZE), (1..=SIZE), (1..=SIZE))
        .max_by_key(|(x, y, sz)| -> i64 {
            if x - 1 + sz - 1 >= SIZE {
                return 0;
            }
            if y - 1 + sz - 1 >= SIZE {
                return 0;
            }
            let mut sm = pref_sum[x - 1 + sz - 1][y - 1 + sz - 1];
            if x - 1 > 0 {
                sm -= pref_sum[x - 1 - 1][y - 1 + sz - 1];
            }
            if y - 1 > 0 {
                sm -= pref_sum[x - 1 + sz - 1][y - 1 - 1];
            }
            if x - 1 > 0 && y - 1 > 0 {
                sm += pref_sum[x - 1 - 1][y - 1 - 1];
            }
            return sm;
        }).unwrap();

    println!("Part 2: {},{},{}", ans.0, ans.1, ans.2);
}

fn main() {
    let inp = 6392;

    p1(inp);
    p2(inp);
}
