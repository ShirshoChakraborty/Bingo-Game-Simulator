#include <stdio.h>
#include <stdlib.h>

#define gotoxy(x,y) printf("\033[%d;%df",(y),(x))
#define goup(x) printf("\033[%dA",(x))
#define goleft(x) printf("\033[%dC",(x))

void swap(int *a,int *b)
{
	int t;
	t=*a;
	*a=*b;
	*b=t;
}

int bingo_check(int arr[][5])
{	
	if(arr[0][0] + arr[0][1] + arr[0][2] + arr[0][3] + arr[0][4] == 5 ||
	arr[1][0] + arr[1][1] + arr[1][2] + arr[1][3] + arr[1][4] == 5 ||
	arr[2][0] + arr[2][1] + arr[2][2] + arr[2][3] + arr[2][4] == 5 ||
	arr[3][0] + arr[3][1] + arr[3][2] + arr[3][3] + arr[3][4] == 5 ||
	arr[4][0] + arr[4][1] + arr[4][2] + arr[4][3] + arr[4][4] == 5 ||
	arr[0][0] + arr[1][0] + arr[2][0] + arr[3][0] + arr[4][0] == 5 ||
	arr[0][1] + arr[1][1] + arr[2][1] + arr[3][1] + arr[4][1] == 5 ||
	arr[0][2] + arr[1][2] + arr[2][2] + arr[3][2] + arr[4][2] == 5 ||
	arr[0][3] + arr[1][3] + arr[2][3] + arr[3][3] + arr[4][3] == 5 ||
	arr[0][4] + arr[1][4] + arr[2][4] + arr[3][4] + arr[4][4] == 5 ||
	arr[0][0] + arr[1][1] + arr[2][2] + arr[3][3] + arr[4][4] == 5 ||
	arr[0][4] + arr[1][3] + arr[2][2] + arr[3][1] + arr[4][0] == 5)
		return 1;
		
	return 0;
}

void print_statement(int a[], int b[], int arr[][5])
{
	gotoxy(0,0);
	int i,j;
	printf("B\tI\tN\tG\tO\n");
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
	printf("Hits: ");
	for(i = 0; i < 24; i++)
		if(a[i] != 0)
			if(i == 0)
				printf("%d",a[i]);
			else
				printf(",%d",a[i]);
	printf("\nNo Hits: ");
	for(i = 0; i < 51; i++)
		if(b[i] != 0)
			if(i == 0)
				printf("%d",b[i]);
			else
				printf(",%d",b[i]);
//	printf("Hits\tNon-Hits\n");
//	for(i = 0; i < 24; i++)
//	{
//		if(a[i] == 0 && b[i] == 0)
//			printf("%s\t%s\n"," ", " ");
//		else if(a[i] == 0 && b[i] != 0)
//			printf("%s\t%d\n"," ", b[i]);
//		else if(a[i] != 0 && b[i] == 0)
//			printf("%d\t%s\n",a[i], " ");
//		else
//			printf("%d\t%d\n",a[i], b[i]);
//	}
//	for(i = 24; i < 51; i++)
//	{
//		if(b[i] != 0)
//			printf("\t%d\n",b[i]);
//		else
//			printf("\t%s\n"," ");
//	}
}

int* shuffle(int a[],int n)
{
	int i,j,*b;
	b=(int*)calloc(n,sizeof(int));
	for(i=0;i<n;i++)
	{
		b[i]=a[i];
	}
	for(i=n-1;i>=0;i--)
	{
		j=rand()%(i+1);
		swap(&b[i],&b[j]);
	}
	return b;
}

int main()
{
	srand(time(0));
	int i,j=0,k,c=1,arr[5][5],a[15],d[75],*sf,*new_sf,hit[24],no_hit[51],ar[5][5];
	for(k=1;k<=5;k++)
	{
		if(k==1)
		{
			for(i=0;i<15;i++)
			{
				a[i]=c;
				c++;
			}	
		}
		if(k==2)
		{
			for(i=0;i<15;i++)
			{	
				a[i]=c;
				c++;
			}
		}
		if(k==3)
		{
			for(i=0;i<15;i++)
			{
				a[i]=c;
				c++;
			}
		}
		if(k==4)
		{
			for(i=0;i<15;i++)
			{
				a[i]=c;
				c++;
			}
		}
		if(k==5)
		{
			for(i=0;i<15;i++)
			{
				a[i]=c;
				c++;
			}
		}
		sf=shuffle(a,15);
		for(i=0;i<5;i++)
		{
			arr[i][j]=sf[i];
		}
		j++;	
	}
	arr[2][2] = 0;
	printf("B\tI\tN\tG\tO\n");
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
	
	for(i=0;i<75;i++)
	{
		d[i]=i+1;
	}
	new_sf=shuffle(d,75);
	k=0;
	int column = 0;
	printf("Hits: \n");
	printf("No Hits: ");
	for(i = 0; i < 24; i++)
	{
		hit[i] = 0;
	}
	for(i = 0; i < 51; i++)
	{
		no_hit[i] = 0;
	}
	int counter_hit = 0;
	int counter_nonhit = 0;
	for(i = 0; i < 5; i++)
	{
		for(j = 0; j < 5; j++)
		{
			ar[i][j] = 0;
		}
	}
	ar[2][2] = 1;
	while(k<=75)
	{
		Sleep(1000);
		column = (new_sf[k]-1)/15;
		for(i = 0; i < 5; i++)
		{
			if(arr[i][column] == new_sf[k])
			{
				hit[counter_hit] = new_sf[k];
				//goup(counter_nonhit - counter_hit);
				counter_hit++;
				ar[i][column] = 1;
				//printf("%d",new_sf[k]);
				break;
			}
		}
		if(i == 5)
		{
			no_hit[counter_nonhit] = new_sf[k];
			counter_nonhit++;
			//printf("\t%d\n",new_sf[k]);
		}
		system("cls");
		print_statement(hit, no_hit, arr);
		if(bingo_check(ar) == 1)
		{
			printf("\n\nBINGO\n\n");
			break;
		}
		k++;
	}
	printf("\nTotal no. of daubs = %d",counter_hit);
	printf("\nTotal no.of numbers drawn before bingo got hit = %d",counter_hit + counter_nonhit);
}
