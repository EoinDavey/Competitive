use std::iter::Iterator;

fn p1<'a>(it: &mut impl Iterator<Item = &'a i32>) -> Option<i32> {
    let c = it.next()?;
    let m = it.next()?;

    let mut sum = 0;
    for _ in 0..*c {
        sum += p1(it)?;
    }

    for _ in 0..*m {
        sum += it.next()?;
    }

    return Some(sum);
}

fn p2<'a>(it: &mut impl Iterator<Item = &'a i32>) -> Option<i32> {
    let c = it.next()?;
    let m = it.next()?;

    let mut cs: Vec<i32> = Vec::new();
    for _ in 0..*c {
        cs.push(p2(it)?);
    }

    let mut ms: Vec<i32> = Vec::new();
    for _ in 0..*m {
        ms.push(*it.next()?);
    }

    if cs.len() == 0 {
        return Some(ms.iter().sum());
    }

    return Some(ms.iter().map(|x| cs.get(*x as usize - 1).unwrap_or(&0)).sum());
}

fn main() {
    let inp: Vec<i32> = include_str!("../input.txt").strip_suffix('\n').unwrap()
        .split(' ').map(|x| x.parse::<i32>().unwrap()).collect();
    println!("Part 1: {:?}", p1(&mut inp.iter()).unwrap());
    println!("Part 2: {:?}", p2(&mut inp.iter()).unwrap());
}
