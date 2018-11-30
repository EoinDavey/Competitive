rep = {
        'at' : '@',
        'At' : '@',
        'AT' : '@',
        'and' : '&',
        'And' : '&',
        'ANd' : '&',
        'AND' : '&',
        'won' : '1',
        'Won' : '1',
        'WOn' : '1',
        'WON' : '1',
        'one' : '1',
        'One' : '1',
        'ONe' : '1',
        'ONE' : '1',
        'to' : '2',
        'To' : '2',
        'TO' : '2',
        'two' : '2',
        'Two' : '2',
        'TWo' : '2',
        'TWO' : '2',
        'too' : '2',
        'Too' : '2',
        'TOo' : '2',
        'TOO' : '2',
        'for' : '4',
        'For' : '4',
        'FOr' : '4',
        'FOR' : '4',
        'four' : '4',
        'Four' : '4',
        'FOur' : '4',
        'FOUr' : '4',
        'FOUR' : '4',
        'be' : 'b',
        'Be' : 'B',
        'BE' : 'B',
        'bea' : 'b',
        'Bea' : 'B',
        'BEa' : 'B',
        'BEA' : 'B',
        'bee' : 'b',
        'Bee' : 'B',
        'BEe' : 'B',
        'BEE' : 'B',
        'sea' : 'c',
        'Sea' : 'C',
        'SEa' : 'C',
        'SEA' : 'C',
        'see' : 'c',
        'See' : 'C',
        'SEe' : 'C',
        'SEE' : 'C',
        'eye' : 'i',
        'Eye' : 'I',
        'EYe' : 'I',
        'EYE' : 'I',
        'oh' : 'o',
        'Oh' : 'O',
        'OH' : 'O',
        'owe' : 'o',
        'Owe' : 'O',
        'OWe' : 'O',
        'OWE' : 'O',
        'are' : 'r',
        'Are' : 'R',
        'ARe' : 'R',
        'ARE' : 'R',
        'you' : 'u',
        'You' : 'U',
        'YOu' : 'U',
        'YOU' : 'U',
        'why' : 'y',
        'Why' : 'Y',
        'WHy' : 'Y',
        'WHY' : 'Y'
}

def proc(s):
    o = ''
    i = 0
    while i < len(s):
        b = False
        for j in xrange(4, 1, -1):
            if s[i:i+j] in rep:
                b = True
                o+=rep[s[i:i+j]]
                i+=j
                break
        if not b:
            o+=s[i]
            i+=1
    return o

for _ in xrange(input()):
    print proc(raw_input())
