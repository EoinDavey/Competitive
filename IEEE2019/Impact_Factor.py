import json
from collections import defaultdict
import sys
s = []
publicists = {}
t = int(input())
article_counts = defaultdict(int)
citation_counts = defaultdict(int)
first = True
for line in sys.stdin:
    if first:
        temp = json.loads(line)
        for publication in temp['publications']:
            publicists[publication['publicationNumber']] = publication['publicationTitle']
            for data in publication['articleCounts']:
                if data['year'] == "2017" or data['year'] == "2018":
                    article_counts[publication['publicationNumber']] += int(data['articleCount'])
        first = False
    else:
        pub = json.loads(line)
        s.append(pub)
        for citation in pub["paperCitations"]["ieee"]:
            if citation['year'] == "2017" or citation['year'] == "2018":
                citation_counts[citation["publicationNumber"]] += 1

ans = [(publicists[number], (citation_counts[number]) / (article_counts[number])) for number in publicists.keys()]
ans = sorted(ans, key=lambda x: (-x[1], x[0]))
eps = 0.0001
for a in ans:
    print(a[0], end=': ')
    print("%.2f" % (a[1] + eps))

