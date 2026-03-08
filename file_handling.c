#include <stdio.h>
#include <string.h>
void File_comparison_function(FILE* l_file, FILE* r_file, FILE* output)
{
    char l_buffer[100];
    char r_buffer[100];

    while(fgets(l_buffer, 100, l_file) && fgets(r_buffer, 100, r_file))
    {
        if (!strcmp(l_buffer, r_buffer))
        {
            fputs(l_buffer, output);
        }

        else
        {
            printf("File1: %s\nFile2: %s\n", l_buffer, r_buffer);
            int v;
            scanf("%d", &v);
            if (v == 1) 
            {
                fputs(l_buffer, output);
                fseek(r_file, -strlen(r_buffer), SEEK_CUR);
            }

            else if(v == 2)
            {
                fputs(r_buffer, output);
                fseek(l_file, -strlen(l_buffer), SEEK_CUR);
            }

            else if(v == 3)
            {
                fputs(l_buffer, output);
            }

            else if(v == 4)
            {
                fputs(r_buffer, output);
            }
        }
    }
}

int main(int argc, char* argv[])
{
    FILE* l_file = fopen(argv[1], "r");
    FILE* r_file = fopen(argv[2], "r");
    
    FILE* output = fopen("output.txt", "w");
    
    if (l_file && r_file) File_comparison_function(l_file, r_file, output);

    return 0;
}