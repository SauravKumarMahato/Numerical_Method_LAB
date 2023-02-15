/**

 *	 @author: Saurav Kumar Mahato
 *	 @desc: Trapezoidal Rule, Simpson's 1/3 rule and Simpson's 3/8 rule
 *	 @time: Wednesday 15-February-2023 20:58:39

**/

#include <iostream>
#include <cmath>
using namespace std;

float F(float x)
{
    return (1 - exp(-(x) / 2.0));
}

void trapezoial(float a, float b, float h, float n)
{
    float sum = 0, integral = 0;
    sum = F(a) + F(b);

    for (size_t i = 0; i < n - 1; i++)
    {
        sum += 2 * F(a + h * i);
    }

    integral = sum * h / 2;
    cout << "\nThe approximate integral using Trapezoidal method is: \n"
         << integral;
}

void simpsonOneThird(float a, float b, float h, float n)
{
    float sum = 0, integral = 0;
    int m = n / 2;

    float f1 = F(a);
    for (size_t i = 1; i <= m; i++)
    {
        float f2 = F(a + h);
        float f3 = F(a + 2 * h);
        sum += f1 + 4 * f2 + f3;
        f1 = f3;
        a = a + 2 * h;
    }
    integral = sum * h / 3;
    cout << "\nThe approximate integral using Simpson's 1/3 method is: \n"
         << integral;
}

void simpsonThreeEight(float a, float b, float h, float n)
{
    float integral=0, k = 0;
    integral = F(a) + F(b);
    for (size_t i = 1; i <= n - 1; i++)
    {
        k = a + i * h;
        if (i % 3 == 0)
            integral = integral + 2 * (F(k));
        else
            integral = integral + 3 * (F(k));
    }
    integral = integral * h * 3.0 / 8.0;
    cout << "\nThe approximate integral using Simpson's 3/8 method is: \n"
         << integral;
}

int main()
{
    int n;
    float a, b, h;
    cout << "enter initial value of x : ";
    cin >> a;
    cout << "enter final value of x : ";
    cin >> b;
    cout << "enter segment width : ";
    cin >> h;

    n = (b - a) / h;
    trapezoial(a, b, h, n);
    simpsonOneThird(a, b, h, n);
    simpsonThreeEight(a, b, h, n);

    return 0;
}
