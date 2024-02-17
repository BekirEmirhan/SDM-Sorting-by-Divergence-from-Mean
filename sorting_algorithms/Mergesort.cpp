/* C program for Merge Sort */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void merge(double *arr, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	double *L = (double*)malloc(sizeof(double)*(n1+1));
	double *R = (double*)malloc(sizeof(double)*(n2+1));
	for (i = 0; i < n1; i++)
	L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
	R[j] = arr[m + 1 + j];
	L[n1]=100000000.0;
	R[n2]=100000000.0;
	i = 0; 
	j = 0;
	//printf("1\n");
	for (int k=l; k<=r;k++)
	{ 
		if (L[i] <= R[j]) {
		arr[k] = L[i];
		i++;
		}
		else {
		arr[k] = R[j];
		j++;
		}
	}
	//printf("2\n");
}
void mergeSort(double *arr, int l, int r)
{
if (l < r) {
int m = (l + r) / 2;
mergeSort(arr, l, m);
mergeSort(arr, m + 1, r);

merge(arr, l, m, r);
}
}

void display(double arr[],int size){
	for(int i=0;i<size;i++) printf("%lf\n",arr[i]);
}

/* Driver code */
int main(int argv,char **argc)
{
int size = atoi(argc[1]);
double*arr = (double*)malloc(sizeof(double)*size);
for(int i=0;i<size;i++) scanf("%lf",&arr[i]);
clock_t begin = clock();
mergeSort(arr, 0,size-1);
clock_t end = clock();
printf("%lf\n",(double)(end-begin)/1000000);
//display(arr,size);
return 0;
}

