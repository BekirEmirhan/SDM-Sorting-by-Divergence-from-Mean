function out =  uniform(start,finish,incr)
  for i = start : incr : finish
    A = rand(1,i)*30000000;
   
    fname = sprintf("u-input%d-1",i);
    ptr = fopen(fname,"wt");
    fprintf(ptr,'%f\n',A);
    fclose(ptr);
    A = rand(1,i)*1000000;
  
    fname = sprintf("u-input%d-2",i);
    ptr = fopen(fname,"wt");
    fprintf(ptr,'%f\n',A);
    fclose(ptr);
    A = rand(1,i)*100000;

    fname = sprintf("u-input%d-3",i);
    ptr = fopen(fname,"wt");
    fprintf(ptr,'%f\n',A);
    fclose(ptr);
    
    end
