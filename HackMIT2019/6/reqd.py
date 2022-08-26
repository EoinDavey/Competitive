from os import listdir
from os.path import isfile, join
import json
import base64
import imageio

def load():
    onlyfiles = [f for f in listdir('images/') if isfile(join('images/', f))]

    rimgs, rpreds, roids = [], [], []
    for f in onlyfiles:
        with open('images/%s' % f, 'r') as fl:
            js = json.load(fl)
            im = base64.b64decode(js['image'])
            img = imageio.imread(im)
            rimgs.append(img)
            rpreds.append(js['prediction'])
            roids.append(js['objectid'])
    return rimgs, rpreds, roids
