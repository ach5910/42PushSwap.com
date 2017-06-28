import os
from subprocess import check_output, PIPE
import numpy
import random

#Creates a random list of numbers
def create_arg_list(arg_count):
	arg_list = []
	arg_str = ""
	rand = 0
	for i in range(arg_count):
		while (rand in arg_list):
			rand = random.randint(0, arg_count * 100)
		arg_list.append(rand)
		arg_str = arg_str + str(rand) + " "
	return (arg_str)

#Takes a path to the push swap program and a string of numbers
#Returns the number of operations required to sort the list
def run_ps(path, args):
	out = check_output("{}/push_swap {}".format(path, args), shell=True)
	check = check_output("echo '{}' | {}/checker {}".format(out, path, args), shell=True)
	if (check == "OK\n"):
		op_count = len(out.split("\n")) - 1
	else:
		op_count = None
	return (op_count)

#Runs push_swap function with random arguments 'n' times
def loop_ps(path, arg_count, n):
	result = []
	for i in range(0, n):
		args = create_arg_list(arg_count)
		op_count = run_ps(path, args)
		if (op_count == None):
			return (None)
		result.append(op_count)
	return (result)

#Crawls through a test_directory and runs push_swap test on each file
def read_tests(ps_path, test_dir):
	result = []
	for test in os.listdir(test_dir):
		f = open(test, 'r')
		args = f.read()
		f.close()
		op_count = run_ps(path, args)
		if (op_count == None):
			return (None)
		result.append(op_count)
	return (result)

#Prints statistical data of a list
def describe_ps(results):
	print ("Mean:{}".format(numpy.mean(results)))
	print ("Std:{}".format(numpy.std(results)))
	print ("Max:{}".format(numpy.max(results)))
	print ("Min:{}".format(numpy.min(results)))

#TODO: create a function to retreive the path of the push_swap executable
