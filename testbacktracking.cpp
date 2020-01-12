#include "testbacktracking.h"

testBacktracking::testBacktracking()
{
    index = 1;
    for(int row = 0; row < 9; row++) {  // stop loops if nothing to read
       for(int column = 0; column < 9; column++){
            dataMap.existParam[row][column] = false;
       }
    }

    for(int row = 0; row < 8; row++) {  // stop loops if nothing to read
       for(int column = 0; column < 8; column++){
            board.data[row][column] = 0;
       }
    }


}

void testBacktracking::readMap() {
    ifstream fp("sudoku.txt");
    if (! fp) {
        cout << "Error, file couldn't be opened" << endl;
        return;
    }
    for(int row = 0; row < 9; row++) {  // stop loops if nothing to read
       for(int column = 0; column < 9; column++){
            fp >> dataMap.data[row][column];
            if(dataMap.data[row][column]!=0) {
                dataMap.existParam[row][column] = true;
            }
            if ( ! fp ) {
               cout << "Error reading file for element " << row << "," << column << endl;
               return;
            }
        }
    }
}

void testBacktracking::runTest() {
    if(!runTest(0, 0)){
        cout<<"This input can't solve this sudoku"<<endl;
    }
    else {
        outputMap();
    }
}

bool testBacktracking::runTest(int rowIndex, int colIndex) {
    outputMap();
    if(colIndex>=9){
        rowIndex++;
    }
    colIndex = colIndex%9;
    if(rowIndex==9)
        return true;

    for(int i = 1; i<10;i++) {
        if (dataMap.existParam[rowIndex][colIndex] || dataMap.data[rowIndex][colIndex] != 0){
            return(runTest(rowIndex,colIndex+1));
        }
        if (checkBox(rowIndex,colIndex,i) && checkRow(rowIndex,i) && checkColumn(colIndex,i)) {
                dataMap.data[rowIndex][colIndex] = i;
                if(runTest(rowIndex,colIndex+1)) {
                    return true;
                }
                else{
                    dataMap.data[rowIndex][colIndex] = 0;
                }
        }

    }
    return false;
}

bool testBacktracking::checkBox(int row, int column, int value) {
    row = row/3;
    row = row*3;
    column = column/3;
    column = column*3;
    for(int i = row;i<row+3;i++){
        for(int j = column;j<column+3;j++){
            if(dataMap.data[i][j]==value){
                //cout<<"returning false as we find "<<value<<" checkBox["<<i<<","<<j<<"]"<<endl;
                return false;
            }
        }
    }
    //cout<<"returning true as we didn't find "<<value<<" checkBox"<<endl;
    return true;
}


bool testBacktracking::checkRow(int row, int value) {
    for(int i=0;i<9;i++){
        if(dataMap.data[row][i]==value){
            //cout<<"returning false as we find "<<value<<" checkRow["<<row<<","<<i<<"]"<<endl;
            return false;
        }
    }
    //cout<<"returning true as we didn't find "<<value<<" checkRow"<<endl;
    return true;
}


bool testBacktracking::checkColumn(int column, int value) {
    for(int i=0;i<9;i++){
        if(dataMap.data[i][column]==value){
            //cout<<"returning false as we find "<<value<<" checkColumn["<<i<<","<<column<<"]"<<endl;
            return false;
        }
    }
    //cout<<"returning true as we didn't find "<<value<<" checkColumn"<<endl;
    return true;
}


void testBacktracking::outputMap() {
    using namespace std::this_thread;
    using namespace std::chrono;
    sleep_for(nanoseconds(10000000));
    system("clear");
    cout<<underline<<"                   "<<endl;
    for(int row = 0; row < 9; row++) {  // stop loops if nothing to read
        cout<<"|";
       for(int column = 0; column < 9; column++){
            if(dataMap.data[row][column]!=0) {
                cout<<dataMap.data[row][column]<< "|";
            }
            else {
                cout<<" "<< "|";
            }
        }
       cout<<endl;
    }
    cout<<endl<<undoUnderline;
}


void testBacktracking::nQueenTest() {
    if(!nQueenTest(0))
        cout<<"Can't run with this set up of the board"<<endl;

}

bool testBacktracking::nQueenTest(int row){
    nQueenOutputMap();
    if(row==8){
        return true;
    }
    for(int i = 0;i<8;i++){
        if(isQueenSafe(row,i)){
            updateMap(row,i,true);
            if(nQueenTest(row+1)){
                return true;
            }
            else{
                updateMap(row,i,false);
            }
        }

    }
    return false;

}

bool testBacktracking::isQueenSafe(int x, int y){
    if(board.data[x][y]!=0)
        return false;
    return true;
}


void testBacktracking::updateMap(int x, int y, bool isAdd){
    if(isAdd){
        for(int i = 0;i<8;i++){
            if(board.data[i][y]==0)
                board.data[i][y] = x+1;
        }
        for(int i = 0;i<8;i++){
            if(board.data[x][i]==0)
                board.data[x][i] = x+1;
        }

        for(int i = x, j = y;i<8 && j<8;i++,j++){
            if(board.data[i][j]==0)
                board.data[i][j] = x+1;
        }

        for(int i = x, j = y;i>=0 && j<8;i--,j++){
            if(board.data[i][j]==0)
                board.data[i][j] = x+1;
        }

        for(int i = x, j = y;i>=0 && j>=0;i--,j--){
            if(board.data[i][j]==0)
                board.data[i][j] = x+1;
        }

        for(int i = x, j = y;i<8 && j>=0;i++,j--){
            if(board.data[i][j]==0)
                board.data[i][j] = x+1;
        }

        board.data[x][y] = 9;


    }
    else{
        for(int i = 0;i<8;i++){
            if(board.data[i][y]==x+1)
                board.data[i][y] = 0;
        }

        for(int i = 0;i<8;i++){
            if(board.data[x][i]==x+1)
                board.data[x][i] = 0;
        }

        for(int i = x, j = y;i<8 && j<8;i++,j++){
            if(board.data[i][j]==x+1)
                board.data[i][j] = 0;
        }

        for(int i = x, j = y;i>=0 && j<8;i--,j++){
            if(board.data[i][j]==x+1)
                board.data[i][j] = 0;
        }

        for(int i = x, j = y;i>=0 && j>=0;i--,j--){
            if(board.data[i][j]==x+1)
                board.data[i][j] = 0;
        }

        for(int i = x, j = y;i<8 && j>=0;i++,j--){
            if(board.data[i][j]==x+1)
                board.data[i][j] = 0;
        }

        board.data[x][y] = 0;

    }
}

void testBacktracking::nQueenOutputMap() {
    using namespace std::this_thread;
    using namespace std::chrono;
    sleep_for(nanoseconds(80000000));
    system("clear");
    cout<<underline<<"                   "<<endl;
    for(int row = 0; row < 8; row++) {  // stop loops if nothing to read
        cout<<"|";
       for(int column = 0; column < 8; column++){
            if(board.data[row][column]==9) {
                cout<<"Q"<< "|";
            }
            else {
                cout<<" "<< "|";
            }
           //cout<<board.data[row][column]<<"|";
        }
       cout<<endl;
    }
    cout<<endl<<undoUnderline;
}



void testBacktracking::permuteString(string data) {
    set<string> stringExist;
    permuteString(data,"",stringExist);
}

void testBacktracking::printBinaryData(int digit) {
    printBinaryData(digit,"");
}

void testBacktracking::printBinaryData(int digit, string printData) {
    if(digit==0){
        cout<<printData<<endl;
    }
    else {
        for(int i=digit-1;i>=0;i--){
           printBinaryData(i,printData + "0");
           printBinaryData(i,printData + "1");
           i=0;
        }
    }
}

void testBacktracking::permuteString(string s, string chosen, set<string> & stringExist) {
    /*for(int i = 0;i<chosen.length();i++) {
        cout<<"   ";
    }
    cout<<"{"<<s<<","<<chosen<<"}"<<endl;*/

    if(s.empty()){
        if (!(stringExist.find(chosen) != stringExist.end())) {
            cout<<index++<<". "<<chosen<<endl;
            stringExist.insert(chosen);
        }
    }
    else {
        for(unsigned int i=0;i<s.length();i++){
            char c = s[i];
            chosen+=c;
            s.erase(i,1);

            permuteString(s,chosen,stringExist);
            s.insert(i,1,c);
            chosen.erase(chosen.length()-1,1);
        }
    }
}
