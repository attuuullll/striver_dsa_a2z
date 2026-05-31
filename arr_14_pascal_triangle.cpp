/*3 TYPES OF PASCAL TRIANGLE QUESTIONS
-----------------------------------------
1. Given Row (R) and Column (C),
   tell the element at that place.
   Example:
   R = 5, C = 3
   Answer:
   6
   sol: n-1
           C 
             r-1
-----------------------------------------
2. Print any Nth row
   of Pascal Triangle.
   Example:
   N = 5
   Output:
   1 4 6 4 1
-----------------------------------------
3. Given N,
   print the entire Pascal Triangle.
   Example:
   N = 5
   Output:
           1
         1   1
       1   2   1
     1   3   3   1
   1   4   6   4   1
-----------------------------------------*/





#include<bits/stdc++.h>
using namespace std;
int nCr(int r, int c){
    long long x = 1;
    for(int i = 0; i < c; i++){
        x = x * (r - i);
        x = x / (i + 1);
    }
    return x;
}

// que1 soln  tc->O(r)    sc->O(1)
// int main(){
//     int r, c;
//     cin>>r>>c;
//     int ans = nCr(r-1,c-1);
//     cout<<ans;
//     return 0;
// }

//que 2   

// better tc->O(n*r)    sc->O(1)
// int main(){
//     int n;
//     cin>>n;
//     for(int c=1; c<=n; c++){
//         cout<<nCr(n-1,c-1)<<" ";
//     }
//     return 0;
// }

//optimal
// int main(){
//     int row;
//     cin>>row;
//     int ans = 1;
//     cout<<1<<" ";
//     for(int col=1; col<row; col++){
//         ans = ans*(row-col)/col;
//         cout<<ans<<" ";
//     }
//     return 0;
// }

//que 3  
// better tc-> O(n3)  sc->O(n2)
// int main(){
//     int n;
//     cin>>n;
//     vector<vector<int>> ans;
//     for(int row=1; row<=n; row++){
//         vector<int> tempList;
//         for(int col=0; col<row; col++){
//             tempList.push_back(nCr(row-1,col));
//         }
//         ans.push_back(tempList);
//     }
    
//     for(auto tempList : ans){
//         for(auto ele : tempList){
//             cout << ele << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

optimal  tc-> O(n2)       sc-> O(n2)
vector<int> generateRow(int row){
    long long ans = 1;
    vector<int> tempList;
    tempList.push_back(1);
    for(int col = 1; col < row; col++){
        ans = ans * (row - col);
        ans = ans / col;
        tempList.push_back(ans);
    }
    return tempList;
}
int main(){
    int n;
    cin >> n;
    vector<vector<int>> ans;
    for(int row = 1; row <= n; row++){
        vector<int> tempList = generateRow(row);
        ans.push_back(tempList);
    }
    for(auto tempList : ans){
        for(auto ele : tempList){
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}