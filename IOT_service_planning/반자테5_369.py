a, b = map(int, input().split()); c = 0
for n in range(a, b + 1): c += str(n).count('3') + str(n).count('6') + str(n).count('9')
print(c)
