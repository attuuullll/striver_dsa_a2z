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