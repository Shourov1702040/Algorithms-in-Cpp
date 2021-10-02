#include<stdio.h>
#include<conio.h>
#include<math.h>
#define e 0.01
void main()
{
 int i,j,k,n;
    float a[10][10],x[10];
    float sum,temp,error,big;
    printf("Enter the number of equations: ");
    scanf("%d",&n) ;
    printf("Enter the co-efficients of the equations: \n");
 for(i=1;i<=n;i++)
 {
 for(j=1;j<=n+1;j++)
 {
 printf("a[%d][%d]= ",i,j);
 scanf("%f",&a[i][j]);
 }
 }
 for(i=1;i<=n;i++)
 {
 x[i]=0;
 }
 do
 {
 big=0;
 for(i=1;i<=n;i++)
 {
 sum=0;
 for(j=1;j<=n;j++)
 {
 if(j!=i)
 {
 sum=sum+a[i][j]*x[j];
 }
 }
 temp=(a[i][n+1]-sum)/a[i][i];
 error=fabs(x[i]-temp);
 if(error>big)
 {
 big=error;
 }
 x[i]=temp;
 printf("\nx[%d] =%f",i,x[i]);
 }printf("\n");
 }
 while(big>=e);
 printf("\n\nconverges to solution");
 for(i=1;i<=n;i++)
 {
 printf("\nx[%d]=%f",i,x[i]);
 }
 getch();
}
