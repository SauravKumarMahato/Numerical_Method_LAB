#include<iostream>
#include <cmath>

using namespace std;

int main(){
    int n ;
    cout << "Enter the variables: ";
    cin >> n ;

    double arr[n][n+1] ;
    cout << "Start entering the element" << endl;
    for ( int i = 0 ; i < n ; i++){
        for ( int j = 0 ; j < n+1 ; j++){
            cin >> arr[i][j] ;
        }
    }

    for ( int j = 0 ; j < n-1; j++){
        if (  abs(arr[j][j]) <= 0.0005 ){
            cout<< "cannot calculate roots";
            return 0;
        }
        for ( int i = j+1 ; i < n; i++){
            if ( i != j ){
                double temp = arr[i][j]/arr[j][j] ;
                for ( int k = 0 ; k < n+1 ; k++ ){
                    arr[i][k] = arr[i][k] - temp * arr[j][k] ;
                }

            }
        }
    }

    cout<< "\nIn matrix form after row operation, we get: " << endl;
     for ( int i = 0 ; i < n ; i++){
        for ( int j = 0 ; j < n+1 ; j++){
            cout << arr[i][j] << " " ;
        }
        cout<< endl;
    }


    double x[n] ;
    x[n-1] = arr[n-1][n]/arr[n-1][n-1];
    for ( int i =  n-2 ; i >= 0  ; i-- ){
        double s = 0;
        for  ( int j = i + 1 ; j <= n ; j++ ){
            s = s + arr[i][j] * x[j];
        }
        x[i] =( arr[i][n] - s )/arr[i][i] ;
    }

    cout << "\nThe required roots are: \n";
    for ( int i = 1 ; i <= n ; i++ ){
        cout <<"x"<< i << " = " << x[i-1]<< " ,";
    }

    return 0;
}
