// index of minimunm should be going to be the ans(how many times a array is rotated)
 



#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int>& arr, int n ){
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    while(low <= high){
        int mid = low + (high - low) / 2;
          if(arr[low] <= arr[high]){
            if(arr[low]<ans){
                index = low;
            }
            break;
        }
        if(arr[mid]>= arr[low]){
            if(arr[low]<ans){
                index = low;
            }
            low = mid+1;
        }
        else{
            if(ans > arr[mid]){
                ans = arr[mid];
            }
            high = mid-1; 
        }
    }
    return index;
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