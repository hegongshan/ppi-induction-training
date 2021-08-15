import smtplib
from email.mime.text import MIMEText
from email.header import Header
from email.utils import formataddr


def send_text_mail():
	sender = 'hegongshan@qq.com'
	passwd = 'pokqunfpsmsoeidj'
	receivers = 'hegongshan@yeah.net'

	message = MIMEText('Hello! 这是一封测试邮件.', 'plain', 'utf-8')
	message['From'] = Header('贺巩山 <%s>' % sender, 'utf-8')
	message['To'] = Header('hegongshan <%s>' % receivers, 'utf-8')
	message['Subject'] = Header('Python SMTP测试邮件', 'utf-8')

	try:
		smtpobj = smtplib.SMTP_SSL('smtp.qq.com')
		smtpobj.login(sender, passwd)
		smtpobj.sendmail(sender, receivers, message.as_string())
		print("邮件发送成功")
	except smtplib.SMTPException:
		print("Error: 邮件发送失败")
	else:
		smtpobj.quit()


def send_html_mail():
	pass


def send_file_mail():
	pass


if __name__ == '__main__':
	send_text_mail()