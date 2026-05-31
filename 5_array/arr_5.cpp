// two sum

//brute
// for(i->n)
//     for(j=i+1->n)
//         if(a[i]+a[j] == target)
//             return i,j

//better(tc = nlogn for ordered and n2 for unordered)(sc = n )
// #include<bits/stdc++.h>
// using namespace std;
// int main() {
//     map<int,int> mpp;
//     int n;
//     cin>>n;
//     int book[n];
//     for(int i=0; i<n; i++){
//         cin>>book[i];
//     }
//     int target;
//     cin>>target;
   
//     for(int i =0; i<n; i++){
//         int a = book[i];
//         int more = target-a; 
//         if(mpp.find(more) != mpp.end()){
//             cout<<"YES"<<endl;
//             return 0;
//         }
//         mpp[a] = i;
//     }
//     cout<<"NO"<<endl;
//     return 0;
// }

//optimal(two pointer) tc -> O(n) + (O(nlogn)for sorting) sc ->O(1)
//sort the array first

#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int target;
    cin>>target;
    int left = 0, right = n-1;
    sort(a,a+n);
    while(left<right){
        if(a[left]+a[right]==target){
            cout<<"yes";
            return 0;
        }
        else if(a[left]+a[right]<target){
            left++;
        }
        else{
            right--;
        }      
    }
    cout<<"NO";
    return 0;
}