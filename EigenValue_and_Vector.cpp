#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main(){
    int n = 0;
    cout << "enter the order of matrix:  " << endl;
    cin >>  n;

    float a[n][n], x[n];

    // enter eigeon  vector
    cout <<  "enter sample eigeon  vector: "<< endl;
    for ( int i = 0 ; i < n; i++)
        cin >> x[i] ;

    // print eigeon vector
    /* cout << "Printing eigeon vector : " << endl;
    for ( int i = 0 ; i < n; i++)
        cout << x[i] << setw(10);
    */

    // enter vector
    cout << "\n\nEnter the matrix: "<< endl;
    for ( int i = 0 ; i < n; i++){
        for ( int j = 0 ; j < n; j++)
            cin >> a[i][j] ;
    }

    // printing  vectors
    /*  cout << "Printing vector : " << endl;
    for ( int i = 0 ; i < n; i++){
        for ( int j = 0 ; j < n; j++)
            cout << setw(10) <<  a[i][j] ;
        cout << endl;
    }
    */


    float zmax = 0;
    float  y[n];
    float d[n];
    float dmax = 0;

    do {
        // Matrix Multiplication
        float z[n];
        for ( int i = 0 ; i < n; i++){
            float sum = 0;
            for ( int j = 0 ; j < n ; j++)
                sum += a[i][j] * x[j] ;
            z[i] = sum;
        }

        // Calculating maxima in z
        zmax = z[0];
        for ( int i = 0; i < n ; i++ ){
            if ( zmax < z[i])
                zmax = z[i];
        }

        // Dividing vector by zmax
        for ( int i = 0; i < n ; i++ ){
                y[i] = z[i]/zmax;
        }

        // difference old and new matrix along with  initializing new x with y
        for ( int i = 0; i < n ; i++ )
        {
            d[i] = abs( y[i] - x[i]);
            x[i] = y[i];
        }


         dmax=d[0];
        for ( int i = 0; i < n ; i++ ){
            if ( dmax < d[i])
                dmax = d[i];
        }

    }while ( dmax > 0.0005 );

    cout << "Largest Eigeon Value Zmax = " << zmax << endl;
    cout << "The req. eigeon vector is: " << endl;
    for ( int i = 0 ; i < n; i++)
        cout << y[i] << setw(10);


    return 0;
}
