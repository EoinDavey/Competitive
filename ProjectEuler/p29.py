st = set()

for a in range(2,101):
    for b in range(2,101):
        st.add(a**b)
print len(st)
