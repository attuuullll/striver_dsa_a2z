//rearrange array elemennt by sign
//what is no. of pos!=no. of neg






//rearrange array elemennt by sign

// brute
// #include<bits/stdc++.h>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;
//     int a[n];
//     for(int i=0; i<n; i++){
//         cin >> a[i];
//     }
//     vector<int> pos;
//     vector<int> neg;
//     for(int i=0; i<n; i++){
//         if(a[i] >= 0){
//             pos.push_back(a[i]);
//         }
//         else{
//             neg.push_back(a[i]);
//         }
//     }
//     for(int i=0; i<n/2; i++){
//         a[2*i] = pos[i];
//         a[2*i + 1] = neg[i];
//     }
//     for(int i=0; i<n; i++){
//         cout << a[i] << " ";
//     }
//     return 0;
// }

// optimal
// #include<bits/stdc++.h>
// using namespace std;
// int main() {
//     int n;
//     cin >> n;
//     int a[n];
//     for(int i=0; i<n; i++){
//         cin >> a[i];
//     }
//     vector<int> ans(n);
//     int posIndex = 0;
//     int negIndex = 1;
//     for(int i=0; i<n; i++){

//         if(a[i] >= 0){
//             ans[posIndex] = a[i];
//             posIndex += 2;
//         }
//         else{
//             ans[negIndex] = a[i];
//             negIndex += 2;
//         } 
//     }
//     for(int i=0; i<n; i++){
//         cout << ans[i] << " ";
//     }
//     return 0;
// }


//what is no. of pos!=no. of neg

#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n]  ;
    vector<int> P;
    vector<int> N;
    for(int i=0; i<n; i++){
        cin>>a[i];
        if(a[i]>=0){        
            P.push_back(a[i]);
        }
        else{
            N.push_back(a[i]);
        }
    }
    
    vector<int> ans;
    int i =0 ;
    while(i<P.size()&&i<N.size()){
        ans.push_back(P[i]);
        ans.push_back(N[i]);
        i++;
    }
    while(i<P.size()){
        ans.push_back(P[i]);
        i++;
    }
    while(i<N.size()){
        ans.push_back(N[i]);
        i++;
    }
    for(int i=0; i<n; i++){
        cout << ans[i] << " ";
    }
    return 0;
}
