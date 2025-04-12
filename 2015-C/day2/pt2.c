#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

#define MAXLEN 100
#define DIM 3

void parse_line(const char line_buffer[], unsigned dimensions[]);
long unsigned ribbon_length(unsigned dimensions[]);
int between(unsigned x, unsigned y, unsigned z);

int main(void)
{
        // We'll do everything on the stack here because I don't know much about
        // the heap tbh. It makes "more sense" to store lines from input on the
        // heap because we don't know how long the input lines will be at
        // compile time.
	FILE *fp;
	char line_buff[MAXLEN];         // "hopefully" big enough (I know it is)
	unsigned parsed_nums[DIM];      // [l, w, h]
	long unsigned total_ribbon = 0;

	fp = fopen("input.txt", "r");

	if (fp == NULL) {
		perror("Can't read file. Exiting.\n");
		return 1;
	}

	while (fgets(line_buff, sizeof(line_buff), fp) != NULL) {
                printf("%s\n", line_buff);
                parse_line(line_buff, parsed_nums);
                printf("%d %d %d\n", parsed_nums[0], parsed_nums[1], parsed_nums[2]);
                total_ribbon += ribbon_length(parsed_nums);

	}

	if (feof(fp)) {
		printf("EOF successfully reached. Total ribbon required:\n%lu\n", total_ribbon);
                fclose(fp);
		return 0;
	} else if (ferror(fp)) {
		printf("An error occured while reading file.\n");
                fclose(fp);
		return 1;
	} else {
                printf("Okay something weird is going on. Get better at programming please. Exiting.\n");
                fclose(fp);
                return 1;
        }

}

// Split string on 'x' and convert to unsigned ints
void parse_line(const char line[], unsigned dimensions[])
{
        // idek what a bounds check is
	char ch;                // store current char
	char num[MAXLEN];       // number builder
	int line_pos = 0;
	int num_pos = 0;
	int dim_pos = 0;
        // Assume each line has the format: [\d+]x[\d+]x[\d+][\n]
        while ((ch = line[line_pos]) != '\n' && ch != '\0' && ch != EOF) {
                if (isdigit(ch))
                        num[num_pos++] = ch;
                else if (ch == 'x') {
                        num[num_pos] = '\0';
                        dimensions[dim_pos++] = (unsigned)atoi(num);
                        num_pos = 0;
                }
                line_pos++;
        }
        // left overs
        num[num_pos] = '\0';
        dimensions[dim_pos++] = (unsigned)atoi(num);
}

long unsigned ribbon_length(unsigned dimensions[])
{
        // dims
	unsigned l = dimensions[0];
	unsigned w = dimensions[1];
	unsigned h = dimensions[2];
        // vol
        unsigned vol = l * w * h;
        // min side-area
	unsigned min_side = (l <= w && l <= h) ? l : (w <= h) ? w : h;
        unsigned mid_side = between(l, w, h) ? l : between(w, l, h) ? w : h;
        printf("min: %d, mid: %d\n\n", min_side, mid_side);
	return 2 * (min_side + mid_side) + vol;
}

int between(unsigned x, unsigned y, unsigned z)
{
        return (x <= y && x > z) || (x < y && x >= z) || (x >= y && x < z) || (x > y && x <= z) || (x == y && x == z);
}
