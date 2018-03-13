#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
int main()
{
FILE *f1,*f2;
int i,c1,c2,store_slno[20000];
c1=0,c2=0;
char line[100],store_res_nm[20000][4],store_res_no[20000],word[5],res_nm[4],ch_id[20000],sh_id[20000],x[9],y[9],z[9],res_no[5],slno[6], atm_nm[4],store_atm_nm[20000][4];
float store_x[20000],store_y[20000],store_z[20000],tot_x,tot_y,tot_z,cm_z,cm_x,cm_y;
f1=fopen("3fe0.pdb","r");
f2=fopen("out.pdb","w");
while(fgets(line,100,f1)!=NULL)
{
     for(i=0;i<4;i++)word[i]=line[i];
      word[4]='\0';
      if(strcmp(word,"ATOM")==0)
    {   
       for(i=0;i<5;i++) slno[i]=line[i+6];
       slno[5]='\0';
       store_slno[c1]=atoi(slno); //store atom number

       for(i=0;i<3;i++) atm_nm[i]=line[13+i];
       atm_nm[3]='\0';
      strcpy( store_atm_nm[c1],atm_nm);

       for(i=0;i<3;i++) res_nm[i]=line[17+i];
       res_nm[3]='\0';
      strcpy( store_res_nm[c1],res_nm);

       ch_id[c1]=line[21];

       for(i=0;i<4;i++) res_no[i]=line[22+i];
       res_nm[4]='\0';
       store_res_no[c1]=atoi(res_no);

       for(i=0;i<8;i++) x[i]=line[30+i];
       x[8]='\0';
       store_x[c1]=atof(x);
  
       for(i=0;i<8;i++) y[i]=line[38+i];
       y[8]='\0';
       store_y[c1]=atof(y);
    
       for(i=0;i<8;i++) z[i]=line[46+i];
       z[8]='\0';
       store_z[c1]=atof(z);

        c1++;
       }
}
fclose(f1);
fclose(f2);
int pos=0;
int neg=0;
int aro=0;
int hydero=0;
int neutral=0;
int residue_count=0;
int current_residue_no=0;
for(i=0;i<c1;i++)
{
if(store_res_no[i] !=current_residue_no)
 {current_residue_no=store_res_no[i];
   residue_count++;
         
     if(strcmp(store_res_nm[i],"LYS")==0){
        pos++;}
           else if(strcmp(store_res_nm[i],"ARG")==0){
               pos++ ;}
                  else if(strcmp(store_res_nm[i],"PHE")==0){
                     aro++ ;}
                         else if(strcmp(store_res_nm[i],"TYR")==0){
                             aro++ ;}
                                  else if(strcmp(store_res_nm[i],"TRP")==0){
                                      aro++ ;}
                                          else if(strcmp(store_res_nm[i],"ASP")==0){
                                               neg++ ;}
                                                    else if(strcmp(store_res_nm[i],"GLU")==0){
                                                        neg++ ;}
                                                else if(strcmp(store_res_nm[i],"SER")==0){
                                                   neutral++ ;}
                                           else if(strcmp(store_res_nm[i],"THR")==0){
                                              neutral++ ;}
                                       else if(strcmp(store_res_nm[i],"HIS")==0){
                                           neutral++ ;}
                                   else if(strcmp(store_res_nm[i],"ASN")==0){
                                       neutral++ ;}
                              else if(strcmp(store_res_nm[i],"GLN")==0){
                                  neutral++ ;}
                           else if(strcmp(store_res_nm[i],"MET")==0){
                               neutral++ ;}
                        else if(strcmp(store_res_nm[i],"CYS")==0){
                            neutral++ ;}
                     else if(strcmp(store_res_nm[i],"VAL")==0){
                          hydero++ ;}
                 else if(strcmp(store_res_nm[i],"ALA")==0){
                      hydero++ ;}
              else if(strcmp(store_res_nm[i],"PRO")==0){
                   hydero++ ;}
          else if(strcmp(store_res_nm[i],"GLY")==0){
                hydero++ ;}
        else if(strcmp(store_res_nm[i],"LEU")==0){
             hydero++ ;}
    else if(strcmp(store_res_nm[i],"ILE")==0){
       hydero++ ;}
}
}
float p,ne,neu,aer,hy;
p=(pos*100)/130.0;
ne=(neg*100)/130.0;
neu=(neutral*100)/130.0;
aer=(aro*100)/130.0;
hy=(hydero*100)/130.0;

printf("%f\n %f\n %f\n %f\n %f\n",p,ne,neu,aer,hy);

    
} 	 
