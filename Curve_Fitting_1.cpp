#include<iostream>
#include<cmath>

using namespace std;

float  deter( float a, float b , float c  , float d){
    return (a*d -b*c);
}

int main(){
    float a=0, b=0;
    int n=0;
    cout<< "Enter the no of data : ";
    cin>> n;
    float x[n] ;
    float y[n] ;

    float X=0 , Y=0, XY=0, X2=0 ;

    cout<< "Enter the values of x : ";
    for( int i = 0; i< n ; i++){
        cin>> x[i];
    }

    cout<< "Enter the values of y : ";
    for( int i = 0; i< n ; i++){
        cin>> y[i];
    }

    for ( int i=0 ; i< n ; i++){
        X += x[i];
        Y += y[i];
        XY += x[i] * y[i] ;
        X2 += x[i] * x[i];
    }

    a = deter(Y, X, XY, X2)/deter(n, X, X, X2);
    b = deter( n, Y, X, XY)/ deter(n, X, X, X2);

    cout<< "The required linear curve to fit the given data is: \n"
        << "y = "<< a << " + " << b << "x"<<  endl;

    return 0;
}

