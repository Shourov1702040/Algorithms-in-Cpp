#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, i, j, index[20];
    float bt[20], wt[20], tat[20], avwt=0, avtat=0;
    cout<<"Enter Number of Processes: ";
    cin>>n;

    cout<<"Enter Process Burst Time:"<<endl;
    for(i=0;i<n;i++){
        cout<<"P["<<i+1<<"]:";
        cin>>bt[i];
        index[i]=i;
    }

    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            if(bt[j]<bt[i])
            {
                swap(bt[i], bt[j]);
                swap(index[i], index[j]);
            }
        }
    }

    wt[0]=0;
    cout<<endl<<"Process\t\tBurst Time\tWaiting Time\tTurnaround Time"<<endl;
    for(i=0;i<n;i++){
        wt[i+1]= wt[i]+bt[i];
        tat[i]= wt[i]+bt[i];
        avwt=avwt+wt[i];
        avtat=avtat+tat[i];
        cout<<"P["<<index[i]+1<<"]\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<endl;
    }

    cout<<endl<<"Average Waiting Time: "<<avwt/i<<endl;
    cout<<"Average Turnaround Time: "<<avtat/n<<endl;
    return 0;
}
