m = {'T' : 'A',
    'A':'T',
    'C':'G',
    'G':'C'}
def inv(v):
    return "".join([m[c] for c in v])
print(inv(input()))
