t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    # you can do either:
    print('1' * k + '0' * (n - k))
    # or:
    # print('0' * (n - k) + '1' * k)
