#include <stdio.h>
#include <stdlib.h>

typedef struct list {
        int pos[2];
        int num_visits;
        struct list *next;
} list;

void print_list(list * ll);
list * initialize_list(void);
list * create_node(int pos[2]);
void add_node(list * ll, int node_pos[2]);
int node_count(list * ll);
void free_list(list * head);
void update_pos(int pos[2], char symbol);

int main(void)
{

        FILE *fp;
        int curr_pos[2] = { 0 };
        char curr_move;

        // File reading
        fp = fopen("input.txt", "r");
        if (fp == NULL) {
                perror("Can't read file. Exiting.");
                return 1;
        }

        // Build List = O(n^2)
        list * head = initialize_list();
        while ((curr_move = fgetc(fp)) != EOF) {
                update_pos(curr_pos, curr_move);
                add_node(head, curr_pos);
        }

        printf("Node count: %d\n", node_count(head));
        free_list(head);
}

void print_list(list * ll)
{
        list * head = ll;
        while (head != NULL) {
                printf("[%d, %d], num_visits: %d; ", head->pos[0], head->pos[1], head->num_visits);
                head = head->next;
        }
        printf("\n");
}

list * initialize_list(void)
{
        list * LL = (list *) malloc(sizeof(list));
        LL->pos[0] = 0;
        LL->pos[1] = 0;
        LL->num_visits = 1;
        LL->next = NULL;
        return LL;
}

list * create_node(int pos[2])
{
        list * new_node = (list *) malloc(sizeof(list));
        new_node->pos[0] = pos[0];
        new_node->pos[1] = pos[1];
        new_node->num_visits = 1;
        new_node->next = NULL;
        return new_node;
}

void add_node(list * ll, int node_pos[2])
{
        list * head = ll;
        while (head->next != NULL) {
                if (head->pos[0] == node_pos[0] && head->pos[1] == node_pos[1]) {
                        head->num_visits++;
                        return;
                }
                head = head->next;
        }
        // we've hit the tail of the list
        if (head->pos[0] == node_pos[0] && head->pos[1] == node_pos[1]) {
                head->num_visits++;
                return;
        }
        list * new_node = create_node(node_pos);
        head->next = new_node;
}

int node_count(list * ll)
{
        list * head = ll;
        int i = 0;
        while (head != NULL) {
                i++;
                head = head->next;
        }
        return i;
}

void free_list(list * head)
{
        list * tmp;
        while (head != NULL) {
                tmp = head;
                head = head->next;
                free(tmp);
        }
}

void update_pos(int pos[2], char symbol)
{
        switch (symbol)
        {
                case 'v':
                        pos[1]--;
                        break;
                case '^':
                        pos[1]++;
                        break;
                case '<':
                        pos[0]--;
                        break;
                case '>':
                        pos[0]++;
                        break;
                default:
                        printf("update_pos(): OOPS. exiting.\n");
                        exit(1);
        }
}
