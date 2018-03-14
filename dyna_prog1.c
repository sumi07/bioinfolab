#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
main ()
{
  int n1,n2,gap_penalty,match_value ,mismatch_value;
printf("length of strings:");
scanf("%i %i",&n1,&n2);
char str1[n1],str2[n2];
printf("input first string:");
scanf("%s",str1);
printf("input second string:");
scanf("%s",str2);
printf("input mismatch value:");
scanf("%i",&mismatch_value);
printf("input match value:");
scanf("%i",&match_value);
printf("input gap_penalty value:");
scanf("%i",&gap_penalty);
int table[n1+1][n2+1];
table[0][0]=0;
int i,j;
 for( j=1;j<n2+1;j++)
{ table[0][j] +=gap_penalty;
}
for( i=1;i<n1+1;i++)
{
table[i][0] +=gap_penalty;
}
for(i=0;i<n1;i++)
     {
       for(j=0;j<n2;j++)
        {
          if(str1[i]==str2[j])
            {
              int score, x,y;
              score=table[i][j]+match_value;
              x=table[i+1][j]+gap_penalty;
              y=table[i][j+1]+gap_penalty;
               if(score>=x && score>=y)
                 { 
                    table[i+1][j+1]=score;
                  }
                 if(x>=score && x>=y)
                  { 
                    table[i+1][j+1]=x;
                   }
                  if(y>=score && y>=x)
                  {
                    table[i+1][j+1]=y;
                  }
                }
             else
                 {
                    int score, x,y;
              score=table[i][j]+mismatch_value;
              x=table[i+1][j]+gap_penalty;
              y=table[i][j+1]+gap_penalty;
               if(score>=x && score>=y)
                 {
                    table[i+1][j+1]=score;
                  }
                 if(x>=score && x>=y)
                  {
                    table[i+1][j+1]=x;
                   }
                  if(y>=score && y>=x)
                  {
                    table[i+1][j+1]=y;
                  }
                }
       
       }
   }
   for(i=0;i<n1+1;i++)
      {
        for(j=0;j<n2+1;j++)
        {
          printf(" %5d",table[i][j]);
     }
  }
}

