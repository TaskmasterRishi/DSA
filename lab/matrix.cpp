#include <bits/stdc++.h>

using namespace std;

// Function to print a matrix
void printMatrix(vector<vector<int>> &mat)
{
    for (int i = 0; i < mat.size(); ++i)
    {
        for (int j = 0; j < mat[i].size(); ++j)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> addMatrices(vector<vector<int>> &mat1, vector<vector<int>> &mat2)
{
    vector<vector<int>> result(mat1.size(), vector<int>(mat1[0].size(), 0));
    for (int i = 0; i < mat1.size(); ++i)
    {
        for (int j = 0; j < mat1[i].size(); ++j)
        {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    return result;
}

vector<vector<int>> subtractMatrices(vector<vector<int>> &mat1, vector<vector<int>> &mat2)
{
    vector<vector<int>> result(mat1.size(), vector<int>(mat1[0].size(), 0));
    for (int i = 0; i < mat1.size(); ++i)
    {
        for (int j = 0; j < mat1[i].size(); ++j)
        {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
    return result;
}

vector<vector<int>> transposeMatrix(vector<vector<int>> &mat)
{
    vector<vector<int>> result(mat[0].size(), vector<int>(mat.size(), 0));
    for (int i = 0; i < mat.size(); ++i)
    {
        for (int j = 0; j < mat[i].size(); ++j)
        {
            result[j][i] = mat[i][j];
        }
    }
    return result;
}

vector<vector<int>> multiplyMatrices(vector<vector<int>> &mat1, vector<vector<int>> &mat2)
{
    vector<vector<int>> result(mat1.size(), vector<int>(mat2[0].size(), 0));
    for (int i = 0; i < mat1.size(); ++i)
    {
        for (int j = 0; j < mat2[0].size(); ++j)
        {
            for (int k = 0; k < mat1[0].size(); ++k)
            {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return result;
}

vector<vector<int>> inputMatrix(int rows, int cols)
{   
    vector<vector<int>>mat(rows,vector<int>(cols,0));
    cout << "Enter the elements of the matrix (" << rows << "x" << cols << "):" << endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cout << "Enter element at position (" << i << ", " << j << "): ";
            cin >> mat[i][j];
        }
    }
    return mat;
}

int main()
{
    int rows1, cols1, rows2, cols2;

    cout << "Enter the number of rows for Matrix 1: ";
    cin >> rows1;
    cout << "Enter the number of columns for Matrix 1: ";
    cin >> cols1;

    cout << "Enter the number of rows for Matrix 2: ";
    cin >> rows2;
    cout << "Enter the number of columns for Matrix 2: ";
    cin >> cols2;

    if (cols1 != rows2)
    {
        cout << "Matrix addition not possible. Matrices must have the same dimensions." << endl;
        return 0;
    }

    if (rows1 != rows2 || cols1 != cols2)
    {
        cout << "Matrix multiplication not possible. Number of columns in Matrix 1 must be equal to the number of rows in Matrix 2." << endl;
        return 0;
    }

    vector<vector<int>> mat1 = inputMatrix(rows1, cols1);
    vector<vector<int>> mat2 = inputMatrix(rows2, cols2);

    cout << "\nMatrix 1:" << endl;
    printMatrix(mat1);

    cout << "\nMatrix 2:" << endl;
    printMatrix(mat2);

    cout << "\nMatrix Addition:" << endl;
    vector<vector<int>> addition = addMatrices(mat1, mat2);
    printMatrix(addition);
    cout << "\nMatrix Subtraction:" << endl;
    vector<vector<int>> subtraction = subtractMatrices(mat1, mat2);
    printMatrix(subtraction);
    cout << "\nTranspose of Matrix 1:" << endl;
    vector<vector<int>> transpose1 = transposeMatrix(mat1);
    printMatrix(transpose1);

    cout << "\nTranspose of Matrix 2:" << endl;
    vector<vector<int>> transpose2 = transposeMatrix(mat2);
    printMatrix(transpose2);

    cout << "\nMatrix Multiplication:" << endl;
    vector<vector<int>> multiplication = multiplyMatrices(mat1, mat2);
    printMatrix(multiplication);

    return 0;
}
