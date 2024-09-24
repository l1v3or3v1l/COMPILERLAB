#include<stdio.h>
#include<string.h>

void main() {
    char a[10], ch;
    printf("Enter the three address code:\n");
    fgets(a, 10, stdin);
    ch = a[3];
    switch (ch) {
    case '+':
        printf("\nMOV R0,%c", a[2]);
        printf("\nADD R0,%c", a[4]);
        printf("\nMOV %c,R0\n", a[0]);
        break;
    case '-':
        printf("\nMOV R0,%c", a[2]);
        printf("\nSUB R0,%c", a[4]);
        printf("\nMOV %c,R0\n", a[0]);
        break;
    case '*':
        printf("\nMOV R0,%c", a[2]);
        printf("\nMUL R0,%c", a[4]);
        printf("\nMOV %c,R0\n", a[0]);
        break;
    case '/':
        printf("\nMOV R0,%c", a[2]);
        printf("\nDIV R0,%c", a[4]);
        printf("\nMOV %c,R0\n", a[0]);
        break;
    default:
        printf("INVALID\n");
    }
}
