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
