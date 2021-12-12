import sys

# This program takes in a P3 .ppm file and upscales it, used to make larger codel
# Piet program images.
# After upscaling use imagemagick to conver to png if desired: `convert img.ppm img.png`

lines = [line.strip() for line in sys.stdin if line[0] != '#']
mul = 50

dim = tuple([int(x) for x in lines[1].split()])

tgtdim = (dim[0] * mul, dim[1] * mul)

out = [list(range(tgtdim[0])) for _ in range(tgtdim[1])]

data = lines[3:]

pxls = []
for l in data:
  l = [int(x) for x in l.split()]
  l = list(zip(*(iter(l),) * 3))
  pxls += l

for y in range(dim[1]):
  for x in range(dim[0]):
    pxl = pxls[y*dim[0] + x]

    tr = (x * mul, y * mul)
    for i in range(mul):
      for j in range(mul):
        out[tr[1] + i][tr[0] + j] = pxl

print('P3')
print(tgtdim[0], tgtdim[1])
print(255)
for r in out:
  for x in r:
    print(*x)
