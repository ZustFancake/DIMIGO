table = {
	100 : "S",
	** { score : "A" for score in range(90, 100) } ,
	** { score : "B" for score in range(80, 90)  } ,
	** { score : "C" for score in range(70, 80)  } ,
	** { score : "F" for score in range(0 , 70)  } ,
}

print(table[int(input())])
