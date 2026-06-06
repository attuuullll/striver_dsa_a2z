// Find floor(sqrt(n))

// n = 25 -> 5
// n = 30 -> 5
// n = 35 -> 5
// n = 36 -> 6

// We need the largest integer x such that:
// x * x <= n


// TC: O(√n)   SC: O(1)
// #include<bits/stdc++.h>
// using namespace std;
// int sqrrt(int n){
//     int ans = 1;
//     for(int i=0; i<n; i++){
//         if(i*i<=n) ans = i;
//         else break;
//     }
//     return ans;
// }
// int main(){
//     int n;
//     cin>>n;
//     cout<<sqrrt(n);
//     return 0;
// }




//using binary tree  tc->log(n)   sc->O(1)
#include<bits/stdc++.h>
using namespace std;
int sqrrt(int n){
    int ans = 1;
    int low = 0;
    int high = n;
    while(low<=high){
        int mid = low + (high - low)/2;
        if(mid*mid<=n){
            ans = mid;
            low = mid+1;
        }
        else if(mid*mid>n)  high = mid-1;
    }
    return ans;     //or return high
}
int main(){
    int n;
    cin>>n;
    cout<<sqrrt(n);
    return 0;
}