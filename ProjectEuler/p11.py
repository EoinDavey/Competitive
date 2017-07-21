import operator
N = 20

board = [map(int,raw_input().split()) for _ in range(N)]

moves = [(0,1),(1,0),(1,1),(1,-1)]

mx = 0
for i in range(N):
    for j in range(N):
        for d in moves:
            pr = 1
            for k in range(4):
                _x = i + k*d[0]
                _y = j + k*d[1]
                if _x >= N or _y >= N or _x < 0 or _y < 0:
                    break
                pr *= board[_x][_y]
            if pr > mx:
                mx = pr
print mx
