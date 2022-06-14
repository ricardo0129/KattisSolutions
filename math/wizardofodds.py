import math
n,k = map(int,input().split())
if(k>=400):
    print("Your wish is granted!")
else:
    q = math.pow(2,k)
    if(q>=n):
        print("Your wish is granted!")
    else:
        print("You will become a flying monkey!")
