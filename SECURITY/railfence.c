#include<stdio.h>
#include<string.h>
void main()
{
 int i,j,k=0,l=0,m=0,n,count=0;
 char str[20],s[20],a[10],b[10];

 printf("PLAIN TEXT :  ");
 scanf("%[^\n]s",str);   //it sets the delimiter for the scanned string as \n
 n=strlen(str);
 //Whitespace removal from string
 for (i = 0; i<n; i++)
        if (str[i] != ' ')
            s[count++] = str[i];
 //Transposition
 n=strlen(s);
 for(i=0;i<n;i++)
 {
    
if(i%2==0)
  
{
   
a[k]=s[i];
   
k++;
  
}
  
else
  
{
   
b[l]=s[i];
   
l++;
  
}
  }
 
 //Display section
 for(i=0;i<k;i++)
 {
  
printf("%c ",a[i]);     //Row 1 print
  
s[m]=a[i];
  m++;
 }
 printf("\n");
 for(i=0;i<l;i++)
 {
  
printf(" %c",b[i]);    //Row 2 print
  
s[m]=b[i];
  m++;
 }
 printf("\n\nCIPHER TEXT :  %s",s);
 getchar();
}
/*
Output:
[root@localhost security lab]# gcc railfence.c
[root@localhost security lab]# ./a.out
PLAIN TEXT :  INDIA IS MY COUNTRY
I D A S Y O N R
 N I I M C U T Y
CIPHER TEXT :  IDASYONRNIIMCUTY
[root@localhost security lab]# 
*/