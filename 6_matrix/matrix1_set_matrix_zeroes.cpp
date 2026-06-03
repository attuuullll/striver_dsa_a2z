//set matrix zero


//brute tc-> O((n*m)(n+m))   sc->O(1)
// #include<bits/stdc++.h>
// using namespace std;

// void markRow(vector<vector<int>> &matrix, int n, int m, int i){
//     for(int j=0; j<m; j++){
//         if(matrix[i][j] != 0){
//             matrix[i][j] = -1;
//         }
//     }
// }
// void markCol(vector<vector<int>> &matrix, int n, int m, int j){
//     for(int i=0; i<n; i++){
//         if(matrix[i][j]!=0){
//             matrix[i][j]=-1;
//         }
//     }
// }

// int main(){
//     int n, m;
//     cin>>n>>m;
//     vector<vector<int>> matrix(n, vector<int>(m));
//     for(int i=0;  i<n; i++){
//         for(int j=0; j<m; j++){
//             cin>>matrix[i][j];
//         }
//     }
//     for(int i=0;  i<n; i++){
//         for(int j=0; j<m; j++){
//            if(matrix[i][j]==0){
//             markRow(matrix, n, m, i);
//             markCol(matrix, n, m, j);
//            }
//         }
//     }
//     for(int i=0;  i<n; i++){
//         for(int j=0; j<m; j++){
//            if(matrix[i][j]==-1){
//             matrix[i][j]=0;
//            }          
//         }
//     }
//     for(int i=0;  i<n; i++){
//         for(int j=0; j<m; j++){
//            cout<<matrix[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }

// better tc -> O(n*m)  sc -> O(n+m)
// #include<bits/stdc++.h>
// using namespace std;


// int main(){
//     int n, m;
//     cin>>n>>m;
//     vector<vector<int>> matrix(n, vector<int>(m));
//     for(int i=0;  i<n; i++){
//         for(int j=0; j<m; j++){
//             cin>>matrix[i][j];
//         }
//     }
//     int row[n]={0}, column[m]={0};
//     for(int i=0;  i<n; i++){
//         for(int j=0; j<m; j++){
//            if(matrix[i][j]==0){
//                 row[i]=1;
//                 column[j]=1;
//            }
//         }
//     }
//     for(int i=0;  i<n; i++){
//         for(int j=0; j<m; j++){       
//             if(row[i]||column[j]){
//                    matrix[i][j]=0;             
//                }                 
//         }
//     }
   
//     for(int i=0;  i<n; i++){
//         for(int j=0; j<m; j++){
//            cout<<matrix[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }

//optimal   tc-> O(n*m)   sc-> O(1)
// #include<bits/stdc++.h>
// using namespace std;

// void markRow(vector<vector<int>> &matrix, int n, int m, int i){
//     for(int j=0; j<m; j++){
//         if(matrix[i][j] != 0){
//             matrix[i][j] = -1;
//         }
//     }
// }
// void markCol(vector<vector<int>> &matrix, int n, int m, int j){
//     for(int i=0; i<n; i++){
//         if(matrix[i][j]!=0){
//             matrix[i][j]=-1;
//         }
//     }
// }

// int main(){
//     int n, m;
//     cin>>n>>m;
//     vector<vector<int>> matrix(n, vector<int>(m));
//     for(int i=0;  i<n; i++){
//         for(int j=0; j<m; j++){
//             cin>>matrix[i][j];
//         }
//     }
//     // int row[n]={0};-> matrix[0][..]
//     // int column[m]={0}; -> matrix[..][0]
//     int col0 = 1;
//     for(int i=0;  i<n; i++){
//         for(int j=0; j<m; j++){
//            if(matrix[i][j]==0){
//                 matrix[i][0]=0;
//                 if(j==0){
//                     col0 = 0;
//                 }
//                 else{
//                     matrix[0][j]=0;
//                 }
//            }
//         }
//     }
//     for(int i=1;  i<n; i++){
//         for(int j=1; j<m; j++){       
//             if(matrix[i][j]!=0){
//                    if(matrix[0][j]==0||matrix[i][0]==0){
//                     matrix[i][j]=0;
//                    }           
//                }                 
//         }
//     }
//     if(matrix[0][0]==0){
//         for(int j=0; j<m; j++) matrix[0][j] = 0;
//     }
//     if(col0==0){
//         for(int j=0; j<n; j++) matrix[j][0]=0;
//     }
//     for(int i=0;  i<n; i++){
//         for(int j=0; j<m; j++){
//            cout<<matrix[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }


