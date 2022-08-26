import matplotlib.pyplot as plt
import numpy as np
import requests
import sys
import json

endpoint = 'http://partition.hackvengers.dev/api/EoinDavey_28685a/prediction'

cnt = 0
while cnt < 60000:
    resp = requests.get(endpoint)

    if resp.status_code != 200:
        break

    js = resp.json()
    oid = js['objectid']
    with open('images/%s.txt' % oid,'w') as out:
        json.dump(js, out)
    cnt += 1
    if cnt%100 == 0:
        print cnt
