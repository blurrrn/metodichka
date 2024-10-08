a = [0, 1, 2, 3] #лагранж
b = [10, 11, 18, 37]
ans = 0
x = float(input())
p = 1
for i in range(4):
    for j in range(4):
        if i != j:
            p *= (x-a[j])
            p /= (a[i] - a[j])
    ans += b[i] * p
    p = 1
print ans

# NEWTON
# вычисляет коэф-ты разделенных разностей
def divided_diff(x, y):
    n = len(y)
    coef = [0] * n
    coef[:] = y

    print("Исходные значения:")
    print(coef)

    for j in range(1, n):
        for i in range(n-1, j-1, -1):
            coef[i] = (coef[i] - coef[i-1]) / (x[i] - x[i-j])

        print(f"Промежуточные значения после {j}-го шага")
        print (coef)
    return coef

# используем их для вычисления значения ф-ции в аданной т
def newton_interpolation(x, y, x_val):
    coef = divided_diff(x, y)
    n = len(x)
    result = coef[n-1]

    for i in range(n-2, -1, -1):
        result = result * (x_val - x[i]) + coef[i]
    return result

# 10 variant
a = [0, 1, 2, 3]
b = [10, 11, 18, 37]
res = float(input('Введите x: '))

result = newton_interpolation(a, b, res)
print('Для x равному', str(res) + ', значение функции: ' + str(result))
