// koko eating bananas -> return the min integer k such that koko can eat all bananas within h hours  
// k == no of bannans per hour he can eat


//tc : O(max(arr)*n)
// #include<bits/stdc++.h>
// using namespace std;
// int reqTime(vector<int> a, int hourly){
//     int time = 0;
//     for(int i = 0; i < a.size(); i++){
//         time += ceil((double)a[i]/hourly);
//     }
//     return time;
// }
// int main(){
//     int n;
//     cin>>n;
//     vector<int> a(n);
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }
//     int h;
//     cin>>h;
//     int hourly = 1;
//     for(int i = 0; i < *max_element(a.begin(), a.end()); i++){
//         int t = reqTime(a, hourly);
//         if(t>h) hourly++;
//         else{
//             cout<<hourly;        
//             break;
//         }
//     }

//     return 0;
// }






//binary search 
// TC = O(n * log(max(a)))
// SC = O(1)
#include<bits/stdc++.h>
using namespace std;
int reqTime(vector<int> a, int hourly){
    int time = 0;
    for(int i = 0; i < a.size(); i++){
        time += ceil((double)a[i]/hourly);
    }
    return time;
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int h;
    cin>>h;
    int low = 1;
    int high = *max_element(a.begin(), a.end());
    int hourly = INT_MAX;
    while(low<=high){
        int mid = low + (high-low)/2;
        int total = reqTime(a,mid);
        if(total>h) low = mid+1;
        else{
            hourly = min(hourly,mid);
            high = mid-1;
        }
    }
    cout<<hourly;
    return 0;
}