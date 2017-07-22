units = ["one","two","three","four","five","six","seven","eight","nine"]
r = ["twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"]
tens = ["eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"]
for x in r:
    tens += map(lambda (x,y):x+y, zip([x]*10,units))
tens += r + ["ten"]
hundreds = map(lambda (x,y):x+y,zip(units,["hundred"]*9))
sofar = units + tens
rest = []
for x in hundreds:
    rest += map(lambda (x,y):x+"and"+y, zip([x]*1000, sofar))
rest += hundreds
rest+= sofar
rest+=["onethousand"]
s = 0
for x in rest:
    s+=len(x)
print s
