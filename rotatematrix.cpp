#include <bits/stdc++.h>
using namespace std;

void rotateMatrix(vector<vector<int>>& mat, int n, int m)
{
    int rowStart = 0, rowEnd = n - 1;
    int colStart = 0, colEnd = m - 1;

    while (rowStart < rowEnd && colStart < colEnd) {
        // Store the first element of next row
        int prev = mat[rowStart + 1][colStart];

        // Move elements of top row one step right
        for (int i = colStart; i <= colEnd; i++) {
            int curr = mat[rowStart][i];
            mat[rowStart][i] = prev;
            prev = curr;
        }
        rowStart++;

        // Move elements of last column one step downwards
        for (int i = rowStart; i <= rowEnd; i++) {
            int curr = mat[i][colEnd];
            mat[i][colEnd] = prev;
            prev = curr;
        }
        colEnd--;

        // Move elements of last row one step left
        if (rowStart <= rowEnd) {
            for (int i = colEnd; i >= colStart; i--) {
                int curr = mat[rowEnd][i];
                mat[rowEnd][i] = prev;
                prev = curr;
            }
        }
        rowEnd--;

        // Move elements of first column one step upwards
        if (colStart <= colEnd) {
            for (int i = rowEnd; i >= rowStart; i--) {
                int curr = mat[i][colStart];
                mat[i][colStart] = prev;
                prev = curr;
            }
        }
        colStart++;
    }
}

// int main()
// {
//     int n, m;
//     cin >> n >> m;

//     vector<vector<int>> mat(n, vector<int>(m));

//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < m; ++j) {
//             cin >> mat[i][j];
//         }
//     }

//     rotateMatrix(mat, n, m);

//     // Print the rotated matrix
//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < m; ++j) {
//             cout << mat[i][j] << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }
