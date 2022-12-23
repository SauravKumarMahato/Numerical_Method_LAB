#include<iostream>
#include<cmath>

using namespace std;

float func( float x){ return x*sin(x) + cos(x) ; }

float dfunc( float x){ return x*cos(x); }

float root(float x ){
    int count=0;
    while ( abs(func(x)) > 0.0005 )
    {
        if ( dfunc(x) == 0 ){
            cout<< "root is not valid " << endl;
        }
        else{
            x = x - func(x)/dfunc(x);
        }
        if ( count == 100){ cout<< "value not found "; }
        else{ count++ ;}
    }
    return x ;
}
int main(){
    float x;
    cout<< "Enter  initial guess x0: ";
    cin>> x;
    cout<< "Required approximated root is: "<< root(x) << endl;

    return 0;
}
