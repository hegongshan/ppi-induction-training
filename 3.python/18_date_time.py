import time
import calendar


def main():
	timestamp = time.time()
	print("当前时间戳为：%s" % timestamp)

	localtime = time.localtime(timestamp)
	print("本地时间为：", localtime)

	asctime = time.asctime(localtime)
	print("可读时间：%s" % asctime)

	# 时间转字符串
	print(time.strftime("%Y-%m-%d %H:%M:%S", localtime))
	print(time.strftime("%a %b %d %H:%M:%S %Y", localtime))

	# 字符串转时间
	a = "Sat Mar 28 22:24:25 2016"
	print(time.strptime(a, "%a %b %d %H:%M:%S %Y"))
	print()

	cal = calendar.month(2021, 8)
	print("输出2018年8月的日历：")
	print(cal)


if __name__ == '__main__':
	main()