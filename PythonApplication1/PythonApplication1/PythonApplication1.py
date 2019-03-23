import math

def a():
	x1, y1, x2, y2, x3, y3 = eval(input("삼각형의 세 꼭짓점을 입력하세요: "))
	a = math.sqrt(math.pow((x2 - x1), 2) + math.pow((y2 - y1), 2))
	b = math.sqrt(math.pow((x3 - x2), 2) + math.pow((y3 - y2), 2))
	c = math.sqrt(math.pow((x1 - x3), 2) + math.pow((y1 - y3), 2))
	s = (a+b+c) /2
	area = math.sqrt(s * (s - a) * (s - b) * (s - c))
	print("삼각형의 넓이는" + area + "입니다.")