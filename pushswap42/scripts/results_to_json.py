import json

'''
Prints results to a json file
'''

def results_to_json(results):
	with open("results.json", 'w+') as output:
		if results != None:
			avg = int(sum(results) / len(results))
			minimum = min(results)
			maximum = max(results)
			dump = json.dump({"avg":avg, "min":minimum, "max":maximum}, output)
		else:
			dump = json.dump({"avg":-1, "min":-1, "max":-1}, output)
