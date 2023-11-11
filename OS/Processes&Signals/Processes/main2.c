#include  <stdio.h>
#include  <sys/types.h>

#define   MAX_COUNT  200

void  ChildProcess(void);                /* child process prototype  */
void  ParentProcess(void);               /* parent process prototype */

// void  main(void)
// {
//      pid_t  pid;

//      pid = fork();
//      if (pid == 0) 
//           ChildProcess();
//      else 
//           ParentProcess();
// }
void  main(void)
{
     ParentProcess();
}

// void  ChildProcess(void)
// {
//      int   i;

//      for (i = 1; i <= MAX_COUNT; i++)
//           printf("   This line is from child, value = %d\n", i);
//      printf("   *** Child process is done ***\n");
// }

void  ChildProcess(void)
{
     time_t sw;
     srand(getpid()):
     int q;
     q = rand() % 30 + 1;

     for (num; num >= 0; num--) {
		pid_t pid = getpid();
		printf("Child Pid: %d is going to sleep!\n", pid);
		sleep(rand() % 10 + 1);
		printf("Child Pid: %d is woke!\nWhere is my Parent: %d?\n", pid, getppid());
	}
}

// void  ParentProcess(void)
// {
//      int   i;

//      for (i = 1; i <= MAX_COUNT; i++)
//           printf("This line is from parent, value = %d\n", i);
//      printf("*** Parent is done ***\n");
// }

void  ParentProcess(void)
{
	pid_t pid1, pid2;
	int status;

	pid1 = fork();
	if (pid1 == 0) {
		ChildProcess();
	}
	else if (pid1 > 0) {
		pid2 = fork();

		if (pid2 == 0) {
			ChildProcess();
		}
		else if (pid2 > 0) {
			wait(&status);
			printf("Child Pid: %d has completed.\n", pid1);
			wait(&status);
			printf("Child Pid: %d has completed.\n", pid2);
		}
		else {
			printf("Child 2 could not be forked.");
		}
	}
	else {
		printf("Child 1 could not be forked.");
	}
}
