def I(): return int(input())
def TI(): return tuple(map(int, input().split()))

n = I()
xy = [TI() for _ in range(n)]
set_xy = set(xy)
res = 0
for i in range(n):
    x1, y1 = xy[i]
    for j in range(i + 1, n):
        x2, y2 = xy[j]
        vec_x, vec_y = x2 - x1, y2 - y1
        if ((-vec_y + x1, vec_x + y1) in set_xy) and ((-vec_y + x2, vec_x + y2) in set_xy):
            res = max(res, vec_x**2 + vec_y**2)
print(res)
