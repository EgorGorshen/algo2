def floyd(matr):
    n = len(matr)
    for i in range(n):
        for j in range(n):
            for k in range(n):
                matr[i][j] = min(matr[i][j], matr[i][k] + matr[k][j])


n = int(input())
matr = []
for i in range(n):
    row = list(map(int, input().split()))
    matr.append(row)

print("Исходная матрица:")
for row in matr:
    print(*row)

floyd(matr)

print("Матрица кратчайших расстояний")
for row in matr:
    print(*row)
