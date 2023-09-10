#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


class Solution 
{
    public:
    bool isSafe(int num,int x,int y,int grid[N][N])
    {
        //Check if already occupied
        if(grid[x][y]!=0)
            return false;
        //Check Row
        for(int i=0;i<9;i++)
        {
            if(grid[x][i]==num)
                return false;
        }
        //Check Column
        for(int i=0;i<9;i++)
        {
            if(grid[i][y]==num)
                return false;
        }
        //Check local galaxy
        int boxx=x-x%3,boxy=y-y%3;
        for(int i=boxx;i<(boxx+3);i++)
            for(int j=boxy;j<(boxy+3);j++)
            {
                if(grid[i][j]==num)
                    return false;
            }
        return true;
    }
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
    { 
        //Finding the first empty position
        int x=-1,y=-1;
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
            {
                if(grid[i][j]==0)
                {
                    x=i;
                    y=j;
                    break;
                }
            }
        if(x==-1 and y==-1) return true;
        
        for(int i=1;i<=9;i++)
        {
            if(isSafe(i,x,y,grid))
            {
                grid[x][y]=i;
                if(SolveSudoku(grid)) return true;      
                else grid[x][y]=0;                  //
            }
        }
        return false;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
         for(int i=0;i<9;i++)
            {
                for(int j=0;j<9;j++)
                    cout<<grid[i][j]<<" ";
            }
    }
};


int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
