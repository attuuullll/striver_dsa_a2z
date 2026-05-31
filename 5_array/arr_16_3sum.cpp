//3sum
// arr[i] + arr[j] + arr[k] = 0
// where i != j != k


// brute tc -> O(n^3 log n)   sc-> O(n2)
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     vector<int> a = {-1,0,1,2,-1,-4};
//     set<vector<int>> st;
//     int n= a.size();
//     for(int i=0;i<n; i++){
//         for(int j=i+1; j<n; j++){
//             for(int k=j+1; k<n; k++){
//                 if(a[i]+a[j]+a[k]==0){
//                     vector<int> temp = {a[i], a[j], a[k]};
//                     sort(temp.begin(), temp.end());
//                     st.insert(temp);
//                 }
//             }
//         }
//     }
//     vector<vector<int>> ans(st.begin(), st.end());
//     for(auto v : ans){
//         for(int x : v){
//             cout<<x<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }


//better          tc->O(n2logm)       sc->O(n)+O(no. of unique triplet)*2
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     vector<int> a = {-1,0,1,2,-1,-4};
//     set<vector<int>> st;
//     int n= a.size();

//     for(int i=0;i<n; i++){
//         set<int> hashset;
//         for(int j=i+1; j<n; j++){
//             int x = -1*(a[i]+a[j]);
//             if(hashset.find(x)!=hashset.end()){             // Check if x exists in hashset                                               
//                 vector<int> temp = {a[i], a[j],x};          // If find(x) != end(), then x is present
//                 sort(temp.begin(), temp.end());
//                 st.insert(temp);
//             }
//             hashset.insert(a[j]);
//         }
//     }
//     vector<vector<int>> ans(st.begin(), st.end());
//     for(auto v : ans){
//         for(int x : v){
//             cout<<x<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// } 




//optimal  tc-> O(nlogn)+O(n2)    sc---> O(1)
//first sort the array
//  a = [  -2    -2     -2   0   0   0   1   1   1   2   2   2   2]
//          ^     ^                                              ^
//          |     |                                              |
//          i     j                                              k
//      (const)
    
//             i always remains constant
//             if sum>0   k--
//             if sum<0   j++


#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> a = {-1,0,1,2,-1,-4};
    sort(a.begin(),a.end()); 
    vector<vector<int>> ans;
    int n= a.size();
    for(int i=0; i<n; i++){
        if(i>0&&a[i]==a[i-1]) continue;
        int j=i+1;
        int k=n-1;
        while(j<k){
            int sum = a[i]+a[j]+a[k];
            if(sum>0) k--;
            else if(sum<0)  j++;
            else{
                vector<int> temp = { a[i], a[j], a[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && a[j]==a[j-1])  j++;
                while(j<k && a[k]==a[k+1])  k--;
            }
        }
        
    }
    for(auto v : ans){
        for(int x : v){
            cout << x << " ";
        }
        cout << endl;
    }
    
    
    return 0;
}