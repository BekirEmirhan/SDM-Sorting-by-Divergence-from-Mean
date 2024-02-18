<h1>SDM-Sorting by Divergence from the Mean</h1>

<b>Contents
<br></br>
1- Test Environment
<br></br>
2- File Structure of Repository
<br></br>
3- Data Availability
<br></br>
4- Data Description
<br></br>
5- Testing and Getting Results from Sorting Algorithms
<br></br>
<br></br></b>
<h1><b>1- Test Environment</b></h1>
All of the test are conducted on Ubuntu 16.04 operating system with 8gb RAM and 8th generation i5 core. Also, we used g++ compiler with version of 5.4.0.
<br></br>
<h1><b>2- File Structure of Repository</b></h1>

We design the repository as a 3 section to make everyting clearly. Sorting algorithms that used in paper, data generator scripts and sample mini data for testing.
<br></br>
<h3><b>A- Sorting Algorithms</b></h3>
It consists of 5 .cpp files which are all of the sorting algorithms used in paper. These algorithms are SDM, Dual Pivot Quicksort, Block Insertion Sort,Mergesort, Quicksort.
<h3><b>B- Data Genarator Scripts</b></h3>
Includes creating data scripts for each distribution used in paper. For example, gaussian.m script genarates all of gaussian distrubuted data.
<h3><b>C- Sample Data</b></h3>
Includes small portion of the data used in validating and testing our sorting algorithm.
<h1><b>3- Data Availability</b></h1>
We open dataset in kaggle to store all of the data. The data set consists of gaussian, uniform and 5 special cases. <br></br>
The link is : https://www.kaggle.com/datasets/bekiremirhanakay/benchmark-dataset-for-sorting-algorithms
<h1><b>4- Data Description</b></h1>
There are 1212 different arrays in each of the two data
sets. These arrays are categorized into 5 different groups. In
the first group, we have 100 arrays with different sizes. The
first array in this group consists of 1000 numbers and the
size of each successive array increases by 1000 and the size
of the last array is 100000. In the second group, we have 180
arrays with different sizes. The first array in the second group
consists of 105000 numbers and the size of each successive
array increases by 5000 and the size of the last array is
1000000. In the third group, we have 100 arrays with different sizes. The first array in this group consists of 1010000
numbers and the size of each successive array increases by
10000 and the size of the last array is 2000000. In the fourth
group, we have 20 arrays with different sizes. These sizes
are 2050000, 2100000, 2150000,…, 3000000, respectively.
The dimensions of 4 arrays in the last group with different
sizes are 3250000, 3500000, 3750000, and 4000000. Thus,
in each group, there are 404 arrays of different sizes. We
obtained 1212 arrays in each data set by randomly generating
three arrays of each size. In the tests, the algorithms were run
for 3 arrays of the same size, and the average of the running
times was taken as the running time for an array of this size.
The numbers in both data sets are floating point numbers
and are not ordered because they are randomly generated. In
the first data set with a uniform distribution, the numbers
vary randomly between 0 and 30000000. A standard normal
distribution was used for the numbers with a Gaussian
distribution.
<h1><b>5- Testing and Getting Results from Sorting Algorithms</b></h1>
We provide simple testing execution for algorithm-3 all process of the testing process will be same for other algorithms.
<br></br>
Firstly, compile the code in linux terminal as : &nbsp;&nbsp;&nbsp;g++ SDM.cpp
<br></br>
Secondly, try with 1 million gaussian input with writing : &nbsp;&nbsp;&nbsp;./a.out 1000000 < gaussian-input-1000000-1-float.txt
<br></br>
Output of the code is the time of the execution of the algorithm in terms of second

<h3><b>Citation:</b></h3>
Please give an references for the using the dataset to authors of the dataset:
Bekir Emirhan Akay,Nermin Kartli,Sahin Emrah Amrahov,Yilmaz Ar
