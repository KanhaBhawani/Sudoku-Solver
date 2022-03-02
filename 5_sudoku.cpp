/*
Problem statement:-
Given a partially filled Sudoku Matrix of 9x9.
Write a function to solve the sudoku.
*/

/*Kanha Bhawani*/
#include <iostream>
#include <vector>
#include <cmath>
// #include <bits/stdc++.h>
using namespace std;

bool isSafe(int mat[][9], int i, int j, int no, int n)
{
    // check for row and col.
    for (int k = 0; k < n; k++)
    {
        if (mat[i][k] == no || mat[k][j] == no)
        {
            return false;
        }
    }
    // check for subgrid
    int sx = (i / 3) * 3;
    int sy = (j / 3) * 3;

    for (int x = sx; x < sx + 3; x++)
    {
        for (int y = sy; y < sy + 3; y++)
        {
            if (mat[x][y] == no)
            {
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(int mat[][9], int i, int j, int n)
{
    /* base case */
    if (i == n)
    {
        // print
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << mat[i][j] << " ";
            }
            cout << "\n";
        }

        return true;
    }

    /* rec case */
    // current row comp --> next row
    if (j == n)
    {
        return solveSudoku(mat, i + 1, 0, n);
    }
    // skip the prefilled cell
    if (mat[i][j] != 0)
    {
        return solveSudoku(mat, i, j + 1, n);
    }

    // ********cell to be filled*******
    // try out all possiblities
    for (int no = 1; no <= n; no++)
    {
        // check whether it is safe to place the number or not
        if (isSafe(mat, i, j, no, n))
        {
            mat[i][j] = no;
            bool solveSubproblem = solveSudoku(mat, i, j + 1, n);
            if (solveSubproblem)
            {
                return true;
            }
        }
    }

    // if no option works (do backtracing)
    mat[i][j] = 0;
    return false;
}

int main()
{
    int n = 9;
    int mat[9][9] = {
        {0, 0, 0, 0, 9, 0, 0, 2, 0},
        {4,0,2,5,0,0,0,6,0},
        {0,5,3,0,7,0,0,4,0},
        {0,7,8,0,0,1,0,0,0},
        {9,0,0,0,5,0,0,0,0},
        {0,4,0,6,0,0,0,0,0},
        {0,0,0,0,0,7,0,0,2},
        {5,0,0,0,4,0,7,0,0},
        {0,0,0,0,0,0,1,0,6}};

    if (!solveSudoku(mat, 0, 0, n))
    {
        cout << "no solution exists!";
    }

    return 0;
}