#include <stdio.h>
/*#include <ctype.h>*/
/*#include <stdlib.h>*/

void g_add_node(int[2]);
int g_node_count(void);
void update_pos(int[2], char);

int main(void)
{
        FILE *fp;
        int pos[2] = { 0 };
        char move;

        // File reading
        fp = fopen("input.txt", "r");
        if (fp == NULL) {
                perror("Can't read file. Exiting.");
                return 1;
        }

        // Build Graph
        g_add_node(pos);
        while ((move = fgetc(fp)) != EOF) {
                update_pos(pos, move);
                g_add_node(pos);
        }

        fclose(fp);

        // success
        printf("|G| = %d\n", g_node_count());
        return 0;
}
