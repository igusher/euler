nums = range(1,101)
s1 = 0
s1 = 0
s2 = 0
for i in nums:
	s2 += i
	s1 += i*i
s2 *= s2
diff = s2 - s1
diff