import json, requests

URL = "https://api.androidhive.info/contacts/"

data = requests.get(URL).json()

a = [1] * 6
b = []

print(a)
print(b)

# print(type(data))
# print(data)

# json_data = json.dumps(data)

# print(type(json_data))