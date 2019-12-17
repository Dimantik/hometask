#include <stdio.h>

#define LENGTH 5

void input();
void other();

int main() {
	input();
	return 0;
}

void other() {
	printf("\n***Function other was worked out.***\n");
}

void input() {

	int  data[LENGTH], i = 0, x = 0;

	printf("Addresses: data[3] = %x, data[4] = %x, data[5] = %x, other = %p\n", data[3], data[4], data[5], &other);
	
	scanf("%x", &x);

	while (x != 0) {

		data[i] = x;
		i++;
		scanf("%x", &x);

	}
}