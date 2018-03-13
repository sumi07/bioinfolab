#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
main()
{
     FILE *f1,*f2,*f3,*f4,*f5,*f6,*f7,*f8,*f9;
int i;
char ch_id,line[100],word[5];
f1=fopen("5un8.pdb","r");
f2=fopen("5un8a.pdb","w");
f3=fopen("5un8b.pdb","w");
f4=fopen("5un8c.pdb","w");
f5=fopen("5un8d.pdb","w");
f6=fopen("5un8e.pdb","w");
f7=fopen("5un8f.pdb","w");
f8=fopen("5un8g.pdb","w");
f9=fopen("5un8h.pdb","w");


while(fgets(line,100,f1)!=NULL)
{
     for(i=0;i<4;i++)word[i]=line[i];
      word[4]='\0';
      if(strcmp(word,"ATOM")==0)
      {  
          ch_id=line[21]; 
           if(ch_id=='A')
            { 
              fprintf(f2,"%s",line);
        }
          
           if(ch_id=='B')
            { 
               fprintf(f3,"%s",line);

        }
         if(ch_id=='C')
            { 
              fprintf(f4,"%s",line);
        }
        if(ch_id=='D')
            { 
              fprintf(f5,"%s",line);
        }
        if(ch_id=='E')
            { 
              fprintf(f6,"%s",line);
        }
       if(ch_id=='F')
            { 
              fprintf(f7,"%s",line);
        }
     if(ch_id=='G')
            { 
              fprintf(f8,"%s",line);
        }
      if(ch_id=='H')
            { 
              fprintf(f9,"%s",line);
        }
     }
}
   fclose(f1);
   fclose(f2);
   fclose(f3);
   fclose(f4);
   fclose(f5);
   fclose(f6);
   fclose(f7);
   fclose(f8);
   fclose(f9);
     
  
}                        
