import os.path
from .repoclone import clone_repo
from .make_ps import make_ps
import time
from .run_tests import Test_500
from .run_tests import get_results, init_results
import unittest
from pushswap42.models import Executable
import shutil
import errno    
import os


def parse_name():
	if os.path.isfile('./repo/push_swap/author'):
		f = open('./repo/push_swap/author', 'r')
		author = f.read().strip("\n")
		f.close()
		return (author)
	elif os.path.isfile('./repo/push_swap/auteur'):
		f = open('./repo/push_swap/auteur', 'r')
		author = f.read().strip("\n")
		f.close()
		return (author)
	elif os.path.isfile('./repo/push_swap/Makefile'):
		f = open('./repo/push_swap//Makefile', 'r')
		for i in range(5):
		    f.readline()
		line = list(f.readline().strip().split(' '))
		line = filter(lambda x: x != '', line)
		author = line[2]
		return (author)
	else:
		return "Unknown"

def repo_test(giturl, login):
	clone_repo(giturl)
	time.sleep(3)
	if (login == '-1'):
		_name = parse_name()
	else:
		_name = login
	make_ps(_name)
	time.sleep(5)
	try:
		os.makedirs('./results')
	except OSError as exc:  # Python >2.5
		if exc.errno == errno.EEXIST and os.path.isdir('./results'):
			pass
		else:
			raise
	init_results()
	suite = unittest.TestSuite()
	for method in dir(Test_500):
		if method.startswith("test_"):
			suite.addTest(Test_500(method))
	unittest.TextTestRunner().run(suite)
	results = get_results()
	avg = int(sum(results) / len(results))
	if Executable.objects.filter(name=_name).exists():
		n = Executable.objects.get(name=_name)
		n.t_min_500 = min(results)
		n.t_max_500 = max(results)
		n.t_avg_500 = avg
	else:
		n = Executable.objects.create(name=_name, t_min_500=min(results), t_max_500=max(results), t_avg_500=avg)
	print(min(results))
	print(max(results))
	print(avg)
	n.save()
	shutil.rmtree('./repo', ignore_errors=True)
	shutil.rmtree('./results', ignore_errors=True)



