#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <string>

int main()
{
	char str1[] = "Ping";
	char str2[] = "Pong";
	char buffer[5];

	memset(buffer , 0 , 5);

	int fd1[2];
	int fd2[2];

	if(pipe(fd1) < 0)
	{
		printf("%s\n" , "Couldn't create a pipe");
		return 1;
	}

	if(pipe(fd2) < 0)
	{
		printf("%s\n" , "Couldn't create a pipe");
		return 1;
	}

	pid_t p = fork();

	if(p < 0)
	{
		printf("%s\n" , "Fork fault");
	    return 1;
	}
	

	while(true)
	{
		if(p == 0)
		{
			write(fd2[1] , str1 , 5);
			wait(NULL);
			sleep(1);
			read(fd1[0] , buffer , 5);
			sleep(1);
			printf("%s\n" , buffer);
		}
		else
		{
			write(fd1[1] , str2 , 5);
			read(fd2[0] , buffer , 5);
			sleep(1);
			printf("%s\n" , buffer);
		}
	//	char c;
	//	std::cin >> c;
	//	//if(c == 'Q' || c == 'q')
	//	{
	//		return 0;
	//	}
	//	std::string c;
	//	if(std::getline(std::cin , c))
	//	{
	//		if(c == "Q" || c == "q")
	//			break;
	//	}
	//	std::cin>>c;
	//	if(c == 'Q' || c == 'q')
	//	{
	//		break;
	//	}
	}

}
