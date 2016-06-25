#include "main.h"

int get_length(FILE *file)
{
    int i,length;
    i = 0;
    length = 0;
    for ( i ; feof(file) == 0 ; i++)
    {
            fgetc(file);
    }
    length = i;
    return length;
}

int main(int argc, char const *argv[])
{
    int length;
    FILE *fp;
    fp = fopen("test.txt","r");
    length = get_length(fp);
    fclose(fp);
    printf("%d\n",length);
    return 0;
}
