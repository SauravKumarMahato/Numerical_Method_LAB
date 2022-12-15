#include <iostream>
#include <cmath>

using namespace std;

float func(float x)
{
    return x * sin(x) + cos(x);
}

float root(float a, float b)
{
    float X , Y ;
    float c;

    do
    {
        X = func(a);
        Y = func(b);

        if( X == Y ){
            cout<< "The root doesn't exist"<< endl;
            break;
        }
        else{
            c = (a*Y - b*X)/(Y - X);
            if( func(c) <= 0.0005){ return c; }
            a = b ;
            b = c ;

        }

    } while (abs(func(c)) > 0.0005);

    return c;
}

int main()
{
    float a, b;

    cout << "enter the initial guess: a,b = ";
    cin >> a >> b;

    cout << "The required root is : " << root(a, b) << endl;

    cout << "Root doesn't lies in between " << a << " , " << b << endl;

    return 0;
}
