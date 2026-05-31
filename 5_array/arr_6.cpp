// sort an arr of 0's, 1's, 2's  (dutch national flag algorithm)

//brute(any sorting algo)

//better tc ->n sc->1
// #include<iostream>
// using namespace std;
// int main() {
//     int n;
//     cin>>n;
//     int a[n] , c1 =0 , c2 = 0, c0 = 0;
//     for(int i=0; i<n; i++){
//         cin>>a[i];
//         if(a[i]==0) c0++;
//         if(a[i]==1) c1++;
//         if(a[i]==2) c2++;
//     }
//     for(int i=0; i<c0; i++){
//         cout<<"0"<<" ";
//     }
//     for(int i=0; i<c1; i++){
//         cout<<"1"<<" ";
//     }
//     for(int i=0; i<c2; i++){
//         cout<<"2"<<" ";
//     }

//     return 0;
// }

//optimal(dutch national flag algorithm)
// Time Complexity: O(n)
// Space Complexity: O(1)


// POINTERS:
//
// low  -> position where next 0 should go
// mid  -> current element being checked
// high -> position where next 2 should go


// ARRAY DIVISION:
//
// 0 ------ low-1      => all 0s
// low ---- mid-1      => all 1s
// mid ---- high       => unsorted part
// high+1 -- n-1       => all 2s


// VISUAL:
//
// [0 0 0 | 1 1 1 | ? ? ? | 2 2 2]
//          low     mid     high

/ RULES:
//
// if(arr[mid] == 0)
// swap(arr[low], arr[mid])
// low++
// mid++
//
// Reason:
// 0 should go to left side


// if(arr[mid] == 1)
// mid++
//
// Reason:
// 1 is already in correct region


// if(arr[mid] == 2)
// swap(arr[mid], arr[high])
// high--
//
// Reason:
// 2 should go to right side
// mid is NOT incremented because swapped element
// can be 0/1/2


// MAIN CONDITION:
//
// while(mid <= high)

#include<bits/stdc++.h>
using namespace std;

int main(){

    int arr[] = {1,0,2,1,0,2,1,0};

    int n = sizeof(arr)/sizeof(arr[0]);

    int low = 0;
    int mid = 0;
    int high = n-1;

    while(mid <= high){

        if(arr[mid] == 0){
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }

        else if(arr[mid] == 1){
            mid++;
        }

        else{
            swap(arr[mid], arr[high]);
            high--;
        }
    }

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}