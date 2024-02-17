#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double fastPow(double a, double b) 
 {
  union {
    double d;
    int x[2];
  } u = { a };
  u.x[1] = (int)(b * (u.x[1] - 1072632447) + 1072632447);
  u.x[0] = 0;
  return u.d;
 }

void swap(double arr[],int a, int b)
{
   double  temp=arr[a];
          arr[a]=arr[b];
          arr[b]=temp;
       }

void BCIS(double arr[],int L, int R)
 {  
  double curr,LC,RC;
  int  SL=L,SR=R; 
  int i,j,Len,MM; 
 
  while (SL<SR)
   {      
    Len=SR-SL;
    swap(arr,SL+Len/2,SR);
    if(arr[SL]==arr[SR])//equality check
      {  i=SL+1;
        while(arr[SL]==arr[i]&& i<SR)i++;
        if(i==SR) return;
        else  swap(arr,i,SL);       
       }
     
    if(arr[SL]>arr[SR])swap(arr,SR,SL) ; //LC Must be less than RC
         i=SL+1  ;
      
    if (Len >100 )  // To Select LC and RC for size >100
    {   MM=SL+ fastPow(Len,0.5);
     while(i < MM)
        {
         if (arr[SR] < arr[i] ) 
            swap(arr,SR, i);
         else if (arr[SL] > arr[i] )
                swap(arr,SL,i );
         i++;
        }      
     }
    LC=arr[SL];
    RC=arr[SR];   
    while ( i<SR )
     {    
        curr=arr[i];
        if(curr>=RC) 
          {    
            arr[i]=arr[--SR];
             j=SR+2;
        while( j<=R && curr > arr[j] ) arr[j-1]=arr[j++];
                  arr[j-1]=curr; 
          }
         else if(curr<=LC) 
          {   
             arr[i]=arr[++SL] ;
             j=SL-2;
        while( j>=L && curr < arr[j] )arr[j+1]=arr[j--];
                  arr[j+1]=curr; 
                  i++;
           } 
         else i++ ;
       }  
    arr[SL]=LC;
    arr[SR]=RC;
    SL++;SR--;
    
   }
  
   }
 


//Above BCIS  is optimized to performance , you can replace the related code by  following factions to increase clarity of the algorithm
void InsertToRight(double arr[],int SR,double curr, int R)
    {   int j;
        j=SR+1;
        while( j<=R && curr > arr[j] )arr[j-1]=arr[j++];
                  arr[j-1]=curr; 
    }
   void InsertToLeft(double arr[],int SL,double curr, int L)
    {   int j;
           j=SL-1;
        while( j>=L && curr < arr[j] )arr[j+1]=arr[j--];
                  arr[j+1]=curr; 
    }

int static e = 0;
double *SDM(double *A,int n, int s, int f){
        if (s>=f) return A;
        if (f-s<=1800){  // check boundry condition if sub-array size below the limit sort it via using BCISs 
	BCIS(A, s, f);
        	return A;
         }
           // Calculate mean and standard deviation
	double sum=0;
	for(int i=s;i<=f;i++){
		sum += A[i];
	}
	double mean = sum/(f-s+1);
	sum = 0;
	for(int i=s;i<=f;i++){
		//sum += pow(A[i]-mean,2);
		sum += (A[i]-mean) * (A[i]-mean);
	}
	double sigma = sqrt(sum/(f-s+1));
	if(sigma == 0) return A; // if standard deviation is 0 so all elements have same value terminate sorting
	double R[7];
	// this is SDM's constants that is explained detailed in the paper
    	R[0]=1.4;
        	R[1]=1.1;
        	R[2] = 0.8;
	R[3] = 0.5;
	for(int k=0;k<4;k++){ // iterate each constant and rearrange the array distance from mean
		double lowerb = mean-(R[k])*sigma; // lower bound from mean
		double upperb = mean+(R[k])*sigma; // upper bound from mean
                		int s1=s;
                		int f1=f;
		int j;
		for(j=s1; j<=f; j++){
		  	if(A[j] <= lowerb){
				double temp = A[j];
				A[j] = A[s];
				A[s] = temp;
				s++;
			}
                        
			else if(A[j] >= upperb){
				double temp = A[j];
				A[j] = A[f];
				A[f] = temp;
				j--;
				f--;
			}
                    
	
		}
                     SDM(A, n, s1, s-1); // sort left of the lower bound
                     SDM(A, n, f+1, f1); // sort left of the upper bound
	}
	SDM(A, n, s, f); // sort the remaining which is middle of the array
	return A;
}




int main(int argv, char **argc){
	int size = atoi(argc[1]);
	double *arr = (double*)malloc(sizeof(double)*size);
	for(int i=0;i<size;i++) scanf("%lf",&arr[i]);
	clock_t begin = clock();
	arr = SDM(arr,size,0,size-1);
	clock_t end = clock();
	printf("%lf\n",(double)(end-begin)/1000000);
	return 0;
}

