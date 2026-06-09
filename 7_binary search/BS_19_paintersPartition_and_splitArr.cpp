//    painters partition/split array largest sum   both problem are same 


//  split arr largest sum = split the arr into k subarr such that the max subarr sum is min









#include<bits/stdc++.h>
using namespace std;
int fff(vector<int> a, int pages){
    int student = 0;
    int currPages = 0;
    for(int i = 0; i < a.size(); i++){
        if(currPages+a[i]>pages){
            currPages = a[i];
            student++;
        }
        else{
            currPages += a[i];
        }
    }
    student ++;
    return student;
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int student;
    cin>>student;
    int low = *max_element(a.begin(), a.end());   //atleast everyone can hola a book
    int high = accumulate(a.begin(), a.end(), 0);
    int ans = high;
    while(low<=high){
        int mid = low + (high-low)/2;
        int x = fff(a,mid);
        if(x>student){
            low = mid+1;
        }
        else{
            ans = mid;
            high = mid-1;
        }
    }
    cout<<ans;   
    return 0;
}