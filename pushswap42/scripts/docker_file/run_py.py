import sys
import os
from subprocess import call, PIPE, Popen
import shlex


clone_dir = 'push_swap'
mount_dir = 'mount_dir'
results = mount_dir + '/results.txt'




def make_ps():
	make_f = open("./mount_dir/make_error.txt", "w+")
	call(["make", "re", "-C", "./push_swap"], stderr=make_f)
	make_f.close
	if os.path.isfile("./push_swap/push_swap"):
		print("compiling successful")
		return (0)
	else:
		print("compiling unsuccessful")
		return (-1)


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
	ch_args = shlex.split("../checker " + args)
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
Prints statistical data of a list
'''
def describe_ps(results):
	rez = open( "./mount_dir/results.txt", "w+")
	rez.write( ("Mean:{}".format((sum(results))/len(results))) + "\n" 
		+ ("Max:{}".format(max(results))) + "\n"
		+ ("Min:{}".format(min(results))) + "\n")

make_ps()
results = read_tests("./push_swap", "test_500") 
describe_ps(results)
