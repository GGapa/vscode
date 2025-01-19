N, M = map(int, input().split())
P = list(map(int, input().split()))
def f (a):
    res = 0
    C = 0
    for p in P:
        tmp = a // p
        tmp += 1
        tmp //= 2
        res += tmp * tmp * p
        C += tmp
    return (res, C)
L = 0; R = 10 ** 15
while R - L > 1:
    mid = (L + R) // 2
    if f(mid)[0] < M:
        L = mid
    else:
        R = mid
print(f(L)[1] + (M - f(L)[0]) // R)