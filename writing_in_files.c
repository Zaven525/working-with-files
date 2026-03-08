#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main()
{
    FILE* reading = fopen("text.txt", "r");
    FILE* writing = fopen("output", "w");

    char buffer[100];

    while(fgets(buffer, 100, reading))
    {
        if (strchr(buffer, 'x')) 
        {
            fputs(buffer, writing);
        }
    }

    return 0;
}