// iterrative code
// recursive code
//tc-> log(n) base 2;  
//overflow case




// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     vector<int> a(n);
//     for(int &x : a){
//         cin>>x;
//     }
//     int target;
//     cin>>target;
//         int low = 0;
//         int high = n-1;
//         while(high>=low){
//             int mid = (low + high)/2;
//             if(a[mid] == target) {
//                 cout<<"target find at index : "<<mid;
//                 break;
//             }
//             else if(a[mid]>target){
//                 high =mid - 1;
//             }
//             else {
//                 low = mid+1;
//             }
//         }
//     return -1;
// }


//using recursion 
#include<bits/stdc++.h>
using namespace std;

int bs(vector<int> &a, int low, int high, int target){
    int mid = (low + high)/2;
     if(a[mid] == target) {
        return mid;
        }
        else if(a[mid]>target){
            return bs(a, low, mid-1, target);

        }
        else{
            return bs(a, mid+1, high, target);
        }
        return -1;
}
 int main(){
    int n;
    cin>>n;
    int target;
    cin>>target;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int x = bs(a, 0, a.size()-1, target);
    cout<<"target is at index : "<<x;
    return 0;
}




// Overflow Condition in Binary Search:
//
// Problem:
// If we calculate mid like this:
// mid = (low + high) / 2
//
// Then for very large values of low and high,
// (low + high) can exceed the integer limit,
// causing INTEGER OVERFLOW.
//
// Example:
// low = 2,000,000,000
// high = 2,100,000,000
//
// low + high becomes larger than int range,
// leading to wrong mid value.
//
// Safe Formula:
// mid = low + (high - low) / 2
//
// Why safe?
// Because (high - low) is always within range,
// so overflow does not happen.
//
// Recommended:
// Always use:
// int mid = low + (high - low) / 2;
//
// Time Complexity of Binary Search:
// O(log n)
//
// Space Complexity:
// O(1)