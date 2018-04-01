import sys
normal = ["don't think so","don't touch me","not bad","cool","great!"]
grump = ["dont' even","are you serious?","go die in a hole","worse","terrible","no way"]
for i in range(10):
    print i
    sys.stdout.flush()
    s = raw_input()
    if s in normal:
        print "normal"
        sys.exit(0)
    elif s in grump:
        print "grumpy"
        sys.exit(0)
