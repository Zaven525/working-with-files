#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main()
{
    FILE* reading = fopen("text.txt", "r");
    FILE* writing = fopen("output", "w");

    
    return 0;
}