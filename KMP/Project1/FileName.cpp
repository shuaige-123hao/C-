#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* StrStr(const char* txt, const char* pat);

int main()
{
    char m[1024], s[1024], * p;
    fgets(m, 1024, stdin);
    fgets(s, 1024, stdin);
    p = StrStr(m, s);
    if (p)
    {
        printf("Found at %d\n", (int)(p - m));
    }
    else
    {
        puts("Not found");
    }
    return 0;
}

int* getNext(const char* pat) {

    int* next = (int*)malloc(sizeof(int) * 1024);
    next[0] = 0;
    for (int i = 1; pat[i] != '\0'; i++) {
        int f = next[i - 1];
        while (f > 0 && pat[f] != pat[i]) {
            f = next[f - 1];
        }

        if (pat[f] == pat[i]) {
            next[i] = f + 1;
        }
    }
    return next;


}
char* StrStr(const char* txt, const char* pat) {
    int* next = getNext(pat);

    if (pat == NULL) {
        return NULL;
    }
    int i, j;
    i = j = 0;
    while (txt[i] != '\0' && pat[j] != '\0') {
        if (txt[i] == pat[j]) {
            i++;
            j++;
        }
        else {
            if (j == 0) {
                i++;
            }
            j = next[j - 1];
        }
        if (pat[j] == '\0') {
            char* f = (char*)(txt + (i - j));
            return f;
        }


    }
    return NULL;


}

