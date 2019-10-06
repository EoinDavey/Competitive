import sys
from math import asin, sqrt
import math

def sin(x):
    return math.sin(math.radians(x))

def cos(x):
    return math.cos(math.radians(x))

R = 6378.137

def toD(inp):
    d = inp[0]
    date, time = d.split(' ')
    MM, dd, yy = date.split('/')
    hh, mm = time.split(':')
    return ':'.join([yy,MM,dd,hh,mm])

def sqr(x):
    return x*x

def hav(lat1, lon1, lat2, lon2):
    ans =  2 * R * asin(sqrt(sqr(sin((lat1 - lat2)/2)) + cos(lat1) * cos(lat2) * sqr(sin((lon1 - lon2)/2))))
    return ans

def solve():
    lines = [x.rstrip() for x in sys.stdin.readlines()]

    lat1, lon1 = [float(x) for x in lines[0].split(',')]
    r = float(lines[1])

    splits = [x.split(',') for x in lines[3:]]
    splits.sort(key=toD)

    phoneMap = {}

    for entry in splits:
        phoneMap[entry[-1]] = (entry[1], entry[2])

    out = []
    for phone, (lat, lon) in phoneMap.items():
        if hav(lat1, lon1, float(lat), float(lon)) <= r:
            out.append(phone)

    out.sort()
    print(','.join(map(str, out)))

solve()
