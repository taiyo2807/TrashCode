#include <stdio.h>
#include <string.h>
#include <ctype.h>

char * email(char s[]){
    static char res[1000] = "";
    res[0] = '\0';
    char a[100][100];
    int n = 0;
    char* token = strtok(s," ");
    while(token != NULL){
        int len = strlen(token);
        for(int i = 0; i < len; i++){
            token[i] = tolower(token[i]);
        }
        strcpy(a[n++], token);
        token = strtok(NULL, " ");
    }
    strcat(res, a[n - 1]);
    for(int i = 0; i < n - 1; i++){
        char ch[2] = {a[i][0], '\0'};
        strcat(res, ch);
    }
    strcat(res, "@28tech.com.vn");
    return res;
}
int main(){
    FILE* in = fopen("text1.txt", "r");
    if(in == NULL){
        printf("Cannot open file");
        return 1;
    }
    FILE* out = fopen("text2.txt", "w");
    int t;
    fscanf(in, "%d", &t);
    fgetc(in);
    while(t > 0){
        char s[100];
        fgets(s, 99, in);
        if(s[strlen(s) - 1] == '\n'){
            s[strlen(s) - 1] = '\0';
        }
        char* result;
        result = email(s);
        fprintf(out, "%s\n", result);
        t--;
    }
    fclose(in);
    fclose(out);
    return 0;
}