import math

def GCD(a, b):
    while b:
        OldA = a
        a = b
        b = OldA % b
    return a

def LCM(a, b):
    return (a // GCD(a, b)) * b

N, M = list(map(int, input().split()))
a = list(map(int, input().split()))

L = 2
for i in range(N):
    L = LCM(L, a[i])

inf = math.ceil((2 - L) / (2 * L))
sup = math.floor((2*M - L) / (2 * L))

res = max(sup - inf + 1, 0)

print(res)
