#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MIN(a,b) a<b?a:b 

int manacher(char * s, int * p)
{
    int size = strlen(s);
    int id = 0;
    int mx = 1;
    p[0] = 1;

    for(int i = 0; i < size; i++)
    {
        if(mx > i)
        {
            p[i] = MIN(p[2*id - i], mx - i);
        }
        else
        {
            p[i] = 1;
        }
        for(;s[i+p[i]] == s[i-p[i]]; p[i]++)
            ;
        if(mx < i + p[i])
        {
            mx = i + p[i];
            id = i;
        }
    }
    return 1;
}

int extendString(char *s, char * new_s)
{
    int size = strlen(s);
    int new_size = 2 * size + 2;
    new_s[0] = '$';
    for(int i = 1, j = 0; i < new_size; i++)
    {
        if(i == (j + 1) * 2)
        {
            new_s[i] = s[j];
            j++;
        }
        else
        {
            new_s[i] = '#';   
        }
    } 
    new_s[new_size] = '\0';
    return 1;
}


int main()
{
    char * s = "whatitahwsht";
    int size = strlen(s);
    int new_size = 2 * size + 2;
    char * s_new = (char *) malloc( new_size + 1 );
    int * p = (int *) malloc(new_size);
    if(s_new == NULL)
    {
        printf("Malloc Fail!\n");
    } 
    if(!extendString(s, s_new))
    {
        printf("Extend String Fail\n");
    }
    printf("%s\n",s_new); 
    if(!manacher(s_new,p))
    {
        printf("Manacher Fail\n");
    }
    
    return 1;
}
