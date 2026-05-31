// missing number 
//Maximum consecutive ones
// find the no. that appears ones, and the others appears twice


// missing number 
//brute (TC = O(N2)) (SC = O(1))
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     int a[n];
//     for(int i=0; i<n; i++){
//         cin>>a[i];
//     }
//     for(int i=1; i<n; i++){
//         int flag =0;
//         for(int j=0; j<n; j++){
//             if( a[j] == i ){
//                 flag = 1;
//                 break;
//             }
//         }
//         if(flag == 0){
//             cout<<i;
//         }
//     }
//     return 0;
// }


// better(using hashing)(TC = O(N)) (SC = O(N))

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     int a[n];
//     for(int i=0; i<n; i++){
//         cin>>a[i];
//     }
//     int hash[n+1] = {0};
//     for(int i=0; i<n; i++){
//         hash[a[i]]=1;
//     }
//     for(int i=1; i<n; i++){
//         if(hash[i]==0){
//             cout<<i;
//         }
//     }
// }


//optimal(there can be 2 optiomal solution SUM or XOR)

//#sum(TC = O(N) (SC = O(1))
// #include<iostream>
// using namespace std;
// int main() {
//     int n;
//     cin>>n;
//     int a[n];
//     for(int i=0; i<n-1; i++){
//         cin>>a[i];
//     }
//     int sum1 = n*(n+1)/2, sum2 =0;
//     for(int i=0; i<n-1; i++){
//         sum2 += a[i];
//     }
//     cout<<(sum1-sum2);
//     return 0;
// }

//#XOR
//(XOR of same no. is 0 and XOR of 0 with any no. is no. itself)
// 2^2 = 0 and 0^2 = 2

//           1 2 3 4 5
//           1 2   4 5
//     XOR = 0 0   0 0


//  XOR1 = 1^2^3^4^5
//  XOR2 = 1^2^4^5
//  XOR1^XOR2 = (1^1)^(2^2)^(3)^(4^4)^(5^5)
//            =  0^0^3^0^0 =0
// #include<bits/stdc++.h>
// using namespace std;
// int main() {
//     int n;
//     cin>>n;
//     int a[n];
//     for(int i=0; i<n-1; i++){
//         cin>>a[i];
//     }
//     int XOR1 = 0, XOR2 = 0;
//     for(int i=1; i<=n; i++){
//         XOR1 = XOR1^i;
//     }
//     for(int i=0; i<n-1; i++){
//         XOR2 = XOR2^a[i];
//     }
//     cout<<(XOR1^XOR2);
//     return 0;
// }



//Maximum consecutive ones
// #include<iostream>
// using namespace std;
// int main(){    
//     int n;
//     cin>>n;
//     int a[n];
//     for(int i=0; i<n; i++){
//         cin>>a[i];
//     }
//     int count =0 , maxi = 0;
//     for(int i=0; i<n; i++){
//         if(a[i]==1){
//             count++;
//             maxi = max(maxi, count);
//         }
//         else{
//             count = 0;
//         }
//     }
//     cout<<maxi;
//     return 0;
// }


// find the no. that appears ones, and the others appears twice
// exm a = [ 1, 1, 2, 3, 3, 4, 4, 5, 5] ans =2

//brute (TC = O(N2)) (SC = O(1))
// #include<bits/stdc++.h>
// using namespace std;
// int main() {
//     int n;
//     cin>>n;
//     int a[n];
//     for(int i=0; i<n; i++){
//         cin>>a[i];
//     }
//     for(int i=0; i<n; i++){
//         int num = a[i];
//         int count = 0;
//         for(int j=0; j<n; j++){
//             if(a[j]==num){
//                 count++;
//             }
//         }
//         if(count==1){
//             cout<<num;
//             break;
//         }
//     }
//     return 0;
// }

//better
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n], maxi =0;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<n; i++){
        maxi = max(maxi,a[i]);
    }
    int hash[maxi+1] = {0};
    for(int i=0; i<n; i++){
        hash[a[i]] += 1;
    }
    for(int i=1; i<maxi+1; i++){
        if(hash[i]==1){
            cout<<i;
      
        }
    }
    return 0;
}