#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void display(double arr[],int size){
	for(int i=0;i<size;i++) printf("%lf\n",arr[i]);
}

void Merge_M2(double *arr,int p,int q,int r,int *b){
	int n1 = b[q]-b[p];
	int n2 = b[r]-b[q];
	double *L = (double*)malloc(sizeof(double)*(n1+1));
	double *R = (double*)malloc(sizeof(double)*(n2+1));
        double cc=arr[b[q]]-arr[b[p]+1];
	int contL,contR;
        if(cc>0) contL=1;
        else contL=-1;
        double ct=arr[b[r]]-arr[b[q]+1];
	if(ct>0) contR=1;
        else contR=-1;
        if(contL==1){
	for(int i=0;i<=n1-1;i++){
		L[i] = arr[b[p]+i+1];
	}}
        else
           {
           for(int i=0;i<=n1-1;i++){
		L[i] = arr[b[q]-i];
	    }
           
           }
        if(contR==1){
	for(int i=0;i<=n2-1;i++){
		R[i] = arr[b[q]+i+1];

	}
        }
        else
        {
        for(int i=0;i<=n2-1;i++){
		R[i] = arr[b[r]-i];
        }
        }
	L[n1] = 999999999.0;
	R[n2] = 999999999.0;
	int i = 0;
	int j = 0;
	for(int k = 0;k<=n1+n2-1;k++){
		if(L[i]<=R[j]){
			arr[b[p]+k+1] = L[i++];
		}
		else{
			arr[b[p]+k+1] = R[j++];
		}
	}
}

   


double *sort(double *arr,int n){
	int *b = (int*)malloc(sizeof(int)*n);             
        double *L = (double*)malloc(sizeof(double)*(n));
	//double R[n2+1];
	double *R = (double*)malloc(sizeof(double)*(n));
	b[0] = -1;
	int t=0; 
        double c1=arr[0];
        double c2=arr[1];
	int cont;
        if(c1<=c2) cont=1;
        else cont=-1;
        
    for (int i = 1; i < n-2; i++)
    { 
        if (cont*arr[i+1]<cont*arr[i] )
            {
                t++;
                b[t]=i;
                if(arr[i+1]<=arr[i+2]) cont=1;
                else cont=-1;
            }
    }
	int k;
    if (cont*arr[n-1]<cont*arr[n-2] )
    {t++;
     b[t]=n-2;}
    b[t+1]=n-1;
    k=t+1;
    
    for(int l=k;l>1;l=ceil(l/2.)){
			int t=0;
		 	for(int i=0;i<l-1;i=i+2){
		  		Merge_M2(arr,i,i+1,i+2,b);
		  		t++;
		  		b[t]=b[i+2];
		 	}
		  	b[t+1]=n-1;
                  	
                }

 return arr;   
}
 


	



int main(int argv, char **argc){
	int size = atoi(argc[1]);
	double *arr = (double*)malloc(sizeof(double)*size);
	for(int i=0;i<size;i++) scanf("%lf",&arr[i]);
	clock_t begin = clock();
	arr = sort(arr,size);
	clock_t end = clock();
	printf("%lf\n",(double)(end-begin)/1000000);
	//display(arr,size);
	return 0;
}
