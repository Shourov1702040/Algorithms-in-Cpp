#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>
#include <iomanip>
#include <stdlib.h>
using namespace std;

double abs(double ABS)
{
    return sqrt(ABS*ABS);
}

double chop(double CHOP)
{
    if (abs(CHOP) < pow(10,-15))
    {
        CHOP = 0;
    }
    return CHOP;
}

int main()
{
    int i,j,m,N,n,w=15;

    // Define size of system
    cout << "Solve system [A.x = b] using Jacobi Iteration"<< endl << endl << "Enter 'N', the size of the system:" << endl;
    cin >> N;
    n = N - 1;

    double A[N][N],b[N],x[N][1000],xnorm,errtol=pow(10,-10),sum[N];

    // Define matrix A (coefficient matrix)
    cout << endl << "Enter coefficients of " << N << "*" << N << " system:" << endl;
    for(j=0;j<=n;j=j+1)
    {
        for (i=0;i<=n;i=i+1)
        {
            cin >> A[j][i];
        }
    }

    // Define constant vector b
    cout << endl << "Enter " << N << " constants of RHS of system:" << endl;
    for(j=0;j<=n;j=j+1)
    {
        cin >> b[j];
    }

    // Define initial guess for vector x that solves [A.x = b]
    m=0;
    for(j=0;j<=n;j=j+1)
    {
        x[j][m] = j + 1;
    }

    // Print system as check
    cout << endl << "System:" << endl;
    for(j=0;j<=n;j=j+1)
    {
        for(i=0;i<=n;i=i+1)
        {
            cout << A[j][i];
            if (i<n)
            {
                cout << setw(5);
            }
        }
        cout << " | " << b[j] << endl;
    }

    // Start output table
    cout << endl << "m";
    for(j=0;j<=n;j=j+1)
    {
        cout << setw(w-1) << "x" << j;
    }
    cout << setw(w) << "||X||2" << endl;
    cout << m;
    for(j=0;j<=n;j=j+1)
    {
        cout << setw(w) << x[j][m];
    }
    cout << setw(w) << "-" << endl;

    // Jacobi algorithm
    do
    {
        m = m + 1;

        // Iterate one row at a time (x0,x1,...,xn)
        for (j = 0; j <= n; j = j + 1)
        {
            sum[j] = 0;

            // for x0
            if ((j = 0))
            {
                for (i = 1; i <= n; i++)
                {
                    sum[j] = sum[j] + (A[j][i]*x[i][m - 1]);
                }
                x[j][m] = (1/A[j][j])*(b[j] - sum[j]);
            }

            // for x1,...,xn-1
            else if ((j > 0) && (j < n))
            {
                for (i = 0; i < j; i++)
                {
                    sum[j] = sum[j] + (A[j][i]*x[i][m - 1]);
                }
                for (i = j + 1; i <= n; i++)
                {
                    sum[j] = sum[j] + (A[j][i]*x[i][m - 1]);
                }
                x[j][m] = (1/A[j][j])*(b[j] - sum[j]);
            }

            // for xn
            else if ((j = n))
            {
                for (i = 0; i < n; i++)
                {
                    sum[j] = sum[j] + (A[j][i]*x[i][m - 1]);
                }
                x[j][m] = (1/A[j][j])*(b[j] - sum[j]);
            }
        }

        // Calculate two norm of error vector (X[m]-X[m-1])
        for(xnorm=0,j=0;j<=n;j=j+1)
        {
            xnorm = xnorm + pow(x[j][m]-x[j][m-1],2);
        }
        xnorm = sqrt(xnorm);

        // Print results of current iterate
        cout << m;
        for(j=0;j<=n;j=j+1)
        {
            cout << setw(w) << x[j][m];
        }
        cout << setw(w) << xnorm << endl;
    } while ((xnorm > errtol) && (m<1000));

    // Format final results
    cout << endl << "x[" << m << "] that solves [A.x = b] = {";
    for (j=0;j<=n;j=j+1)
    {
        cout << x[j][m];
        if (j<n)
        {
            cout << ", ";
        }
    }
    cout << "}T" << endl;

    // Print info
    cout << endl << "Copyright © 2016 Kyle James Hansen. All rights reserved. ";
}
