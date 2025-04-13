#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(void)
{
        int char_count = system("wc --bytes input.txt");
        printf("%d\n", char_count);
        return 0;
}
