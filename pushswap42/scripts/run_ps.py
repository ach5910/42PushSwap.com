import os
from subprocess import check_output, PIPE, Popen
from pushswap42.models import Executable
import shlex
import numpy


'''
Takes a path to the push swap program and a string of numbers
Returns the number of operations required to sort the list
'''
def run_ps(args):
	ps_args = shlex.split("./push_swap " + args)
	ps_proc = Popen(args=ps_args, stdout=PIPE)
	out = ps_proc.communicate()[0]
	f = open("command_list", mode='w+r')
	f.write(out)
	f.seek(0)
	ch_args = shlex.split("../../tests/checker " + args)
	ch_proc = Popen(args=ch_args, stdin=f, stdout=PIPE)
	f.close
	check = ch_proc.communicate()[0]
	if (check == "OK\n"):
		op_count = len(out.split("\n")) - 1
	else:
		op_count = None
	return (op_count)

'''
Crawls through a test_directory and runs push_swap test on each file
'''
def read_tests(ps_path, test_dir):
	result = []
	abs_test_dir = os.path.abspath(test_dir)
	current_wd = os.getcwd()
	os.chdir(ps_path)
	print ("\n\033[92mRead_tests\033[0m")
	for test in os.listdir(abs_test_dir):
		if test.startswith("test"):
			print (test)
			f = open(abs_test_dir + "/" + test, 'r')
			args = f.read()
			f.close()
			op_count = run_ps(args)
			if (op_count == None):
				os.chdir(current_wd)
				return (None)
			result.append(op_count)
	os.chdir(current_wd)
	return (result)

'''
Creates an entry in the database
'''
def create_entry(login, minimum, maximum, avg):
	if Executable.objects.filter(name=login).exists():
		n = Executable.objects.get(name=login)
		n.t_min_500 = minimum
		n.t_max_500 = maximum
		n.t_avg_500 = avg
	else:
		n = Executable.objects.create(name=login,
				t_min_500=minimum,
				t_max_500=maximum,
				t_avg_500=avg)
	n.save()
	return (n)

'''
load database model
'''
def load_db(login, results):
	if results != None:
		avg = int(sum(results) / len(results))
		minimum = min(results)
		maximum = max(results)
		print("Min:{}\nMax:{}\nAvg:{}".format(minimum, maximum, avg))
		n = create_entry(login, minimum, maximum, avg)
	else:
		print("\033[91mFailed checker\033[0m")
		n = create_entry(login, -1, -1, -1)

	return (n)

'''
Prints statistical data of a list
'''
def describe_ps(results):
	print ("Mean:{}".format(numpy.mean(results)))
	print ("Std:{}".format(numpy.std(results)))
	print ("Max:{}".format(numpy.max(results)))
	print ("Min:{}".format(numpy.min(results)))
