#include <iostream>
#include<cmath>
#include<iomanip>

using namespace std;

double fun(double x)
{
    double c;
    c = x*x-4*x-10; /* Equation */
  return(c);
}

const double TOL=1e-5;

int main()
{
    double x3,x1,x2,xs,f1,f2,f3;
    int iter=0;
    cout << "Enter brackting numbers x1, x2" << endl;
    cin>>x1>>x2;

    f1=fun(x1);
    f2=fun(x2);

    if((f1*f2)>0)
        {
            cout<<"\nDoesn't bracket...\n";
         }
    else
    {
        do
        {
            xs=x3;
            x3=x1-(f1*(x2-x1))/(f2-f1);
            f3=fun(x3);
            iter++;

            cout<<setprecision(10)<<setw(3)<<iter<<setw(15)<<x1<<setw(15)<<x2<<setw(15)<<fun(x3)<<endl;

            if((f1*f3)<0)

                x2=x3;
            else
                x1=x3;
                f1=fun(x1);
                f2=fun(x2);
        }while(fabs(fun(x3))>=TOL);//Terminating case
    }
    cout<<"\nThe root of the equation is :"<<x3;
    cout<<"\n\nf(x)="<<fun(x3);
    return 0;
}
