#include<bits/stdc++.h>
using namespace std ;


//for int


// int main(){
//     int n;
//     cin>>n;
//     int s[n];
//     for(int i=0; i<n ; i++){
//         cin>>s[i];
//     }

//     // PRECOMPUTE
//     int hash[13] = {0};          // maxm size of array we can declare is 10 ki power 6 if it is inside int main but if      
//     for(int i=0; i<n ; i++){     //we go globally then we can go for #arr[1e7] means 10ki power 7
//          hash[s[i]] += 1;        // for bool inside int main 10 k power 7 but globally 10 ki pow 8
//     }

//     int t;
//     cin>>t;
//     for(int j = 0 ; j < t ; j++ ){
//         int number;
//         cin>>number;
//         //FETCH
//         cout<<hash[number]<<endl;
//     }
    

//     return 0;
// }


// for char


// int main(){
   
//     string s;
//     cin>>s;
//     //precompute
//     int hash[26]={0};
//     for(int i=0 ; i<s.size() ; i++ ){
//         hash[s[i]-'a']++;
//     }

//     int q;
//     cin>> q;
//     while(q--){
//         char c;
//         cin>>c;
//         //fetch
//         cout<<hash[c-'a'];
//     }
//  return 0;
// }


// for val greator than 10 ki pow 8 ( using map)

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n ; i++ ){
        cin>>arr[i];
    }
    //precompute
    map<int, int> mpp;    // can also take long long instead of int and for char map<char , int> mpp
     for(int i=0 ; i<n ; i++){
        mpp[arr[i]]++;
     }
    int q;
    cin>>q;
    while(q--){
        int number;
        cin>>number;
        //fetch
        cout<<mpp[number]<<" ";
    }

    return 0;
}


//methods of hashing
//      1: division method (linear chaning)
//      2: folding method
//      3: mid square method

// learn collision

