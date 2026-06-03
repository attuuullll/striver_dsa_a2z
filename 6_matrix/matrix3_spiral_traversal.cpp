// spiral matrix 

// Direction of traversal:
// → move right
// ↓ move down
// ← move left
// ↑ move up
// Repeat again layer by layer.
 
// it doesnt have multiple solution , it has only one solutions which is optimal solution

// interviewer can ask you this que to check your
// 1. implementation
// 2. how clean can you write the code


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
    int top = 0, left = 0, right = n-1, bottom = n-1; 
    while(top<=bottom&&left<=right){
        for(int i = left; i<=right; i++){
        cout<<matrix[top][i];
        }
        top++;
        for(int i=top; i<=bottom; i++){
            cout<<matrix[i][right];
        }
        right--;
        if(top<=bottom){
            for(int i=right; i>=left; i--){
                cout<<matrix[bottom][i];
            }
            bottom--;
        }
        
        if(left<=right){
            for(int i=bottom; i>=top; i--){
            cout<<matrix[i][left];
        }
        left++;
        }
    }
    return 0;
}


