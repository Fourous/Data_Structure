#include <stdio.h>
int maxsum(int* a,int left,int right){
	int sum,midsum,leftsum,rightsum;
	int center,s1,s2,lefts,rights;
	if (left==right)
	{
		if (left>0)
		{
			sum=left;
		}
		else sum=0;
	}
	else{
		center=(left+right)/2;
		leftsum=maxsum(a,left,center);
		rightsum=maxsum(a,center+1,right);
		s1=0;lefts=0;
		for (int i = center; i >=left ; i--)
		{
			lefts+=a[i];
			if(lefts>s1)	s1=leftsum;	
		}
		s2=0;rights=0;
		for (int j = center+1; j <=right; j++)
		{
			rights+=a[j];
			if(rights>s2)	s2=rights;
		}
		midsum=s1+s2;
		if(midsum>leftsum)   sum=midsum;
		else sum=leftsum;
		if(sum<rightsum)	sum=rightsum; 
	}
		return sum;
}

int main()
{
	int a[6]={-20,11,-4,13,-5,-2};
	printf("%d\n",maxsum(a,0,0) );
	return 0;
}
