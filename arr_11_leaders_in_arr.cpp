// leaders : everthing on the right should be smaller'


//brute tc ->n2 
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n; 
    cin>>n;
    int a[n];
    vector<int> ans;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<n; i++){
        bool leader = true;
        for(int j=i+1; j<n; j++){
            if(a[j]>a[i]){
                leader = false;
                break;
            }
        }
        if(leader){
            ans.push_back(a[i]);
        }
    }
    for(int i=0; i<ans.size(); i++){
            cout << ans[i] << " ";
        }
    return 0;
}


// ================= OPTIMAL APPROACH =================
//
// IDEA:
//
// Traverse from right side.
//
// Keep track of maximum element seen so far.
//
// If current element > maxi,
// then current element is a leader.
//
// ----------------------------------------------------
// WHY?
//
// Leader means:
//
// all elements on right are smaller.
//
// So if current element is greater than
// maximum element on right side,
// it is definitely a leader.
//
// ----------------------------------------------------
// TIME COMPLEXITY:
// O(n)
//
// SPACE COMPLEXITY:
// O(n)
//
// ----------------------------------------------------

#include<bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    int a[n];

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    vector<int> ans;

    int maxi = INT_MIN;

    // Traverse from right
    for(int i=n-1; i>=0; i--){

        if(a[i] > maxi){

            ans.push_back(a[i]);

            maxi = a[i];
        }
    }

    // Reverse because elements
    // were added from right to left
    reverse(ans.begin(), ans.end());

    // Print answer
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }

    return 0;
}

