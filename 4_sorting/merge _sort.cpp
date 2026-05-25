#include<bits/stdc++.h>
using namespace std; 
void merge(vector<int> &arr, int low , int mid, int high){
    int left = low;
    int right = mid+1;
    while(left<=mid && right<=high){
        if(c<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[left]);
             right++; 
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=mid){
        temp.push_back(arr[left]);
        right++;
    }
    for(i=low ; i<=high ; i ++){
        arr[i]=temp[i-low];
    }
}
void ms(vector<int> &arr, int low, int high){
    if (low==high) return 0;
    int mid = (low+high)/2;
    ms(arr, low, mid);
    ms(arr,mid+1, hign);
    merge(arr, low, mid, high);
}

int main()z{
    ms();
    return 0;
}
