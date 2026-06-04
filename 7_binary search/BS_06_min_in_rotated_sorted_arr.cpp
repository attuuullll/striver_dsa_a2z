// minimum in rotated sorted array [unique]



#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int>& arr, int n ){
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    while(low <= high){
        int mid = low + (high - low) / 2;
        //if entire search space is sorted
        if(arr[low] <= arr[high]){
            ans = min(ans, arr[low]);
            break;
        }
        //if left half sort
        if(arr[mid]>= arr[low]){
            ans = min(ans,arr[low]);
            low = mid+1;
        }
        //if right half sort
        else{
            ans = min(ans,arr[mid]);
            high = mid-1; 
        }
    }
    return ans;
    }

   

int main(){
    int n; 
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int x = binarySearch(arr, n);
    cout<<x;
    return 0;
}