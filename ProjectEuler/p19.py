ds = {0:31, 1:28, 2:31, 3:30, 4:31, 5:30, 6:31, 7:31, 8:30, 9:31, 10: 30, 11: 31}
def days(month, year):
    if month == 1 and year % 4 == 0 and (year % 100 != 0 or year % 400 == 0):
        return 29
    return ds[month]

w = 1

cnt = 0
for year in range(1901, 2001):
    for month in range(12):
        for day in range(days(month,year)):
            if day == 0 and w == 6:
                cnt+=1
            w = (w+1)%7
print cnt
