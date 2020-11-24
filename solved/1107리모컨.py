N = int(input())
M = int(input())
list_disable = []
if M > 0:
    list_disable = map(int, input().split())
is_enable = [True] * 10

for i, x in enumerate(list_disable):
    is_enable[x] = False

min_val = float('inf')
for num in range(1000001):
    term = abs(N - 100)

    can_make_flag = True
    s = str(num)
    for c in s:
        if not is_enable[ord(c) - ord('0')]:
            can_make_flag = False
            break
    
    if can_make_flag:
        term = min(term, len(s) + abs(N - num))
    
    if term < min_val:
        min_val = term

print(min_val)