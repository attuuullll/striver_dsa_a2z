//rotate image (clockwise dirn)



// brute tc -> O(n2)  sc->O(n2)
// matrix[i][j]  --->  ans[j][n-1-i]
// -----------------------------------------
// EXAMPLE (4 x 4)
// -----------------------------------------
// Original Matrix:
// [0][0] = 1   ->   ans[0][3]
// [0][1] = 2   ->   ans[1][3]
// [0][2] = 3   ->   ans[2][3]
// [0][3] = 4   ->   ans[3][3]


// [1][0] = 5   ->   ans[0][2]
// [1][1] = 6   ->   ans[1][2]
// [1][2] = 7   ->   ans[2][2]
// [1][3] = 8   ->   ans[3][2]


// [2][0] = 9   ->   ans[0][1]
// [2][1] = 10  ->   ans[1][1]
// [2][2] = 11  ->   ans[2][1]
// [2][3] = 12  ->   ans[3][1]


// [3][0] = 13  ->   ans[0][0]
// [3][1] = 14  ->   ans[1][0]
// [3][2] = 15  ->   ans[2][0]
// [3][3] = 16  ->   ans[3][0]

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n,m;
//     cin>>n>>m;
//     vector<vector<int>> matrix(n, vector<int>(m));
//     for(int i=0; i<n; i++){
//         for(int j=0; j<m; j++){
//             cin>>matrix[i][j];
//         }
//     }
//     vector<vector<int>> ans(n, vector<int>(m));
//     for(int i=0; i<n; i++){
//         for(int j=0; j<m; j++){
//             ans[j][n-i-1]=matrix[i][j];
//         }
//     }
//     for(int i=0; i<n; i++){
//         for(int j=0; j<m; j++){
//             cout<<ans[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }



// optimal tc->O(n2)  sc->O(1)

// STEP 1:
// Transpose the matrix
// Swap:

//     matrix[i][j]
//             ↕
//     matrix[j][i]

// Meaning:
// Rows become columns.

// STEP 2:
// REVERSE EVERY ROW
// Reverse Formula:

//     matrix[i][j]
//             ↔
//     matrix[i][n-j-1]

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>matrix[i][j];
        }
    }
    cout<<endl;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m/2; j++){
            swap(matrix[i][j],matrix[i][n-j-1]);
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}