
a, b = map(float, input().split())

c = 299792458
ans = (a + b) / (1 + (a * b) / (c ** 2))
print(ans)
