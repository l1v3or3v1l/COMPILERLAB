#include <stdio.h>
#include <string.h>

char result[20][20], copy[3], states[20][20];

void add_state(char a[3], int i) {
    strcpy(result[i], a);
}

void display(int n) {
    int k = 0;
    printf("Epsilon closure of %s = { ", copy);
    while (k < n) {
        printf(" %s", result[k]);
        k++;
    }
    printf(" } \n");
}

int main() {
    FILE *INPUT;
    INPUT = fopen("input.dat", "r");
    int n, i, k, end = 0;
    char state1[3], input[3], state2[3], state[3];
    printf("Enter no of states : ");
    scanf("%d", &n);
    printf("Enter the states : \n");
    for (k = 0; k < n; k++) {
        scanf("%s", states[k]);
    }
    for (k = 0; k < n; k++) {
        i = 0;
        strcpy(state, states[k]);
        strcpy(copy, state);
        add_state(state, i++);
        while (end != EOF) {
            end = fscanf(INPUT, "%s%s%s", state1, input, state2);
            if (strcmp(state, state1) == 0 && strcmp(input, "e") == 0) {
                      add_state(state2, i++);
                      strcpy(state, state2);
            }
        }
        display(i);
        rewind(INPUT);
    }
}
