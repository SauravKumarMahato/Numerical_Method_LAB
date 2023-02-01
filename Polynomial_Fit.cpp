#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int d = 0, n = 0;
    cout << "enter the no of data : ";
    cin >> n;
    cout << "Enter the degree of equation: ";
    cin >> d;

    float x[n], y[n];
    float a[d + 1][d + 2];

    if (n > d)
    {
        // asking to enter data
        cout << "Start entering data : " << endl;
        for (int i = 0; i < n; i++)
            cin >> x[i];
        for (int i = 0; i < n; i++)
            cin >> y[i];
    }
    else{
        cout << "Not enough data " << endl;
        exit(0);
    }

    for (int i = 0; i <= d; i++)
    {
        for (int j = 0; j <= d; j++)
        {
            float sum = 0;
            for (int k = 0; k < n; k++)
                sum = sum + pow(x[k], i + j);
            a[i][j] = sum;
        }
    }

    for (int i = 0; i <= d; i++)
    {
        float sum = 0;
        for (int k = 0; k < n; k++)
        {
            sum += pow(x[k], i) * y[k];
        }
        a[i][d + 1] = sum;
    }

    // Printing the matrix
    cout << "\nPrinting the matrix: " << endl;
    for (int i = 0; i <= d; i++)
    {
        for (int j = 0; j <= d + 1; j++)
            cout << setw(10) << a[i][j] << " ";
        cout << endl;
    }

    // Gauss Jordan
    for (int j = 0; j <= d; j++)
    {
        for (int i = 0; i <= d; i++)
        {
            if (i != j)
            {
                float temp = a[i][j] / a[j][j];
                for (int k = 0; k <= d + 1; k++)
                    a[i][k] = a[i][k] - temp * a[j][k];
            }
        }
    }

    // Printing the matrix
    cout << "\nPrinting the matrix: " << endl;
    for (int i = 0; i <= d; i++)
    {
        for (int j = 0; j <= d + 1; j++)
            cout << setw(10) << a[i][j] << " ";
        cout << endl;
    }

    float ans[d + 1];
    // Calculating roots
    for (int i = 0; i <= d; i++)
        ans[i] = a[i][d + 1] / a[i][i];

    // printing the equation
    cout << "y = ";
    for (int i = 0; i <= d; i++)
    {
        cout << ans[i] << "x^(" << i << ") ";
        if (i != d)
            cout << "+ ";
    }
    return 0;
}
