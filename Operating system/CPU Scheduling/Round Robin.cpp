#include<iostream> 
using namespace std; 

void findWaitingTime(int n, int bt[], int wt[], int quantum) 
{
	int rem_bt[n]; 
	for (int i = 0 ; i < n ; i++) 
		rem_bt[i] = bt[i]; 
	int t = 0; // Current time 
	while (1) 
	{ 
		bool done = true; 
		for (int i = 0 ; i < n; i++) 
		{ 
			if (rem_bt[i] > 0) 
			{ 
				done = false; 
				if (rem_bt[i] > quantum) 
				{ 
					t += quantum;  
					rem_bt[i] -= quantum; 
				} 
				else
				{ 
					t = t + rem_bt[i]; 
					wt[i] = t - bt[i]; 
					rem_bt[i] = 0; 
				} 
			} 
		} 
		if (done == true) 
		break; 
	} 
} 
void findTurnAroundTime(int n, int bt[], int wt[], int tat[]) 
{ 
	for (int i = 0; i < n ; i++) 
		tat[i] = bt[i] + wt[i]; 
} 
int main() 
{  
	int n,i, bt[20], quantum, wt[20], tat[20];
	float total_wt = 0, total_tat = 0;

	cout<<"Enter time quantam: ";
	cin>>quantum;
	cout<<"Enter the number of process: ";
	cin>>n;
	cout<<"Enter Process Burst Time:"<<endl;
	for(i=0;i<n;i++){
		cout<<"P["<<i+1<<"]:";
		cin>>bt[i];
	}
	findWaitingTime(n, bt, wt, quantum);
	findTurnAroundTime(n, bt, wt, tat); 
	cout << "Processes "<< " Burst time " << " Waiting time " << " Turn around time\n"; 
	for (int i=0; i<n; i++) 
	{ 
		total_wt = total_wt + wt[i]; 
		total_tat = total_tat + tat[i]; 
		cout << " " << i+1 << "\t\t" << bt[i] <<"\t " << wt[i] <<"\t\t " << tat[i] <<endl; 
	} 
	cout << "Average waiting time = " << total_wt << endl; 
	cout << "\nAverage turn around time = " << total_tat <<endl;

	return 0; 
}
