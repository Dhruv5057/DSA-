#include<iostream>
#include<vector>
#include<algorithm>

//#include <bits/stdc++.h>
using namespace std ; 
int main(){
    int t ; cin >> t ; 
    while(t--){
        string a ; 
        cin >> a ;
        for(int i = 0 ; i < a.length() ; i++) {
            if(a[i] == 'q') {
                a[i] = 'p' ; 
            }
            else if(a[i] == 'p') {
                a[i] = 'q'; 
            }
        }
        reverse(a.begin(), a.end()) ; 

        cout << a << endl ;

        
    }
}