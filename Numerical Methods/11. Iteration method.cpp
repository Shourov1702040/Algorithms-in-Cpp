#include <iostream>
#include <math.h>
using namespace std;

class FixedPoint
{
public:
    void askEqn();
    double g(double x);
    void solve();
    void findError();
    void askX0();
    void display();
private:
    double a,b,c;
    double Error;
    double x0,x1;


};

void FixedPoint::askX0()
{
    cout << "Enter initial value of X0: ";
    cin >> x0;
}

void FixedPoint::askEqn()
{
    cout << "For the eqn ax*x + bx + c = 0 , Enter a,b,c,d:\n";
    cin >>a>>b>>c;
}
double FixedPoint::g(double x)
{
    return -(a*x*x + c) / b;
}

void FixedPoint::findError()
{
    Error = fabs( (x1-x0)/x1 );
}

void FixedPoint::solve()
{
    askEqn();
    askX0();
    cout << endl << endl << "S.N.\tXi\tXi+1\tError\n";
    do{
        x1 = g(x0);
        findError();
        display();
        x0 = x1;
    }while(Error>=0.0009);

    cout << endl<< "The root is : " << x1 <<  endl;
}
void FixedPoint::display()
{
    static int i;
    cout << ++i << "\t" << x0 << "\t" << x1 << "\t" << Error << endl;
}
int main()
{
    FixedPoint f1;
    f1.solve();
    return 0;
}

