from zhihu_oauth import ZhihuClient
from zhihu_oauth.exception import NeedCaptchaException
client = ZhihuClient()
user = '+8618790129080'
pwd = '5769895'
try:
  client.login(user,pwd)
  print("登陆成功")
except NeedCaptchaException:
  with open('a.gif','wb') as f:
    f.write(client.get_captcha())
  captcha = input("please input the captcha:")
  client.login('email_or_phone','password',captcha)
client.save_token('token.pk1')
  
