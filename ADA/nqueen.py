def is_safe(board, row, col):
    # Check if there is a queen in the same row on the left
    for i in range(col):
        if board[row][i] == 1:
            return False

    # Check upper diagonal on the left
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    # Check lower diagonal on the left
    for i, j in zip(range(row, len(board), 1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    return True

def solve_n_queens_util(board, col):
    if col >= len(board):
        return True

    for i in range(len(board)):
        if is_safe(board, i, col):
            board[i][col] = 1

            # Menampilkan papan setiap kali ratu ditambahkan
            print_board(board, col)
            print("\n-----------------\n")

            if solve_n_queens_util(board, col + 1):
                return True

            board[i][col] = 0  # Backtrack

    return False

def solve_n_queens(n):
    board = [[0 for _ in range(n)] for _ in range(n)]

    if not solve_n_queens_util(board, 0):
        print("Solution does not exist")
        return

def print_board(board, col):
    print(f"Langkah ke - {col + 2}")
    for row in board:
        print(" ".join("Q" if cell == 1 else "." for cell in row))

# Example: Solve 8-Queen Problem
solve_n_queens(8)
