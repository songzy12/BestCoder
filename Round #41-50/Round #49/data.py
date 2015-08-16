import sys
from random import randint
sys.stdout = open('out.txt', 'w')

s = ''
for i in range(20000):
    s += chr(ord('a') + randint(1, 100) % 26)
print s
