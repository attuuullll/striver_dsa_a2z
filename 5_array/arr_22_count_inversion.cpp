// Count Inversion:
//
// An inversion is a pair (i, j) such that:
//
// i < j
// and
// a[i] > a[j]
//
// It means the elements are not in correct sorted order.
//
// Example:
// arr = [5, 3, 2, 4, 1]
//
// Inversions:
// (5,3)
// (5,2)
// (5,4)
// (5,1)
// (3,2)
// (3,1)
// (2,1)
// (4,1)
//
// Total inversions = 8



//brute force   tc-> O(n2)   sc-> O(1)
// #include<bits/stdc++.h>
// using namespace std;
// int main() {
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     for(int &x : a) {
//         cin >> x;
//     }
//     int cnt = 0;
//     for(int i = 0; i < n - 1; i++) {
//         for(int j = i + 1; j < n; j++) {
//             if(a[i] > a[j]) {
//                 cnt++;
//             }
//         }
//     }
//     cout << cnt;
//     return 0;
// }




//optimal tc->O(nlogn)   sc->O(n)
#include<bits/stdc++.h>
using namespace std;

// Merge function
int merge(vector<int>& a, int low, int mid, int high) {

    vector<int> temp;

    int left = low;
    int right = mid + 1;

    int cnt = 0;

    // Count inversions + merge
    while(left <= mid && right <= high) {

        if(a[left] <= a[right]) {
            temp.push_back(a[left]);
            left++;
        }
        else {

            // All remaining elements in left half
            // will form inversions
            cnt += (mid - left + 1);

            temp.push_back(a[right]);
            right++;
        }
    }

    while(left <= mid) {
        temp.push_back(a[left]);
        left++;
    }

    while(right <= high) {
        temp.push_back(a[right]);
        right++;
    }

    // Copy back to original array
    for(int i = low; i <= high; i++) {
        a[i] = temp[i - low];
    }

    return cnt;
}

// Merge Sort
int mergeSort(vector<int>& a, int low, int high) {

    int cnt = 0;

    if(low >= high) {
        return cnt;
    }

    int mid = (low + high) / 2;

    cnt += mergeSort(a, low, mid);

    cnt += mergeSort(a, mid + 1, high);

    cnt += merge(a, low, mid, high);

    return cnt;
}

int main() {

    int n;
    cin >> n;

    vector<int> a(n);

    for(int &x : a) {
        cin >> x;
    }

    int inversions = mergeSort(a, 0, n - 1);

    cout << "Count of inversions = " << inversions;

    return 0;
}