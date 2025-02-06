#include "libft.h"

void ft_free_array(char **strs, int len)
{
int i;

i = 0; 

while(strs[i] && i < len)
{
    free(strs[i]);
    i++;
}
free(strs);

}