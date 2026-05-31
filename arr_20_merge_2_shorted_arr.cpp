// merging 2 shorted array without using extra space 

//tc->O(n+m)   sc->O(n+m)
// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int n, m;
//     cin >> n >> m;
//     long long arr1[n], arr2[m];
//     for(int i = 0; i < n; i++){
//         cin >> arr1[i];
//     }
//     for(int i = 0; i < m; i++){
//         cin >> arr2[i];
//     }
//     long long arr3[n + m];
//     int left = 0;
//     int right = 0;
//     int index = 0;
//     while(left < n && right < m){
//         if(arr1[left] <= arr2[right]){
//             arr3[index] = arr1[left];
//             left++;
//             index++;
//         }
//         else{
//             arr3[index] = arr2[right];
//             right++;
//             index++;
//         }
//     }
//     while(left < n){
//         arr3[index++] = arr1[left++];
//     }
//     while(right < m){
//         arr3[index++] = arr2[right++];
//     }
//     for(int i = 0; i < n + m; i++){
//         if(i < n){
//             arr1[i] = arr3[i];
//         }
//         else{
//             arr2[i - n] = arr3[i];
//         }
//     }
//     for(int i = 0; i < n; i++){
//         cout << arr1[i] << " ";
//     }
//     cout << endl;
//     for(int i = 0; i < m; i++){
//         cout << arr2[i] << " ";
//     }
//     return 0;
// }



//mine tc-->O(n×m+mlogm)   sc->O(1)
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n,m;
//     cin>>n>>m;
//     int a[n], b[m];
//     for(int i = 0; i < n; i++){
//         cin>>a[i];
//     }
//     for(int i = 0; i < m; i++){
//         cin>>b[i];
//     }
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < m; j++){
//             if(b[j]<a[i]) swap(b[j],a[i]);
//         }
//     }
//     for(int i = 0; i < n; i++){
//         cout<<a[i]<<" ";
//     }
//     sort(b,b+m);
//     for(int i = 0; i < m; i++){
//         cout<<b[i]<<" ";
//     }
//     return 0;
// }


//1st optimal solution tc->O(min(n,m)+nlogn+mlogm)   sc->O(1)
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n,m;
//     cin>>n>>m;
//     int a[n], b[m];
//     for(int i = 0; i < n; i++){
//         cin>>a[i];
//     }
//     for(int i = 0; i < m; i++){
//         cin>>b[i];
//     }
//     int left=n-1;
//     int right=0;
//     while(left>=0&&right<m){
//         if(a[left]>b[right]){
//             swap(a[left],b[right]);
//             left--;
//             right++;
//         }
//         else{
//              break;
//         }       
//     }
//     sort(a,a+n);
//     sort(b,b+m);
//     for(int i = 0; i < n; i++){
//         cout<<a[i]<<" ";
//     }
//     for(int i = 0; i < m; i++){
//         cout<<b[i]<<" ";
//     }
//     return 0;
// }

//2nd optimal sol  tc-> O((n+m)log(n+m))    sc->O(1)
#include<bits/stdc++.h>
using namespace std;

int nextGap(int gap){
    if(gap <= 1) return 0;
    return (gap / 2) + (gap % 2);
}

int main(){
    int n,m;
    cin >> n >> m;

    int a[n], b[m];

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < m; i++){
        cin >> b[i];
    }

    int gap = nextGap(n + m);

    while(gap > 0){

        int i = 0;
        int j = gap;

        while(j < n + m){

            if(i < n && j < n){
                if(a[i] > a[j]){
                    swap(a[i], a[j]);
                }
            }

            else if(i < n && j >= n){
                if(a[i] > b[j - n]){
                    swap(a[i], b[j - n]);
                }
            }

            else{
                if(b[i - n] > b[j - n]){
                    swap(b[i - n], b[j - n]);
                }
            }

            i++;
            j++;
        }

        gap = nextGap(gap);
    }

    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }

    cout << endl;

    for(int i = 0; i < m; i++){
        cout << b[i] << " ";
    }

    return 0;
}