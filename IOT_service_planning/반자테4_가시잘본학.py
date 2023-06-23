score = []

for _ in range(5):
	_, ko, ma, en = map(float, input().split())
	score.append((ko + ma + en) / 3)

cut = float(input())

c = 0
for i in score:
	if i > cut: c += 1

print(c)
