#include<iostream>
#define n 8
using namespace std;
//printing the solution of n queen problem
void printSoln(int board[n][n]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}
//to check whether two queens are attacking each other or not
bool isSafe(int board[n][n], int row, int col){
    int i,j;
    //Check this row on left side
    for(i=0;i<col;i++){
        if(board[row][i]){
            return false;
        }
    }
    //Check upper diagonal on left side
    for(i=row, j=col; i>=0 && j>=0;i--,j--){
        if(board[i][j]){
            return false;
        }
    }
    //Check lower diagonal on left side
    for(i=row, j=col; j>=0 && i<n; i++, j--){
        if(board[i][j]){
            return false;
        }
    }
    return true;
}
//main function where we will solve n queen problem
// in this problem we are fixing the columns and making the rows and diagonals variable for each queen
bool solveNQUtil(int board[n][n], int col){
    //base case -  If all queens are placed
    if(col>=n){
        return true;
    }
    for(int i=0;i<n;i++){
            // to check for the safety of the position for that particular position board[i][col] queen
            //small calculation
        if(isSafe(board,i,col)){
            board[i][col] = 1;
            //recursive call
            // to place other queen in the chess board
            bool val = solveNQUtil(board,col+1);
            if(val){
                return true;
            }
            //if placing the queen does not lead to a solution the, remove the queen
            board[i][col] = 0;
        }
    }
    //if queen cannot be placed in any row or column
    return false;
}
bool solveNQ(){
    int board[n][n] = { { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 }};
    if(solveNQUtil(board,0) == false){
        cout<<"Solution does not exists";
        return false;
    }
    printSoln(board);
    return true;
}
int main(){
    solveNQ();
    return 0;
}
//{ 0, 0, 0, 0, 0, 0, 0, 0 },
