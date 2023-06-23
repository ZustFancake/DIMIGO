d = []
for n in map(int, input().split()):
	if n not in d:
		d.append(n); print("%d " % n, end = '')
