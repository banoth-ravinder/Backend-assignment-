#include <stdio.h>
#define M 1000000007 //module

long long int a,b,c,d;
void f(long long n,long long int ans[]){
	if(n==0){
		ans[0]=0;
		ans[1]=1;
		return ;
	}
	f(n/2,ans);
	a=ans[0];
	b=ans[1];
	c=2*b-a;
	if(c<0)
		c+=M;
	c=(a*c)%M;
	d=(a*a+b*b)%M;
	if(n%2==0){
		ans[0]=c;
		ans[1]=d;
	}
	else{
		ans[0]=d;
		ans[1]=c+d;
	}
}
int main(){
	long long int n,i,j;
	scanf("%lld",&i);
	for(j=0;j<i;j++){
		long long int ans[2]={0};
		scanf("%lld",&n);
		if(n==0||n==1)
			f(n,ans);
		else
			f(n+2,ans);
		printf("%lld\n",ans[0]);
	}
	return 0;
}