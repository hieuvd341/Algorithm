def main():
    rows, cols = (9, 9)
    count = [0]
    board = [[0 for _ in range(cols)] for _ in range(rows)]

    for i in range(rows):
        line = input()
        tmp_arr = line.split()
        for j in range(cols):
            board[i][j] = int(tmp_arr[j])
    
    def isValid(row, col, check):
        for i in range(9):
            if board[row][i] == check or board[i][col] == check:
                return False
            if board[3 * (row // 3) + i // 3][3 * (col // 3) + i % 3] == check:
                return False
        return True

    def solve(row, col):
        if row == 8 and col == 9:
            print(board)
            for i in range (0, 9):
                for j in range (0,9):
                    print(board[i][j], end=" ")
                print("\n")
            count[0] += 1
            return
        
        if col == 9:
            solve(row + 1, 0)
            return
        
        if board[row][col] == 0:
            for num in range(1, 10):
                if isValid(row, col, num):
                    board[row][col] = num
                    solve(row, col + 1)
                    board[row][col] = 0  
        else:
            solve(row, col + 1)

    solve(0, 0)
    print(count[0])

if __name__ == "__main__":
    main()
