def closure(ls,bound=1000):
    st = set(ls)
    while True:
        mut = False
        for i in range(len(ls)):
            for j in range(i):
                if len(ls[i]) + len(ls[j]) > bound:
                    continue
                if ls[i] < ls[j]:
                    ns = ls[i] + ls[j]
                    if ns not in st:
                        mut = True
                        ls.append(ns)
                        st.add(ns)
                if ls[j] < ls[i]:
                    ns = ls[j] + ls[i]
                    if ns not in st:
                        mut = True
                        ls.append(ns)
                        st.add(ns)
        if not mut:
            break
    return st
