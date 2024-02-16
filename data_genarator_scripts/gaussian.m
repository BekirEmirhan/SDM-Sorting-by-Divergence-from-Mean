function out = gaussian(start,finish,incr)
  for i = start : incr : finish
        A = normrnd(1,30000000,1,i);
        fname = sprintf("g-input%d-1",i);
        ptr = fopen(fname,"wt");
        fprintf(ptr,'%f\n',A);
        fclose(ptr);
        
        A = normrnd(1,1000000,1,i);
        fname = sprintf("g-input%d-2",i);
        ptr = fopen(fname,"wt");
        fprintf(ptr,'%f\n',A);
        fclose(ptr);
        
         A = normrnd(1,100000,1,i);
        fname = sprintf("g-input%d-3",i);
        ptr = fopen(fname,"wt");
        fprintf(ptr,'%f\n',A);
        
        fclose(ptr);
   end
