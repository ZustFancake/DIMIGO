class Person:
	def __init__(self, name, age):
		self.name = name; self.age = age;
	def getName(self): return self.name
	def getAge (self): return self.age

class Student(Person):
	def __init__(self, name, age, schoolName):
		super().__init__(name, age); self.schoolName = schoolName;
	def printStuInfo(self):
		grade = 0
		if 17 <= self.age <= 19:
			grade = self.age - 16
			print("%s는 %s %d학년에 재학중입니다." % (self.name, self.schoolName, grade))
		else: print("고등학생 나이가 아닙니다.")
	
name, age, schoolName = input().split();
student = Student(name, int(age), schoolName)
student.printStuInfo()
