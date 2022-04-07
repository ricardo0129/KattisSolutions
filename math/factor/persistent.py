while True:
    n = int(input())
    if(n==-1):
        break

    if(n>=0 and n<=9):
        print("1"+str(n))
    else:
        ans = ""
        for i in reversed(range(2,10)):
            while(n%i==0):
                ans+=str(i)
                n = n//i
        if(n!=1):
            print("There is no such number.")
        else:
            print(ans[::-1])

