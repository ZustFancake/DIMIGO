table = {
	(data := input().split())[0] : int(data[1]) for _ in [0] * 10
}

print("%d원" % sum([table[item] for item in input().split()]))
