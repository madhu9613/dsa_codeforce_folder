#include <stdio.h>
#include <stdlib.h>

int main() {
    int n; // number of camels
    scanf("%d", &n);

    int* pos = (int*)malloc(n * sizeof(int));
    int* distance = (int*)malloc(n * sizeof(int));

    if (pos == NULL || distance == NULL) {
        printf("Memory allocation failed\n");
        return 1; 
    }

    for(int i = 0; i < n; i++) {
        scanf("%d %d", &pos[i], &distance[i]);
    }

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) { 
            if(pos[i] + distance[i] == pos[j] && pos[j] + distance[j] == pos[i]) {
                printf("YES\n");

                free(pos);
                free(distance);

                return 0; 
            }
        }
    }

    printf("NO\n");

    free(pos);
    free(distance);

    return 0;
}
