#include<iostream>
#include<cmath>

using namespace std;

float func(float x ){
    return x*sin(x) + cos(x);
}

float root(float a , float b ) {
    float c ;
    do{
        c = (a+b)/2;

        if ( func(c)*func(a) < 0 ){
            b = c;
        }
        else if ( func(c) == 0 )
        {
            return c ;
        }
        else{
            a = c ;
        }
    }while( abs(func(c)) > 0.0005);

    return c ;
}

int main()
{
    float a,b;

    cout<<"enter the initial guess: a,b = ";
    cin >> a >> b;

    if ( (func(a)* func(b) ) < 0 ){
        cout<<"Root lies between "<< a << " , " << b << endl;
        cout<< "The required root is : "<< root(a,b) << endl;
    }
    else{
        cout<<"Root doesn't lies in between "<< a << " , " << b << endl;
    }

    return 0;
}
