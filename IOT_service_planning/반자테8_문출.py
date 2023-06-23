for s in input().split():
	mi = s[0]
	for c in s:
		if mi <= c <= 'z': mi = c
	print(mi, end = '')
