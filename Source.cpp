#include <iostream>
#include <semaphore.h>
#include <sys/shm.h>
#include <queue>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
using namespace std;


int main()
{
	int n;

	cout << "Enter a number between 10-100: ";
	cin >> n;

	while(n <= 10 || n >= 100)
	{
		cout << "Wrong input. Please enter a number between 10-100: ";
		cin >> n;
	}

	int pid1,pid2;
	int k = 700;
	int id_sem1 = shmget(k, 1024, 0666 | IPC_CREAT | IPC_EXCL);
	
	sem_t *semaphore1;

	if (id_sem1 == -1)
	{   
		cout<<"ERROR!";
		return 1;
	}

	semaphore1 = (sem_t*) shmat(id_sem1, NULL, 0);
	sem_init(semaphore1, 1, 0);	

	pid1 = fork();

	if(pid1 != 0)
	{
		pid2 = fork();
	}
		
	if(pid1 == 0)
	{
		cout << ">>>starting process 1 the process ID is:" << getpid() << endl;
		int i = 1;
		while(i != (n/2) + 1)
		{
			cout << "process 1: " << i << " , the process ID is:" << getpid() << endl;
			i++;
		}
		cout << ">>>ending process 1 the process ID is:" << getpid() << endl;
		sem_post(semaphore1);			
			
	}
		
	if(pid2 == 0)
	{					
		sem_wait(semaphore1);

		cout << endl << ">>>starting process 2 the process ID is:" << getpid() << endl;
	
		int i = (n/2) + 1;
		while(i != n+1)
		{
			cout << "process 2: " << i << " , the process ID is:" << getpid() << endl;
			i++;
		}
		cout << ">>>ending process 1 the process ID is:" << getpid() << endl;
	}
		
		
	if((pid1!=0)&&(pid2!=0))
	{
		wait(NULL);		
	}
		
	sem_destroy(semaphore1);
	shmdt(semaphore1);
	shmctl(id_sem1, IPC_RMID, NULL);

	return 0;
}


