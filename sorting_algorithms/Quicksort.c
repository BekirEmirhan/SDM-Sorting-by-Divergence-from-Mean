#include <stdio.h>
 #include <stdlib.h>
#include <time.h>
#include <math.h>


void display(double *arr,int size){
	for(int i=0;i<size;i++) printf("%lf\n",arr[i]);
}

int partition (double *arr, int low, int high) 
{ 
    double mean =0;
    //printf("low: %d,high: %d\n",low,high);
    for(int i=low;i<=high;i++){
	 mean += arr[i];
	//printf("arr: %d\n",arr[i]);
}
    mean = mean/(high-low+1);
    double f = abs(mean -arr[low]);
    int index = low;
    for(int i = low+1;i<=high;i++){
	if(abs(mean-arr[i]) < f) {
		index = i;
		f = abs(mean-arr[i]);
	}
    }
   //printf("index: %d\n",index);
    double temp1 = arr[high];
    arr[high] = arr[index];
    arr[index] = temp1;
    double pivot = arr[high]; // pivot
    int i = (low - 1);
  
    for (int j = low; j < high; j++) 
    { 
        if (arr[j] <= pivot) 
        { 
            	i++; 
		double temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
        } 
    } 
	double temp = arr[i+1];
	arr[i+1] = arr[high];
	arr[high] = temp;
    return i + 1; 
} 

void quickSort(double *arr, int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr, low, high); 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 



int main(int argv,char **argc){
	int size = atoi(argc[1]);
	double*arr = (double*)malloc(sizeof(double)*size);
	for(int i=0;i<size;i++) scanf("%lf",&arr[i]);
	//display(arr,size);
	clock_t begin = clock();
	quickSort(arr,0,size-1);
	clock_t end = clock();
	printf("%lf\n",(double)(end-begin)/1000000);
	//display(arr,size);
	return 0;
}

