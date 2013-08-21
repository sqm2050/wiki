#include <stdio.h>
//int sum(int **array,int size);
 
int sum(int (*array)[4],int size)
//int sum(int** array,int size)
{
    int ret=0;
    int i, j;
    for( i=0;i<size;i++)
    {
        for( j=0;j<4;j++)
            ret += array[i][j];
    }
     
    return ret;
}
int main()
{
	int i = 0;
    int array[8][4]={0};
    for (i =  0;i<8;i++)
    {
        array[i][0] = 1;
        array[i][1] = 2;
        array[i][2] = 3;
        array[i][3] = 4;
    }
    int ret=0;
//    ret=sum((int**)array,8);
    ret=sum(array,8);
    printf("The total number is %d\n",ret);
    return 0;
}
