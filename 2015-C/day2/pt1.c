#include <stdio.h>

unsigned *parse_line(const char line_buffer[], unsigned uint_buffer[]);
unsigned SA(unsigned l, unsigned w, unsigned h);

int main(void)
{
	FILE fp;
	char buff[100];
	unsigned parsed[3];	// l, w, h
	long unsigned total_paper = 0;

	fp = fopen("input.txt", "r");

	if (fp == NULL) {
		perror("Can't read file. Exiting.\n");
		return 1;
	}

	while (fgets(buff, sizeof(buff), fp) != NULL) {
		// parse buff
		// calculate area
		// add area to accumulator
	}

	if (feof(fp)) {
		printf("EOF successfully reached. Total paper required: %lu\n");
		return 0;
	} else if (ferror(fp)) {
		printf("An error occured while reading file.\n");
		return 1;
	}

}

unsigned *parse_line(const char line[], unsigned nums[])
{
	char ch;
	char num[];
	int pos = 0;
	
	// read char
	// if char numeric:
	// 	write into num[]; advance cursor
	// else:
	// 	advance cursor
	// evaluate loop condition: not newline, EOF, or null terminator
}

unsigned SA(unsigned l, unsigned w, unsigned h)
{
	unsigned x = l * h;
	unsigned y = l * w;
	unsigned z = w * h;
	unsigned min = (x >= y && x >= z) ? x : (y > z) ? y : z;

	return 2 * (x + y + z) + min;
}
