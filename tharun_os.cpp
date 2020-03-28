#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cout<<"Enter no. of processes"<<endl;
	cin>>n;
	int wt[n]={0},bt[n]={0},at[n]={0},tat[n]={0};
	float pri[n]={0.0};
	bool done[n]={0};
	int ma,mi,tot_sum,avg_wt,avg_tat,m=INT_MIN,pos=0,time;
	ma=mi=INT_MAX;
	tot_sum=avg_wt=avg_tat=0;
	cout<<"Enter Arr.Time and Burst Time"<<endl;
	for(int i=0;i<n;i++){
		cout<<"P"<<i+1<<endl;
		cin>>at[i]>>bt[i];
		tot_sum+=bt[i];
	}
	cout<<endl;
	for(int i=0;i<n;i++) ma=min(ma,at[i]);
	for(int i=0;i<n;i++){
		if(at[i]==ma && bt[i]<mi){
			mi=bt[i];
			pos=i;
		}
	}
	//cout<<"pos->"<<pos<<endl;
	time=at[pos];
	while(time<tot_sum){
	    time=time+bt[pos];
	    tat[pos]=time-at[pos];
	    done[pos]=1;
	    m=0;
	    for(int i=0;i<n;i++){
		    if(!done[i] && at[i]<time){
			    wt[i]=time-at[i];
		    pri[i]=1+((float)wt[i]/bt[i]);
		    if(pri[i]>m){
			    m=pri[i];
			    pos=i;
		    }
		    }
	    }
	    //for(int i=0;i<n;i++) cout<<tat[i]<<" "<<wt[i]<<" "<<pri[i]<<endl;
	//cout<<"pos->"<<pos<<endl;
	}
	for(int i=0;i<n;i++) {
	    avg_wt+=wt[i];
		avg_tat+=tat[i];	
	}
	cout<<"Pid\tArr.T\tBrst.T\tWait.T\tTurnArnd.T\n"<<endl;
	for(int i=0;i<n;i++) cout<<"P"<<i+1<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<endl<<endl;
	cout<<"Average Waiting time -> "<<(float)avg_wt/n<<endl;
	cout<<"Average Turnaround time -> "<<(float)avg_tat/n<<endl;
}
/*Sample Test case
5
2 6
5 2
1 8
0 3
4 4
*/
