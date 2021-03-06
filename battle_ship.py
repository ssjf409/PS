from random import randint

players = {}
my_board = []
enemy_board = []
BOARD_ROW = 5
BOARD_COL = 5
# MAX_TRY = int(BOARD_ROW * BOARD_COL * 0.85)

def set_board(board):
    for x in range(0, BOARD_ROW):
        board.append(["O"] * BOARD_COL)

def set_ship(board, ship_isRow, ship_size, ship_row, ship_col):
    y = 0
    x = 0
    for i in range(ship_size):
        board[ship_row + y][ship_col + x] = '#'
        if ship_isRow:
            y += 1
        else:
            x += 1

def print_board(board, flag):
    for row in range(len(board)):
        for col in range(len(board[row])):
            if not flag and board[row][col] == '#':
                print('O', end=" ")
            else:
                print(board[row][col], end=" ")
        print()

def random_row(board, isRow, ship_size):
    if isRow:
        return randint(0, len(board) - ship_size)
    else:
        return randint(0, len(board) - 1)

def random_col(board, isRow, ship_size):
    if isRow:
        return randint(0, len(board[0]) - 1)
    else:
        return randint(0, len(board[0]) - ship_size)

def random_size():
    return randint(0, 2) + 1

def random_direct():
    a = randint(0, 1)
    if a == 0:
        return False
    else:
        return True


def add_player(players):
    new_player = input("플레이어의 이름을 알려주세요.")
    if new_player in players:
        print("이미 등록된 이름입니다. ")
        return
    else:
        players[new_player] = [0, 0]
        print(new_player + "님이 추가되었습니다.")

def show_players(players):
    # print(players)
    for player in players.keys():
        # print(players[player][0])
        print(player + " : " + str(players[player][0]) + "승, " + str(players[player][1]) + "패")
    print()

def show_game_boards(my_board, enemy_board, my_life, enemy_life):
    print("Enemy board")
    print_board(enemy_board, False)
    print("----------")
    # print_board(enemy_board, False)
    print("My board")
    print_board(my_board, True)
    print("My life : " + str(my_life) +", Enemy life : " + str(enemy_life))
    print()

def give_hint(y, x):
    for i in range(len(enemy_board)):
        if enemy_board[i][x] == '#':
            return True
    for j in range(len(enemy_board[0])):
        if enemy_board[y][j] == '#':
            return True
    return False

def player_turn(player):
    print(player + "'s Turn!")
    x = 0
    y = 0
    while True:
        try:
            x, y = [int(x) for x in input("Enter (x,y): ").split(',')]
            if x not in range(len(my_board)) or y not in range(len(my_board[0])):
                print("보드의 크기 안으로 입력해주세요.")
                continue
            break
        except:
            print("x, y 형태로 입력해주세요")
            continue

    if enemy_board[y][x] == '#':
        enemy_board[y][x] = '*'
        print("HiT!")
        return True
    elif enemy_board[y][x] == "X" or enemy_board[y][x] == "*":
        print("같은 곳을 포격하셨네요")
    else:
        enemy_board[y][x] = 'X'
        if(give_hint(y, x)):
            print("HINT : 같은 열 혹은 행에 적이 있습니다.")
    return False

def comptuer_turn():
    print("Computer's Turn!")
    y = 0
    x = 0
    hitted = False
    y_hit = False
    x_hit = False
    dy = [-1, 1, 0, 0]
    dx = [0, 0, -1, 1]


    for i in range(len(my_board)):
        for j in range(len(my_board[i])):
            if my_board[i][j] == '*':
                hitted = True
                y = i
                x = j
                break
        if hitted == True:
            break

    if hitted:
        for i in range(len(my_board)):
            if i != y and my_board[i][x] == '*':
                y_hit = True
                break
        for j in range(len(my_board[0])):
            if j != x and my_board[y][j] == '*':
                x_hit = True
                break
    if y_hit:
        for i in range(1, len(my_board)):
            if y + i < len(my_board) and (my_board[y + i][x] == 'O' or my_board[y + i][x] == '#'):
                y = y + i
                break
            elif y - i >= 0 and my_board[y - i][x] == 'O':
                y = y - i
                break
    elif x_hit:
        for i in range(1, len(my_board[0])):
            if x + i < len(my_board[0]) and (my_board[y][x + i] == 'O' or my_board[y][x + i] == '#'):
                x = x + i
                break
            elif x - i >= 0 and my_board[y][x - i] == 'O':
                x = x - i
                break
    elif hitted:
        for dir in range(4):
            ny = y + dy[dir]
            nx = x + dx[dir]
            if ny < 0 or ny >= len(my_board) or nx < 0 or nx >= len(my_board[0]):
                continue
            if my_board[ny][nx] == 'X' or my_board[ny][nx] == '*':
                continue
            if my_board[ny][nx] == 'O' or my_board[ny][nx] == '#':
                y = ny
                x = nx
                break
    else:
        while True:
            y = random_col(my_board, True, 1)
            x = random_row(my_board, True, 1)
            if my_board[y][x] == 'X' or my_board[y][x] == '*':
                continue
            else:
                break


    # hit check
    if my_board[y][x] == '#':
        my_board[y][x] = '*'
        return True
    else:
        my_board[y][x] = 'X'
    return False

def is_game_over(player, my_life, enemy_life):
    # 승리
    if enemy_life == 0:
        print(player + "님 승리하셨습니다.")
        players[player][0] = players[player][0] + 1
        return True
    # 패배
    elif my_life == 0:
        print(player + "님 패배하셨습니다.")
        players[player][1] = players[player][1] + 1
        return True
    return False


def play_game():
    player = ""
    while True:
        show_players(players)
        print("플레이어를 선택해주세요.")
        player = input()
        if not player in players:
            print("잘못 입력하셨습니다.")
            continue
        else:
            break

    # 게임 설정
    my_life = 0
    enemy_life = 0

    my_board.clear()
    enemy_board.clear()
    set_board(my_board)
    set_board(enemy_board)

    # 랜덤 내 위치
    ship_isRow = random_direct()
    ship_size = random_size()
    ship_row, ship_col = random_row(my_board, ship_isRow, ship_size), random_col(my_board, ship_isRow, ship_size)
    set_ship(my_board, ship_isRow, ship_size, ship_row, ship_col)

    my_life = ship_size

    # 랜덤 적 위치
    ship_isRow = random_direct()
    ship_size = random_size()
    ship_row, ship_col = random_row(enemy_board, ship_isRow, ship_size), random_col(enemy_board, ship_isRow, ship_size)
    set_ship(enemy_board, ship_isRow, ship_size, ship_row, ship_col)

    enemy_life = ship_size


    # 게임 시작

    show_game_boards(my_board, enemy_board, my_life, enemy_life)


    while True:
        #My Turn
        if(player_turn(player)):
            enemy_life = enemy_life - 1
        show_game_boards(my_board, enemy_board, my_life, enemy_life)

        if is_game_over(player, my_life, enemy_life):
            break

        #computer_turn
        if(comptuer_turn()):
            my_life = my_life - 1
        show_game_boards(my_board, enemy_board, my_life, enemy_life)
        if is_game_over(player, my_life, enemy_life):
            break




print("################################")
print("   Welcome To Battleship game   ")
print("################################")

while True:
    if len(players) == 0:
        new_player = input("플레이어의 이름을 알려주세요.")
        players = {new_player : [0, 0]}
    else:
        print("      Menu      ")
        print("1. 플레이어 추가")
        print("2. 플레이어 전적")
        print("3. 게임 시작")
        print("4. 종 료")

        cmd = int(input("메뉴를 선택해주세요."))
        if cmd < 0 or cmd > 4:
            continue
        else:
            if cmd == 1:
                add_player(players)
            elif cmd == 2:
                show_players(players)
            elif cmd == 3:
                play_game()
            elif cmd == 4:
                print("게임이 종료됩니다.")
                break


