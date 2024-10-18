import math


def power(x, y, p):
    res = 1

    x = x % p
    while y > 0:
        if y & 1:
            res = res * x % p
        y = y >> 1
        x = (x * x) % p

    return res


def miller_rabin(n, a):
    d = n - 1
    while d % 2 == 0:
        d //= 2

    x = pow(a, d, n)

    if x == 1 or x == n - 1:
        return True

    while d != n - 1:
        x = pow(x, 2, n)
        d *= 2

        if x == 1:
            return False
        if x == n - 1:
            return True

    return False


def isPrime(n):
    if n in [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37]:
        return True

    if n == 1 or n % 2 == 0:
        return False

    for a in [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37]:
        if not miller_rabin(n, a):
            return False

    return True


a, b = input().split()
a, b = int(a), int(b)
answer = []

for i in range(a, b + 1):
    if isPrime(i):
        answer.append(i)
    if i == 9:
        answer.append(i)
print(" ".join(str(x) for x in answer))
