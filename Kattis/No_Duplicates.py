print ["no","yes"][(lambda x: len(set(x)) == len(x))(raw_input().split())]
