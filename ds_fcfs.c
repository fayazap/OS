#include <stdio.h>
#include <stdlib.h>

void fcfs(int arr[], int head, int n)
{
    int seek_count=0;
    int distance, cur_track;
    for(int i=0; i<n; i++){
        cur_track = arr[i];
        distance = abs(cur_track - head);
        seek_count += distance;
        head = cur_track;
    }
        printf("total seek count %d", seek_count);
        
        printf("\n sequence ->");
        for(int i=0; i<n; i++){
            printf("%d ->", arr[i]);
        }
}
int main()
{
    int n, head;
	printf("Enter the no of tracks : ");
	scanf("%d",&n);
	int tracks[n];
	printf("Enter the head position :");
	scanf("%d",&head);
	printf("Enter the tracks to be seeked :");
	for(int i=0;i<n;i++)
		scanf("%d",&tracks[i]);
	fcfs(tracks,head,n);
	return 0;
}