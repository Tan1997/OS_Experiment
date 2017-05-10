#include<stdio.h>
#include<math.h>
#define N 15
void sort(int a[N],int len)//排序
{
	int i,j,t;
	for(j=0;j<len;j++)
	{
		for(i=0;i<len-j-1;i++)
			if(a[i]>a[i+1])
			{
				t=a[i];
				a[i]=a[i+1];
				a[i+1]=t;


			}
	}
}
void main()
{
	int i,n=0,min,mark=-1,sum=0,now,direct;
	int a[N];
	printf("请输入磁头位置：\n");
	scanf("%d",&now);
	printf("请输入方向:(0表示像小，1表示向大）\n");
	scanf("%d",&direct);
	printf("请输入磁盘请求序列：\n");
	for(i=0;i<N-1;i++)
		scanf("%d",&a[i]);
	a[N-1]=now;
	printf("输出响应磁盘请求的顺序：\n");
	printf("%d\t",now);
	sort(a,N);
	for(n=0;n<N;n++){
		if(a[n]==now){
			break;
		}
	}
	if(direct==0){
		for(i=n-1;i>=0;i--){
			printf("%d\t",a[i]);
			sum+=now-a[i];
			now=a[i];
		}
		for(i=n+1;i<N;i++){
			printf("%d\t",a[i]);
			sum+=a[i]-now;
			now=a[i];
		}
	}
	else{
		for(i=n+1;i<N;i++){
			printf("%d\t",a[i]);
			sum+=a[i]-now;
			now=a[i];
		}
		for(i=n-1;i>=0;i--){
			printf("%d\t",a[i]);
			sum+=now-a[i];
			now=a[i];
		}
	}
	printf("\n输出移臂的总量：\n");
	printf("%d\n",sum);
}






