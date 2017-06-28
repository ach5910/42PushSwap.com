import os
from subprocess import check_output, PIPE
from pushswap42.models import Executable
import numpy


'''
Takes a path to the push swap program and a string of numbers
Returns the number of operations required to sort the list
'''
def run_ps(path, args):
	out = check_output("{}/push_swap {}".format(path, args), shell=True)
	check = check_output("echo '{}' | {}/checker {}".format(out, path, args), shell=True)
	if (check == "OK\n"):
		op_count = len(out.split("\n")) - 1
	else:
		op_count = None
	return (op_count)

#Crawls through a test_directory and runs push_swap test on each file
def read_tests(ps_path, test_dir):
	result = []
	print ("\n\033[92mRead_tests\033[0m")
	for test in os.listdir(test_dir):
		if test.startswith("test"):
			print (test)
			f = open(test_dir + "/" + test, 'r')
			args = f.read()
			f.close()
			op_count = run_ps(ps_path, args)
			if (op_count == None):
				return (None)
			result.append(op_count)
	return (result)

#load database model
def load_db(login, results):
	avg = int(sum(results) / len(results))
	minimum = min(results)
	maximum = max(results)
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
	print("Min:{}\nMax:{}\nAvg:{}".format(minimum, maximum, avg))
	n.save()
	return (n)

#Prints statistical data of a list
def describe_ps(results):
	print ("Mean:{}".format(numpy.mean(results)))
	print ("Std:{}".format(numpy.std(results)))
	print ("Max:{}".format(numpy.max(results)))
	print ("Min:{}".format(numpy.min(results)))

#TODO: create a function to retreive the path of the push_swap executable
