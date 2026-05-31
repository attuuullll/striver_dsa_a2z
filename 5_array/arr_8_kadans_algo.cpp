//max subarr sum

//better
// #include<iostream>
// using namespace std;
// int main() {
//     int n;
//     cin>>n;
//     int a[n] , maxi = 0;
//     for(int i=0; i<n; i++){
//         cin>>a[i];
//     }
//     for(int i=0; i<n; i++){
//         int sum = 0;
//         for(int j=i; j<n; j++){
//             sum += a[j];
//             maxi = max(maxi,sum);
//         }
//     }
//     cout<<maxi;
//     return 0;
// }



// ------------------------------------------------------
// OPTIMAL APPROACH : KADANE'S ALGORITHM
//
// IDEA:
// 1. Traverse the array.
// 2. Keep adding elements to current sum.
// 3. If current sum becomes negative,
//    discard it because negative sum
//    will reduce future subarray sum.
// 4. Keep track of maximum sum found.
//
// ------------------------------------------------------
// IMPORTANT OBSERVATION:
//
// If sum < 0
// then starting fresh from next element
// is always better.
//
// Example:
//
// sum = -5
// next element = 10
//
// (-5 + 10) = 5
// But directly taking 10 is better.
//
// Therefore:
// if(sum < 0) sum = 0;
//
// ------------------------------------------------------
// DRY RUN:
//
// arr = {-2,1,-3,4,-1,2,1,-5,4}
//
// i=0 -> sum=-2 -> maxi=-2 -> sum reset to 0
//
// i=1 -> sum=1 -> maxi=1
//
// i=2 -> sum=-2 -> maxi=1 -> sum reset to 0
//
// i=3 -> sum=4 -> maxi=4
//
// i=4 -> sum=3 -> maxi=4
//
// i=5 -> sum=5 -> maxi=5
//
// i=6 -> sum=6 -> maxi=6
//
// i=7 -> sum=1 -> maxi=6
//
// i=8 -> sum=5 -> maxi=6
//
// Final Answer = 6
//
// ------------------------------------------------------
// TIME COMPLEXITY:
// O(n)
//
// Because we traverse array once.
//
// ------------------------------------------------------
// SPACE COMPLEXITY:
// O(1)
//
// Only variables are used.
//
// ------------------------------------------------------
// MOST IMPORTANT LINE:
//
// if(sum < 0) sum = 0;
//
// ------------------------------------------------------
// EDGE CASE:
//
// If all elements are negative,
// initialize maxi with INT_MIN.
//
// ------------------------------------------------------
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int maxi = INT_MIN;
    int sum = 0, ansstart = -1, ansend = -1, start;
    for(int i=0; i<n; i++){
        if(sum == 0){
            start = i;  
        }
       sum += a[i];
       if(sum>maxi){
        maxi = sum;
        ansstart = start, ansend = i;
       }
       if(sum < 0) sum = 0;
    }
    cout<<"maxi : "<<maxi<<endl;
    for(int i=ansstart; i<ansend+1; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}