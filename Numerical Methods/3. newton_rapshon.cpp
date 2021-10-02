#include<iostream>
#include<cmath>

using namespace std;

float f(float(x))
{
       return (pow(x,2)-(2*x)-3);
}

float g(float(x))
{
       return (2*x-2);
}

int main()
{
       float a,b,d,i,n;
       cout<<"Given algebric equation is x^2-2x-3 "<<endl;
       cout<<"Enter the initial guess of the root "<<endl;
       cin>>a;
       cout<<"Enter the number of Iterations "<<endl;
       cin>>i;
       if(f(a) != 0.0)
       {
              for(n=1;n<=i;n++)
              {
                     b=a-(f(a)/g(a));
                     if(f(b)==0)
                     {
                           cout<<"i = "<<n<<" Root of the given equation is "<<b<<endl;
                     }
                     else
                     {
                           d=fabs((b-a)/b);
                           cout<<"i = "<<n<<" a = "<<a<<" b = "<<b<<" |E| = "<<d*100<<" % "<<endl;
                           a=b;
                     }
              }
              cout<<"Root of the given equation is "<<b<<endl;
       }
       else
       {
              cout<<"Root of the given equation is "<<a<<endl;
       }
       return 0;
}
