#include "main.h"

int main(int argc, char const *argv[])
{
    FILE *fp;
    fp = fopen("test.xml","r");
    if (fp != NULL)
    {
        no_format(fp);
        fclose(fp);
        return 0;
    }
    printf("%s\n","不能打开文件\n" );
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

char *no_format(FILE *xml)
{
    char c;
    const char space = ' ';
    const char enter1 = '\r';
    const char enter2 = '\n';
    const char l_chevron = '<';
    const char r_chevron = '>';

    int label_leng = 0,file_leng = 0;
    int i = 0;
    char *changed = NULL;
    char *head;

    file_leng = get_length(xml);
    changed = (char *)malloc(file_leng);
    if(changed  == NULL)
    {
        printf("%s\n","内存分配错误！");
        return NULL;
    }
    head = changed ;
    while (! feof(xml) )
    {
         *changed++ = fgetc(xml);
    }
    for(i;i < file_leng;i++)
    {
        printf("%s",head);
    }
    printf("\n" );
    free(head);
    return NULL;
}
