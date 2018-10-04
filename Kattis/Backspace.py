def p(s):
    chrs = []
    for c in s:
        if c=='<':
            chrs.pop()
        else:
            chrs.append(c)
    return "".join(chrs)

print p(raw_input())
