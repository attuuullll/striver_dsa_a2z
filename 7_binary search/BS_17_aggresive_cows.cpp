// aggresive cows :_ (minimum dist btw two cows)is max 
// minm dist = consecutive cows so first sort them
// Step 1: Sort the stall positions.
// Step 2: Binary search on the answer (minimum distance).
//          low = 1
//          high = last_stall - first_stall
// Step 3: For a given distance 'mid', check if it is possible
//         to place all k cows while maintaining at least 'mid'
//         distance between every pair of cows.
// Step 4:
//         If possible -> store answer and try larger distance.
//         Else -> try smaller distance.
// Step 5: The largest feasible distance is the final answer.

// check(mid):
// Place first cow in the first stall.
// Traverse remaining stalls.
// Whenever current stall - last_placed_stall >= mid,
// place another cow.
// If we can place at least k cows, return true.
// Otherwise return false.

// Time Complexity: O(n log(max_position))
// Space Complexity: O(1)









 //arr = [0, 3, 4, 7, 9, 10] cows = 4
// TC=O(nlogn+nlog(max_stall-min_stall))
// SC=O(1)
 #include<bits/stdc++.h>
using namespace std;
  int fff(vector<int> a, int days, int cows){
    int past = 0, count =0;
    for(int i = 1; i<a.size(); i++){
        if(a[i]-a[past] >= days){
            count++;
            past = i;
        }
    }
    if(count >= cows-1) return 1;
    else return 0;
 }

 int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int cows;
    cin>>cows;
    
    int low = 1;
    int high = (*max_element(a.begin(), a.end()) - *min_element(a.begin(), a.end()));
    int ans = high;
    while(low<=high){
        int mid = low + (high - low)/2;
        int x = fff(a,mid,cows);
        if(x == 1){
            ans = mid;
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    cout<<ans;
    return 0;
 }