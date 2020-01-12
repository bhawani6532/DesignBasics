#ifndef TESTBACKTRACKING_H
#define TESTBACKTRACKING_H
#define underline "\033[4m"
#define undoUnderline "\033[0m"
#include <set>
#include <iostream>
#include <fstream>
#include <cstdlib>          //need to use CLS and clear system commands
#include <chrono>
#include <thread>
using namespace std;

struct suduko {
    int data[9][9];
    bool existParam[9][9];
};

struct nQueen {
    int data[8][8];
};

class testBacktracking
{
public:
    testBacktracking();

    //Suduko methods
    void runTest();
    void readMap();
    void outputMap();


    //nQueen methods
    void nQueenTest();
    void nQueenOutputMap();


    //extra testing data
    void permuteString(string data);
    void printBinaryData(int digit);

private:
    suduko dataMap;
    nQueen board;
    int index;

    //Suduko methods
    bool runTest(int rowIndex, int colIndex);
    bool checkBox(int row, int column, int data);
    bool checkRow(int row, int data);
    bool checkColumn(int column, int data);


    //nQueen methods
    bool nQueenTest(int row);
    bool isQueenSafe(int x, int y);
    void updateMap(int x, int y, bool IsAdd);

    //extra testing data
    void permuteString(string s, string chosen, set<string> & stringExist);
    void printBinaryData(int digit, string printData);

};

#endif // TESTBACKTRACKING_H
