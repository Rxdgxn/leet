#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int lexicographic_sort(const char* a, const char* b) {
    if (strcmp(a, b) > 0) return 1;
    return 0;
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return !lexicographic_sort(a, b);
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    bool da[123] = {0}, db[123] = {0};
    int ta = 0, tb = 0;
    
    for (int i = 0; i < strlen(a); i++)
        if (!da[a[i]]) {
            da[a[i]] = 1;
            ta++;
        }
    for (int i = 0; i < strlen(b); i++)
        if (!db[b[i]]) {
            db[b[i]] = 1;
            tb++;
        }

    if (ta > tb) return 1;
    else if (ta < tb) return 0;
    return lexicographic_sort(a, b);
}

int sort_by_length(const char* a, const char* b) {
    if (strlen(a) > strlen(b)) return 1;
    else if (strlen(a) < strlen(b)) return 0;
    return lexicographic_sort(a, b);
}

void string_sort(char** arr, const int len, int (*cmp_func)(const char* a, const char* b)) {
    for (int i = 0; i < len - 1; i++)
        for (int j = i + 1; j < len; j++)
            if ((*cmp_func)(arr[i], arr[j])) {
                const char* aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
}


int main() {
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++) {
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}