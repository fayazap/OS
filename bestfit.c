
#include <stdio.h>


int find(int nb,int b[],int a,int bf[]){
    int i,best=1000,pos=-1,temp;
    for(i=0;i<nb;i++){
        if(bf[i]!=1){
            temp=b[i]-a;
            if(temp>=0){
                if(temp<best){
                    best=temp;
                    pos=i;
                }
            }
        }
    }
    return pos;
}


int main() {
int nf,nb,i,j,bf[10],b[10],f[10],flag,all[10],bk,temp,highest,pos;
printf("Enter number of blocks");
scanf("%d",&nb);
printf("Enter size of blocks");
for(i=0;i<nb;i++){
    scanf("%d",&b[i]);
}
printf("Enter number of files");
scanf("%d",&nf);
printf("Enter size of files");
for(i=0;i<nf;i++){
    scanf("%d",&f[i]);
}
for(i=0;i<nb;i++){
    bf[i]=0;
}

for(i=0;i<nf;i++){
    pos =find(nb,b,f[i],bf);
    bf[pos]=1;
    all[i]=pos;
}
for(i=0;i<nf;i++){
printf("%d got %d \n",i,all[i]);
}
}

