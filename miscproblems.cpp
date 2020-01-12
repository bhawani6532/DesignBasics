#include "miscproblems.h"

MiscProblems::MiscProblems()
{

}

MiscProblems::MiscProblems(int rows, int columns){
    *arrData2D = new int[rows];
    for(int i = 0; i<rows;i++) {
        arrData2D[rows] = new int[columns];
    }
    this->rows = rows;
    this->columns = columns;
}


MiscProblems::MiscProblems(int index){
    arrData1D = new int[index];
    this->index = index;
}
