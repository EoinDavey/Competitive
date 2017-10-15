n1 = input()
n2 = input()

a1 = (n2-n1)%360
a2 = -(360-a1) if a1 >=0 else 360+a1

if abs(a1) < abs(a2):
    print a1
elif abs(a1)==abs(a2):
    print abs(a2)
else:
    print a2
