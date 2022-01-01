use std::collections::HashMap;
use std::collections::BinaryHeap;
use std::cmp::Ordering;

#[derive(Eq, Hash, PartialEq, Debug)]
struct Entry(char);

impl PartialOrd for Entry {
    fn partial_cmp(&self, other: &Entry) -> Option<Ordering> {
        return other.0.partial_cmp(&self.0);
    }
}

impl Ord for Entry {
    fn cmp(&self, other: &Entry) -> Ordering {
        return other.0.cmp(&self.0);
    }
}

fn get_inp(inp: &str) -> Vec<(char, char)> {
    return inp.lines().map(|ln| {
        let sp: Vec<&str> = ln.split(' ').collect();
        return (sp[1].chars().nth(0).unwrap(), sp[sp.len() - 3].chars().nth(0).unwrap());
    }).collect();
}

fn build_graph(edges: &Vec<(char, char)>) -> HashMap<char, Vec<char>> {
    let mut grph: HashMap<char, Vec<char>> = HashMap::new();
    for edge in edges {
        grph.entry(edge.0).or_insert_with(|| Vec::new()).push(edge.1);
    }
    return grph;
}

fn p1(nodes: &Vec<char>, grph: &HashMap<char, Vec<char>>) {
    let mut in_cnt: HashMap<char, usize> = HashMap::new();
    for (_, v) in grph {
        for x in v {
            *in_cnt.entry(*x).or_default() += 1;
        }
    }

    let mut q: BinaryHeap<Entry> = nodes
        .iter().filter(|x| *in_cnt.get(x).unwrap_or(&0) == 0)
        .map(|x| Entry(*x)).collect();

    let mut ord: Vec<char> = Vec::new();
    while q.len() > 0 {
        let hd = q.pop().unwrap();
        ord.push(hd.0);
        for v in grph.get(&hd.0).unwrap_or(&Vec::new()) {
            *in_cnt.entry(*v).or_default() -= 1;
            if let Some(cnt) = in_cnt.get(v) {
                if *cnt == 0 {
                    q.push(Entry(*v));
                }
            }
        }
    }
    println!("Part 1: {}", ord.into_iter().collect::<String>());
}

fn p2(nodes: &Vec<char>, grph: &HashMap<char, Vec<char>>) {
    let mut in_cnt: HashMap<char, usize> = HashMap::new();
    for (_, v) in grph {
        for x in v {
            *in_cnt.entry(*x).or_default() += 1;
        }
    }

    let mut q: BinaryHeap<Entry> = nodes
        .iter().filter(|x| *in_cnt.get(x).unwrap_or(&0) == 0)
        .map(|x| Entry(*x)).collect();

    let mut left: [i32; 5] = [0; 5];
    let mut work: [char; 5] = ['\0'; 5];

    let mut t = 0;
    loop {
        for i in 0..5 {
            if left[i] == 0 {
                continue;
            }
            left[i] -= 1;
            if left[i] > 0 {
                continue;
            }
            for v in grph.get(&work[i]).unwrap_or(&Vec::new()) {
                *in_cnt.entry(*v).or_default() -= 1;
                if let Some(cnt) = in_cnt.get(v) {
                    if *cnt == 0 {
                        q.push(Entry(*v));
                    }
                }
            }
        }

        for i in 0..5 {
            if left[i] != 0 {
                continue;
            }
            if let Some(x) = q.pop() {
                work[i] = x.0;
                left[i] = 60 + (x.0 as i32) - ('A' as i32) + 1;
            }
        }

        if q.len() == 0 && left.iter().all(|x| *x == 0) {
            break;
        }

        t += 1;
    }

    println!("Part 2: {}", t);
}

fn get_nodes(edges: &Vec<(char, char)>) -> Vec<char> {
    let mut all: Vec<char> = edges.iter().map(|(a, b)| vec![*a, *b]).flatten().collect();
    all.sort();
    all.dedup();
    return all;
}

fn main() {
    let inp = get_inp(&include_str!("../input.txt"));
    let grph = build_graph(&inp);
    let nodes = get_nodes(&inp);
    p1(&nodes, &grph);
    p2(&nodes, &grph);
}
