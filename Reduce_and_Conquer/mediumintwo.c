#include <stdio.h>
int mediumintwo(int *a,int *b,int n){
	int s1=0,s2=0;
	int e1=n-1,e2=n-1;
	int mid1,mid2;
	while (s1<e1&&s2<e2){
		mid1=(e1+s1)/2;
		mid2=(e2+s2)/2;
		if (a[mid1]==b[mid2])
		{
			return a[mid2];
		}
		if (a[mid1]<b[mid2])
		{
			if ((s1+e1)%2==0)	s1=mid1;
			else s1=mid1+1;
			s2=mid2;
		}
		else
		{
			if ((s2+e2)%2==0)
			{
				if((s2+e2)%2==0)	s2=mid2;
				else s2=mid2+1;
				s1=mid1;
			}
		}
	}
	if(a[s1]<b[s2])	return a[s1];
	else return b[s2];
}