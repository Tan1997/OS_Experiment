#include <stdio.h>
#define N 15
#define M 5
int main(int argc,char *argv[])
{
    int i,j,k=0,temp=0,count=0,flag=0,num=0,flag2=0;
    int a[N];//页栈堆列
    int b[M]={0,0,0,0,0};//内存数组
    int c[M]={0,0,0,0,0};//调入时间数组
    printf("请输入页面调用序列：\n");
    for(;i<N;i++){
        scanf("%d",&a[i]);
    }
//内存中已存在，直接退出循环
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            if(b[j]==a[i]){
                flag=1;
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
	count++;
//内存中不存在，则插入，并赋给c数组相应值
        for(j=0;j<M;j++){
            if(b[j]==0){
                flag2=1;
		c[j]=j;
                b[j]=a[i];
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
//内存已满，淘汰c值最小的
	for(j=0;j<M;j++){
		if(c[j]==0){
			temp=b[j];
			break;
		}
	}
	for(k=0;k<M;k++){
		if(k!=j){
			c[k]-=1;
		}
	}
	c[j]=4;
	b[j]=a[i];
	printf("淘汰页号%d\n",temp);
         for(j=0;j<M;j++)
                printf("%d\t",b[j]);
            printf("\n");
    }
	printf("缺页次数为%d\n",count);
	printf("缺页率为%f\n",count/(float)N);
    return 0;
}
