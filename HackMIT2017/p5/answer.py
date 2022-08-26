import os
import string
import hashlib

out = list(string.lowercase) + [str(x) for x in range(10)]

print "{"
print "\"solutions\":["
for filename in os.listdir('captchas'):
    comb = "EoinDavey" + filename[:len(filename)-4]
    name = hashlib.md5(comb).hexdigest()
    print "{"
    print "\"name\": \"%s\"," % filename[:len(filename)-4]
    print "\"solution\": \"%s\"" % "".join([out[int(name[x:x+4],16)%36] for x in range(0,16,4)])
    print "},"

print "]"
print "}"
