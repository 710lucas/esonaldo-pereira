import sys
from ednaldo import *

my_file = []

with open(sys.argv[1], 'r') as my_file:
    my_file = my_file.read()
    my_file = my_file.split('\n')

for i in my_file:
    # print(i)
    start(i)
