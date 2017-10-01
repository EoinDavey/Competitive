import re
p = re.compile(r'.*CD.*')
print sum(map(lambda x: 1 if p.match(x)== None else 0,[raw_input() for _ in range(input())]))
