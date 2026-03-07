#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main()
{
	FILE* file = fopen("text.txt", "r"); //opens ifle if it exists
	if (!file) 
	{ 
		file = fopen("text.txt", "w"); //creates file, if exists owerwrites
		return 0;
	}
	
	char buffer[100];
	int n = 1;
	while(fgets(buffer, 100, file)) //returns char* to str, NULL if error or eof
	{
		printf("%d: %s", n++, buffer);
	}

	
	fseek(file, 0, SEEK_SET); // start of file
	printf("%ld \n", ftell(file));
	fgets(buffer, 100, file);
	printf("%s \n", buffer);
	printf("%ld \n", ftell(file));
	
	
	return 0;
}
