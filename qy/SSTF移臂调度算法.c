#include<stdio.h>
#include<math.h>
#define MAXMUM 10000
#define N 15
void main()
{
	int i,n=0,min,mark=-1,sum=0,now;
	int a[N];
	int flag[N];
	printf("请输入磁头位置：\n");
	scanf("%d",&now);
	printf("请输入磁盘请求序列：\n");
	for(i=0;i<N;i++)
		scanf("%d",&a[i]);
	for(i=0;i<N;i++)
		flag[i]=0;
	min=MAXMUM;
	printf("输出响应磁盘请求的顺序：\n");
	printf("%d\t",now);
	for(;n<N;n++)
	{
		for(i=0;i<N;i++)
			if(flag[i]==0)
				if(min>abs(a[i]-now))
				{
					min=abs(a[i]-now);
					mark=i;
				}
		flag[mark]=1;
		sum+=min;
		printf("%d\t",a[mark]);
		min=MAXMUM;
		now=a[mark];
	}
	printf("\n输出移臂的总量：\n");
	printf("%d\n",sum);
}






