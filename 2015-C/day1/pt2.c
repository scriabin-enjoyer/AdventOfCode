#include <stdio.h>

int main(void)
{
	FILE *fp;
	char ch;
	// Looking at the input, we can assume no overflows.
	int floor = 0;
	int pos = 0;

	fp = fopen("input1.txt", "r");
	
	if (NULL == fp) {
		perror("Can't read file. Exiting.\n");
		return 1;
	}

	ch = fgetc(fp);
	while (ch != EOF) {
		if (ch=='(')
			floor++;
		else if (ch==')')
			floor--;
		if (floor == -1)
			goto answer;
		ch = fgetc(fp);
	}
answer:
	printf("ans: %ld\n", ftell(fp));
	fclose(fp);
	return 0;
}
