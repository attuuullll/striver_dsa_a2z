// Book Allocation Problem

// Given an array where arr[i] represents the number of pages
// in the i-th book and m students.

// Conditions:
// 1. Every student must get at least one book.
// 2. A book can be assigned to only one student.
// 3. Books assigned to a student must be contiguous.
// 4. Minimize the maximum pages assigned to any student.
//return Maximum pages assigned to any student








//brute force
// Time Complexity: O(n²)
// Space Complexity: O(1)
// #include<bits/stdc++.h>
// using namespace std;
// int fff(vector<int> a, int student){

//     if(student>a.size()) return -1;

//     int  x = a.size()-student;
//     int ans  = INT_MAX;
//     for(int i = 0; i+x< a.size(); i++){
//         int sum =0;
//         if(i+x<a.size()){
//             for(int j = i; j <i+x+1 ; j++){
//                 sum += a[j]; 
//             }
//         }
//         ans = min(ans,sum); 
//     }
//     return ans;
// }
// int main(){
//     int n;
//     cin>>n;
//     vector<int> a(n);
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }
//     int student;
//     cin>>student;
//     cout<<fff(a,student);   
//     return 0;
// }


//binary search
// Time Complexity: O(n * log(sum(arr) - max(arr)))
// Space Complexity: O(1)
#include<bits/stdc++.h>
using namespace std;
int fff(vector<int> a, int pages){
    int student = 0;
    int currPages = 0;
    for(int i = 0; i < a.size(); i++){
        if(currPages+a[i]>pages){
            currPages = a[i];
            student++;
        }
        else{
            currPages += a[i];
        }
    }
    student ++;
    return student;
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int student;
    cin>>student;
    int low = *max_element(a.begin(), a.end());   //atleast everyone can hola a book
    int high = accumulate(a.begin(), a.end(), 0);
    int ans = high;
    while(low<=high){
        int mid = low + (high-low)/2;
        int x = fff(a,mid);
        if(x>student){
            low = mid+1;
        }
        else{
            ans = mid;
            high = mid-1;
        }
    }
    cout<<ans;   
    return 0;
}