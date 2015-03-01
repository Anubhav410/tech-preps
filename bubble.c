#include<stdio.h>

int main()
{
	int x[] = {5,4,3,2,1};

	int i , j ;

	for(i = 0 ; i < 5 ; i++)
	{
		printf("%d\t" , x[i]);
	}
	printf("\n");

	for(i = 0  ; i< 5 ; i++)
	{
		for(j = 0 ; j < (5-i)-1 ; j++)	//we are suppose to not go till the end as we are checking for a J+1 , and hence the end will go to OUT-OUT-BOUNDS
		{
			if(x[j] > x[j+1])
			{
				int temp = x[j];
				x[j] = x[j+1];
				x[j+1] = temp;
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