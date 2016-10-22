#include<iostream>
using namespace std;


bool inRow(int g[][9],int row,int num)
{
for(int col=0;col<9;col++)
if(g[row][col] == num)
return true;
cout<<"\n"<<row<<" InRow";
return false;
}

bool inCol(int g[][9],int col,int num)
{
for(int row=0;row<9;row++)
if(g[row][col] == num)
return true;
cout<<"\n"<<col<<" InCol";
return false;
}

bool inBox(int g[][9],int row,int col,int num)
{
for(int i=0;i<3;i++)
{
for(int j=0;j<3;j++)
{
if(g[row+i][col+j] == num)
return true;
}
}
cout<<"\n"<<row<<" "<<col<<" InBox";
return false;
}

void print_(int g[][9])
{
for(int i=0;i<9;i++)
{
for(int j=0;j<9;j++)
cout<<g[i][j]<<" ";
cout<<endl;
}
}

bool safe(int g[][9],int row,int col,int num)
{
return (!inRow(g,row,num) && !inCol(g,col,num) && !inBox(g,row-row%3,col-col%3,num));
}

bool empty_cell(int g[][9],int &row,int &col)
{
for(row=0;row<9;row++)
for(col=0;col<9;col++)
if(g[row][col]==0)
return true;
return false;
}

bool sudoku(int g[][9])
{
int row,col;
//done
if(!empty_cell(g,row,col))
return true;

for(int num = 1;num<=9;num++)
{
if(safe(g,row,col,num))
{
g[row][col] = num;
if(sudoku(g))
return true;
g[row][col] = 0;
}
}
return false;
}

bool check_sudoku(int g[][9])
{
for(int i=0;i<9;i++)
{
for(int j=0;j<9;j++)
{
if(safe(g,i,j,g[i][j]))
return false;
}
}
return true;
}

main()
{
	int grid[][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};
if(sudoku(grid))
print_(grid);
else
cout<<"\nNo sol";

if(check_sudoku(grid))
cout<<"\nSolved correctly!";
else
cout<<"\nNope;";
}
