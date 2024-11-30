#include "pch.h"
#include "C:\Visualstudio 2 êóðñ\Ppoislab1\Ppoislab1\GameUI.cpp"


TEST(GamefieldTest, CreateBoardTest) {
    Gamefield game;
    game.createBoard();
    EXPECT_EQ(game.getBoard().size(), 4);
    EXPECT_EQ(game.getBoard()[0].size(), 4);
}

TEST(GamefieldTest, FillBoardRandomlyTest) {
    Gamefield game;
    game.createBoard();
    game.fillBoardRandomly();
    vector<int> numbers(16);
    iota(numbers.begin(), numbers.end(), 0);
    bool allNumbersPresent = true;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (find(numbers.begin(), numbers.end(), game.getBoard()[i][j]) == numbers.end()) {
                allNumbersPresent = false;
                break;
            }
        }
    }
    EXPECT_TRUE(allNumbersPresent);
}

TEST(GamefieldTest, SymbolSwapTest) {
    Gamefield game;
    vector<vector<int>> board = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 0, 15}
    };
    game.setBoard(board);

    auto currentBoard = game.getBoard();
    game.SymbolSwap(currentBoard, 3, 2, 3, 3);
    EXPECT_EQ(game.getBoard()[3][2], 0);
    EXPECT_EQ(game.getBoard()[3][3], 15);
}

TEST(GamefieldTest, GameProccesTest_CaseThree) {
    Gamefield game;
    vector<vector<int>> board = {
       {1, 2, 3, 4},
       {5, 6, 7, 8},
       {9, 10, 11, 12},
       {13, 14, 0, 15}
    };
    game.setBoard(board);
    game.GameProcess();
    vector<vector<int>>massive = { {1,2,3,4},
                                   {5,6,7,8},
                                   {9,10,11,12},
                                   {13,14,15,0} };
    EXPECT_EQ(massive, game.getBoard());
}

TEST(GamefieldTest, GameProccesTest_CaseOne) {
    Gamefield game;
    vector<vector<int>> board = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 0},
        {13, 14, 15, 12}
    };
    game.setBoard(board);
    game.GameProcess();
    vector<vector<int>>massive = { {1,2,3,4},
                                   {5,6,7,8},
                                   {9,10,11,12},
                                   {13,14,15,0} };
    EXPECT_EQ(massive, game.getBoard());
}

TEST(GamefieldTest, GameProccesTest_CaseTwoOO) {
    Gamefield game;
    vector<vector<int>> board = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 0},
        {13, 14, 15, 12}
    };
    game.setBoard(board);
    game.GameProcess();
    vector<vector<int>>massive = { {1,2,3,4},
                                   {5,6,7,8},
                                   {9,10,11,12},
                                   {13,14,15,0} };
    EXPECT_EQ(massive, game.getBoard());
}

TEST(GamefieldTest, GameProccesTest_CaseFourTT) {
    Gamefield game;
    vector<vector<int>> board = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 0, 15}
    };
    game.setBoard(board);
    game.GameProcess();
    vector<vector<int>>massive = { {1,2,3,4},
                                   {5,6,7,8},
                                   {9,10,11,12},
                                   {13,14,15,0} };
    EXPECT_EQ(massive, game.getBoard());
}

TEST(GamefieldTest, PrintBoardCorrect_CaseTwo) {
    Gamefield game;
    vector<vector<int>> board = {
       {1, 2, 3, 4},
       {5, 6, 7, 8},
       {9, 10, 11, 0},
       {13, 14, 15, 12}
    };
    game.setBoard(board);
    testing::internal::CaptureStdout();
    game.printBoard();
    string output = testing::internal::GetCapturedStdout();
    string expected_output = "1 2 3 4 \n5 6 7 8 \n9 10 11 0 \n13 14 15 12 \n\n";
    EXPECT_EQ(output, expected_output);
}

int main(int argc, char** argv) {
    setlocale(LC_ALL, "ru");
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
