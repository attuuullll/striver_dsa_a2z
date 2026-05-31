// merge overlapping
// Given intervals:
// (1,3) (2,6) (8,9) (9,11) (8,10) (2,4) (15,18) (16,17)


// After sorting and merging:

// {1,6}                         |   {8,11}                        | {15,18}
// Intervals (1,3), (2,6), (2,4) |   Intervals (8,9),(9,11),(8,10) | Intervals (15,18), (16,17)
// overlap with each other       |   overlap with each other       | overlap with each other
//
// Visualization:
//
// 1------3                          8-----9                          15------------18
//    2----------6                         9-------11                     16----17
//    2------4                       8--------10
//
// Final merged interval             Final merged interval            Final merged interval
// 1-------------6                   8------------11                  15------------18

//brute     Time Complexity  : O(n²) Space Complexity : O(n)
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     vector<vector<int>> a(n, vector<int>(2));   // n rows and har row me 2 column
//     for(int i=0; i<n; i++){
//         cin>>a[i][0]>>a[i][1];
//     }
//     sort(a.begin(),a.end());
//     vector<vector<int>> ans;
//     for(int i=0; i<n; i++){
//         int start = a[i][0];
//         int end = a[i][1];
//         if(!ans.empty()&& end<=ans.back()[1]){
//             continue;
//         }
//         for(int j=i+1; j<n; j++){
//             if(a[j][0]<=end) end = max(end,a[j][1]);
//             else break;
//         }
//         ans.push_back({start, end});        
//     }
//     for(int i = 0; i < ans.size(); i++) {
//         cout<<"Interval "<<i+1<<" : "<<ans[i][0]<<"-"<<ans[i][1]<<endl;
//     }
//     return 0;
// }
//input
// 8
// 1 3
// 2 6
// 8 9
// 9 11
// 8 10
// 2 4
// 15 18
// 16 17


///optimal
// #include<bits/stdc++.h>
// using namespace std; 
// int main(){
//     int n;
//     cin >> n;
//     vector<vector<int>> arr(n, vector<int>(2));
//     for(int i = 0; i < n; i++) {
//         cin >> arr[i][0] >> arr[i][1];
//     }
//     sort(arr.begin(), arr.end());

//     vector<vector<int>> ans;
//     for(int i = 0; i < n; i++) {
//         if(ans.empty() || arr[i][0] > ans.back()[1]) {
//             ans.push_back(arr[i]);
//         }
//         else {
//             ans.back()[1] =
//             max(ans.back()[1], arr[i][1]);
//         }
//     }
//     for(int i = 0; i < ans.size(); i++) {
//         cout << ans[i][0] << " "
//              << ans[i][1] << endl;
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>> a(n, vector<int>(2));
    for(int i = 0; i < n; i++){
        cin >> a[i][0]>>a[i][1];
    }
    sort(a.begin(), a.end());
    vector<vector<int>> ans;
    for(int i = 0; i < n; i++){
        if(ans.empty()||a[i][0]>ans.back()[1]){
            ans.push_back(a[i]);
        }
        else{
            ans.back()[1] = max(ans.back()[1],a[i][1]);
        }
    }
    for(int i = 0; i < ans.size(); i++){
        cout<<"Interval "<<i+1<<" : "<<ans[i][0]<<"-"<<ans[i][1]<<endl;
    }
    return 0;
}

