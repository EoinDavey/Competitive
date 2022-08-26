import fileinput
f = fileinput.input()

def dist((a,b),(x,y)):
    return abs(a-x) + abs(b-y)

class ride:
    def __init__(self,a,b,x,y,_s,_f):
        self.start = (a,b)
        self.finish = (x,y)
        self.s=_s
        self.f=_f
        self.dist = dist(self.start,self.finish)

class car:
    def __init__(self,p):
        self.t = 0
        self.path = p


R,C,F,N,B,T = map(int,f.next().split())

rides = [ride(*map(int,f.next().split())) for _ in xrange(N)]

cars = [car(map(int,f.next().split())[1:]) for _ in xrange(F)]

assert(len(set(reduce(lambda x,y:x+y.path,cars,[]))) == sum(map(lambda x:len(x.path),cars)))

assert(all(map(lambda x: x >= 0 and x < N,reduce(lambda x,y:x+y.path,cars,[]))))

score = 0

for car in cars:
    loc = (0,0)
    for r in car.path:
        ride = rides[r]
        car.t += dist(loc,ride.start)
        loc = ride.start
        if car.t <= ride.s:
            car.t = ride.s
            score+=B
        car.t += ride.dist
        loc = ride.finish
        if car.t <= ride.f:
            score+=ride.dist

print score
