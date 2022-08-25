import sys
def catalan(n):
    dp = [1]
    for i in range(1,n+1):
        top = dp[-1]*(2*i-1)*(2*i)
        bot = (i+1)*i
        dp.append(top//bot)
    return dp



lines = int(sys.stdin.readline().strip())
dp = catalan(5000)
for n in sys.stdin:
    print(dp[int(n.strip())])
