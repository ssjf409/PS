
symbols = "{"
for i in range(101):
    a = input()
    symbols += '"' + a + '", '

a = input()
symbols += '"' + a + '"}'


print(symbols)