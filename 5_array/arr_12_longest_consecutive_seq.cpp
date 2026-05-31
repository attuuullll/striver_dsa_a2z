




//brute tc -> O(n2) sc-> O(1)
// #include<bits/stdc++.h>
// using namespace std;
// bool linearSearch(int a[], int n, int x){
//     for(int i=0; i<n; i++){
//         if(a[i] == x){
//             return true;
//         }
//     }
//     return false;
// }
// int main(){
//     int n;
//     cin>>n;
//     int a[n];
//     for(int i=0; i<n; i++){
//         cin>>a[i];
//     }
//     int longest = 1;
//     for(int i=0; i<n; i++){
//          int x = a[i];
//          int count = 1;
//          while(linearSearch(a,n,x+1)==true){
//             x += 1;
//             count++;
//          }
//          longest = max(longest, count);
//     }
//     cout<<longest;

//     return 0;
// }



//optimal tc->O(n) sc -> O(n)
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int cc = 0, longest = 1, ls = INT_MIN;      // cc = corrcount ls = last smaller
    for(int i=0; i<n; i++){
        if(a[i] == ls ){
            continue;
        }
        else if(a[i] == ls+1){
            cc++;
            ls++;
            longest = max(longest,cc);
        }
        else{
            ls = a[i];
            cc =1;
             longest = max(longest,cc);
        }
    }
    cout<<longest;
    return 0;
}
