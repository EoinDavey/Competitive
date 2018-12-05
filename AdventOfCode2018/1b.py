import sys
s = 0
st = set()
st.add(0)
ds = [int(line) for line in sys.stdin]
while True:
    for d in ds:
        s+=d
        if s in st:
            print s
            sys.exit(0)
        st.add(s)
