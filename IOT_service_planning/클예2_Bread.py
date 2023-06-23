class Bread:
	def __init__(self, name, *main_ingredients, price):
		self.name = name; self.mi = main_ingredients; self.price = int(price);
	def sell(self, amount):
		print("%s빵을 %d개 팔아 총 가격은 %d원입니다." % (self.name, amount, self.price * amount))
	def make(self, amount):
		print("%s를 재료로 %s빵을 %d개 만듭니다." % (' '.join(self.mi), self.name, amount))

bread = Bread(*(I := input().split())[:-1], price = I[-1])
cmd, arg = input().split(); arg = int(arg);
getattr(bread, cmd)(arg)
