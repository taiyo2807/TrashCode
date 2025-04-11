#include <stdio.h>
#include <ctype.h>
#include <string.h>
char* ChuanHoaTen(char s[]){
    static char res[100] = "";
    res[0] = '\0';
    char* token = strtok(s," ");
    while(token != NULL){
        token[0] = toupper(token[0]);
        for(int i = 1; i < strlen(token); i++){
            token[i] = tolower(token[i]);
        }
        strcat(res, token);
        strcat(res, " ");
        token = strtok(NULL," ");
    }
    return res;
}
int main(){
    FILE* in = fopen("text1.txt", "r");
    FILE* out = fopen("text2.txt", "w");
    int n; 
    fscanf(in,"%d", &n);
    fprintf(out, "%d\n", n);
    fgetc(in);
    for(int i = 1; i <= 4; i++){
        char s[100];
        fgets(s, 99, in);
        if(s[strlen(s) - 1] == '\n'){
            s[strlen(s) - 1] = '\0';
        }
        char * result;
        result = ChuanHoaTen(s);
        fprintf(out, "%s\n", result);
    }
    fclose(in);
    fclose(out);

}