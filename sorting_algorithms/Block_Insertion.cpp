#include <iostream>
#include <iostream>
#include <cstdlib>
#include <random>
#include <ctime>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
size_t blockIS = 16; 		// block size for blockInsertionSort and  blockInsertionSortMaxB, it must be a power of two
size_t maxBlockIS = 1048576; 
void blockInsertionSort(double *A, size_t l, size_t r){
	size_t pos, ini, end, dt, bLev, sp, ep, lenB, n = r-l+1, potBIS = log2(blockIS);
	long int i, j;
	double key;

	// 1- sort all small blocks: Blk_1, Blk_2, ..
	ini=l;
	end=ini+blockIS;
	while(ini<=r){
		if(end>r) end=r+1;
		for(pos=ini+1; pos<end; pos++){
			key = A[pos];
			j = pos-1;
			while (j>=(long int)ini && key<A[j]){
				A[j+1] = A[j];
				j--;
			}
			A[j+1] = key;
		}
		ini=end;
		end+=blockIS;
	};
	if (n<=blockIS)
		return;

	dt = log(n)/log(blockIS);
	dt = pow(blockIS,dt);
	if (dt==n)
		dt>>=potBIS;
	//printf("%ld\n",dt);
	double* ArrBI = new double[dt];		// extra size

	// We iterate for any segments S[sp...ep] of k blocks, for k in {blockIS, blockIS^2, blockIS^3, ...}
	bLev = blockIS;
	while (bLev < n){
		sp = l;
		while(sp<=r){
			ep = sp + (bLev<<potBIS) -1;
			if(ep>r) ep=r;
			ini=sp+bLev;
			end=ini+bLev;
			if(end>ep+1){
				end=ep+1;
				lenB = end-ini;
			}else
				lenB = bLev;

			// 2- copy the block Blk_2 from A[sp..ep] to ArrBI[]
			for(pos=ini; pos<end; pos++)
				ArrBI[pos-ini] = A[pos];

			// 3- insert all sorted blocks, from Blk_3 to the last block into A[sp..ep]
			ini=sp+(bLev<<1);
			end=ini+bLev;
			j = sp+bLev-1;
			while(ini<=ep){
				if(end>ep+1){
					end=ep+1;
					dt=end-ini;
				}else
					dt=bLev;
				for(i=end-1; i>=(long int)ini; i--){
					key = A[i];
					while (j>=(long int)sp && key<A[j]){
						A[j+dt] = A[j];
						j--;
					}
					A[j+dt] = key;
					dt--;
				}
				j=ini-1;
				ini=end;
				end+=bLev;
			}

			// 4- Insert ArrBI (blk_2) in A
			dt = lenB;
			j = ep-lenB;
			for(i=lenB-1; i>=0; i--){
				key = ArrBI[i];
				while (j>=(long int)sp && key<A[j]){
					A[j+dt] = A[j];
					j--;
				}
				A[j+dt] = key;
				dt--;
			}
			// A[sp..ep] is already sorted
			sp = ep+1;
		}
		// to multiply by blockIS for the next level
		bLev <<= potBIS;
	}
	delete [] ArrBI;
}

void blockInsertionSortMaxB(double *A, size_t l, size_t r){
	size_t pos, ini, fin, dt, bLev, sp, ep, lenB, potBIS = log2(blockIS);
	long int i, j;
	double key;

	// 1- sort all small blocks: Blk_1, Blk_2, ..
	ini=l;
	fin=ini+blockIS;
	while(ini<=r){
		if(fin>r) fin=r+1;
		for(pos=ini+1; pos<fin; pos++){
			key = A[pos];
			j = pos-1;
			while (j>=(long int)ini && key<A[j]){
				A[j+1] = A[j];
				j--;
			}
			A[j+1] = key;
		}
		ini=fin;
		fin+=blockIS;
	};
	if (r-l<blockIS)
		return;
	//printf("%ld\n",maxBlockIS);
	double* ArrBIB = new double[maxBlockIS];		// extra size
	bLev = blockIS;
	// We iterate for any segments S[sp...ep] of k blocks, for k in {blockIS, blockIS^2, blockIS^3, ..., maximum-size}
	while (bLev <= maxBlockIS){
		sp = l;
		while(sp<=r){
			if ((bLev<<potBIS) > maxBlockIS)
				ep = r;
			else{
				ep = sp + (bLev<<potBIS) -1;
				if(ep>r)
					ep=r;
			}

			// 2- copy the block Blk_2 from A[sp..ep] to ArrBIB[]
			ini=sp+bLev;
			fin=ini+bLev;
			if(fin>ep+1){
				fin=ep+1;
				lenB = fin-ini;
			}else
				lenB = bLev;
			for(pos=ini; pos<fin; pos++)
				ArrBIB[pos-ini] = A[pos];

			// 3- insert all sorted blocks, from blk_3 to the last block into A[sp..ep]
			ini=sp+(bLev<<1);
			fin=ini+bLev;
			j = sp+bLev-1;
			while(ini<=ep){
				if(fin>ep+1){
					fin=ep+1;
					dt=fin-ini;
				}else
					dt=bLev;

				for(i=fin-1; i>=(long int)ini; i--){
					key = A[i];
					while (j>=(long int)sp && key<A[j]){
						A[j+dt] = A[j];
						j--;
					}
					A[j+dt] = key;
					dt--;
				}
				j=ini-1;
				ini=fin;
				fin+=bLev;
			}

			// 4- Insert ArrBIB (blk_2) in A
			dt = lenB;
			j = ep-lenB;
			for(i=lenB-1; i>=0; i--){
				key = ArrBIB[i];
				while (j>=(long int)sp && key<A[j]){
					A[j+dt] = A[j];
					j--;
				}
				A[j+dt] = key;
				dt--;
			}
			// A[sp..ep] is already sorted
			sp = ep+1;
		}
		bLev <<= potBIS;	// to multiply by blockIS for the next level
	}
	delete [] ArrBIB;
}
void display(double arr[],int size){
	for(int i=0;i<size;i++) printf("%lf\n",arr[i]);
}
using namespace std;
//using namespace srt;
int main(int argv, char **argc) {
	size_t size = atoi(argc[1]);
	double *arr = (double*)malloc(sizeof(double)*size);
	for(int i=0;i<size;i++) scanf("%lf",&arr[i]);
	size_t l = 0;
	size_t r = 100000;
	clock_t begin = clock();
	blockInsertionSort(arr, l, size-1);
	clock_t end = clock();
	//display(arr,size);
	printf("%lf\n",(double)(end-begin)/1000000);
    	return 0;
}
