import sys
import os
import subprocess
import  os.path
from    django.conf     import settings

def make_ps(username='zsmith'):
	print(username)
	make_f = open("./repo/make_error", "w+")
	subprocess.call(["make", "re", "-C" + "./repo/push_swap"], stderr=make_f)
	make_f.close
	if (os.stat("./repo/make_error").st_size != 0):
		return (make_f)
	else:
		return (0)


def test_ps(username):
	pass


print make_ps(str(sys.argv[1]))