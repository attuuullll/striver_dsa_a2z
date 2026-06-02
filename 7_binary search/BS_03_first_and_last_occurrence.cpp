//first and last occurrencre 
// if arr = [1, 2, 3, 3, 3, 3, 4, 5, 6]
// target = 3 theit returns {2,5}  ( {first index, last index})


//brute tc->O(n)  sc->O(1)
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     vector<int> a(n);
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }
//     int target ;
//     cin>>target;
//     int first = -1, last = -1;
//     for(int i = 0; i < n; i++){
//         if(target == a[i]){
//             if(first == -1){
//                 first = i;
//             }
//             last = i ;
//         }
//     }
//     cout<<
//     return 0;
// }

//binary seach method
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     vector<int> a(n);
//     for(int i = 0; i < n; i++){
//         cin>>a[i];
//     }
//     int target ;
//     cin>>target;
//     int first = -1, last = -1;
//     int low = 0;
//     int high = n-1;
//     while(low <= high){
//         int mid = low + (high - low) / 2;

//         if(a[mid] == target){
//             first = mid;
//             high = mid - 1;
//         }
//         else if(a[mid] < target){
//             low = mid + 1;
//         }
//         else{
//             high = mid - 1;
//         }
//     }
//     low =0;
//     high = n-1;
//     while(low <= high){
//         int mid = low + (high - low) / 2;

//         if(a[mid] == target){
//             last = mid;
//             low = mid + 1;
//         }
//         else if(a[mid] < target){
//             low = mid + 1;
//         }
//         else{
//             high = mid - 1;
//         }
//     }

//     cout<<first<<" "<<last;
//     return 0;
// }


//lower and upper bound
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    int target ;
    cin>>target;
    int first = lower_bound(a.begin(), a.end(),target) - a.begin();
    int last =upper_bound(a.begin(), a.end(), target) - a.begin() - 1;
     if(first == n || a[first] != target){
        cout << -1 << " " << -1;
    }
    else{
        cout << first << " " << last;
    }
    return 0;
}