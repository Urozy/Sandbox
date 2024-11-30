#include "Gamefield.h"

vector<vector<int>> Gamefield::getBoard() {
    return board;
}


void Gamefield::setBoard(vector<vector<int>> newBoard) {
    board = newBoard;
}



void Gamefield::createBoard() {
    board = vector<vector<int>>(4, vector<int>(4, '='));
    cout << "Игра началась\n" << endl;
}

void Gamefield::fillBoardRandomly() {
    vector<int> numbers(16);
    iota(numbers.begin(), numbers.end(), 0);

    random_device rd;
    mt19937 gen(rd());
    shuffle(numbers.begin(), numbers.end(), gen);

    int count = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            board[i][j] = numbers[count++];
        }
    }
}

void Gamefield::printBoard() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void Gamefield::SymbolSwap(vector<vector<int>>& array, int row1, int col1, int row2, int col2) {
    if (row1 < 0 || row1 >= 4 || col1 < 0 || col1 >= 4
        || row2 < 0 || row2 >= 4 || col2 < 0 || col2 >= 4) {
        cout << "\n" << "Похоже вы вышли за рамки игрового поля, попробуйте еще раз\n" << endl;

    }
    else {
        int temp_cell = array[row1][col1];
        array[row1][col1] = array[row2][col2];
        array[row2][col2] = temp_cell;
    }
}

void Gamefield::GameProcess() {

    vector<vector<int>>massive = { {1,2,3,4},
                                   {5,6,7,8},
                                   {9,10,11,12},
                                   {13,14,15,0} };

    while (board != massive) {

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {

                if (board[i][j] == 0) {
                    int d;
                    cout << "Выберете--1 если хотите передвинуть число снизу на пустое место\n"
                        << "Выберете--2 если хотите передвинуть число сверху на пустое место\n"
                        << "Выберете--3 если хотите передвинуть число справа на пустое место\n"
                        << "Выберете--4 если хотите передвинуть число слево на пустое место\n"
                        << "\n" << endl;
                    cin >> d;
                    switch (d) {
                    case 1:
                        SymbolSwap(board, i + 1, j, i, j);
                        cout << endl;
                        printBoard();
                        break;
                    case 2:
                        SymbolSwap(board, i, j, i - 1, j);
                        cout << endl;
                        printBoard();
                        break;
                    case 3:
                        SymbolSwap(board, i, j + 1, i, j);
                        cout << endl;
                        printBoard();
                        break;
                    case 4:
                        SymbolSwap(board, i, j, i, j - 1);
                        cout << endl;
                        printBoard();
                        break;
                    default:
                        cout << "Некорректный ввод" << endl;
                        break;
                    }
                }
            }
        }

    }
    cout << endl;
    cout << "Пазл собран" << endl;
};




