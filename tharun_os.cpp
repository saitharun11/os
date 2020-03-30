#include<bits/stdc++.h>
using namespace std;
class project{
	public:
	    int at=0,wt=0,tat=0,bt=0;
	    float pri=0.0;
	    bool done;
};
int main()
{
	int n,f=0;
	cout<<"Enter no. of processes"<<endl;
	cin>>n;
	project s[n];
	int ma,mi,tot_sum,avg_wt,avg_tat,m=INT_MIN,pos=0,time;
	ma=mi=INT_MAX;
	tot_sum=avg_wt=avg_tat=0;
	cout<<"\nEnter Arr.Time and Burst Time"<<endl;
	for(int i=0;i<n;i++){
		cout<<"\nP"<<i+1<<endl;
		cin>>s[i].at>>s[i].bt;
		tot_sum+=s[i].bt;
	}
	cout<<endl;
	for(int i=0;i<n;i++) ma=min(ma,s[i].at);
	for(int i=0;i<n;i++){
		if(s[i].at==ma && s[i].bt<mi){
			mi=s[i].bt;
			pos=i;
		}
	}
	time=s[pos].at;
	time=time+s[pos].bt;
	s[pos].tat=time-s[pos].at;
	s[pos].done=1;
	while(1){
		f=0;
		for(int i=0;i<n;i++){
			if(!s[i].done){
				f=1;
				break;
			}
		}
		if(!f) break;
	    f=m=0;
	    for(int i=0;i<n;i++){
		    if(!s[i].done && s[i].at<=time){
		    	f=1;
			    s[i].wt=time-s[i].at;
		    s[i].pri=1+((float)s[i].wt/s[i].bt);
		    if(s[i].pri>m){
			    m=s[i].pri;
			    pos=i;
		    }
		    }
	    }
	    if(f){
	    	time=time+s[pos].bt;
	        s[pos].tat=time-s[pos].at;
	        s[pos].done=1;
		}
		else
		time++;
	}
	for(int i=0;i<n;i++) {
	    avg_wt+=s[i].wt;
		avg_tat+=s[i].tat;	
	}
	cout<<"Pid\tArr.T\tBrst.T\tWait.T\tTurnArnd.T\n"<<endl;
	for(int i=0;i<n;i++) cout<<"P"<<i+1<<"\t"<<s[i].at<<"\t"<<s[i].bt<<"\t"<<s[i].wt<<"\t"<<s[i].tat<<endl<<endl;
	cout<<"Average Waiting time -> "<<(float)avg_wt/n<<endl;
	cout<<"Average Turnaround time -> "<<(float)avg_tat/n<<endl;
}
/*Sample Test case

4
0 6
5 1
13 8
17 1

4
0 8
5 4
13 9
17 5

4
0 8
5 4
13 9
17 5

*/
