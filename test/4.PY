t = int(input())
for _ in range(t):
    n = int(input())
    ops = []

    for i in range(2, n+1):
        if i - 1 >= 2:
            ops.append((i, 1, i-1))  # reverse first i-1 elements
        if n - i + 1 >= 2:
            ops.append((i, i, n))    # reverse last n - i + 1 elements
        ops.append((i, 1, n))        # final full reverse

    # Now ensure total ops <= 2n
    # If length exceeds, we truncate
    if len(ops) > 2 * n:
        ops = ops[:2 * n]

    print(len(ops))
    for op in ops:
        i, l, r = op
        if l != r:  # skip no-op
            print(i, l, r)
