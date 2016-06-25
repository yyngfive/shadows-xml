#include "main.h"

int main(int argc, char const *argv[])
{
    FILE *fp;
    fp = fopen("test.xml","r");
    if (fp != NULL)
    {
        format_xml(fp);
        fclose(fp);
        return 0;
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
    fseek(file,0,0);
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

    file_leng = get_length(xml);
    printf("%d\n",file_leng );
    formated = (char *)malloc(file_leng+1);
    if(formated == NULL)
    {
        printf("%s\n","ERROR!" );
        return NULL;
    }
    while (! feof(xml) )
    {
        formated[i] = fgetc(xml);
    }
    for(i;i < file_leng;i++)
    {
        printf("%c",formated[i]);
    }
    printf("\n" );
    return formated;
}
