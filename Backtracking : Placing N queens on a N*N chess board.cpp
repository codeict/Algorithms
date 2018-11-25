#include <bits/stdc++.h>
using namespace std;
int ctr = 0;

void backtrack(int ptr,int n, int pos[], int dg1[], int dg2[], int ch[]){
	if (ptr == n){
		cout<<"Permutation "<<++ctr<<" : \n";
		for (int i = 0; i<n; i++){
			for (int j = 0; j<n; j++){
				cout<<((pos[i] == j)? "Q " : "+ ");
			}
			cout<<"\n";
		}
	}
	else{
		for (int i = 0; i<n; i++){
			if (ch[i])
				continue;
			int d1 = i + n-1-ptr;
			int d2 = i + ptr;
			if (dg1[d1] || dg2[d2])
				continue;
			dg1[d1] = dg2[d2] = ch[i] = 1;
			pos[ptr++] = i;
			backtrack(ptr, n , pos, dg1, dg2, ch);
			dg1[d1] = dg2[d2] = ch[i] = 0;
			ptr--;
		}
	}
	return;
}

int main(){
	system("clear");
    int n;
    cout<<"Enter side of Chess Board : ";
    cin>>n;
    int pos[n], dg1[2*n-1], dg2[2*n-1], ch[n];
    memset(dg1,0,sizeof(dg1));
    memset(dg2,0,sizeof(dg2));
    memset(ch,0,sizeof(ch));
    backtrack(0,n,pos,dg1,dg2,ch);
    if (ctr == 0)
    	cout<<"No valid permutations exist\n";
    return 0;
}