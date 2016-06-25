#include "main.h"

int main(int argc, char const *argv[])
{
    char data[1024];
    FILE *fp;
    fp = fopen("test1.x","r");
    if (file != NULL)
    {
        data = format_xml(file);
        printf("%s\n",data);
        fclose(fp);
    }
    printf("%s\n","Can not open the file!\n" );
    return 0;
}

int get_length(FILE *file)
{
    int i;
    i = 0;
    for ( i ; feof(file) == 0 ; i++)
    {
            fgetc(file);
    }
    return i;
}

char *format_xml(FILE *xml)
{
    char c;
    const char space = ' ';
    const char enter1 = '\r';
    const char enter2 = '\n';
    const char l_chevron = '<';
    const char r_chevron = '>';

    int label_leng = 0,file_leng = 0;
    int i = 0;
    char *formated = NULL;

    file_leng = get_length(file);
    formated = (char *)malloc(file_leng+1);
    while (feof(file) != 0 )
    {
        formated[i] = fgetc(file);
    }
    return formated;
}
