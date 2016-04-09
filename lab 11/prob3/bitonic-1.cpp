#include "bitonic.h"

//Implement function 'bitonic()'. It is declared in 'bitonic.h'
// write your code here
void bitonic(int n, point p[], bool T[]) 
{
	double len[n][n];

	int soln[n][n];
	for(int i=0;i<n;i++) 
	{
		T[i] = false;
		
		for(int j=0;j<n;j++) 
		{
			soln[i][j]=0;
		}
	}


	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {	// only handling for i<j, otherwise zero (actually l[i][j] should be = l[j][i])
			len[i][j] = 0.0;
			if(i == 0 && j == 1) {
				len[i][j] = d(p[0],p[1]);
				len[j][i] = len[i][j];
				soln[i][j] = 0;//
			}
			else if(i<j-1) {
				len[i][j] = len[i][j-1] + d(p[j-1],p[j]);
				len[j][i] = len[i][j];
				soln[i][j] = j-1;//
			}
			else if(i==j-1 || i==j) {
				double mindist = len[0][i] + d(p[0],p[j]);
				soln[i][j] = 0;//
				for(int k=0;k<i;k++) {
					if(len[k][i] + d(p[k],p[j]) < mindist) {
						mindist = len[k][i] + d(p[k],p[j]);
						soln[i][j] = k;//
					}
				}
				len[i][j] = mindist;
				len[j][i] = len[i][j];
			}
		}
	}

	// // wrong
	// for(int i=0;i<n;i++) {
	// 	for(int j=0;j<n;j++) {
	// 		if(i>j) {
	// 			soln[i][j] = soln[j][i];
	// 		}
	// 	}
	// }
	
	// for(int i=0;i<n;i++) {
	// 	for(int j=0;j<n;j++) {
	// 		cout << soln[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }	

	int p1 = n-1;
	int p2 = n-1;	// p1 <= p2
	T[0] = true;
	T[n-1] = true;
	int flag = 1; // if 1 then T will be set to true
	while(soln[p1][p2] > 0) {
		// cout << soln[n-1][pos] << endl;
		// T[soln[n-1][pos]] = true;	// in the rightward path (bottom)
		// pos = soln[n-1][pos];
		if(flag) {
			T[soln[p1][p2]] = true;
			p2 = soln[p1][p2];
			if(p2 < p1) {
				flag = false;
				int temp = p1;
				p1 = p2;
				p2 = temp;
			}
		}
		else {
			p2 = soln[p1][p2];
			if(p2 < p1) {
				flag = true;
				int temp = p1;
				p1 = p2;
				p2 = temp;
			}
		}
	}






	// int pos=n-1;
	// T[0] = true;
	// T[n-1] = true;
	// while(soln[pos][n-1] != 0) {
	// 	cout << soln[pos][n-1] << endl;
	// 	T[soln[pos][n-1]] = true;	// in the rightward path (bottom)
	// 	pos = soln[pos][n-1];
	// }

	// double mindist = len[n-1][n-1];
	// cout << mindist << endl;

}