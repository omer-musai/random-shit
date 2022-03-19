import random

def currentLocation(board):
    parities = [0] * 6
    for i in range(8):
        parities[0] += (board[i][1] + board[i][3] + board[i][5] + board[i][7])
        parities[1] += (board[i][2] + board[i][3] + board[i][6] + board[i][7])
        parities[2] += (board[i][4] + board[i][5] + board[i][6] + board[i][7])
        parities[3] += (board[1][i] + board[3][i] + board[5][i] + board[7][i])
        parities[4] += (board[2][i] + board[3][i] + board[6][i] + board[7][i])
        parities[5] += (board[4][i] + board[5][i] + board[6][i] + board[7][i])
    return (''.join([str(p % 2) for p in parities]))


def findTileToFlip():
    parities_to_flip = [0] * 6
    board = [[random.randint(0, 1) for i in range(8)] for j in range(8)]
    print('Board:')
    for l in board:
        print(l)
    key_loc = int(input('Choose key location: '))
    curr_loc = currentLocation(board)
    bin_key = str(bin(key_loc))[2:]
    while len(bin_key) < 6:
        bin_key = '0' + bin_key

    for i in range(len(curr_loc)):
        if bin_key[i] != curr_loc[i]:
            parities_to_flip[i] = 1
    print('Tile to flip: ' + str(findTile(parities_to_flip))    )

def findTile(parities_to_flip):
    board = [[i + (8*j) for i in range(8)] for j in range(8)]
    rows = set([i for i in range(8)])
    columns = set([i for i in range(8)])

    for index, parity in enumerate(parities_to_flip):
        if parity == 1:
            if index == 0:
                rows = rows.intersection({1, 3, 5, 7})
            if index == 1:
                rows = rows.intersection({2, 3, 6, 7})
            if index == 2:
                rows = rows.intersection({4, 5, 6, 7})
            if index == 3:
                columns = columns.intersection({1, 2, 5, 7})
            if index == 4:
                columns = columns.intersection({2, 3, 6, 7})
            if index == 5:
                columns = columns.intersection({4, 5, 6, 7})
    rows = list(rows)
    columns = list(columns)
    return board[rows[0]][columns[0]]


findTileToFlip()




