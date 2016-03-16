/*************************************************************************
> File Name: main.c
> Author: 
> Mail: 
> Created Time: Tue 15 Mar 2016 03:22:04 PM CST
************************************************************************/

#include <stdlib.h>
#include <stdio.h>
int lcs[100][100];
int B[100][100];
char X[100]="10000001000000000000000!";
char Y[100]="00000000000000000!";
typedef enum _dire{ left=1,l_up=2,up=3  }dire;
void LCS(int m,int n)
{

    if(m==0||n==0)
    return;
    if(B[n][m]==l_up)
    {
//        printf("%c",X[m-1]);
        LCS(m-1,n-1);
        printf("%c",X[m-1]);
    }
    else if(B[n][m]==up)
        LCS(m,n-1);
    else 
        LCS(m-1,n);
}

//typedef enum _dire{ left,l_up,up }dire;
int main()
{

//    char X[100]="d1d3ffs!";
//    char Y[100]="3ffs!";

    int i=0;
    int M=0,N=0;//数组大小,M 表示X数组字符个数
    while(X[i]!='!')
    i++;
    M=i;
    i=0;
    while(Y[i]!='!')
    i++;
    N=i;
    //int lcs[100][100];
    //int B[100][100];
    for( i=0;i<M+1;i++)
    {
        lcs[0][i]=0;
        printf("lcs[0][%d]=%d    \n",i,lcs[0][i]);
    }
    for(i=0;i<N+1;i++)
    {
        lcs[i][0]=0;
        printf("lcs[%d][0]=%d    \n",i,lcs[i][0]);
    }
    
    int j;
    //填充数据，从左往右，从上到下；最右下边最大
    
    for( j=1;j<N+1;j++)
    {
    for( i=1;i<M+1;i++)//i代表X坐标
    {
        if(X[i-1]==Y[j-1])
        {
            lcs[j][i]=lcs[j-1][i-1]+1;
            //printf("%d  ",lcs[j][i]);
            //printf("lcs[%d][%d]=%d         l_up \n",j,i,lcs[j][i]);
            B[j][i]=l_up;
        }
        else if(lcs[j][i-1]<=lcs[j-1][i])
        {  
            lcs[j][i]=lcs[j-1][i];
            //printf("lcs[%d][%d]=%d          up\n",j,i,lcs[j][i]);
            B[j][i]=up;
        }
        else if(lcs[j][i-1]>lcs[j-1][i])
        {
            lcs[j][i]=lcs[j][i-1];
            //printf("lcs[%d][%d]=%d         left \n",j,i,lcs[j][i]);
            B[j][i]=left;

        }
    }
    }


/*
    for(j=0;j<N+1;j++)
    {
    printf("\n");
    for(i=0;i<M+1;i++)
    printf("lcs[%d][%d]=%d          ",j,i,lcs[j][i]);
    }
    

    for(j=0;j<N+1;j++)
    {
        printf("\n");
        for(i=0;i<M+1;i++)
         printf("B[%d][%d]=%d          ",j,i,B[j][i]);
    }
   // 
   // printf("\n%d",LCS(M,N));
   // */
   printf("%s\n",X);
   printf("%s\n",Y);
    LCS(M,N);

    return 0;
}
