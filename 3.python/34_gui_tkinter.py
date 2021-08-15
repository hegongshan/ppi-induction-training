import tkinter


def main():
	root = tkinter.Tk()
	li = ['C', 'Python3', 'PHP', 'HTML', 'SQL', 'Java']
	movies = ['CSS', 'jQuery', 'Bootstrap']

	lista = tkinter.Listbox(root)
	listb = tkinter.Listbox(root)
	for item in li:
		lista.insert(0, item)
	for item in movies:
		listb.insert(0, item)
	lista.pack()
	listb.pack()

	root.mainloop()


if __name__ == '__main__':
	main()