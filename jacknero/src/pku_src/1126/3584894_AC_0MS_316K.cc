#include <stdio.h>
#include <string.h>
 
int main()
{
    int i, count, len;
    char line[257];
 
    while (EOF != scanf("%s", line))
    {
        count = 0;
        len = strlen(line);
        for (i = len - 1; i >= 0; --i)
        {
            if ('p' <= line[i] && line[i] <= 'z')
                ++count;
            else if ('N' == line[i])
            {
                if (0 == count)
                    break;
            }
            else if ('C' == line[i] || 'D' == line[i] || 'E' == line[i] || 'I' == line[i])
            {
                if (count >= 2)
                    --count;
                else
                {
                    count = 0;
                    break;
                }
            }
            else
            {
                count = 0;
                break;
            }
        }
        printf(1 == count ? "YES\n" : "NO\n");
    }
}