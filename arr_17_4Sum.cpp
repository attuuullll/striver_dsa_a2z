// nums[i] + nums[j] + nums[k] + nums[l] = target
// where i != j != k != l


// brute force     tc--> O(n4logm)   sc-->O(n3)
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     vector<int> nums(n);
//     for(int i=0; i<n; i++){
//         cin>>nums[i];
//     }
//     set<vector<int>> st;
//     for(int i=0; i<n; i++){
//         for(int j=i+1; j<n; j++){
//             for( int k=j+1; k<n; k++){
//                 for (int l=k+1; l<n; l++){
//                     if(nums[i]+nums[j]+nums[k]+nums[l]==0){
//                         vector<int> temp ={nums[i],nums[j],nums[k],nums[l]};
//                         sort(temp.begin(), temp.end());
//                         st.insert(temp);
//                     }
//                 }
//             }
//         }
//     }
//     vector<vector<int>> ans(st.begin(), st.end());
//     for(auto v: ans){
//         for(int x : v){
//             cout<<x<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }



//better  tc-> O(n3logm)   sc->O(m)
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     vector<int> nums(n);
//     for(int i=0; i<n; i++){
//         cin>>nums[i];
//     }
//     set<vector<int>> st;
//     for(int i=0; i<n; i++){
//         for(int j=i+1; j<n; j++){
//             set<long long> hashset;
//             for( int k=j+1; k<n; k++){
//                 long long sum = nums[i]+nums[k];
//                 sum += nums[j];
//                 int fourth = -(sum);
//                 if(hashset.find(fourth)!=hashset.end()){
//                     vector<int> temp ={nums[i], nums[j], nums[k], fourth};
//                     sort(temp.begin(), temp.end());
//                     st.insert(temp);
//                 }
//                 hashset.insert(nums[k]);
//             }
//         }
//     }
//     vector<vector<int>> ans(st.begin(), st.end());
//     for(auto v: ans){
//         for(int x : v){
//             cout<<x<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }

//optimal  tc-> O(n3)   sc-> O(1)
//first sort the array
//  a = [  -2    -2     -2   0   0   0   1   1   1   2   2   2   2]
//          ^     ^      ^                                       ^
//          |     |      |                                       |
//          i     j      k                                       l
//      (const)
    
//             i always remains constant
//             if sum>0   k--
//             if sum<0   j++

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    vector<vector<int>> ans;
    for(int i=0; i<n; i++){
        if(i>0&&a[i]==a[i-1]) continue;
        for(int j=i+1; j<n; j++){
            if(j>i+1&&a[j]==a[j-1]) continue;
            int k = j + 1;
            int l = n-1;
            while(l>k){
                int sum = a[i]+a[j]+a[k]+a[l];
                if(sum>0) l--;
                else if(sum<0) k++;
                else{
                    vector<int> temp = {a[i],a[j],a[k],a[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while(k < l && a[k] == a[k-1]) k++;
                    while(k < l && a[l] == a[l+1]) l--;
                }
            }
        }
    }
    for(auto x : ans){
        for(int v : x){
            cout<<v<<" ";
        }
        cout<<endl;
    }

    return 0;
}