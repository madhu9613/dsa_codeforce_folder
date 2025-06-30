t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    a = [list(map(int, input().split())) for _ in range(n)]

    max_val = -1
    max_positions = []

    for i in range(n):
        for j in range(m):
            if a[i][j] > max_val:
                max_val = a[i][j]
                max_positions = [(i, j)]
            elif a[i][j] == max_val:
                max_positions.append((i, j))

    # Try each (r, c) where max element is present
    min_max_after = float('inf')

    for r, c in max_positions:
        b = [[a[i][j] for j in range(m)] for i in range(n)]

        for i in range(n):
            b[i][c] -= 1
        for j in range(m):
            b[r][j] -= 1
        b[r][c] += 1  # because it was subtracted twice

        current_max = max(max(row) for row in b)
        min_max_after = min(min_max_after, current_max)

    print(min_max_after)
