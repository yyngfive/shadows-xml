#include "main.h"

int main(int argc, char const *argv[])
{
    int length;
    FILE *fp;
    fp = fopen("test1.x","r");
    length = get_length(fp);
    if(length == -1)
    {
        printf("%s\n","无法得到长度" );
    }
    fclose(fp);
    printf("%d\n",length);
    return 0;
}

int get_length(FILE *file)
{
    int i,length;
    i = 0;
    length = 0;
    if (file == NULL)
    {
        return -1;
    }
    for ( i ; feof(file) == 0 ; i++)
    {
            fgetc(file);
    }
    length = i;
    return length;
}
