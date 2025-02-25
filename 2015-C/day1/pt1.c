#include <stdio.h>

int main()
{
	FILE *fp;
	char ch;
	int floor = 0;


	fp = fopen("input1.txt", "r");
	
	if (NULL == fp) {
		printf("Can't read file. Exiting.\n");
		return 1;
	}
	ch = fgetc(fp);
	while (ch != EOF) {
		if (ch=='(')
			floor++;
		else if (ch==')')
			floor--;
		ch = fgetc(fp);
	}
	printf("ans: %d\n", floor);
	return 0;
}
