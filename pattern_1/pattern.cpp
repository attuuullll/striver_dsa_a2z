#include<iostream>
using namespace std;
void print1(int n){
    for(int i=0; i<n ;i++){
        for(int i=0 ; i<n ;i++){
            cout<<"*";
        }
        cout<<endl;
    }
 }


void print3(int n){
    for(int i=0 ; i<n ; i++){
        int x=1 ;
        for(int j=0 ; j<=i ; j++){
            cout<<x;
            x++;
        }
        cout<<endl;
    }
 }

void print4(int n){ 
    int x=1;
    for(int i=0 ; i<n ; i++){       
        for(int j=0 ; j<=i ; j++){
             cout<<x;   
        }
        x++;
        cout<<endl;
    }
 }

void print5(int n){
    for(int i=n ; i>0 ; i--){
        for(int j=0 ; j<i ; j++){
             cout<<"*";
        }
       
        cout<<endl;
    }
 }

void print6(int n){
    for(int i=n ; i>0 ; i--){
        for(int j=0 ; j<i ; j++){
             cout<<"*";
        }
       
        cout<<endl;
    }
 }

void print7(int n){
    int count=1;
    for(int i=0 ; i<n ; i++){
        for(int j=i;j<n-1;j++){
            cout<<" ";


        }
        for(int k=0 ;k<count ;k++){
            cout<<"*";
            
        }
        count+=2;
        cout<<endl;
    }
 }
void print8(int n){
    for(int i=0 ; i<n ; i++){
        
        for(int k=0 ; k<i ; k++){
                  printf(" ");  
        }
        for(int j=0 ; j<2*(n-i)-1 ; j++){
             printf("*");

        }
        printf("\n");
    }
 }
void print9(int n){ 
   for(int i=0;i<=2*n-1; i++){
     int stars=i;
     if(i>n){ 
      stars=2*n-i;
     }
        for(int j=0;j<stars;j++){
     cout<<"*";
    }
    cout<<endl;
    }
 }
void print10(int n){ 
    
   for(int i=0;i<=n; i++){
      int x=1;
    if(i%2==0){
        x=1;
    }
    else{
        x=0;
    }
    for(int j=0;j<i;j++){
     cout<<x<<" ";
     if(x==1){
        x=0;
     }
     else{
        x=1;
     }
    }
    cout<<endl;
    }
 }
void print11(int n){ 
    
   for(int i=0;i<=n; i++){
        int x=1;
         for(int k=0;k<i; k++){ 
            cout<<x; 
            x++;
         }
         x-=1;
         for(int l=0;l<2*(n-i); l++){
               cout<<" ";
          }
          for(int j=i;j>0; j--){ 
            cout<<x;
            x--;       
           }
           cout<<endl;
 }
 }
void print12(int n){ 
    int x=1;
   for(int i=0;i<=n; i++){
    for(int j=0;j<i;j++){
     cout<<x<<" ";
        x++;
    
    }
    cout<<endl;
 }
}
int main(){
    int t;
    cin>>t;
    for (int i=0 ; i<t ; i++){
        int n;
        cin>>n;
        print12(n);
    }

return 0;
}
