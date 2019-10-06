from collections import deque
from math import floor
T = int(input())
for _ in range(T):
    temp  = list(map(int, input().split()))
    p = temp[0]
    s = temp[1]
    n = temp[2]
    fifo = set()
    q = deque()
    lru = set()
    lru_lst = []
    lru_page_faults = 0
    fifo_page_faults = 0 
    for _ in range(n):
        address = int(input())
        page = floor(address / s)
        if len(fifo) < p:
            if page not in fifo:
                fifo.add(page)
                q.append(page)
        elif len(fifo) == p:
            if page not in fifo:
                fifo_page_faults += 1
                oldest = q.popleft()
                fifo.remove(oldest)
                q.append(page)
                fifo.add(page)
        if len(lru) < p:
            if page in lru:
                swap_idx = None
                for idx, val in enumerate(lru_lst):
                    if val == page:
                        swap_idx = idx
                lru_lst = lru_lst[:swap_idx] + lru_lst[swap_idx + 1:] + [lru_lst[swap_idx]]
            else:
                lru.add(page)
                lru_lst.append(page)
        elif len(lru) == p:
            if page in lru:
                swap_idx = None
                for idx, val in enumerate(lru_lst):
                    if val == page:
                        swap_idx = idx
                lru_lst = lru_lst[:swap_idx] + lru_lst[swap_idx + 1:] + [lru_lst[swap_idx]]
            else:
                lru_page_faults += 1
                lru.remove(lru_lst[0])
                lru_lst.pop(0)
                lru_lst.append(page)
                lru.add(page)
        # print("LRU {}".format(lru_lst))
        # print("FIFO {}".format(list(q)))
    if lru_page_faults < fifo_page_faults:
        print("yes {} {}".format(fifo_page_faults, lru_page_faults))
    else:
        print("no {} {}".format(fifo_page_faults, lru_page_faults))
