if __name__ == '__main__':
	f_list = []
	l_list = []
	y_list = []
	e_list = []
	r_list = []
	s_list = []
	for i in range(128):
		c = chr(i)
		v = i & 0xf;
		if v == 9:
			f_list.append(c)
		elif v == 15:
			l_list.append(c)
		elif v == 14:
			y_list.append(c)
		elif v == 5:
			e_list.append(c)
		elif v == 6:
			r_list.append(c)
		elif v == 7:
			s_list.append(c)

	solutions = []
	for f in f_list:
		for l in l_list:
			for y in y_list:
				for e in e_list:
					for r in r_list:
						for s in s_list:
							solutions.append(f + l + y + e + r + s)
	print('\n'.join(solutions))
