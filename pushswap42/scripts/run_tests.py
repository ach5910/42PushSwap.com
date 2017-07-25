#!/usr/bin/python
import os
from subprocess import Popen, PIPE, STDOUT
import unittest

results = []
class Test_500(unittest.TestCase):
	def test_1_0(self):
		proc = Popen('./repo/push_swap/push_swap $(< test1.tst)', shell=True, stdout=PIPE)
		re = proc.stdout.read()
		out = re.split("\n")
		f = open('./results/result1.txt', 'w')
		f.write(re[:])
		results.append((len(out) - 1))
		f.close()

	def test_1_1(self):
		proc = Popen('cat ./results/result1.txt | ./repo/push_swap/checker $(< test1.tst)', shell=True, stdout=PIPE)
		re = proc.stdout.read()
		self.assertEqual("OK\n", re)

	def test_2_0(self):
		proc = Popen('./repo/push_swap/push_swap $(< test2.tst)', shell=True, stdout=PIPE)
		re = proc.stdout.read()
		out = re.split("\n")
		f = open('./results/result2.txt', 'w')
		f.write(re[:])
		results.append((len(out) - 1))
		f.close()

	def test_2_1(self):
		proc = Popen('cat ./results/result2.txt | ./repo/push_swap/checker $(< test2.tst)', shell=True, stdout=PIPE)
		re = proc.stdout.read()
		self.assertEqual("OK\n", re)

	def test_3_0(self):
		proc = Popen('./repo/push_swap/push_swap $(< test3.tst)', shell=True, stdout=PIPE)
		re = proc.stdout.read()
		out = re.split("\n")
		f = open('./results/result3.txt', 'w')
		f.write(re[:])
		results.append((len(out) - 1))
		f.close()

	def test_3_1(self):
		proc = Popen('cat ./results/result3.txt | ./repo/push_swap/checker $(< test3.tst)', shell=True, stdout=PIPE)
		re = proc.stdout.read()
		self.assertEqual("OK\n", re)

	def test_4_0(self):
		proc = Popen('./repo/push_swap/push_swap $(< test4.tst)', shell=True, stdout=PIPE)
		re = proc.stdout.read()
		out = re.split("\n")
		f = open('./results/result4.txt', 'w')
		f.write(re[:])
		results.append((len(out) - 1))
		f.close()

	def test_4_1(self):
		proc = Popen('cat ./results/result4.txt | ./repo/push_swap/checker $(< test4.tst)', shell=True, stdout=PIPE)
		re = proc.stdout.read()
		self.assertEqual("OK\n", re)

	def test_5_0(self):
		proc = Popen('./repo/push_swap/push_swap $(< test5.tst)', shell=True, stdout=PIPE)
		re = proc.stdout.read()
		out = re.split("\n")
		f = open('./results/result5.txt', 'w')
		f.write(re[:])
		results.append((len(out) - 1))
		f.close()

	def test_5_1(self):
		proc = Popen('cat ./results/result5.txt | ./repo/push_swap/checker $(< test5.tst)', shell=True, stdout=PIPE)
		re = proc.stdout.read()
		self.assertEqual("OK\n", re)

	def complete(self):
		return results


if __name__ == '__main__':
	suite = unittest.TestSuite()
	for method in dir(Test_500):
		if method.startswith("test"):
			suite.addTest(Test_500(method))
	unittest.TextTestRunner().run(suite)

def init_results():
	results[:] = []

def get_results():
	return results
