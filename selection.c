#include<stdio.h>

int main()
{
	int x[] = {5,4,3,2,1};

	int i , j ;
	for(i =0  ; i< 5 ; i++)
	{
		for(j = i+1 ; j < 5 ; j++)
		{
			if(x[j] < x[i])
			{
				int temp = x[i];
				x[i] = x[j];
				x[j] = temp;
			}
		}
	}		
	for(i = 0 ; i < 5 ; i++)
	{
		printf("%d\t" , x[i]);
	}
	printf("\n");
	return 0;
}