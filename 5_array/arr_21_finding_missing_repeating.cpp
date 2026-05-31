//arr = [4, 3, 6, 2, 1, 1]
// here 5 is missing nd 1 is repeating




//method 1 TC: O(n2)  , SC: O(1)
//  #include<bits/stdc++.h>
//  using namespace std;
//  int main(){
//     int n; 
//     cin>>n;
//     vector<int> a(n);
//     for(int &x : a){
//         cin>>x;
//     } 
//     int missing = -1, repeating =-1;
//     for(int i = 1; i <=n; i++){
//         int count = 0;
//         for(int j=0; j<n; j++){
//             if(a[j]==i) count++;
//         }
//         if(count == 2 ){
//             repeating = i;
//             cout<<"repeating no: "<<i<<endl;
//         }
//         else if(count == 0){
//             cout<<"missing no: = "<<i<<endl;
//             missing = i;
//         }
//         if(missing != -1 && repeating != -1){
//             break;
//         }
//     }
//      return 0;
//  }


// method 2   TC: O(2n)  , SC: O(n)

//   #include<bits/stdc++.h>
//  using namespace std;
//  int main(){
//     int n; 
//     cin>>n;
//     vector<int> a(n);
//     for(int &x : a){
//         cin>>x;
//     }
//     int missing = -1;
//     int repeating = -1;
//     int hash[n+1] = {0};
//     for(int i=0; i<n; i++){
//         hash[a[i]]++;
//     }
//     for(int i = 1; i < n+1; i++){
//             if(hash[i]==2){
//             repeating = i;
//             cout<<"repeating no: = "<<i<<endl;

//         }
//         else if(hash[i]==0){
//             missing = i;
//             cout<<"missing no: = "<<i<<endl;
//         }
//         if(missing != -1 && repeating != -1){
//             break;
//         }
//     }
//     return 0;
//  } 


//method 3   TC: O(n)  , SC: O(1)

//   #include<bits/stdc++.h>
//  using namespace std;
//  int main(){
//     int n; 
//     cin>>n;
//     vector<int> a(n);
//     for(int &x : a){
//         cin>>x;
//     }
//     int missing = -1;
//     int repeating = -1;
//     int sum = (n*(n+1))/2;
//     int sum2 = (n*(n+1)*(2*n+1))/6;
//     int Rsum = 0;
//     int Rsum2 = 0;
//     for(int i = 0; i < n; i++){
//         Rsum += a[i];
//         Rsum2 += a[i]*a[i];
//     }
//     int c = sum - Rsum;
//     int b = (sum2 - Rsum2)/c;
//     missing = (c+b)/2;
//     repeating = (b-c)/2;
//     cout<<missing<<" "<<repeating;


//     return 0;
//  } 



// 4th method 
// 1. XOR all array elements with numbers from 1 to n
//    (arr[0] ^ arr[1] ^ ... ^ arr[n-1]) ^ (1 ^ 2 ^ ... ^ n)
//    = missing ^ repeating

// 2. Find a differing bit in the result (rightmost set bit)

// 3. Divide numbers into two groups based on that bit
//    and XOR separately to get missing and repeating numbers


#include<bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> a(n);

    for(int &x : a) {
        cin >> x;
    }

    int xr = 0;

    // XOR of array elements
    for(int i = 0; i < n; i++) {
        xr ^= a[i];
    }

    // XOR with 1 to n
    for(int i = 1; i <= n; i++) {
        xr ^= i;
    }

    // Rightmost set bit
    int bit = xr & (-xr);

    int zero = 0;
    int one = 0;

    // Divide array elements into two groups
    for(int i = 0; i < n; i++) {

        if(a[i] & bit) {
            one ^= a[i];
        }
        else {
            zero ^= a[i];
        }
    }

    // Divide numbers 1 to n into two groups
    for(int i = 1; i <= n; i++) {

        if(i & bit) {
            one ^= i;
        }
        else {
            zero ^= i;
        }
    }

    // Check which is repeating
    int repeating = -1;
    int missing = -1;

    for(int i = 0; i < n; i++) {

        if(a[i] == one) {
            repeating = one;
            missing = zero;
            break;
        }

        if(a[i] == zero) {
            repeating = zero;
            missing = one;
            break;
        }
    }

    cout << "Missing Number = " << missing << endl;
    cout << "Repeating Number = " << repeating;

    return 0;
}