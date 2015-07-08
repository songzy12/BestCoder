from random import randint

f = open('in.txt', 'w')
f.write('3000\n')
for i in range(3000):
    f.write(str(i) + ' ' + str(randint(0, 10000))+'\n')
f.write('3000\n')
for i in range(3000):
    l = randint(1,1500)
    r = randint(1,1500)
    f.write(str(l)+' '+str(l+r)+' '+str(randint(0, 10000))+'\n')
f.close()
