//Longest subarray with sum k

//arr = [1, 2, 3]
//[1, 2] is a subarray but [1,3] is not a subarray

///brute (tc = n3)(sc = )
// #include<iostream>
// using namespace std;
// int main() {
//     int n;
//     cin>>n;
//     int a[n];
//     for(int i=0; i<n; i++){
//         cin>>a[i];
//     }
//     int length = 0, k;
//     cin>>k;
//     for(int i=0; i<n; i++){
//         for(int j=i; j<n; j++){
//             int sum = 0;
//             for(int m=i; m<=j; m++){ 
//                 sum += a[m];
//             }
//             if(sum == k){
//                 length = max(length, j-i+1);
//             }
//         }
//     }
//     cout<<length;
//     return 0;
// }

//better(hashing)(tc for ordered map = nlogn and for unordered n2)(sc = n )
// #include<bits/stdc++.h>
// using namespace std;
// int Longestsubarraywithsumk(vector<int> a, long long k){
//     map<long long,int> preSumMap;
//     long long sum = 0;
//     int maxlen = 0;
//     for(int i =0; i<a.size(); i++){
//         sum += a[i];
//         if(sum == k){
//             maxlen = max(maxlen, i+1);
//         }
//         long long rem = sum-k;
//         if(preSumMap.find(rem) != preSumMap.end()){
//             int len = i- preSumMap[rem];
//             maxlen = max(maxlen, len);
//         }
//         long long rem = sum-k;
//         if(preSumMap.find(rem) == preSumMap.end()){
//             preSumMap[sum] = i;
//         }
//     }
// }


// optimal
// #include<iostream>
// using namespace std;
//     int longestSubarray(vector<int> &nums, int k){
//           int left =0, right =0;
//     int sum = nums[0];
//     int maxlen =0;
//     int n = nums.size();
//     while(right<n){
//         while(left<=right && sum>k){
//                 sum -= nums[left];
//                 left++;
//         }
//         if(sum == k){
//             maxlen =  max(maxlen, right-left+1);
//         }
//         right++;
//         if(right<n){
//             sum += nums[right];
//         }
//     }
//     return maxlen;
//     }


