/*

least capacity to Ship Packages Within D Days

weights = [1,2,3,4,5,6,7,8,9,10]
days = 5

Try ship capacity = 10

Day 1 -> {1,2,3,4}   (load = 10)
Day 2 -> {5}         (load = 5)
Day 3 -> {6}         (load = 6)
Day 4 -> {7}         (load = 7)
Day 5 -> {8}         (load = 8)
Day 6 -> {9}         (load = 9)
Day 7 -> {10}        (load = 10)

Total days needed = 7

7 > 5 (given days)

=> Capacity = 10 is NOT valid
=> We need a larger ship capacity
--------------------------------------------------

Try Capacity = 15

Day 1 -> {1,2,3,4,5} (load = 15)
Day 2 -> {6,7}       (load = 13)
Day 3 -> {8}         (load = 8)
Day 4 -> {9}         (load = 9)
Day 5 -> {10}        (load = 10)

Total days needed = 5

5 <= 5

=> Capacity = 15 is valid
=> Try to find a smaller valid capacity
--------------------------------------------------

Pattern:

Capacity = 10 -> 7 days ❌
Capacity = 11 -> 6 days ❌
Capacity = 12 -> 6 days ❌
Capacity = 13 -> 5 days ✅
Capacity = 14 -> 5 days ✅
Capacity = 15 -> 5 days ✅

❌ ❌ ❌ ✅ ✅ ✅ ...

Search Space:
low  = max(weights) = 10
high = load(weights) = 55

Binary Search on Answer
to find the smallest valid capacity.



*/


//binary search
// TC = O(n log(sum(weights)))
// SC = O(1)

#include<bits/stdc++.h>
using namespace std;
int fff(vector<int> a, int capacity){
    int load = 0, days =1;
    for(int i = 0; i < a.size(); i++){
        if(load+a[i]>capacity){
            load = a[i];
            days++;
        }
        else {
            load += a[i];
        }
        
    }
    return days;
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int days;
    cin>>days;
    int low =  *max_element(a.begin(),a.end());
    int high = 0;
    for(int i = 0; i < n; i++){
        high += a[i];
    }
    int ans = high;
    while(low<=high){
        int mid = low+(high-low)/2; 
        int x = fff(a, mid);
        if(x<=days){
            ans = mid;
            high  = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    cout<<ans;
    return 0;
}
    





