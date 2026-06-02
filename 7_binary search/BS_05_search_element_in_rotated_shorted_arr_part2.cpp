// if dublicates are present
//previous part code works on [1,2 3,4,4,5]
//but doent work on arr = [3,1,2,3,3,3,3]
//tc -> O(log n  base 2)  sc->
#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int>& arr, int n, int target){
    int low = 0, high = arr.size() - 1;

    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] == target) return mid;
        // from part 1 add this line
        if(arr[mid]==arr[low] && arr[mid]==arr[high]){
            low += 1;
            high -= 1;
            continue;
        }


        if(arr[mid]>= arr[low]){
            if(arr[low]<=target && target<=arr[mid]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        else{
            if(arr[mid]<=target && target<=arr[high]){
                low = mid+1;
            }
            else{
                high = mid -1;
            }
        }

    }

    return -1;
}
int main(){
    int n; 
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int target;
    cin>>target;
    int x = binarySearch(arr, n, target);
    cout<<x;
    return 0;
}