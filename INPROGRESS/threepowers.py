while True:
    n = int(input())
    if n==0:
        break
    n = n-1
    vals = []
    for i in range(64):
        if (1<<i)&n:
            vals.append(int(pow(3,i)))
    print("{ ",end='')

    for i in range(len(vals)):
        if i == len(vals)-1:
            print(str(vals[i]),end='')
        else:
            print(str(vals[i])+", ",end='')
    print(" }")

            
