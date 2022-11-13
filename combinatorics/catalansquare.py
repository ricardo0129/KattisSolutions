n = int(input())
n = n+1
fact = [0]*(2*n+10)
fact[0] = 1
for i in range(1,2*n+10):
    fact[i] = fact[i-1]*i
catalan = fact[2*n]//(fact[n+1]*fact[n])
print(catalan)
