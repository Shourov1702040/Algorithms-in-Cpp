using namespace std;

#include <iostream>
#include <fstream>
#include <cmath>

//global varibles
ifstream Infile;
int i, n;
float x[15],y[15], sumXY, sumX2;
float m, b, A, B, C, D;

//functional prototypes
float sumX();
float sumY();
float slope();

int main()
{
Infile.open("regressionData.txt");
while(!Infile.eof())
{
Infile>>x[i]; Infile>>y[i];
cout<<x[i]<<"  "<<y[i]<<endl<<endl;
i++;
}
Infile.close();
n=i-1;

cout<<"The number of data points is "<<n<<endl;

cout<<"The value of sumX is "<<sumX()<<endl;

cout<<"The value of sumY is "<<sumY()<<endl;

sumXY = sumX() * sumY();
cout<<"The value of sumXY is "<<sumXY<<endl;

sumX2 = sumX2 + sumX() * sumX();
cout<<"X2 "<<sumX2<<endl;

cout<<"The linear regression equation is "<<"y="<<slope()<<"x-"; cout<<b<<endl;

return 0;
}

float sumX()
{
  int i;
  float sumX=0;

  for(i=0; i<=n; i++)
       sumX = sumX + x[i];

	return sumX;
}

float sumY()
{
  int i;
  float sumY=0;

  for(i=0; i<=n; i++)
       sumY = sumY + y[i];

 	return sumY;
}

float slope()
{
	int i;
	float slope=0;

	A=sumX();
	B=sumY();
	C=sumX2;
	D=sumXY;


	for(i=0; i<=n; i++)
	{

	A +=x[i];//sumX
        B +=y[i];//sumY
        C +=x[i]*x[i];
        D +=x[i]*y[i];//sumXY
	}

          slope = (n*D-A*B) / (n*C-A*A);
	  b = (B-slope*A) / n;

return slope;

}
