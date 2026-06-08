/*
Find Kth Missing Positive Number

arr = [2, 3, 4, 7, 11]
k = 5

Answer = 9

Number:    1   2    3   4   5   6   7   8   9   10  11
           |   ✓   ✓   ✓   |   |   ✓   |   |   |   ✓
           ↓                ↓   ↓       ↓   ↓   ↓
Missing#:  1                2   3       4   5   6

Missing numbers:
{1, 5, 6, 8, 9, 10, ...}

1st missing -> 1
2nd missing -> 5
3rd missing -> 6
4th missing -> 8
5th missing -> 9   ← Answer
*/



// opimal  tc->O(n)   sc:O(1)
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int k;
    cin>>k;
    for(int i = 0; i < n; i++){
        if(a[i]>k) break;
        else k++;
    }
    cout<<k;
    return 0;
}







//binary search
/*
missing numbers till index i
missing = arr[i] - (i + 1)
arr = [2,3,4,7,11]
missing:
[1,1,1,3,6]
k = 5
Find first index where:
missing >= k
BS result:
low = 4
Answer = low + k
       = 4 + 5
       = 9
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	int k;
	cin>>k;
	int low=0,high=n-1;
	while(low<=high){
		int mid=low+(high-low)/2;
		int missing=a[mid]-(mid+1);
		if(missing<k) low=mid+1;
		else high=mid-1;
	}
	cout<<low+k;
	return 0;
}