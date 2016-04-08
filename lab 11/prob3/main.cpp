#include <iostream>
#include <iomanip>
#include "bitonic.h"
using namespace std;

int main(int argc, char *argv[])
{
	int n, i,j;
	point *p;
	cout<<"Enter number of points\n";
	cin>>n; p = new point[n];
	cout<<"Enter co-ordinates (integers) of "<<n<<" points\n";
	for(i=0;i<n;i++) {cin>>p[i].x; cin>>p[i].y;}

	bool *T = new bool[n];
	bitonic(n,p,T);
	
	double l=0,dst; T[0]=true; T[n-1]=true; i=0; j=0;
	if(argc>1) cout<<"Left to Right sweep: "<<endl;
	while(j<n-1)
	{
		for(j=i+1;T[j]==false;j++);
		dst=d(p[i],p[j]); l+=dst;
		if(argc>1)
		{
			cout<<"("<<p[i].x<<","<<p[i].y<<") -> ";
			cout<<"("<<p[j].x<<","<<p[j].y<<") ";
			cout<<", increment:"<<fixed<<dst<<" , cumulative path-length:"<<fixed<<l<<endl;
		}
		i=j;
	}
	T[0]=false; T[n-1]=false; i=n-1; j=n-1;
        if(argc>1) cout<<"Right to Left sweep: "<<endl;
	while(j>0)
	{
		for(j=i-1;T[j]==true;j--);
		dst=d(p[i],p[j]); l+=dst;
                if(argc>1) 
                { 
                        cout<<"("<<p[j].x<<","<<p[j].y<<") <- ";
                        cout<<"("<<p[i].x<<","<<p[i].y<<") ";
                        cout<<", increment:"<<fixed<<dst<<" , cumulative path-length:"<<fixed<<l<<endl;
                }
		i=j;
	}

	cout<<"Bitonic tour length (rounded upto 2 dec place): "<<setprecision(2)<<fixed<<l<<endl;
}
