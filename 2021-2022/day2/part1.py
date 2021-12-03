def calcPos(pos, move):

    moves = move.split(" ")
    dir = moves[0]
    steps = int(moves[1])

    if dir == 'forward':
        pos = [pos[0]+steps, pos[1]]
    
    elif dir == 'down':
        pos = [pos[0], pos[1]+steps]

    elif dir == 'up':
        pos = [pos[0], pos[1]-steps]
    
    return pos



def computeFile():

    pos = [0,0]
    file = open("day2.txt", "r")

    for line in file:
        pos = calcPos(pos, line)
    
    print("Horizontal position: " + str(pos[0]) + \
          "\nDepth: " + str(pos[1]) + \
          "\nRes: " + str(pos[0]*pos[1]))





if __name__ == '__main__':
    computeFile()
