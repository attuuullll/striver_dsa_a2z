//peek
// a[i-1] < a[i] > a[i+1]

// arr = [1, 2, 3, 4, 5, 6, 7, 8, 5, 1]    ans = 8
// arr = [1, 2, 1, 3, 5, 6, 4]   ans = 2,6
// arr = [1, 2, 3, 4, 5]   ans = 5     coz imagine -infinity[1, 2, 3, 4, 5]-infinity  4 < 5 > -infinity
// arr = [5, 4, 2, 3, 1]  ans = 5


//brute force  tc->O(n) ans sc->O(1)
// #include<bits/stdc++.h>
// using namespace std;
// int peek(vector<int> a, int n){
//     for(int i = 0; i < n; i++){
//         if((i==0||a[i-1]<a[i])&&(i==n-1||a[i]>a[i+1])){
//             return i;
//         }
//     }
//     return -1;
// }
// int main(){
//     int n;
//     cin>>n;
//     vector<int> a(n);
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }
//     int x = peek(a, n);
//     cout<<x;
//     return 0;
// }


//binary search tc->O(logn base 2)  sc->O()
// this code is going to work for only one peek but if we do one single change it can work for multiple peek


//for single peek
// #include<bits/stdc++.h>
// using namespace std;
// int peeek(vector<int> a, int n){
//     if(n==1) return 0;
//     if(a[0]>a[1]) return 0;
//     else if(a[n-1]>a[n-2]) return n-1;
//     else{
//         int low=1;
//         int high=n-2;
//         while(low<=high){
//             int mid=low+(high-low)/2;
//             if(a[mid]>a[mid-1] && a[mid]>a[mid+1]) return mid;
//             else if(a[mid]>a[mid-1]) low = mid+1;
//             else if(a[mid]>a[mid+1]) high = mid-1;
//         }
//         return -1;
//     }
// }
// int main(){
//     int n;
//     cin>>n;
//     vector<int> a(n);
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }
//     cout<<peeek(a,n);
//     return 0;
// }



// for multiple peek
#include<bits/stdc++.h>
using namespace std;
int peeek(vector<int> a, int n){
    if(n==1) return 0;
    if(a[0]>a[1]) return 0;
    else if(a[n-1]>a[n-2]) return n-1;
    else{
        int low=1;
        int high=n-2;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(a[mid]>a[mid-1] && a[mid]>a[mid+1]) return mid;
            else if(a[mid]>a[mid-1]) low = mid+1;
            else high = mid-1;           //heres the change
        }
        return -1;
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout<<peeek(a,n);
    return 0;
}