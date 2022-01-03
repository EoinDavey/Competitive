const DS: [(i32, i32); 4] = [
    (0, 1),
    (0, -1),
    (-1, 0),
    (1, 0),
];

// c -> (left, straight, right)
const INSCT: [[char; 3]; 4] = [
    ['^', '>', 'v'],
    ['v', '<', '^'],
    ['<', '^', '>'],
    ['>', 'v', '<'],
];

// c -> ('/', '\')
const TURNS: [(char, char); 4] = [
    ('^', 'v'),
    ('v', '^'),
    ('>', '<'),
    ('<', '>'),
];

type Board = Vec<(char, usize)>;

#[derive(Clone)]
struct State {
    board: Board,
    w: i32,
}

fn is_cart(c: char) -> bool {
    return c == '>' || c == '<' || c == '^' || c == 'v';
}

fn idx(c: char) -> usize {
    if c == '>' {
        return 0;
    }
    if c == '<' {
        return 1;
    }
    if c == '^' {
        return 2;
    }
    return 3;
}

fn bidx(x: i32, y: i32, w: i32) -> usize {
    return (x*w + y).try_into().unwrap();
}

fn tick_once(b: &mut State, orig: &Board, remove_carts: bool) -> Option<(i32, i32)> {

    let mut carts: Vec<(i32, i32)> = b.board.iter()
        .enumerate()
        .filter(|(_, (c, _))| is_cart(*c))
        .map(|(idx, _)| (idx as i32 / b.w, idx as i32 % b.w))
        .collect();

    if carts.len() == 1 {
        return Some(carts[0]);
    }

    carts.sort();

    for (xr, yr) in carts.iter() {
        let (x, y) = (*xr, *yr);
        let (c, t) = b.board[bidx(x, y, b.w)];
        if !is_cart(c) {
            continue;
        }
        let (dx, dy) = DS[idx(c)];
        let (nx, ny) = (x + dx, y + dy);
        let (nxt, _) = b.board[bidx(nx, ny, b.w)];

        let nc = if nxt == '-' || nxt == '|' {
            c
        } else if nxt == '/' {
            TURNS[idx(c)].0
        } else if nxt == '\\' {
            TURNS[idx(c)].1
        } else if is_cart(nxt) {
            if !remove_carts {
                return Some((nx, ny));
            }
            orig[bidx(nx, ny, b.w)].0
        } else if nxt == '+' {
            INSCT[idx(c)][t]
        } else {
            panic!("How did we ge here?");
        };

        let nt = if nxt == '+' {
            (t + 1) % 3
        } else {
            t
        };

        b.board[bidx(nx, ny, b.w)] = (nc, nt);
        b.board[bidx(x, y, b.w)] = orig[bidx(x, y, b.w)];
    }
    return None;
}

fn p1(mut st: State, orig: &Board) {
    loop {
        let crash = tick_once(&mut st, &orig, false);
        if let Some((x, y)) = crash {
            println!("Part 1: {},{}", y, x);
            break;
        }
    }
}

fn p2(mut st: State, orig: &Board) {
    loop {
        let crash = tick_once(&mut st, &orig, true);
        if let Some((x, y)) = crash {
            println!("Part 2: {},{}", y, x);
            break;
        }
    }
}

fn main() {
    let inp: Vec<&str> = include_str!("../input.txt").lines().collect();
    let h = inp.len() as i32;
    let w = inp.iter().map(|x| x.len()).max().unwrap() as i32;
    let mut board: Board = Vec::with_capacity((h*w).try_into().unwrap());
    board.resize((h*w).try_into().unwrap(), (' ', 0));
    for (x, l) in inp.iter().enumerate() {
        for (y, c) in l.chars().enumerate() {
            let idx = bidx(x as i32, y as i32, w);
            board[idx] = (c, 0);
        }
    }

    let orig = board.iter().map(|(c, t)| {
            return if *c == '>' || *c == '<' {
                ('-', *t)
            } else if *c == '^' || *c == 'v' {
                ('|', *t)
            } else {
                (*c, *t)
            }
        }).collect::<Board>();

    let st = State { board, w };

    p1(st.clone(), &orig);
    p2(st, &orig);
}
