e_yul = tuple(map(float, input().split()))
grade, amount = map(int, input().split())

per = e_yul[grade - 1]

print("%d" % (amount * (per / 100)))
