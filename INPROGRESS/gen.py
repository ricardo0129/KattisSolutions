f = open("in", "w")
f.write("100 2\n")
n = int(input())
for i in range(2):
    for j in range(n):
        f.write("a ")
    if i == 0:
        f.write("a? a\n")
    else:
        f.write("b? b\n")

