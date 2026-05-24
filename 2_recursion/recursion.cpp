#include<bits/stdc++.h>
#include<algorithm> //swap
using namespace std;

void print1(int n, int i){
    if(i>n){
        return;
    }
 cout<<"Hello World";
 cout<<endl;
    print1(n, i+1);
 }
 
void print2(int i, int n){ 
   if(i>n){
    return;
   }
   cout<<i;
   cout<<endl;
   print2(i+1, n);
    }

// Backward Printing , BACKTRACKING

void print3(int i, int n){ 
       if(i>n){
    return;
   }
   print3(i+1, n);
   cout<<i;
   cout<<endl;
   
    
 }
//lec3

// SUM OF N MUBERS USING PARAMETERS
void print4(int i, int sum){
    if(i<1){
        cout<<sum;
        return;
    }
    print4(i-1,sum+i);
}
// SUM OF N MUBERS USING FUNCTIONS
int print5(int i){
    if(i==0){
        return i;
    }

    return i + print5(i-1); 
}

//FACTORIAL OF A NUMBER
int print6(int i){
    if(i==0||i==1){
        return 1;
    }

    return i * print6(i-1); 
}
// Reverrse an array using recursion
int a[100];
void reverse(int l , int r ){
    if(l>=r){
        return;
    }
    swap(a[l],a[r]);
    reverse(l+1,r-1);
}
// int main(){
//     int n;
//     cin>>n;
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }
//     reverse(0,n-1);
//     for(int i=0;i<n;i++){
//         cout<<a[i]<<" ";
//     }
//     cout<<endl;
//     return 0;
// }

// check the string is palindrome or not ( reverse of madam is madam)
bool palindrome(int i ,char s[] ,int n){
    if(s[i]!=s[n-1-i]){
        return false;
    }
    if(i>=n/2){
        return true;
    }
    palindrome(i+1 , s, n);
}
// int main(){
//     char s[500];
//     cin>>s;
//     int n=strlen(s);
//     cout << (palindrome(0, s, n) ? "Palindrome" : "Not Palindrome") << endl;
//     return 0;
// }

// Fibonacci number

int Fibonacci(int i){
    if(i<=1){
        return i;
    }
    
        return Fibonacci(i-1) + Fibonacci(i-2);
}

int main(){
    int n;
    cin>>n;
    for(int j=0; j<n ; j++){
        cout<<Fibonacci(j)<<" ";
    }
     
     return 0;
}


