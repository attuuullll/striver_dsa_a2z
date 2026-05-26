#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a[500];
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Selection Sort
    for(int i = 0; i < n - 1; i++) {
        int minindex = i;

        for(int j = i + 1; j < n; j++) {
            if(a[j] < a[minindex]) {
                minindex = j;
            }
        }

        swap(a[i], a[minindex]);
    }

    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}
