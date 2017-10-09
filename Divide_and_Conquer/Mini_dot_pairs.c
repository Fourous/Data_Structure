#include <stdio.h>
#include < math.h>

struct point
{
	int x,y;
};

double Closest (point S[],int low,int high){
	double d1,d2,d3,d;
	int mid,i,j,index;
	point P[n];
	if (high-low==1)
	{
		return Distance(S[low],S[high]);
	}
	if(high-low==2){
		d1=Distance(S[low],S[low+1]);
		d2=Distance(S[low+1],S[high]);
		d3=Distance(S[low],S[high]);
		if((d1<d2)&&(d1<d3)) return d1;
		else if(d2<d3)	return d2;
		           else return d3;
	}
	mid=(high+low)/2;
	d1=Closest();
	d2=Closest();
	if(d1<=d2) d=d1;
	else d=d2;
	index=0;
	for(i=mid;(i>=low)&&(S[mid].x-S[i].x<d);i--)
		P[index++] =S[i];
	for(i=mid+1;(i<=high)&&(S[i].x-S[mid].x<d);i++)
		P[index++]=S[i];
	QuickSort(P,0,index-1);
	for (int i = 0; i < index; ++i)
	{
		for (int j = i+1; i < index; j++)
		{
			if(P[j].y-P[i].y>=d)
				break;
			else
			{
				d3=Distance(P[i],P[j]);
				if(d3<d)		d=d3;
			}
		}
	}
	return d;
}
double Distance(point a,point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

