//brute
//better
//optimal -> prefix sum method




//brute   tc ->O(n3)    sc->O(1)
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;
//     cin >> n;
//     int a[n];
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }
//     int k;
//     cin >> k;
//     int count = 0;
//     for(int i = 0; i < n; i++){
//         for(int j = i; j < n; j++){
//             int sum = 0;
//             for(int k=i; k<=j; k++){
//                 sum += a[k];
//             }
//             if(sum == k){
//                 count++;
//             }
//         }
//     }
//     cout << count;
//     return 0;
// }


//better     tc->O(n2)    sc->O(1)
// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int n;
//     cin >> n;
//     int a[n];
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }
//     int k;
//     cin >> k;
//     int count = 0;
//     for(int i = 0; i < n; i++){
//         int sum = 0;
//         for(int j = i; j < n; j++){
//             sum += a[j];
//             if(sum == k){
//                 count++;
//             }
//         }
//     }
//     cout << count;
//     return 0;
// }

//optimal  tc->O(nlogn)( if using unordered map->)(n) )      sc->O(n)
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, k;
    cin>>n>>k;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    map<int,int> mpp;
    mpp[0]=1;
    int presum = 0, cnt = 0;
    for(int i=0; i<n; i++){
        presum += a[i];
        int remove = presum - k;
        cnt += mpp[remove];
        mpp[presum]+=1;
    }
    cout<<cnt;
    return 0;
}