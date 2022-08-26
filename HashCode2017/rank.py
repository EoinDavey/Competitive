def ints():
    return map(int, raw_input().split())

class Endpoint:
    def __init__(self):
        self.lat, cc = ints()
        self.caches = {}
        self.req = {}
        for _ in range(cc):
            c, lat = ints()
            self.caches[c] = lat

    def __repr__(self):
        return "<lat: {} caches: {} reqs: {}>".format(self.lat, self.caches, self.req)

# Two props: endpoints, vidsize
class Input():
    def __init__(self):
        _, epc, reqc, cc, csize = ints()
        vidsize = list(ints())
        epls = []
        for _ in range(epc):
            epls.append(Endpoint())
        for _ in range(reqc):
            vid, ep, rc = ints()
            epls[ep].req[vid] = rc

        self.endpoints = epls
        self.vidsize = vidsize

def get_output(inp):
    contents = {}
    cc = list(ints())[0]
    for _ in range(cc):
        nums = list(ints())
        cs = nums[0]
        vids = vids[1:]
        if sum(inp.vidsize[v] for v in vids) > 100:
            raise Exception("Cache {} full".format(cs))
        contents[cs] = vids
    return contents

inp = Input()
output = get_output(inp)

total = sum([sum(x.req.values()) for x in inp.endpoints])
ours = 0
for ep in inp.endpoints:
    for vid, rc in ep.req.items():
        #print("LAntecy for video {} with {} requets".format(vid, rc))
        minlat = ep.lat
        for cid, vih in output.items():
            if cid in ep.caches and vid in vih:
                minlat = min(minlat, ep.caches[cid])
        #print("New latnecy {} vs {}".format(minlat, ep.lat))
        ours += rc * (ep.lat - minlat)

print int((ours / total) * 1000)
