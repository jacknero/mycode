#include <cstdio>
#include <cstring>
 
int main()
{
	char s[101][101]={{0,},};
	int i,j,k, n,ml=0,l;
 
	for(i=0;;i++) {
		scanf("%s", s[i]);
		if(s[i][0]=='0' && s[i][1]==0) break;
 
		l=strlen(s[i])-1;
		ml = l > ml ? l : ml;
		for(j=l,k=100;j>=0;j--,k--) {
			s[i][k]=s[i][j];
			s[i][j]=0;
		}
	}
 
	n=i;
	char res[111]={0,};
	int tmp, carry=0;
 
	for(i=100,k=0;k<=ml;i--,k++) {
		tmp = carry;
		for(j=0;j<n;j++) {
			if(s[j][i]) tmp+=s[j][i]-'0';
		}
		res[k] = (tmp%10)+'0';
		carry = tmp/10;
	}
 
	for(;carry;k++) {
		res[k]=(carry%10)+'0';
		carry/=10;
	}
 
	for(--k;k>=0;k--) {
		putchar(res[k]);
	}
	puts("");
 
	return 0;
}

