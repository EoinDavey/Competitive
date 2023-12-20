import re
n = int(input())
rs = [len(x) for x in re.findall(r'R+', input())]
rs.sort(reverse=True)
print(sum(rs) - sum(rs[:n]))
