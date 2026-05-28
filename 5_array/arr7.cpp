//majority elements(>n/2 times)// MOORE'S VOTING ALGORITHM

// BRUTE FORCE APPROACH
// ---------------------------------------------------

// For every element count frequency again
//
// Time Complexity: O(n²)
// Space Complexity: O(1)
// #include<bits/stdc++.h>
// using namespace std;

// int main() {

//     int arr[] = {2,2,1,1,1,2,2};

//     int n = sizeof(arr)/sizeof(arr[0]);

//     for(int i = 0; i < n; i++){

//         int count = 0;

//         // count frequency of arr[i]

//         for(int j = 0; j < n; j++){

//             if(arr[j] == arr[i]){
//                 count++;
//             }
//         }

//         // check majority condition

//         if(count > n/2){
//             cout << arr[i];
//             return 0;
//         }
//     }

//     cout << "No Majority Element";

//     return 0;
// }

// ---------------------------------------------------
// BETTER APPROACH (HASHING / MAP)
// ---------------------------------------------------

// Store frequency using map
//
// map<int,int> mpp;
//
// mpp[arr[i]]++;
//
// Then check:
//
// if(mpp[it] > n/2)


// Time Complexity: O(n log n)
// unordered_map => O(n)
//
// Space Complexity: O(n)
#include<bits/stdc++.h>
using namespace std;

int main() {

    int arr[] = {2,2,1,1,1,2,2};

    int n = sizeof(arr)/sizeof(arr[0]);

    map<int,int> mpp;

    // storing frequency

    for(int i = 0; i < n; i++){
        mpp[arr[i]]++;
    }

    // checking majority element

    for(auto it : mpp){

        if(it.second > n/2){

            cout << it.first;
            return 0;
        }
    }

    cout << "No Majority Element";

    return 0;
}


// ---------------------------------------------------
// OPTIMAL APPROACH
// MOORE'S VOTING ALGORITHM
// ---------------------------------------------------

// MOST IMPORTANT FOR INTERVIEWS


// IDEA:
//
// Majority element frequency > n/2
// So it can never be completely cancelled out


// VARIABLES:
//
// element -> possible majority element
// count   -> voting count


// RULES:
//
// if(count == 0)
// choose current element
//
// if(current element == element)
// count++
//
// else
// count--


// ---------------------------------------------------
// VISUAL UNDERSTANDING
// ---------------------------------------------------

// Array:
//
// [2,2,1,1,1,2,2]
//
// Step:
//
// 2 -> count=1
// 2 -> count=2
// 1 -> count=1
// 1 -> count=0
//
// count became 0
// choose new candidate
//
// 1 -> count=1
// 2 -> count=0
// 2 -> count=1
//
// Final candidate = 2


// ---------------------------------------------------
// WHY IT WORKS?
// ---------------------------------------------------

// Majority element occurs more than all other
// elements combined.
//
// So after cancellation,
// majority element survives.


// ---------------------------------------------------
// CODE
// ---------------------------------------------------

#include<bits/stdc++.h>
using namespace std;

int main(){

    int arr[] = {2,2,1,1,1,2,2};

    int n = sizeof(arr)/sizeof(arr[0]);

    int count = 0;
    int element;

    // Finding candidate

    for(int i=0; i<n; i++){

        if(count == 0){
            element = arr[i];
            count = 1;
        }

        else if(arr[i] == element){
            count++;
        }

        else{
            count--;
        }
    }


    // Verification step
    // (important if majority element may not exist)

    int cnt = 0;

    for(int i=0; i<n; i++){
        if(arr[i] == element){
            cnt++;
        }
    }

    if(cnt > n/2){
        cout << element;
    }

    else{
        cout << "No Majority Element";
    }

    return 0;
}


// ---------------------------------------------------
// COMPLEXITIES
// ---------------------------------------------------

// Time Complexity: O(n)
// Space Complexity: O(1)


// ---------------------------------------------------
// IMPORTANT INTERVIEW POINT
// ---------------------------------------------------

// Moore's Voting only gives candidate.
//
// Verification step is needed if
// majority element is NOT guaranteed.


