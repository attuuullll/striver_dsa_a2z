// ================= NEXT PERMUTATION =================
//
// PROBLEM:
// Find the next lexicographically greater permutation
// of the given array.
//
// If next permutation does not exist,
// return the first permutation (sorted order).
//
// ----------------------------------------------------
// Example:
//
// arr = {1,2,3}
// Next = {1,3,2}
//
// arr = {3,2,1}
// Next = {1,2,3}
//
// ----------------------------------------------------
// BRUTE FORCE:
//
// 1. Generate all permutations
// 2. Sort them
// 3. Find current permutation
// 4. Return next one
//
// Time Complexity:
// O(n! * n)
//
// Not optimal.
//
// ----------------------------------------------------
// OPTIMAL APPROACH:
//
// STEP 1:
// Find the "break point"
//
// Traverse from back and find first index
// where:
//
// a[i] < a[i+1]
//
// ----------------------------------------------------
// WHY?
//
// Because after breakpoint,
// elements are in decreasing order.
//
// We need a slightly greater number.
//
// ----------------------------------------------------
// Example:
//
// 1 2 7 4 3 1
//
// breakpoint = 2
// because:
//
// 2 < 7
//
// ----------------------------------------------------
// STEP 2:
//
// Find element just greater than a[i]
// from the back side.
//
// Swap them.
//
// Example:
//
// 1 2 7 4 3 1
//   ^
//
// Find element > 2
//
// swap with 3
//
// Result:
//
// 1 3 7 4 2 1
//
// ----------------------------------------------------
// STEP 3:
//
// Reverse everything after breakpoint.
//
// Why reverse?
//
// Because right part is in decreasing order.
// Reversing makes it minimum possible.
//
// Example:
//
// 1 3 7 4 2 1
//
// reverse after index 1
//
// Final:
//
// 1 3 1 2 4 7
//
// ----------------------------------------------------
// IMPORTANT OBSERVATION:
//
// Next permutation means:
//
// "Just greater permutation"
//
// So after swapping,
// make remaining part smallest possible.
//
// ----------------------------------------------------
// EDGE CASE:
//
// If no breakpoint exists,
// array is completely decreasing.
//
// Example:
//
// 5 4 3 2 1
//
// Answer:
//
// 1 2 3 4 5
//
// ----------------------------------------------------
// TIME COMPLEXITY:
//
// O(n)
//
// ----------------------------------------------------
// SPACE COMPLEXITY:
//
// O(1)
//
// ----------------------------------------------------

#include<bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> a(n);

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    int ind = -1;

    // STEP 1: Find breakpoint
    for(int i=n-2; i>=0; i--){

        if(a[i] < a[i+1]){
            ind = i;
            break;
        }
    }

    // If no breakpoint exists
    if(ind == -1){

        reverse(a.begin(), a.end());
    }

    else{

        // STEP 2: Find next greater element
        for(int i=n-1; i>ind; i--){

            if(a[i] > a[ind]){

                swap(a[i], a[ind]);
                break;
            }
        }

        // STEP 3: Reverse right half
        reverse(a.begin() + ind + 1, a.end());
    }

    // Print answer
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }

    return 0;
}
