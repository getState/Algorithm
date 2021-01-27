#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> arr;
int rows, cols;

void showResult(int check, int x, int y);

int main()
{
    cin >> rows >> cols;
    arr = vector<vector<int>>(rows, vector<int>(cols, 0));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> arr[i][j];
        }
    }
    if (rows % 2 != 0)
    {
        //홀수행
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols - 1; j++)
            {
                if (i % 2 == 0)
                {
                    cout << "R";
                }
                else
                {
                    cout << "L";
                }
            }
            if (i != rows - 1)
            {
                cout << "D";
            }
        }
        return 0;
    }
    else if (cols % 2 != 0)
    {
        //홀수열
        for (int i = 0; i < cols; i++)
        {
            for (int j = 0; j < rows - 1; j++)
            {
                if (i % 2 == 0)
                {
                    cout << "D";
                }
                else
                {
                    cout << "U";
                }
            }
            if (i != cols - 1)
            {
                cout << "R";
            }
        }
        return 0;
    }
    int minimum = 1000;
    int minX = -1;
    int minY = -1;
    int check = 0;
    for (int i = 0; i < cols; i++)
    {
        if (i % 2 == 1 && arr[0][i] < minimum)
        {
            minimum = arr[0][i];
            minX = 0;
            minY = i;
            check = 1;
        }
        else if (i % 2 == 0 && arr[rows - 1][i] < minimum)
        {
            minimum = arr[0][i];
            minX = rows - 1;
            minY = i;
            check = 2;
        }
    }
    for (int i = 0; i < rows; i++)
    {
        if (i % 2 == 1 && arr[i][0] < minimum)
        {
            minimum = arr[i][0];
            minX = i;
            minY = 0;
            check = 3;
        }
        else if (i % 2 == 0 && arr[i][cols - 1] < minimum)
        {
            minimum = arr[i][cols - 1];
            minX = i;
            minY = cols - 1;
            check = 4;
        }
    }

    showResult(check, minX, minY);
}

void showResult(int check, int x, int y)
{
    if (check == 1)
    {
    }
    else if (check == 2)
    {
    }
    else if (check == 3)
    {
    }
    else
    {
    }
}