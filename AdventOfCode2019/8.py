from functools import reduce

inp = input()
W = 25
H = 6
SZ = W * H
lrs = [inp[x : x + SZ] for x in range(0, len(inp), SZ)]
print(
    "Part A",
    (lambda y: y.count("1") * y.count("2"))(min(lrs, key=lambda x: x.count("0"))),
)

print("Part B")
img = [reduce(lambda a, b: [b, a][a != "2"], x) for x in zip(*lrs)]
rws = [img[x : x + W] for x in range(0, len(img), W)]
for rw in rws:
    print("".join(map(lambda x: ["0", "\033[92m1\033[0m"][x == "1"], rw)))
