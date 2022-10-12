#include<stdio.h>

int main(){
    int b,f,visit[10],ff[10],fs[10],bs[10],temp,fg[10],small,small_var;
    printf("No.of block");
    scanf("%d",&b);
    printf("Files");
    scanf("%d",&f);
    printf("Size of blocks");
    for(int i=1; i<=b; i++){
        scanf("%d",&bs[i]);
        visit[i]=0;
    }
    printf("Size of files");
    for(int i=1; i<=b; i++){
        scanf("%d",&fs[i]);
    }
    
    for(int i=1; i<=f; i++){
        small=0;
        for(int j=1; j<=b; j++){
            temp=bs[j]-fs[i];
            if(temp>=0 && visit[j]==0 && temp>=small){
                small=temp;
                small_var = j;
            }
        }
        if(visit[small_var]==0){
            ff[i] = small_var;
            visit[small_var]=1;
            fg[i] = small;
        }
    }
    
    printf("\t f_no \tf_size \tb_no \tb_size \tfg \n");
    for(int i=1; i<=f; i++){
        printf("\t%d \t%d \t%d \t%d \t%d \n", i,fs[i],ff[i],bs[ff[i]],fg[i]);   
    }
    return 0;
}






