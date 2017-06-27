import  os.path
from    django.conf     import settings

settings.configure()
if os.path.isfile('./repo/author'):
    f = open('./repo/author', 'r')
    author = f.read()
    f.close()
    print(author)
if os.path.isfile('./repo/Makefile'):
    f = open('./repo/Makefile', 'r')
    for i in range(5):
        f.readline()
    line = list(f.readline().strip().split(' '))
    line = filter(lambda x: x != '', line)
    author = line[2]
    print(author)    
    
    