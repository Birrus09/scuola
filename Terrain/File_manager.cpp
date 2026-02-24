
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


struct node{
    int x;
    int y;
    int altitude;
    //bool edge;
    //could be useful in the future
};

int main(){

    //test matrix
    int rows, columns;
    rows = 3;
    columns = 3;
    vector<vector<int>> testmatrix = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            cout << testmatrix[i][j] << "\t ";
        }
        cout << endl;
    }


}
