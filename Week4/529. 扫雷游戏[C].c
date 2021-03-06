//DFS
void findadj(char*** board, int boardSize, int boardColSize, int row, int col);
int haveMines(char*** board, int boardSize, int boardColSize, int row, int col);

char** updateBoard(char** board, int boardSize, int* boardColSize, int* click, int clickSize, int* returnSize, int** returnColumnSizes){
    *returnSize = boardSize;
    (*returnColumnSizes) = malloc(sizeof(int) * boardSize);
    for (int i = 0; i < boardSize; i++){
        (*returnColumnSizes)[i] = boardColSize[i];
    }
    int row, col;
    row = click[0];
    col = click[1];
    if (board[row][col] == 'M'){
        board[row][col] = 'X';
        return board;
    }
    findadj(&board, boardSize, boardColSize[0], row, col);
    return board;
}

void findadj(char*** board, int boardSize, int boardColSize, int row, int col){
    if (row < 0 || col < 0 || row >= boardSize || col >= boardColSize)
        return;
    //printf("row = %d, col = %d\n", row, col);
    if ((*board)[row][col] != 'M' && (*board)[row][col] != 'E'){
        return;
    }
    (*board)[row][col] = 'B';
    int num = 0;
    num += haveMines(board, boardSize, boardColSize, row - 1, col);
    num += haveMines(board, boardSize, boardColSize, row + 1, col);
    num += haveMines(board, boardSize, boardColSize, row, col - 1);
    num += haveMines(board, boardSize, boardColSize, row, col + 1);
    num += haveMines(board, boardSize, boardColSize, row - 1, col - 1);
    num += haveMines(board, boardSize, boardColSize, row - 1, col + 1);
    num += haveMines(board, boardSize, boardColSize, row + 1, col - 1);
    num += haveMines(board, boardSize, boardColSize, row + 1, col + 1);
    if (num != 0){
        (*board)[row][col] = num + '0';
        return;
    }
    findadj(board, boardSize, boardColSize, row - 1, col);
    findadj(board, boardSize, boardColSize, row + 1, col);
    findadj(board, boardSize, boardColSize, row, col - 1);
    findadj(board, boardSize, boardColSize, row, col + 1);
    findadj(board, boardSize, boardColSize, row - 1, col - 1);
    findadj(board, boardSize, boardColSize, row - 1, col + 1);
    findadj(board, boardSize, boardColSize, row + 1, col - 1);
    findadj(board, boardSize, boardColSize, row + 1, col + 1);
    return;
}

int haveMines(char*** board, int boardSize, int boardColSize, int row, int col){
    if (row < 0 || col < 0 || row >= boardSize || col >= boardColSize)
        return 0;
    if ((*board)[row][col] == 'M'){
        return 1;
    }
    return 0;
}