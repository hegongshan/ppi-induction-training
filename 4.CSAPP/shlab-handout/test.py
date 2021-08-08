import os


def main():
	file_prefix = 'trace'

	with open('./tsh.out', 'w') as file:
		content = []
		for i in range(1, 16 + 1):
			filename = '%s%02d.txt' % (file_prefix, i)
			cmd = './sdriver.pl -t %s -s ./tsh -a "-p"' % filename
			content.append(cmd + '\n')
			content.extend(os.popen(cmd).readlines())
		file.writelines(content)


if __name__ == '__main__':
	main()