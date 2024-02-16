function out = repeated(start,finish,incr)
   for i = start : incr : finish
        A = int32(mod(rand(1,i)*100,5)+1);
        fname = sprintf("special-4-input%d",i);
        ptr = fopen(fname,"wt");
        fprintf(ptr,'%f\n',A);
        
        fclose(ptr);
        end