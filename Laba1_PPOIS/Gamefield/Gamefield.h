#pragma once

#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <numeric>



using namespace std;

class Gamefield
{
private:
    int numberofcells;
    vector<vector<int>> board;
public:
    vector<vector<int>> getBoard();
    void setBoard(vector<vector<int>> newBoard);
    void createBoard();
    void fillBoardRandomly();
    void printBoard();
    void SymbolSwap(vector<vector<int>>& array, int row1, int col1, int row2, int col2);
    void GameProcess();
};


