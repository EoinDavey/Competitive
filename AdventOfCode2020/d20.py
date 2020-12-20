import sys
from collections import defaultdict
from itertools import chain, product

seaM = [
"                  # ",
"#    ##    ##    ###",
" #  #  #  #  #  #   ",
]
seaMW = len(seaM[0])

def lines():
  return [line.strip() for line in sys.stdin]

def key(s):
  return min(s, s[::-1])

def getEdges(board):
  top = board[0]
  bot = board[-1]
  l = ''.join([x[0] for x in board])
  r = ''.join([x[-1] for x in board])
  return top, bot, l, r

def getEdgeKeys(board):
  return [key(x) for x in getEdges(board)]

def flip(tile):
  return tile[::-1]

def rot(tile, times):
  for _ in range(times):
    tile = [''.join(x) for x in zip(*tile)][::-1]
  return tile

def allOri(tile):
  return list(chain(*[[rot(tile, i), flip(rot(tile, i))] for i in range(4)]))

def findMatchRot(tile, matchFn):
  oris = allOri(tile)
  for ori in oris:
    if matchFn(ori):
      return ori

def rotToMatchLeft(static, free):
  _, _, _, r = getEdges(static)
  def fn(tile):
    _, _, l, _ = getEdges(tile)
    return l == r
  return findMatchRot(free, fn)

def rotToMatchTop(static, free):
  _, b, _, _ = getEdges(static)
  def fn(tile):
    t, _, _, _ = getEdges(tile)
    return t == b
  return findMatchRot(free, fn)

def rotToTopLeftCorn(tile, edges):
  def fn(tile):
    t, _, l, _ = getEdgeKeys(tile)
    return len(edges[t]) == 1 and len(edges[l]) == 1
  return findMatchRot(tile, fn)

def rowConcat(row):
  return '\n'.join([''.join(x) for x in zip(*row)])

def stripBorders(tile):
  return [x[1:-1] for x in tile[1:-1]]

def countSeaMSqs(board):
  s = set()
  for x, y in product(range(len(board) - 2), range(len(board[0]) - (seaMW - 1))):
    mtch = True
    cur = set()
    for i, j in product(range(3), range(seaMW)):
      if seaM[i][j] != '#':
        continue
      if board[x + i][y + j] != '#':
        mtch = False
      cur.add((x + i, y + j))
    if mtch:
      s |= cur
  return len(s)

def partA():
  cnt = defaultdict(int)
  for id, tile in tiles:
    for k in getEdgeKeys(tile):
      cnt[k] += 1

  prd = 1
  for id, tile in tiles:
    if sum(cnt[k] == 1 for k in getEdgeKeys(tile)) >= 2:
      prd *= id
  print(prd)

def partB():
  edges = defaultdict(list)
  for (id, tile) in tiles:
    keys = getEdgeKeys(tile)
    for k in keys:
      edges[k].append(id)

  grph = defaultdict(dict)
  for k, ls in edges.items():
    if len(ls) == 1:
      continue
    [a, b] = ls
    grph[a][k] = b
    grph[b][k] = a

  corners = [id for (id, tile) in tiles if sum([len(edges[k]) == 1 for k in getEdgeKeys(tile)]) >= 2]

  board = []
  cornerID = corners[0]
  cornerTile = rotToTopLeftCorn(tileMp[cornerID], edges)
  row = [(cornerID, cornerTile)]
  while True:
    while True:
      stID, static = row[-1]
      _, _, _, r = getEdges(static)
      k = key(r)
      if k not in grph[stID]:
        break
      freeID = grph[stID][k]
      free = rotToMatchLeft(static, tileMp[freeID])
      row.append((freeID, free))
    board.append(rowConcat([stripBorders(x[1]) for x in row]))
    pID, pTile = row[0]
    botKey = key(getEdges(pTile)[1])
    if botKey not in grph[pID]:
      break
    freeID = grph[pID][botKey]
    free = rotToMatchTop(pTile, tileMp[freeID])
    row = [(freeID, free)]

  out = '\n'.join(board)
  mx = max(countSeaMSqs(ori) for ori in allOri(out.split('\n')))
  print(out.count('#') - mx)

inp = [x.split('\n') for x in '\n'.join(lines()).split('\n\n')]
tiles = []
tileMp = {}
for tile in inp:
  id = int(tile[0].split(' ')[1][:-1])
  board = tile[1:]
  tiles.append((id, board))
  tileMp[id] = board

partA()
partB()
