fl = map(int, raw_input().split())
jusg = [(fl[i],fl[i+1]) for i in xrange(0,20,2)]
state = [(u, r, t) for (u, r, t) in [map(int, raw_input().split()) for _ in xrange(10)]]

time = 0
for _ in xrange(3):
    for nxt in xrange(10):
        # nxt is next machine we want

        u, r, t = state[nxt]
        if t > time:
            # guy hasn't started
            time += jusg[nxt][0]
            if t <= time:
                #guy wants to start
                state[nxt] = (u, r, time)
            time += jusg[nxt][1]
            continue

        # guy has started

        pStart = time - (time-t)%(u+r)
        recovEnds = pStart + u + r
        wait = max(0, u - (time - t) % (u+r))

        time += wait

        # we can start now
        time += jusg[nxt][0]

        if recovEnds <= time:
            # guy wants to start
            state[nxt] = (u, r, time)
        time += jusg[nxt][1]

print time - jusg[9][1]
