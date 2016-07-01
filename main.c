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
    rewind(file);
    return i;
}

int get_label_length(FILE *file)
{
    int length;
    const char r_chevron = '>';
    char c;
    length = 0;
    for(length;c != r_chevron;length++)
    {
        c = fgetc(file);
    }
    fseek(file,0-length,SEEK_CUR);
    return length;
}

char *no_format(FILE *xml)
{
    char c;
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

    //测试
    /*while (! feof(xml) )
    {
         *changed++ = fgetc(xml);
    }
    printf("%s\n",head);
    */
    while (! feof(xml))
    {
        c = fgetc(xml);
        switch (c)
        {
            //对于标签，不去空格。
            case '<':
                *changed = c;
                changed++;
                label_leng = get_label_length(xml);
                for(label_leng;label_leng > 0;label_leng--)
                {
                    c = fgetc(xml);
                    *changed = c;
                    changed++;
                }
                break;
            case ' ':
                break;
            case '\r':
                break;
            case '\n':
                break;
            default:
                *changed = c;
                changed++;
            }
    }
    printf("%s\n",head );
    free(head);
    return NULL;
}
