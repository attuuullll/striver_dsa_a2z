// Minimum Number of Days to Make m Bouquets

// arr[i] = day on which ith flower blooms
// To make 1 bouquet, we need k adjacent bloomed flowers

// Goal:
// Find the minimum day such that we can make at least m bouquets

// Example:
// bloomDay = [7,7,7,7,13,11,12,7]
// m = 2, k = 3

// Day = 12
// Flowers bloomed: [7,7,7,7,X,11,12,7]
// Bouquets possible = 2

// Binary Search on Answers

// low  = minimum bloom day
// high = maximum bloom day

// For a given day:
// cnt how many bouquets can be formed using
// consecutive flowers with bloomDay[i] <= day

// If bouquets >= m:
//     answer = day
//     try smaller day (high = mid - 1)
// Else:
//     need more flowers to bloom
//     low = mid + 1

// Edge Case:
// If m * k > n
// return -1 (not enough flowers)


//arr = [7, 7, 7, 7, 13, 11, 12, 7]  m=2(no. of bouquets)  k=3(no. of flower in one bouquets)




//brute force
// TC = O(n * (maxBloomDay - minBloomDay))
// SC = O(1)
// #include<bits/stdc++.h>
// using namespace std;
// int bouquets(vector<int> a,int day, int k){
//     int cnt = 0, bq=0;
//     for(int i = 0; i < a.size(); i++){
//         if(day>=a[i]){
//             cnt++;
            
//         }
//         else{
//              bq+= cnt/k;
//             cnt = 0;
//         }
//     }
//     bq += cnt/k;
//     return bq;
// }
// int main(){
//     int n;
//     cin>>n;
//     vector<int> a(n);
//     for(int i = 0; i < n; i++){
//         cin>>a[i];
//     }
//     int m,k;
//     cin>>m>>k;
//     if((long long)m * k > n){
//         cout << -1;
//         return 0;
//     }
//     for(int i=*min_element(a.begin(), a.end()); i<=*max_element(a.begin(), a.end()); i++){
//        int x = bouquets(a,i,k);
//        if(x>=m){
//         cout<<i;
//         break;
//        }
//     }
//     return 0;
// }


//binary search
// TC = O(n * log(maxBloomDay - minBloomDay))
// SC = O(1)
#include<bits/stdc++.h>
using namespace std;
int bouquets(vector<int> a,int day, int k){
    int cnt = 0, bq=0;
    for(int i = 0; i < a.size(); i++){
        if(day>=a[i]){
            cnt++;
            
        }
        else{
             bq+= cnt/k;
            cnt = 0;
        }
    }
    bq += cnt/k;
    return bq;
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    int m,k;
    cin>>m>>k;
    if((long long)m * k > n){
        cout << -1;
        return 0;
    }
    int low = *min_element(a.begin(), a.end());
    int high = *max_element(a.begin(), a.end());
    int ans = -1;
    while(low<=high){
        int mid = low + (high - low)/2;
        int x = bouquets(a,mid,k);
        if(x>=m){
            high = mid -1;
            ans = mid;
        }
        else low = mid+1;
    }
    cout<<ans;
    return 0;
}