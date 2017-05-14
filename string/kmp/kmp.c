#include<stdio.h>
#include<string.h>

int calcNext(char * p, int next[])
{
    int nlen = strlen(p);
    next[0] = -1;
    int k = -1;
    int j = 0;

    while ( j < nlen - 1)
    {
        if ( k == -1 || p[j] == p[k] )
        {
            ++k;
            ++j;
            next[j] = k;
        }
        else
        {
            k = next[k];
        }
    }

    return 1;

}

int kmp(char * g_s, char * g_pattern, int g_next[])
{
    int ans = -1;
    int i = 0;
    int j = 0;
    int s_len = strlen(g_s);
    int pattern_len = strlen(g_pattern);
    while ( i < s_len )
    {
        if ( j == -1 || g_s[i] == g_pattern[j])
        {
            ++i;
            ++j;
        }
        else
            j = g_next[j];
        if( j == pattern_len )
        {
            ans = i - pattern_len;
            break;
        }
    }
    return ans;

}

int main()
{
    char * g_s = "I'm a good boy";
    char * g_pattern = "boy";
    int ret = 0;
    int next[4];
    if(!calcNext(g_s, next))
    {
        printf("Calculate Next Array Error\n");
    }

    ret = kmp(g_s, g_pattern, next);
    if(ret == -1)
    {
        printf("Not found\n");
    }
    else
        printf("Result:%d\n", ret);
    return 1;
}


