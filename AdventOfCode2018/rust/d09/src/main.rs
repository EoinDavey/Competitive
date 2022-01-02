#![allow(dead_code)]
#![allow(unused_variables)]

use std::rc::Rc;
use std::cell::RefCell;
use std::fmt;

struct Circle {
    head: Option<Rc<RefCell<Node>>>,
}

#[derive(Debug)]
struct Node {
    val: i64,
    next: Option<Rc<RefCell<Node>>>,
    prev: Option<Rc<RefCell<Node>>>,
}

impl Circle {
    fn rotate_clockwise(&mut self) {
        let hd = self.head.take();
        if let Some(rc) = hd {
            let rc_borrow = rc.borrow();
            let nxt: Option<&Rc<RefCell<Node>>> = rc_borrow.next.as_ref();
            if let Some(nxt_rc_ref) = nxt {
                let new_head: Rc<RefCell<Node>> = nxt_rc_ref.clone();
                self.head = Some(new_head);
            }
        }
    }

    fn rotate_widdershins(&mut self) {
        let hd = self.head.take();
        if let Some(rc) = hd {
            let rc_borrow = rc.borrow();
            let prv: Option<&Rc<RefCell<Node>>> = rc_borrow.prev.as_ref();
            if let Some(prv_rc_ref) = prv {
                let new_head: Rc<RefCell<Node>> = prv_rc_ref.clone();
                self.head = Some(new_head);
            }
        }
    }

    fn insert_after(&mut self, val: i64) {
        let hd_opt = self.head.as_ref();
        if let Some(hd_rc) = hd_opt {
            let mut hd = hd_rc.borrow_mut();

            let nxt_rc = hd.next.take().expect("Next should never be None");

            if Rc::ptr_eq(&hd_rc, &nxt_rc) {
                let n = Rc::new(RefCell::new(Node {
                    val: val,
                    next: Some(hd_rc.clone()),
                    prev: Some(hd_rc.clone()),
                }));

                hd.next = Some(n.clone());
                hd.prev = Some(n);

                return;
            }

            let mut nxt = nxt_rc.borrow_mut();

            let n = Rc::new(RefCell::new(Node {
                val: val,
                next: Some(nxt_rc.clone()),
                prev: Some(hd_rc.clone()),
            }));

            nxt.prev = Some(n.clone());
            hd.next = Some(n);
        }
    }

    fn remove_head(&mut self) {
        if let Some(hd_rc) = self.head.take() {
            let mut hd = hd_rc.borrow_mut();
            let nxt_rc = hd.next.take().expect("Next should never be none");

            if Rc::ptr_eq(&hd_rc, &nxt_rc) {
                // Only 1 entry, head now is None
                return;
            }

            if Rc::ptr_eq(&hd.prev.as_ref().unwrap(), &nxt_rc) {
                {
                    let mut nxt = nxt_rc.borrow_mut();

                    // 2 entries, leave only nxt
                    nxt.next = Some(nxt_rc.clone());
                    nxt.prev = Some(nxt_rc.clone());
                }

                self.head = Some(nxt_rc);
                return;
            }

            let mut nxt = nxt_rc.borrow_mut();
            let prv_rc = hd.prev.take().expect("Prev should never be None");
            let mut prv = prv_rc.borrow_mut();

            prv.next = Some(nxt_rc.clone());
            nxt.prev = Some(prv_rc.clone());

            self.head = Some(nxt_rc.clone());
        }
    }
}

impl fmt::Debug for Circle {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self.head.as_ref() {
            None => {f.write_str("None")?;},
            Some(head) => {
                let mut wlk = head.clone();
                f.write_str("(.. ")?;

                loop {
                    f.write_fmt(format_args!("{}, ", wlk.borrow().val))?;

                    let nxt = wlk.borrow().next.as_ref().unwrap().clone();
                    wlk = nxt;

                    if Rc::ptr_eq(&wlk, &head) {
                        break;
                    }
                }
                f.write_str(" ..)")?;
            },
        }
        return Ok(());
    }
}

fn new(initial: i64) -> Circle {
    let l: Rc<RefCell<Node>> = Rc::new(RefCell::new(Node{ val: initial, next: None, prev: None }));
    {
        let mut mt = l.borrow_mut();
        mt.next = Some(l.clone());
        mt.prev = Some(l.clone());
    }

    return Circle {
        head: Some(l),
    }
}

fn solve(players: usize, last: i64) -> i64 {
    let mut scores = Vec::with_capacity(players);
    scores.resize(players, 0);

    let mut c = new(0);
    let mut p = 0_usize;

    for m in 1..=last {
        if m % 23 == 0 {
            scores[p] += m;
            for _ in 0..7 {
                c.rotate_widdershins();
            }
            scores[p] += c.head.as_ref().unwrap().borrow().val;
            c.remove_head();
        } else {
            c.rotate_clockwise();
            c.insert_after(m);
            c.rotate_clockwise();
        }
        p = (p + 1) % players;
    }
    return *scores.iter().max().unwrap();
}

fn main() {
    let inp: Vec<&str> = include_str!("../input.txt").split(' ').collect();
    let p: usize = inp[0].parse().unwrap();
    let last: i64 = inp[inp.len() - 2].parse().unwrap();
    println!("Part 1: {}", solve(p, last));
    println!("Part 2: {}", solve(p, 100 * last));
}
