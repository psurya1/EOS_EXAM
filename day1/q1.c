#include <stdio.h>
#include <string.h>



int main(int argc,char const *argv[])
{   
    FILE *fp;
    char str[20];
    int count=0;
    fp=fopen("file.txt","r");
    
    while(fgets(str,10,fp)!=NULL)
    {
        if((strstr(str,argv[1]))!=NULL)
        {
         printf("IT IS\n");
         printf("%s\n",argv[1]);
         count++;
        }
    }
    if(count==0)
    {
        printf("IT IS NOT\n");
    }
    fclose(fp);
    return 0;
}