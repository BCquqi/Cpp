def do(x):
    flag = False
    counter = 0
    print('%d=' % x, end='')
    if x % 2 == 0:
        flag = True
        while x % 2 == 0:
            counter += 1
            x //= 2
        if counter == 1:
            print(2, end='')
        else:
            print('2^%d' % counter, end='')
    for i in range(3, x+1, 2):
        if i > x:
            break
        if x % i == 0:
            if flag:
                print('*', end='')
            flag = True
            counter = 0
            while x % i == 0:
                counter += 1
                x //= i
            if counter == 1:
                print(i, end='')
            else:
                print('%d^%d' % (i, counter), end='')


n = int(input())
do(n)
