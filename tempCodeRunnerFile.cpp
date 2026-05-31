#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int &x : a){
        cin>>x;
    }
    int sum =0;
    for(int i = 0; i < n; i++){
        sum += a[i];
    }
    int Rsum = (n*(n+1)/2);
    int d = Rsum - sum;
    for(int i = d+1; i <=n; i++){
        if(find(a.begin(), a.end(), i) != a.end()){
            continue;
        }
        else{
            cout<<"missing no: = "<<i<<endl;
            cout<<"repeating no: "<<i-d;
            break;
        }
    }
    return 0;
}