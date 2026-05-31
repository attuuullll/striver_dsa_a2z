 //majority element (>[L/3]times)

// If elements appear more than (n/k) times,
// then maximum possible such elements can only be (k-1).
//
// Example:
// > n/2  -> at most 1 element
// > n/3  -> at most 2 elements
// > n/4  -> at most 3 elements

//so for L/3 we have at most 2 elements




//brute(sortd array) tc-> O(n2)    sc-> O(1)
// #include<bits/stdc++.h>
// using namespace std;
// int main() {
//     int n;
//     cin>>n;
//     vector<int> a(n);
//     for(int i=0; i<n; i++){
//         cin>>a[i];
//     }
//     vector<int> ls;
//     for(int i=0; i<n; i++){
//         if(ls.size()==0 || ls[0] != a[i] ){
//             int cnt = 0;
//             for(int j=0; j<n; j++){
//                 if(a[i]==a[j]){
//                     cnt++;
//                 }
//             }
//             if(cnt>n/3){
//                 ls.push_back(a[i]);
//             }
//         }
//         if(ls.size()==2) break;
//     }
//     for(int i=0; i<ls.size(); i++){
//         cout<<ls[i]<<" ";
//     }
//     return 0;
// }

//better tc-> O(nlogn)   sc->O(n)
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     vector<int> a(n);
//     for(int i=0; i<n; i++){
//         cin>>a[i];
//     }
//     map<int,int> mpp;
//     for(int i=0; i<n; i++){
//         mpp[a[i]]++;
//     }
//     vector<int> ans;
//     for(auto it : mpp){
//         if(it.second>n/3){
//             ans.push_back(it.first);
//         }
//     }
//     for(int x : ans){
//         cout<<x<<" ";
//     }
//     return 0;
// }



//optimal   tc->O(n)   sc->O(1)
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int &x : a){
        cin>>x;
    }
    int cnt1 = 0, cnt2 = 0 ;
    int ele1, ele2;
    for(int i=0; i<n; i++){
        if(cnt1 == 0 && a[i]!=ele2 ){
            cnt1 = 1;
            ele1 = a[i];
        }
        else if(cnt2 == 0 && a[i]!=ele1){
            cnt2 = 1;
            ele2 = a[i];
        }
        else if(a[i] == ele1 ){ 
            cnt1++;
        }
        else if(a[i]==ele2){
            cnt2++;
        }
        else{
            cnt1--;
            cnt2--;
        }
    }
    int count1=0,count2=0;
    for(int i=0; i<n; i++){
        if(a[i]==ele1){
            count1++;
        }
        else if(a[i]==ele2){
            count2++;
        }
    }
    if(count1>n/3) cout<<ele1<<" ";
    if(count2>n/3) cout<<ele2;
    return 0;
}