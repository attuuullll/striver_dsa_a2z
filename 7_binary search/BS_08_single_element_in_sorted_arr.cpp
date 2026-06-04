// it is guarented that only one element will occur single and it is also guarebteed that 
// all other elemts gonna occour twice

//brute force tc-> O(n)  sc->O(1)
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n; 
//     cin>>n;
//     vector<int> a(n);
//     for(int i = 0; i < n; i++){
//         cin >> arr[i];
//     }
//     if(n==1){
//         cout<<arr[0];
//         return 0;
//     }
//     for(int i = 0; i < n; i++){
//         if(i==0){
//             if(arr[i]!=arr[i+1]) cout<< arr[i];
//         }
//         else if(i==n-1){
//             if(arr[n-1]!=arr[n-2]) cout<< arr[n-1];
//         }
//         else{
//             if(arr[i]!=arr[i-1]&&arr[i]!=arr[i+1]) cout<< arr[i];
//         }
//     }
//     return  0;
// }



//binary search
// (even, odd)  -> unique element is in the right half
// (odd, even)  -> unique element is in the left half

//a = [1,1,2,2,3,3,4,5,5,6,6]

// If mid is even and arr[mid] == arr[mid+1],
// unique element lies on the right side.

// If mid is odd and arr[mid] == arr[mid-1],
// unique element lies on the right side.

// Otherwise, unique element lies on the left side (including mid).

   
#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int>& arr, int n){
    if(n==1)  return 0;
    if(arr[0]!=arr[1]) cout<< arr[0];
    if(arr[n-1]!=arr[n-2]) cout<< arr[n-1];
    int low =1, high = arr.size() - 2;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1])  return arr[mid];
        if(mid%2==1 && arr[mid-1]==arr[mid]||mid%2==0 && arr[mid]==arr[mid+1]){
            low = mid+1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int x = binarySearch(a, n);
    cout<<x;

    return 0;
}
