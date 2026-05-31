// XOR Properties:
//
// a ^ a = 0
// a ^ 0 = a
// XOR of same numbers cancels out
// Used to find unique element efficiently
//
// XOR works on binary bits
//
// Example:
// 2 ^ 2 ^ 5 = 5
// 4 ^ 2 = 6
// 4 = 100
// 2 = 010
// --------
//     110 = 6

// better tc-> n2   sc->
// #include<bits/stdc++.h>
// using namespace std;
// int main() {
//     int n,target;
//     cin>>n>>target;

//     vector<int> a(n);
//     for(int i=0; i<n; i++){
//         cin>>a[i];
//     }
//     int count = 0;
//     for(int i=0; i<n; i++){
//         int XOR = 0;
//         for(int j=i; j<n; j++){           
//                 XOR = XOR^a[j];
//             if(XOR == target){
//                 count++;
//             }
//         }
//     }
//     cout<<count;
//     return 0;
// }


//optimal
