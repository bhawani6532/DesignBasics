#ifndef MISCPROBLEMS_H
#define MISCPROBLEMS_H


class MiscProblems
{
public:
    MiscProblems();
    MiscProblems(int index);
    MiscProblems(int row, int columns);
    int largestIsland();

private:
   int **arrData2D;
   int rows;
   int columns;

   int *arrData1D;
   int index;
};

#endif // MISCPROBLEMS_H
