// C program to implement dual pivot QuickSort
#include <stdio.h>
 #include <stdlib.h>
#include <time.h>
void display(double arr[],int size){
	for(int i=0;i<size;i++) printf("%lf\n",arr[i]);
}
int partition(double* arr, int low, int high, int* lp);

void swap(double* a, double* b)
{
	double temp = *a;
	*a = *b;
	*b = temp;
}

void DualPivotQuickSort(double* arr, int low, int high)
{
	if (low < high) {
		// lp means left pivot, and rp means right pivot.
		int lp, rp;
		rp = partition(arr, low, high, &lp);
		DualPivotQuickSort(arr, low, lp - 1);
		DualPivotQuickSort(arr, lp + 1, rp - 1);
		DualPivotQuickSort(arr, rp + 1, high);
	}
}

int partition(double* arr, int low, int high, int* lp)
{
	if (arr[low] > arr[high])
		swap(&arr[low], &arr[high]);
	// p is the left pivot, and q is the right pivot.
	int j = low + 1;
	int g = high - 1, k = low + 1;
	double p = arr[low], q = arr[high];
	while (k <= g) {

		// if elements are less than the left pivot
		if (arr[k] < p) {
			swap(&arr[k], &arr[j]);
			j++;
		}

		// if elements are greater than or equal
		// to the right pivot
		else if (arr[k] >= q) {
			while (arr[g] > q && k < g)
				g--;
			swap(&arr[k], &arr[g]);
			g--;
			if (arr[k] < p) {
				swap(&arr[k], &arr[j]);
				j++;
			}
		}
		k++;
	}
	j--;
	g++;

	// bring pivots to their appropriate positions.
	swap(&arr[low], &arr[j]);
	swap(&arr[high], &arr[g]);

	// returning the indices of the pivots.
	*lp = j; // because we cannot return two elements
	// from a function.

	return g;
}

// Driver code
int main(int argv,char **argc)
{
	int size = atoi(argc[1]);
	double *arr = (double*)malloc(sizeof(double)*size);
	for(int i=0;i<size;i++) scanf("%lf",&arr[i]);
	clock_t begin = clock();
	DualPivotQuickSort(arr, 0, size-1);
	clock_t end = clock();
	printf("%lf\n",(double)(end-begin)/1000000);
	//display(arr,size);
	return 0;
}

