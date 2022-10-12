#include<stdio.h>

int findLRU(int t[], int fcount) {
    int k, min, pos;
    pos =0;
    min = t[0];
    for(k=1; k< fcount; ++k){
        if(t[k]<min){
            min = t[k];
            pos=k;
        }
    }
    return pos;
}

void LRU(int pages[], int frames[], int t[], int fc, int pc){
    int i,j,k,pos,flag,fcount,counter,queue;
    counter=0, queue=0, fcount=0;
    for(i=0; i<pc; i++){
        flag=0;
        printf("%d \t| \t", pages[i]);
        for(j=0; j<fc; j++){
            if(frames[j] == pages[i]){
                flag=1;
                counter++;
                t[j] = counter;
                printf("Hit\n\n");
                break;
            }
        }
        if((flag==0) && (queue<fc)){
            fcount++;
            counter++;  
            frames[queue] = pages[i];
            t[queue] = counter;
            queue++;
        }
        else if((flag==0) && (queue==fc)){
            fcount++;
            counter++;
            pos = findLRU(t, fc);
            frames[pos] = pages[i];
            t[pos] = counter;
         }
         if(flag==0){
             for(k=0; k<fc; k++){
                 printf("%d", frames[k]);
             }
             printf("\n\n");
         }
    }
    printf("\n Total page faults = %d\n\n", fcount);
}

int main() {
    int i, pc, fc, pages[30], frames[20], t[20];
    printf("No.of frames");
    scanf("%d",&fc);
    for (i = 0; i < fc; ++i)
    frames[i] = -1;
    printf("\n Number of Pages : ");
    scanf("%d", &pc);
    printf("\n Enter the reference string : ");
    for (i = 0; i < pc; ++i)
    scanf("%d", &pages[i]);
    LRU(pages, frames, t, fc, pc);
    return 0;

}






