#include<iostream>
#include<cmath>

using namespace std;

float deri( float x, float y ){
    return x+y ;
}

void  euler(float x0, float y0, float xn , float h ){
    float x= x0, y=y0;

    for (float i = x0 ; i <= xn ; i += h ){
        cout<< x << "   " << y << endl;
        y = y + h * deri(x, y);
        x = x + h;
    }
    cout<< x << "   " << y << endl;
    cout<< "The required sol at x ="<< xn << " is : " << y << endl;

}
void  rk2(float x0, float y0, float xn , float h ){
    float x= x0, y=y0,  k1 =0 , k2 = 0, k=0 ;

    for (float i = x0 ; i <= xn ; i += h ){
        cout<< x << "   " << y << endl;
        k1 = h* deri(x, y);
        k2 = h* deri(x + h , y + k1 );
        k = (k1 + k2)/2;
        y = y + k;
        x = x + h;
    }
    cout<< x << "   " << y << endl;
    cout<< "The required sol at x ="<< xn << " is : " << y << endl;

}

void  rk3(float x0, float y0, float xn , float h ){
    float x= x0, y=y0,  k1 =0 , k2 = 0, k3 = 0, k4 = 0,  k=0 ;

    for (float i = x0 ; i <= xn ; i += h ){
        cout<< x << "   " << y << endl;
        k1 = h* deri(x, y);
        k2 = h* deri(x + h/2 , y + k1/2 );
        k3 = h* deri(x + h/2 , y + k2/2 );
        k4 = h* deri( x + h, y + k3);
        k = (k1 + 2*k2 + 2*k3 + k4)/6;
        y = y + k;
        x = x + h;
    }
    cout<< x << "   " << y << endl;
    cout<< "The required sol at x ="<< xn << " is : " << y << endl;

}
int main(){
    float x0=0, y0=0 ,xn =0,  h=0;
    cout<< "Enter the  value of x0, y0, xn and interval h: ";
    cin>> x0 >>  y0 >> xn >> h ;

    euler(x0, y0, xn, h );
    rk2( x0, y0, xn, h );
    rk3( x0, y0, xn, h );
    return 0;
}
