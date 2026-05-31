//rotating array left bye one place
//by d places(better)
//by d places(optimal)
// move all zeroes to the end of the array
// union of two sorted arrays(brute solution)
//union of two sorted arrays(optimal solution)
//intersection of sorted array(brute)
//intersection of sorted array(optimal)



//rotating array left bye one place
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     int a[n];
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }
//     int temp=a[0];
//     for(int i=1;i<n;i++){
//         a[i-1]=a[i];
//     }
//     a[n-1]=temp;
//     for(int i=0;i<n;i++){
//         cout<<a[i]<<" ";
//     }

//     return 0;
// }



//by d places(better)
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n,d;
//     cin>>n>>d;
//     int a[n],x=0;
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }
//     int temp[d];
//     for(int i=0;i<d;i++){
//         temp[i]=a[i];
//     }
//     for(int i=d;i<n;i++){
//         a[i-d]=a[i];
//     }
//     for(int i=n-d;i<n;i++){
//         a[i]=temp[x];
//         x++;
//     }
//     for(int i=0;i<n;i++){
//         cout<<a[i]<<" ";
//     }

//     return 0;
// }


//by d places(optimal)

// #include<bits/stdc++.h>
// using namespace std;
// void leftRotate(int a[], int n, int d){
//     reverse(a, a+d);
//     reverse(a+d,a+n);
//     reverse(a,a+n);
// }
// int main(){
//     int n,d;
//     cin>>n>>d;                           //reverse(a,a+d)
//     int a[n],x=0;                        //reverse(a+d,a+n)
//     for(int i=0;i<n;i++){                //reverse(a,a+n)
//         cin>>a[i];
//     }
//     leftRotate(a , n ,d);
//     for(int i=0;i<n;i++){
//         cout<<a[i]<<" ";
//     }

//     return 0;
// }


// move all zeroes to the end of the array
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     int j=-1;
//     vector<int> a(n);
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }
//     for(int i=0;i<n;i++){
//        if(a[i]==0){
//            j=i;
//            break;
//        }
//     }
//      if(j == -1){
//         // no zero found
//         for(int x : a) cout << x << " ";
//         return 0;
//     }
//     for(int i=j+1;i<n;i++){
//         if(a[i]!=0){
//             swap(a[i], a[j]);
//             j++;
//         }
//     }
//     for(int i=0;i<n;i++){
//         cout<<a[i]<<" ";
//     }

//     return 0;
// }


// union of two sorted arrays(brute solution)
// #include<bits/stdc++.h>
// using namespace std;

// int main() {
//     int n1, n2;
//     cin >> n1;

//     vector<int> nums1(n1);
//     for(int i = 0; i < n1; i++){
//         cin >> nums1[i];
//     }

//     cin >> n2;
//     vector<int> nums2(n2);
//     for(int i = 0; i < n2; i++){
//         cin >> nums2[i];
//     }

//     set<int> st;

//     for(int x : nums1) st.insert(x);
//     for(int x : nums2) st.insert(x);

//     vector<int> temp;
//     for(int x : st){
//         temp.push_back(x);
//     }

//     // Output
//     for(int x : temp){
//         cout << x << " ";
//     }

//     return 0;
// }

//union of two sorted arrays(optimal solution)

// #include<bits/stdc++.h>
// using namespace std;

// int main() {
//     int n1, n2;
//     cin >> n1;

//     vector<int> a(n1);
//     for(int i = 0; i < n1; i++){
//         cin >> a[i];
//     }

//     cin >> n2;
//     vector<int> b(n2);
//     for(int i = 0; i < n2; i++){
//         cin >> b[i];
//     }

//     int i=0,j=0;
//     vector<int> unionArr;
//     while(i<n1 && j<n2){
//         if(a[i]<=b[j]){
//             if(unionArr.size() == 0 || unionArr.back() != a[i]){
//                 unionArr.push_back(a[i]);
//             }
//             i++;
//         }
//         else{                                                      // tc= o(n1+n2)
//             if(unionArr.size() == 0 || unionArr.back() != b[j]){   // sc= o(n1+n2)
//                 unionArr.push_back(b[j]);
//             }
//             j++;
//         }
//     }
//     while(j<n2){
//          if(unionArr.size() == 0 || unionArr.back() != b[j]){
//                 unionArr.push_back(b[j]);
//             }
//             j++;
//     }
//        while(i<n1){
//          if(unionArr.size() == 0 || unionArr.back() != a[i]){
//                 unionArr.push_back(a[i]);
//             }
//             i++;
//     }
//      for(int x : unionArr){
//         cout << x << " ";
//     }
    
//     return 0;
// }



//intersection of sorted array(brute)

// #include<bits/stdc++.h>
// using namespace std;

// int main() {
//     int n1, n2,m;
//     cin >> m;
//     vector<int> ans;
//     int vis[m] = {0};
//     cin >> n1;
//     vector<int> a(n1);
//     for(int i = 0; i < n1; i++){
//         cin >> a[i];
//     }

//     cin >> n2;
//     vector<int> b(n2);
//     for(int i = 0; i < n2; i++){
//         cin >> b[i];
//     }                                   //tc = o(n1*n2)
//                                         //sc = 0(n2)
//     for(int i=0; i<n1; i++){
//         for(int j=0; j<n2; j++){
//             if(a[i]==b[j]&&vis[j]==0){
//                 ans.push_back(a[i]);
//                 vis[j] = 1;
//                 break;
//             }
//             if(b[j]>a[i]){
//                 break;
//             }
//         }
//     }

//     for(int x : ans){
//         cout << x << " ";
//     }
//     return 0;
// }

//intersection of sorted array(optimal)
// #include<bits/stdc++.h>
// using namespace std;

// int main() {
//     int n1, n2;
//     cin >> n1;

//     vector<int> a(n1);
//     for(int i = 0; i < n1; i++){
//         cin >> a[i];
//     }

//     cin >> n2;
//     vector<int> b(n2);
//     for(int i = 0; i < n2; i++){
//         cin >> b[i];
//     }

//     int i=0,j=0;
//     vector<int> intersection;
//     while(i<n1 && j<n2){
//         if(a[i]>b[j]){
//             j++;
//         }
//         else if(a[i]<b[j]){                            // tc = o(n1+n2)
//             i++;                                       // sc = o(1)
//         }
//         else if(a[i]=b[j]){
//                 intersection.push_back(a[i]);
            
//             i++;
//             j++;
//         }
//     }
    
//      for(int x : intersection){
//         cout << x << " ";
//     }
    
//     return 0;
// }
