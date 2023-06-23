class DimigoStudent:
	def __init__(self, id, name, club):
		self.id = id; self.name = name; self.club = club;
	def 공부하다(self): print("%s %s은 공부를 합니다." % (id, name))
	def 동아리활동하다(self): print("%s은 %s 동아리활동을 합니다." % (name, club))
	
id, name, club = input().split()
student = DimigoStudent(id, name, club)

if (act := input()) == "동아리": student.동아리활동하다()
elif act == "공부": student.공부하다()
