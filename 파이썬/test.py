import json, requests

x_auth_token = "d6322e0a32e839c73749156ce465383c"
url = "https://pegkq2svv6.execute-api.ap-northeast-2.amazonaws.com/prod/users"

map_size = 60
truck_num = 10

def start(problem_id):
    uri = url + "/start"
    # header = {"X-Auth-Token":x_auth_token, 'Content-Type' : 'application/json'}
    header = {"X-Auth-Token":x_auth_token}
    datas = {"problem": problem_id}
    res = requests.post(uri, headers=header, data = datas).json()
    return res

def location_api(auth_key):
    uri = url + "/locations"
    header = {"Authorization" : auth_key}
    res = requests.get(uri, headers=header).json()
    return res

def trucks_api(auth_key):
    uri = url + "/trucks"
    header = {"Authorization" : auth_key}
    res = requests.get(uri, headers=header).json()
    return res

def simulate_api(auth_key, command):
    uri = url + "/simulate"
    datas = json.dumps({"commands" : command})
    header = {"Authorization" : auth_key}
    res = requests.put(uri, headers = header, data = datas).json()
    return res

def score_api(auth_key):
    uri = url + "/score"
    header = {"Authorization" : auth_key}
    res = requests.get(uri, headers=header).json()
    return res

def get_dist(a, b):
    y1 = a // map_size
    x1 = a % map_size
    y2 = b // map_size
    x2 = b % map_size
    return abs(y1 - y2) + abs(x2 - x1)



class Truck():
    def __init__(self, id):
        self.id = id
        self.location = 0
        self.loaded_bike = 0
        self.command = []
        self.destination = 0
        self.hasJob = False
        self.isPickupJob = False




if __name__ == '__main__':
    start_ret = start(1)
    auth_key = start_ret['auth_key']

    trucks = [Truck(i) for i in range(truck_num)]
    location_api_ret = location_api(auth_key)
    bike_num = []
    bike_num_data = location_api_ret['locations']
    
    for i in range(len(bike_num_data)):
        bike_num.append(bike_num_data[i]['located_bikes_count'])

    for x in range(720):
        trucks_api_ret = trucks_api(auth_key)
        trucks_data = trucks_api_ret['trucks']
        for i in range(len(trucks_data)):
            trucks[i].loaded_bike = trucks_data[i]['loaded_bikes_count']

        for case in range(10):
            bike_num_avg = 0
            for i in range(len(bike_num_data)):
                bike_num_avg += bike_num_data[i]['located_bikes_count']

            bike_num_avg = bike_num_avg / (map_size * map_size)




            # 알고리즘 시작
            for cur in range(len(bike_num)):
                cur_bike_num = bike_num[cur]
                if cur_bike_num < bike_num_avg:
                    index = 0
                    dist = float('inf')
                    for idx, truck in enumerate(trucks):
                        if truck.loaded_bike == 0 or truck.hasJob: continue
                        temp_dist = get_dist(cur, truck.location)
                        if temp_dist < dist:
                            dist = temp_dist
                            index = idx
                    truck[index].hasJob = True
                    truck[index].destination = cur
                    truck[index].isPickupJob = True
                elif cur_bike_num > bike_num_avg:
                    index = 0
                    dist = float('inf')
                    for idx, truck in enumerate(trucks):
                        if truck.loaded_bike == 20 or truck.hasJob: continue
                        temp_dist = get_dist(cur, truck.location)
                        if temp_dist < dist:
                            dist = temp_dist
                            index = idx
                    truck[index].hasJob = True
                    truck[index].destination = cur
                    truck[index].isPickupJob = False

            
            for j, truck in enumerate(trucks):
                if truck.hasJob :
                    if truck.location == truck.destination:
                        truck.hasJob = False
                        if truck.isPickupJob:
                            # 상차
                            truck.loaded_bike += 1
                            bike_num[truck.location] -= 1
                            truck.command.append(5)
                        else:
                            # 하차
                            truck.loaded_bike -= 1
                            bike_num[truck.location] += 1
                            truck.command.append(6)
                    else:
                        y1 = truck.destination // map_size
                        x1 = truck.destination % map_size
                        y2 = truck.loaction // map_size
                        x2 = truck.loaction % map_size
                        if y1 == y2:
                            if x1 - x2 > 0:
                                # 아래 
                                truck.command.append(3)
                            else:
                                # 위
                                truck.command.append(1)
                        else:
                            if y1 > y2:
                                # 왼쪽
                                truck.command.append(4)
                            else:
                                truck.command.append(2)
                else:
                    truck.command.append(0)
                    truck.hasJob = False

        truck_command = []

        for i, truck in enumerate(trucks):
            truck_command.append({"truck_id" : i, "command" : truck.command})

        # a = json.dumps(truck_command)
        # print(a)

        # 답 내기
        simulate_api_ret = simulate_api(auth_key, truck_command)
        print(simulate_api_ret)

