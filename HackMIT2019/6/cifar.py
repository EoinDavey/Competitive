import matplotlib.pyplot as plt
import numpy as np
def unpickle(file):
    import cPickle
    with open(file, 'rb') as fo:
        dict = cPickle.load(fo)
    return dict

def shape(x):
    r = np.reshape(x[:1024], (32,32))
    g = np.reshape(x[1024:2048], (32,32))
    b = np.reshape(x[2048:], (32,32))
    return np.stack((r,g,b), axis=2)

def load():
    meta = unpickle('cifar-100-python/meta')
    train = unpickle('cifar-100-python/train')
    test = unpickle('cifar-100-python/test')
    imgs = []
    lbls = []

    for i in xrange(len(train['data'])):
        img = shape(train['data'][i,:])
        imgs.append(img)
        lbls.append(train['fine_labels'][i])
        
    for i in xrange(len(test['data'])):
        img = shape(test['data'][i,:])
        imgs.append(img)
        lbls.append(test['fine_labels'][i])

    return imgs, np.array(lbls)
