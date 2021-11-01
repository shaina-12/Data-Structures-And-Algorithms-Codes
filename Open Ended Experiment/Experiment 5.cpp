//This code is contributed by Anjali Gaur
#include <stdio.h>
#include <conio.h>

int a[10][10], visited[10], no, cost=0, sum, visit[10];
int least(int c)
{
	int i, ncity = 999, min = 999, kmin;
	for(i = 1; i <= no; i++)
	{
		if((a[c][i] != 0) && (visited[i] == 0))
			if(a[c][i] < min)
			{
				min = a[i][1] + a[c][i];
				kmin = a[c][i];
				ncity = i;
			}
	}
	if(min != 999)
		cost += kmin;
	return ncity;
}

void tsp(int city)
{
	int ncity;
	visited[city] = 1;
	printf("%d ->",city);
	ncity = least(city);
	if(ncity == 999)
	{
		cost += a[city][1];
		printf("1\n");
		return;
	}
	tsp(ncity);
}

void nearest_neighbor(int city)
{
	int min, j, i, u;
	visit[city] = 1;
	printf("%d -> ", city);
	u = city;
	for(j = 1; j <= no; j++)
	{
		min = 999;
		for (i = 0; i <= no; ++i)
			if((visit[i] == 0) && (a[city][i] != 0))
				if(a[city][i] < min)
				{
					min = a[city][i];
					u = i;
				}
		visit[u] = 1;
		if(min != 999)
		{
			sum += min;
			printf("%d -> ", u);
		}
		city = u;
	}
	printf("1\n");
	sum += a[u][1];
}

int main()
{
	int i, j;

	printf("Enter the No of Cities\n");
	scanf("%d", &no);
printf("Enter the cost matrix\n");
            for(i=1;i<=no;i++)
            {
                        printf("Enter elements of row:%d\n",i );
                        for(j=1;j<=no;j++)
                                    scanf("%d",&a[i][j]);
                        visited[i]=0;
            }
            printf("The cost list is \n");
            for(i=1;i<=no;i++)
            {
                        printf("\n\n");
                        for(j=1;j<=no;j++)
                                    printf("\t%d",a[i][j]);
            }
           
            printf("\n  optimal solution  :\n");
             tsp(1);
           printf("\n Minimum cost:");
            printf("%d",cost);

            printf("\n\n using approx method path is :\n");
            nearest_neighbor(1);
            printf("\n cost is:");
            printf("%d",sum);
            printf("\n\nError in approximation is approximated solution/optimal solution=%f",
                        (float)sum/cost);
}
