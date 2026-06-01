//lower_bound
//upper_bound
//search insert position
//floor and ceil







// lower_bound: tc-> O(log n)   sc-> O(1)
// returns first index where value >= target
// if target is bigger than all elements -> returns hypothetical index n

// upper_bound:
// returns first index where value > target
// if no greater element exists -> returns hypothetical index n


// In C++, you usually don't need to write these functions manually
// because STL already provides inbuilt functions:
// lower_bound(a.begin(), a.end(), n) -> first index/value >= target
// upper_bound(a.begin(), a.end(), n) -> first index/value > target
// present in <algorithm> library




//lower bond in int main
#include<bits/stdc++.h>
using namespace std;
int lowerBound(vector<int> arr,int n,int x){
    int low=0,high=n-1;
    int ans=n;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]>=x){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
int upperBound(vector<int> arr,int n,int x){
    int low=0,high=n-1;
    int ans=n;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]>x){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
int floor(vector<int>& a,int x){
	int l=0,r=a.size()-1,ans=-1;
	while(l<=r){
		int mid=l+(r-l)/2;
		if(a[mid]<=x){
			ans=a[mid];
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	return ans;
}
int ceil(vector<int>& a,int x){
	int l=0,r=a.size()-1,ans=-1;
	while(l<=r){
		int mid=l+(r-l)/2;
		if(a[mid]>=x){
			ans=a[mid];
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int x;
    cin>>x;             
    cout<<"lowerBound : "<<lowerBound(arr,n,x)<<endl;
    cout<<"upperBound : "<<upperBound(arr,n,x)<<endl;
    cout<<"floor : "<<floor(arr,x)<<endl;
    cout<<"ceil : "<<ceil(arr,x)<<endl;
return 0;
}




// lower bound in recursive fxn
// #include<bits/stdc++.h>
// using namespace std;
// int lowerBound(vector<int>a , int low, int high, int target, int n){
//     if(low>high){
//         return n;
//     }
//     int mid = low + (high - low) / 2;
//     if(a[mid]>target){
//         int left = lowerBound(a, low, mid-1, target, n);
//         if(left!=n){
//             return left;
//         }
//         else{
//             return mid;
//         }
//     }
//     else{
//         return lowerBound(a, mid+1, high, target, n);
//     }
// }
// int main(){
//     int n;
//     cin>>n;
//     vector<int> a(n);
//     for(int i = 0; i < n; i++){
//         cin>>a[i];
//     }
//     int low=0;
//     int high=n-1;
//     int target;
//     cin>>target;
//     int lower = lowerBound(a, low, high, target, n);
//     cout<<lower;
//     return 0;
// }







