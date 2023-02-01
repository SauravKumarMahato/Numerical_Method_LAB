#include <iostream>
#include  <cmath>

using namespace std;

int main(){
    int n ;
    cout << "Enter the order of square matrix: ";
    cin >> n ;

    float a[n][2*n] ;
    cout << "Start entering the element" << endl;
    for ( int i = 0 ; i < n ; i++){
        for ( int j = 0 ; j < n ; j++){
            cin >> a[i][j] ;
        }
    }

    // Making augmented matrix
    for ( int i = 0 ; i < n ; i++){
        for ( int j = n; j < 2*n ; j++){
            if ( j == i + n )
                a[i][j] = 1 ;
            else
                a[i][j] = 0 ;
        }
    }

    // Printing matrix
    cout<<"\nPrinting matrix after making augmented matrix as identity:\n";
    for ( int i = 0 ; i < n ; i++){
        for ( int j = 0; j < 2*n ; j++){
            cout<< a[i][j] << " ";
        }
        cout << endl;
    }

    // diagonalzing
    for ( int j = 0 ; j < n  ; j++){
        for ( int i = 0; i < n; i++){
            if ( i != j ){
                float temp = a[i][j]/a[j][j] ;
                for ( int k = 0 ; k < 2*n ; k++ )
                    a[i][k] = a[i][k] - temp * a[j][k] ;
            }
        }
    }

    // Printing matrix  after row elimination
    cout<< "\nPrinting matrix after row elimination methods:" << endl;
    for ( int i = 0 ; i < n ; i++){
        for ( int j = 0; j < 2*n ; j++){
            cout<< a[i][j] << " ";
        }
        cout << endl;
    }

    // making identity matrix in front matrix
    for ( int i = 0 ; i < n ; i++){
        float temp = a[i][i] ;
        for ( int j = 0 ; j < 2*n ; j++){
                a[i][j] = a[i][j]/ temp;
        }
    }

    // Printing matrix after making  identity on front matrix
    cout << "\nThe matrix after making identity in front matrix part: \n";
    for ( int i = 0 ; i < n ; i++){
        for ( int j = 0 ; j < 2*n ; j++){
            cout<< a[i][j] << " ";
        }
        cout << endl;
    }
    
    // Printing the inverse of the matrix
    cout << "\nThe required inverse matrix is: \n";
    for ( int i = 0 ; i < n ; i++){
        for ( int j = n ; j < 2*n ; j++){
            cout<< a[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}
