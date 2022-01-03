fn step(v: &mut Vec<usize>, a: &mut usize, b: &mut usize) {
    let sm = v[*a] + v[*b];
    if sm >= 10 {
        v.push((sm / 10) % 10);
    }
    v.push(sm % 10);
    *a = (*a + 1 + v[*a]) % v.len();
    *b = (*b + 1 + v[*b]) % v.len();
}

fn p1(steps: usize) {
    let mut v = vec![3, 7];
    let mut a = 0_usize;
    let mut b = 1_usize;

    while v.len() < steps + 10 {
        step(&mut v, &mut a, &mut b);
    }

    println!("Part 1: {}", (&v[steps..steps+10]).iter().map(|x| (((*x as u8) + ('0' as u8)) as char)).collect::<String>());
}

fn p2(tgt: usize) {
    let tgt_vec: Vec<usize> = tgt.to_string().chars()
        .map(|x| (x as usize) - ('0' as usize)).collect();
    let t = &tgt_vec[..];
    let mut v = vec![3, 7];
    let mut a = 0_usize;
    let mut b = 1_usize;
    loop {
        step(&mut v, &mut a, &mut b);
        if v.len() >= tgt_vec.len() && &v[v.len() - tgt_vec.len()..] == t {
            println!("Part 2: {}", v.len() - tgt_vec.len());
            break;
        }
        if v.len() >= tgt_vec.len() + 1 && &v[v.len() - tgt_vec.len() - 1..v.len() - 1] == t {
            println!("Part 2: {}", v.len() - tgt_vec.len() - 1);
            break;
        }
    }
}

fn main() {
    let inp = 633601;
    p1(inp);
    p2(inp);
}
