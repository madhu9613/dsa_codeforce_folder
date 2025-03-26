#include <stdio.h>
#include <string.h>

int zeroindex(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return ch - 'A'; 
    } else if (ch >= 'a' && ch <= 'z') {
        return ch - 'a'; 
    }
    return -1; 
}

int main() {
    int n;
    scanf("%d", &n);
    char arr[101];
    int level[26] = {0};

    scanf("%s", arr);
    int len = strlen(arr);
    
    if (n < 26) {
        printf("NO\n");
    } else {
        for (int i = 0; i < len; i++) {
            int index = zeroindex(arr[i]);
            if (index >= 0) { 
                level[index] = 1; 
            }
        }

        int missingCount = 0;
        for (int i = 0; i < 26; i++) {
            if (level[i] == 0) {
                missingCount++; 
            }
        }
        
        if (missingCount == 0) {
            printf("YES\n"); 
        } else {
            printf("NO\n"); 
        }
    }
    
    return 0;
}
