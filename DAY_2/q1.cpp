/* 
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.
And constant space

APPROACH :
	store states of each row in the first of that row, and store states of each column in the first of that column. 
	Because the state of row0 and the state of column0 would occupy the same cell, 
	I let it be the state of row0, and use another variable "col0" for column0. 
	In the first phase, use matrix elements to set states in a top-down way. 
	In the second phase, use states to set matrix elements in a bottom-up way.

	Time: O(MxN)
	Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;

void setZeros(vector<vector<int>> &matrix)
{
	int col0 = 1;
	int R = matrix.size();
	int C = matrix[0].size();

	for(int i=0; i < R; i++)
	{
		if(matrix[i][0] == 0)
			col0 = 0;

		for(int j=1; j< C;j++)
			if(matrix[i][j] == 0)
				matrix[i][0] = matrix[0][j] = 0;
	}

	for(int i=R-1; i >= 0; i--)
	{
		for(int j = C-1; j >= 1; j--)
			if(matrix[i][0] == 0 || matrix[0][j] == 0)
				matrix[i][j] = 0;
		if(col0 == 0)
			matrix[i][0] = 0;
	}

}

void printMatrix(vector<vector<int>> matrix) 
{ 

	int R = matrix.size();
	int C = matrix[0].size();

    int i, j; 
    for (i = 0; i < R; i++) 
    { 
        for (j = 0; j < C; j++) 
        { 
            cout << matrix[i][j]<<" "; 
        } 
        cout << endl; 
    } 
    cout<<endl;
}

int main() 
{ 
    vector<vector<int>> matrix = { {0, 1, 2, 0}, 
                       {2, 7, 1, 1}, 
                       {3, 1, 4, 5}}; 
  
    cout << "Input Matrix \n"; 
    printMatrix(matrix); 
  
    setZeros(matrix); 
  
    printf("Matrix after modification \n"); 
    printMatrix(matrix); 
  
    return 0; 
} 