/*
Find the Smallest Divisor Given a Threshold

arr = [1, 2, 5, 9]
threshold = 6

Try divisor = 4

        1      2      5      9
       ---    ---    ---    ---
        4      4      4      4

ceil(1/4) = 1
ceil(2/4) = 1
ceil(5/4) = 2
ceil(9/4) = 3

Sum = 1 + 1 + 2 + 3
    = 7

Since 7 > threshold (6),
divisor = 4 is NOT valid.
-----------------------------------------------------------
Try divisor = 5

     1/5 -> ceil = 1
     2/5 -> ceil = 1
     5/5 -> ceil = 1
     9/5 -> ceil = 2

     1 + 1 + 1 + 2 = 5

     5 <= 6 (threshold)

=> divisor 5 is valid
=> Smallest valid divisor = 5
*/


//brute force tc:O(O(n × max(a)))  sc:O(1)
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     vector<int> a(n);
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }
//     int threshold;
//     cin>>threshold;
//     int mx = *max_element(a.begin(), a.end());
//     for(int divisor = 1; divisor <= mx; divisor++){
//         int sum = 0;
//         for(int j = 0; j < n; j++){
//             sum += ceil((double)a[j]/divisor);
//         }
//         if(sum<=threshold){
//             cout<<divisor;
//             break;
//         }
//     }
//     return 0;
// }




//binary search
// TC = O(n log(max(arr)))
// SC = O(1)
#include<bits/stdc++.h>
using namespace std;
int fff(vector<int> a, int divisor){
    int sum =0;
        for(int j = 0; j < a.size(); j++){
            sum += ceil((double)a[j]/divisor);
        }
        return sum;
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int threshold;
    cin>>threshold;
    int low = 1;
    int high = *max_element(a.begin(), a.end());
    int ans = high;
    while(low<=high){
        int mid = low + (high - low)/2;
        int x = fff(a,mid);
        if(x>threshold){
            low = mid+1;
        }
        else{
            high = mid - 1;
            ans = mid;
        }
    }
    cout<<ans;
    return 0;
}
