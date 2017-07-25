import docker
import sys
import os
import shutil

client = docker.from_env()
container_nm = "running"
image_nm = "zsmith32/run_ps"
root_dir = "/home/zsmith/pushswap42/pushswap42/scripts/docker_file/"
mount_dir = root_dir + "mount_dir/"


"""
create files that I want to mount inside the docker, and that I will delete after each run
"""
def run_container():
	try:
		make_error = open(mount_dir + "make_error.txt", "w+")
		make_error.close()
	except IOError as e:
		print "IOError caught"
		print e.errno
		print e.strerror
	result_file = open(mount_dir + "results.txt", "w+")
	result_file.close()

	"""
	build docker image that includes user's push_swap
	"""
#	print "root_dir = " + root_dir
	client.images.build(path=root_dir, tag=image_nm)

	"""
	run docker container that will test user's push_swap
	"""
	container = client.containers.run(image_nm, name=container_nm, remove=True, volumes={root_dir : {"bind" : "/app", "mode": "rw"}})


"""
save data to data base
"""

"""
remove Makefile log && remove
"""
run_container()
