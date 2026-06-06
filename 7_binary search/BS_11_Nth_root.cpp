// Find the Nth root of M.
// N = 3   M = 27      ³√27 = 3
// N = 4   M = 69      ⁴√69 = -1


// tc:O(m*logn)     sc:O(1)
// #include<bits/stdc++.h>
// using namespace std;
// long long power(long long a, long long b){
//     long long res = 1;
//     while(b > 0){
//         if(b & 1) res *= a;
//         a *= a;
//         b >>= 1;
//     }
//     return res;
// }
// int main(){
//     int n,m;
//     cin>>n>>m;
//     for(int i = 0; i < m; i++){
//         if(power(i,n)==m){
//             cout<<i;
//             return 0;
//         } 
//         else if(power(i,n)>m) break;
//     }
//     cout<<-1;
//     return 0;
// }





//using binary search 
// Your logic is correct, but there are two issues:
//1. Possible Overflow
//2. Repeated Computation
// #include<bits/stdc++.h>
// using namespace std;
// long long power(long long a, long long b){
//     long long res = 1;
//     while(b > 0){
//         if(b & 1) res *= a;
//         a *= a;
//         b >>= 1;
//     }
//     return res;
// }
// int main(){
//     int n,m;
//     cin>>n>>m;
//     int low = 1;
//     int high = m;
//     while(low<=high){
//     int mid = low + (high-low)/2;
//         if(power(mid,n)==m){
//             cout<<mid;
//             return 0;
//         }
//         else if(power(mid,n)>m){
//             high = mid-1;
//         }
//         else{
//             low=mid+1;
//         }
//     }
//     cout<<-1;
//     return 0;
// }



//so the correct code is
#include<bits/stdc++.h>
using namespace std;
int func(int mid,int n,int m){
	long long ans=1;
	for(int i=1;i<=n;i++){
		ans=ans*mid;
		if(ans>m) return 2;
	}
	if(ans==m) return 1;
	return 0;
}
int main(){
	int n,m;
	cin>>n>>m;
	int low=1,high=m;
	while(low<=high){
		int mid=(low+high)/2;
		int midN=func(mid,n,m);
		if(midN==1){
			cout<<mid;
			return 0;
		}
		else if(midN==0) low=mid+1;
		else high=mid-1;
	}
	cout<<-1;
	return 0;
}