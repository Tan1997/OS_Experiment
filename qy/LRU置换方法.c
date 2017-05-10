#include <stdio.h>
#define N 15
#define M 5
int main(int argc,char *argv[])
{
    int i,j,k=0,count=0,flag=0,num=0,flag2=0;
    int a[N];//页栈堆列
    int b[M]={0,0,0,0,0};//内存页堆列
    printf("请输入页面调用序列：\n");
    for(;i<N;i++){
        scanf("%d",&a[i]);
    }
//
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            if(b[j]==a[i]){
                flag=1;
                for(k=j;k>0;k--){
                    b[k]=b[k-1];
                }
                b[0]=a[i];
                break;
            }
        }
        if(flag==1){
            flag=0;
            for(j=0;j<M;j++)
                printf("%d\t",b[j]);
            printf("\n");
            continue;
        }
//
	count++;
        for(j=0;j<M;j++){
            if(b[j]==0){
                flag2=1;
                for(k=j;k>0;k--){
                    b[k]=b[k-1];
                }
                b[0]=a[i];
                break;
            }
        }
        if(flag2==1){
            flag2=0;
            for(j=0;j<M;j++)
                printf("%d\t",b[j]);
            printf("\n");
            continue;
        }
//
	printf("淘汰页号%d\n",b[M-1]);
        for(k=M;k>0;k--){
            b[k]=b[k-1];
         }
         b[0]=a[i];
         for(j=0;j<M;j++)
                printf("%d\t",b[j]);
            printf("\n");
    }
	printf("缺页次数为%d\n",count);
	printf("缺页率为%f\n",count/(float)N);
    return 0;
}
