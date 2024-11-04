#include <stdio.h>
#include <string.h>

void main() {
	int i = 0, j, n = 0, d;
	char a[20], c = 'A';
	printf("Enter the code : ");
	scanf("%s", a);
	while (a[i] != '\0') {
		n = n + 1;
		i = i + 1;
	}
	for (j = 0; j < n ; j++) {
		for (i = 0; i < n; i++) {
			if (a[i] == '*' || a[i] == '/') {
				d = i - 1;
				while (a[d] == ' ') {
					d = d - 1;
				}
				printf("%c=%c%c%c\n", c, a[d], a[i], a[i + 1]);
				a[d] = c;
				a[i] = ' ';
				a[i + 1] = ' ';
				c = c + 1;
				continue;
			}
		}
	}
	for (j = 0; j < n ; j++) {
		for (i = 0; i < n; i++) {
			if (a[i] == '+' || a[i] == '-') {
				d = i - 1;
				while (a[d] == ' ') {
					d = d - 1;
				}
				printf("%c=%c%c%c\n", c, a[d], a[i], a[i + 1]);
				a[d] = c;
				a[i] = ' ';
				a[i + 1] = ' ';
				c = c + 1;
				continue;
			}
		}
	}
}
