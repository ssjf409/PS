import json, requests

URL = "https://api.androidhive.info/contacts/"

data = requests.get(URL).json()

print(data["contacts"][0]["id"])

# print(type(data))
# print(data)

# json_data = json.dumps(data)

# print(type(json_data))