#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

int main()
{

	int pid = fork();


	//shmget returns an identifier in shmid
	int shmid1 = shmget((key_t)100,1024,0666|IPC_CREAT);
	int shmid2 = shmget((key_t)200,1,0666|IPC_CREAT);
	char *flag = (char *) shmat(shmid2,(void*)0,0);
	flag[0]='w';

	if (pid!=0)
	{
		//shmat to attach to shared memory
		char *str = (char *) shmat(shmid1,(void*)0,0);
		//int p = getpid();


		//flag[0] = 'w';
		printf("Write data : ");

		fgets(str,1000,stdin);
		printf("process %d writing data to memory : %s\n",getpid(),str);
		shmdt(str);
		flag[0]='r';
	}
	
	else 
	{
		while (flag[0]=='w');
		int p = getpid();

		char *str = (char*) shmat(shmid1,(void*)0,0);

		printf("process %d reading from memory: %s\n",p,str);
		// destroy the shared memory
		shmctl(shmid1,IPC_RMID,NULL);
		   
		
		return 0;
	}

}
