function out = same_input(start,finish,incr)
      for i = start : incr : finish
        A = ones(1,i);
        fname = sprintf("special-2-input%d",i);
        ptr = fopen(fname,"wt");
        fprintf(ptr,'%f\n',A);
        
        fclose(ptr); 
        
        
        
        end