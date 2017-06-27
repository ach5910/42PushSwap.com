from run_tests import Test_500
from run_tests import get_results
import unittest

suite = unittest.TestSuite()
for method in dir(Test_500):
	if method.startswith("test_"):
		suite.addTest(Test_500(method))
unittest.TextTestRunner().run(suite)
results = get_results()
print(results)