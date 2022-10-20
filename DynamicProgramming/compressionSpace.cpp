#include <stdio.h>


int main() {

	char a[] = "a  b   c     d123456789";
	int a_size = strlen(a);
	printf("%s\n", a);
	printf("%d\n", a_size);

	int k = 1;
	for (int i = 0; i < a_size-1; i++) {
		if ((a[i] == a[i + 1]) && a[i] == ' ')
		{
			for (int j = i ; j < a_size - 1 ; j++) {
				a[j] = a[j + 1];
				printf("%s\n", a);
				
			}
			i--;
			a[a_size - k] = '\0';
		}
	}
	printf("%s", a);


	return 0;
}