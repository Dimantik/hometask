  
#include <stdio.h>

void other() {

	printf("\n --- BUFFER OVERFLOW! --- \n\n");

}

void input() {

	int data[3], i = 0, x = 0;

	printf("Adr: %x %x %x\n", &data[3], &data[4], &data[5]);

	printf("Adr of other: %p\n", &other);

	scanf("%x", &x);
	while (x) {

		data[i] = x;
		scanf("%x", &x);
		i++;

	}
}

int main() {

	input();
	return 0;

}