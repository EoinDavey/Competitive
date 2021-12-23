import * as readline from "readline";

type elt = 'A'|'B'|'C'|'D';
type hallElt = '.'|elt;

function hallIdx(stck: number): number {
    return 2 * (1 + stck);
}

function isRoomDoor(idx: number): boolean {
    return 0 < idx && idx < 10 && idx % 2 == 0
}

function openHallSlots(hall: hallElt[], idx: number): number[] {
    const s: number[] = [];
    let w = idx;
    while(w > 0 && hall[w-1] == '.') {
        w--;
        s.push(w);
    }
    w = idx;
    while(w < 10 && hall[w+1] == '.') {
        w++;
        s.push(w);
    }
    return s;
}

function movesToHall(hall: hallElt[], idx: number): number[] {
    return openHallSlots(hall, idx).filter(x => !isRoomDoor(x));
}

function stackPseudoSolved(stcks: elt[][], idx: number): boolean {
    const tgt: elt = String.fromCharCode("A".charCodeAt(0) + idx) as elt;
    for(const st of stcks[idx])
        if(st !== tgt)
            return false;
    return true;
}

function stackSolved(stcks: elt[][], idx: number, stackh: number): boolean {
    return stcks[idx].length == stackh && stackPseudoSolved(stcks, idx);
}

function solved(stcks: elt[][], stackh: number): boolean {
    for(let idx = 0; idx < stcks.length; idx++)
        if(!stackSolved(stcks, idx, stackh))
            return false;
    return true;
}

function toKey(stcks: elt[][], hall: hallElt[]): string {
    return `([${stcks.map(stck=>`[${stck}]`)}], "${hall}")`;
}

const costMp = {
    'A': 1,
    'B': 10,
    'C': 100,
    'D': 1000,
};

const memo: Map<string, number> = new Map();
function solve(stcks: elt[][], hall: hallElt[], stackh: number): number {
    if(solved(stcks, stackh))
        return 0;
    const k = toKey(stcks, hall);
    const m = memo.get(k);
    if(m != undefined)
        return m;
    let ans = 1000*1000*1000;

    for(let st = 0; st < stcks.length; st++) {
        if(stcks[st].length == 0)
            continue;
        if(stackPseudoSolved(stcks, st))
            continue;
        const v = stcks[st][stcks[st].length - 1];
        const hidx = hallIdx(st);
        const hallPoss = movesToHall(hall, hidx);
        for(const h of hallPoss) {
            hall[h] = v
            stcks[st].pop();

            const subCst = solve(stcks, hall, stackh);

            stcks[st].push(v);
            hall[h] = '.';

            const cst = subCst + costMp[v] * (1 + stackh - stcks[st].length + Math.abs(h - hidx));
            ans = cst < ans ? cst : ans;
        }
    }

    for(let i = 0; i < hall.length; i++) {
        const h = hall[i];
        if(h == '.')
            continue;
        const trgt = h.charCodeAt(0) - 'A'.charCodeAt(0);
        const hidx = hallIdx(trgt);
        if(stcks[trgt].length == stackh)
            continue;
        if(!stackPseudoSolved(stcks, trgt))
            continue;
        const slots = openHallSlots(hall, i);
        if(!slots.includes(hidx))
            continue;

        hall[i] = '.'
        stcks[trgt].push(h);
        const subCst = solve(stcks, hall, stackh);
        hall[i] = h
        stcks[trgt].pop();

        const cst = subCst + costMp[h] * (Math.abs(i - hidx) + stackh - stcks[trgt].length);
        ans = cst < ans ? cst : ans;
    }

    memo.set(k, ans);
    return ans;
}

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
  terminal: false
});

async function main() {
    const stcks: elt[][] = [[], [], [], []];

    for await (const line of rl) {
        const stck: elt[] = [];
        const mtches = Array.from(line.matchAll(/[A-Z]/g));
        for(const i in mtches)
            stcks[i].push(mtches[i][0] as elt);
    }
    for(const i in stcks)
        stcks[i].reverse();
    const hall = Array(11).fill('.');
    console.log(`Part 1: ${solve(stcks, hall, 2)}`);

    const stckD: elt[][] = [['D', 'D'], ['B', 'C'], ['A', 'B'], ['C', 'A']];
    for(const i in stcks)
        stcks[i] = [stcks[i][0]].concat(stckD[i]).concat([stcks[i][1]]);
    console.log(`Part 2: ${solve(stcks, hall, 4)}`);
}

main();
