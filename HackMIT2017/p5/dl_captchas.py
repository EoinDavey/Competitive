import json, requests, base64

url = 'https://captcha.delorean.codes/u/oafdsfdnv/challenge'

images = requests.get(url).json()["images"]

for i in images:
   jpg = base64.decodestring(i['jpg_base64']) 
   f=open("captchas/" + i['name'] + '.jpg','w')
   f.write(jpg)
   f.close()
