import imageio
from collections import defaultdict
import numpy as np
import matplotlib.pyplot as plt

def loadshards(count):
    ims = []
    for i in xrange(count):
        ims.append(imageio.imread("shards/shard-%d.png" % i))
    return ims

def mtchScr(a, b):
    rgta = a[:, -1:, :]
    lftb = b[:, :1, :]
    score = np.sum(np.square(rgta-lftb))
    return score

if __name__=='__main__':
    shrds = loadshards(760)
    usd = defaultdict(lambda: False)

    while True:
        seed = np.random.randint(0,len(shrds)-1)
        while usd[seed]:
            seed = np.random.randint(0,len(shrds)-1)
        print "random seed", seed
        usd[seed]=True
        st = shrds[seed]
        while True:
            bsti, bsts = -1, 10**10
            for i in xrange(len(shrds)):
                if usd[i]:
                    continue
                scr = mtchScr(st, shrds[i])
                if scr < bsts:
                    bsts = scr
                    bsti = i
            if bsti < 0:
                break
            cat = np.concatenate((st, shrds[bsti]), axis=1)
            plt.figure(figsize=(100,100))
            plt.imshow(cat)
            plt.show()
            s = raw_input("Keep?")
            if s=='N' or s=='n' or s=='No':
                break
            usd[bsti] = True
            st = cat
        print "Saving row"
        imageio.imwrite('rows/r%d.png' % seed, st)
        print "adding row to shrds"
        shrds.append(st)
