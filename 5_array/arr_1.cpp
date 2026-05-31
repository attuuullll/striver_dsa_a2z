// finding the largest no. of an array
// second largest no. in an array
//second smallest
// check the arr is sorted or not
// remove duplicate from the sorted array
//method 2:- withput making new arr




// finding the largest no. of an array

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int j = 0 ; j<n ; j++){                // we can also sort the array and then print arr[n-1]
//         cin>>arr[j];
//     }
//     int max = arr[0];
//     for(int i = 1 ; i<n-1 ; i++){
//            if(arr[i]>max){
//               max = arr[i];
//            }
//     }
//     cout<<max;
//     return 0;
// }


// second largest no. in an array

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int j = 0 ; j<n ; j++){                // we can also sort the array and then run a for loop from the back
//         cin>>arr[j];                             // side that if n-1 != n-2 then largest but not equal to max 
//     }
//     int max = arr[0];
//     int secmax = - INT_MAX ;
//     for(int i = 1 ; i<n-1 ; i++){
//            if(arr[i]>max){
//               secmax = max;
//               max = arr[i];
//            }
//            else if(arr[i]<max && arr[i]>secmax){
//               secmax = arr[i];
//            }
//     }
//     cout<<secmax;
//     return 0;
// }


//second smallest

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int j = 0 ; j<n ; j++){                
//         cin>>arr[j];                              
//     }
//     int min = arr[0];
//     int secmin = INT_MAX ;
//     for(int i = 1 ; i<n-1 ; i++){
//            if(arr[i]<min){
//               secmin = min;
//               min = arr[i];
//            }
//            else if(arr[i]>min && arr[i]<secmin){
//               secmin = arr[i];
//            }
//     }
//     cout<<secmin;
//     return 0;
// }


// check the arr is sorted or not
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n, count= 0;
//     cin>>n;
//     int arr[n];
//     for(int j = 0 ; j<n ; j++){               
//         cin>>arr[j];                             
//     }
//     for(int i =1 ; i<n ; i++){
//         if(arr[i]<arr[i-1]){
//             cout<<"not sorted";
//             break;
//         }
//         else if(arr[i]>=arr[i-1]){
//               count++;
//         }
//     }
//     if(count == n-1){
//         cout<<"sorted";
//     }
//     return 0;
// }



// remove duplicate from the sorted array
// method 1 :- making new arr
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n, count= 0;
//     cin>>n;
//     int arr[n] , newarr[n], x=1;
//     for(int j = 0 ; j<n ; j++){               
//         cin>>arr[j];                             
//     }
//     newarr[0]=arr[0];
//     for(int i =1 ; i<n ; i++){
//         if(arr[i]!=arr[i-1]){
//             newarr[x]=arr[i];
//             x++;
//         }
//     }
//     for(int j = 0 ; j<x ; j++){               
//         cout<<newarr[j]<<" ";                             
//     }
//     return 0;
// }

//method 2:- withput making new arr
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n, count= 0;
//     cin>>n;
//     int arr[n] , newarr[n], x=1;
//     for(int j = 0 ; j<n ; j++){               
//         cin>>arr[j];                             
//     }
//     set<int> st;
    
//     for(int i =1 ; i<n ; i++){     // NlogN
//          st.insert(arr[i]);
//     }
//     int index = 0;
//     for(auto it : st){             // N
//         arr[index] = it;
//         index++;
//     }
//     for(int i =0; i<index ; i++){     
//         cout<<arr[i];
//     }
//                                     //SC = o(N)
//     return 0;                       //TC =  o(N+NlogN)
// }

