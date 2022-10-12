#include <stdio.h>
int main()
{
	int b,f,visit[10],ff[10],fe[10],be[10],temp,fg[10];
	printf("block : ");
	scanf("%d",&b);
	printf("file : ");
	scanf("%d",&f);
	printf("Block size :");
	for(int i=0;i<b;i++){
		scanf("%d",&be[i]);	
		visit[i]=0;
	}
	printf("File size : ");
	for(int j=0;j<f;j++){
		scanf("%d",&fe[j]);
		
	}
	for(int i=0;i<f;i++)
	{
		for(int j=0;j<b;j++)
		{
			
				temp=be[j]-fe[i];
				if(temp>=0 && visit[j]==0)
				{
					ff[i]=j;
					visit[j]=1;
					fg[j]=temp;
					break;					
				}
		}
	}
	printf("\n");
	printf("\tf_no \tf_size \tb_no \tb_size \tfg \n");
	for(int i=0;i<f;i++)
		printf("\t%d \t%d \t%d \t%d \t%d\n",i+1,fe[i],ff[i]+1,be[ff[i]],fg[i]);
	return 0;
}