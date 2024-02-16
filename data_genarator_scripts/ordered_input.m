function out = ordered_input(start,finish,incr)
      for i = start : incr : finish
        A = 1:i;
        fname = sprintf("special-3-input%d",i);
        ptr = fopen(fname,"wt");
        fprintf(ptr,'%f\n',A);
        
        fclose(ptr); 
        
        
        
        end
