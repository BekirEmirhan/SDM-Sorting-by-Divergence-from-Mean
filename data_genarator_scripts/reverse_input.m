function out = reverse_input(start,finish,incr)
      for i = start : incr : finish
        A = i:-1:1;
        fname = sprintf("special-1-input%d",i);
        ptr = fopen(fname,"wt");
        fprintf(ptr,'%f\n',A);
        
        fclose(ptr); 
        
        
        
        end
  
  