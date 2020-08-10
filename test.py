a = [False for i in range(42)]


for i in range(10):
    b = int(input())
    a[b % 42] = True

cnt = 0
for i in range(42):
    if a[i] == True:
        cnt += 1
print(cnt)