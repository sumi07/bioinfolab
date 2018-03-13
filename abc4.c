#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
 float find_distance(x,y,z,x1,y1,z1)
{   

float distance=0.0;
     distance=sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1)+(z-z1)*(z-z1));
  return distance;
}

int main()
{
FILE *f1,*f2;
int i,j,c1,c2,store_slno[20000],store_slno1[20000];
c1=0,c2=0;
char line[100],store_res_nm[20000][4],store_res_no[20000],word[5],res_nm[4],ch_id[20000],sh_id[20000],x[9],y[9],z[9],res_no[5],slno[6], atm_nm[4],store_atm_nm[20000][4],store_res_nm1[20000][4],store_res_no1[20000],res_nm1[4],res_no1[5], atm_nm1[4],store_atm_nm1[20000][4];
;
float distance, store_x[20000],store_y[20000],store_z[20000],store_x1[20000],store_y1[20000],store_z1[20000];
f1=fopen("1asy.pdb","r");
f2=fopen("out.pdb","w");
while(fgets(line,100,f1)!=NULL)
{
     for(i=0;i<4;i++)word[i]=line[i];
      word[4]='\0';
      if(strcmp(word,"ATOM")==0)
      {     
            for(i=0;i<1;i++)
            ch_id[i]=line[i+21];
            ch_id[2]='\0';
           if(strcmp(ch_id,"R")==0)
         {    
                for(i=0;i<5;i++) slno[i]=line[i+6];
                slno[5]='\0';
                store_slno[c1]=atoi(slno);
    
             for(i=0;i<3;i++) atm_nm[i]=line[13+i];
              atm_nm[3]='\0';
              strcpy( store_atm_nm[c1],atm_nm);
                      
             for(i=0;i<3;i++) res_nm[i]=line[17+i];
             res_nm[3]='\0';
             strcpy( store_res_nm[c1],res_nm);
             
     
              for(i=0;i<4;i++) res_no[i]=line[22+i];
              res_nm[4]='\0';
             store_res_no[c1]=atoi(res_no);


              for(i=0;i<8;i++) x[i]=line[32+i];
              x[8]='\0';
              store_x[c1]=atof(x);
  
              for(i=0;i<8;i++) y[i]=line[40+i];
              y[8]='\0';
              store_y[c1]=atof(y);
    
              for(i=0;i<8;i++) z[i]=line[48+i];
              z[8]='\0';
              store_z[c1]=atof(z);

              c1++;
    }
      else if(strcmp(ch_id,"A")==0)
      {  
           for(i=0;i<5;i++) slno[i]=line[i+6];
                slno[5]='\0';
                store_slno1[c2]=atoi(slno);

             for(i=0;i<3;i++) atm_nm1[i]=line[13+i];
              atm_nm1[3]='\0';
              strcpy( store_atm_nm1[c2],atm_nm1);

             for(i=0;i<3;i++) res_nm1[i]=line[17+i];
             res_nm1[3]='\0';
             strcpy( store_res_nm1[c2],res_nm1);

              for(i=0;i<4;i++) res_no1[i]=line[22+i];
              res_nm1[4]='\0';
             store_res_no1[c2]=atoi(res_no1);


          for(i=0;i<8;i++) x[i]=line[32+i];
          x[8]='\0';
          store_x1[c2]=atof(x);

          for(i=0;i<8;i++) y[i]=line[40+i];
          y[8]='\0';
          store_y1[c2]=atof(y);

         for(i=0;i<8;i++) z[i]=line[48+i];
         z[8]='\0';
         store_z1[c2]=atof(z);

        c2++;

          }
  }
  } 
     for(i=0;i<c1;i++)
     {
         for(j=0;j<c2;j++)
        { 
           distance= find_distance(store_x[i],store_y[i],store_z[i],store_x1[j],store_y1[j],store_z1[j]);
           printf("%f",distance);       
                  if(distance<=4.5)
                       {
                           
                     printf("%i  %s  %s %i %i  %s  %s %i\n",store_slno1[j],store_atm_nm1[j],store_res_nm1[j],store_res_no1[j],store_slno[i],store_atm_nm[i],store_res_nm[i],store_res_no[i]);
                      }
                }
         }
fclose(f1);
fclose(f2);
  }
