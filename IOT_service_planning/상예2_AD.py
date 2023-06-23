class Animal:
    def __init__(self, weight, sound):
        self.weight = weight
        self.sound = sound

    def cry(self):
        print("동물이 웁니다.")

    def size(self):
        print(f"동물의 몸무게는 {self.weight}입니다.")


class Dog(Animal):
    def __init__(self, name, weight, sound):
        super().__init__(weight, sound)
        self.name = name

    def cry(self):
        print(f"{self.name}가 {self.sound}하며 웁니다.")

    def size(self):
        print(f"{self.name}의 몸무게는 {self.weight}입니다.")

name, weight, sound = input().split()

dog = Dog(name, int(weight), sound)
dog.cry()
dog.size()
