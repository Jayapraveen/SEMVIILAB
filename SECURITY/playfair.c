#include<stdio.h>
#include<string.h>
void initialize();
void fillMatrix();
void fillRemaining(int);
void displayMatrix();
void encrypt();
void searchMatrix(int,int);
char matrix[5][5],keyword[25],plaintext[25],ciphertext[25],flag[26];
int row,col,row1,col1,row2,col2;
void main()
{
initialize();
printf("\nEnter Keyword: ");
scanf("%s",keyword);
printf("\nEnter Plaintext:");
scanf("%s",plaintext);
fillMatrix();
encrypt();
displayMatrix();
printf("\nCiphertext: %s \n",ciphertext);
}
void initialize()
{
int i,j;
for(i=0;i<26;i++)
flag[i]=0;
for(i=0;i<5;i++)
for(j=0;j<5;j++)
matrix[i][j]=0;
}
void fillMatrix()
{
int k=0,i,j,p,m=0,n,val;
flag[9]=1;  //since J is put in I 
n=strlen(keyword);
for(i=0;i<5;i++)
{
for(j=0;j<5;j++)
{
b:
if(k<n)
{
val=keyword[k]-65;
 
if(flag[val]==0)
{
matrix[i][j]=keyword[k];
flag[val]=1;k++;
}
else
{
k++;
goto b;
}
}
else
{
col=j;
goto c;
}
                }
}
  
c:      row=i;
while(m<26)
{
  
if(flag[m]==0)
fillRemaining(m);
m++;
        }
}
void fillRemaining(int m)
{
 
if(row<5)
{
if(col<5)
        { matrix[row][col]=m+65;
}
else
{
col=0;
row++;
matrix[row][col]=m+65;
}
}
col++;
}
 
void encrypt()
{
int psize,i=0,j=1;
psize=strlen(plaintext);
 
if(psize%2!=0)   //Adding filler character X since plaintext is odd in size
strcat(plaintext,"X");
while(j<=psize)
{
searchMatrix(i,j);
if(row1==row2)  //same row plaintext elements
{
if(plaintext[i]==plaintext[j])    //Adding $ if two plaintext elements refer to
same character
{
ciphertext[i]=matrix[row1][(col1+1)%5];
ciphertext[j]='$';
}
else
{
ciphertext[i]= matrix[row1][(col1+1)%5];
ciphertext[j]= matrix[row2][(col2+1)%5];
}
}
else if(col1==col2)  //same col plaintext elements
     {
ciphertext[i]= matrix[(row1+1)%5][col1];
ciphertext[j]= matrix[(row2+1)%5][col2];
     }
     else // different row and different col plaintext elements
     {
ciphertext[i]= matrix[row1][col2];
ciphertext[j]= matrix[row2][col1];
     }
i+=2;
j+=2;printf("\n");
        }
}
void searchMatrix(int i,int j)
{
int r,t,foundRow,foundCol;
for(r=0;r<5;r++)
{
for(t=0;t<5;t++)
{
if(plaintext[i]==matrix[r][t])
{
row1=r;col1=t;
foundRow=1;
}
if(plaintext[j]==matrix[r][t])
{
row2=r;col2=t;
foundCol=1;
}
}
if((foundRow==1)&&(foundCol==1))
break;
}
}
void displayMatrix()
{
 
int i,j;
printf("\n");
for(i=0;i<5;i++)
{
for(j=0;j<5;j++)
printf("%c ",matrix[i][j]);
printf("\n");
}
}

/*
Output:
Output:
[root@localhost security lab]# gcc playfair.c
[root@localhost security lab]# ./a.out
Enter Keyword: MONARCHY
Enter Plaintext:INDIA
M O N A R
C H Y B D
E F G I K
L P Q S T
U V W X Z 
Ciphertext: GABKBA
Result:
*/