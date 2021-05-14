#include "array2.h"

#include <time.h>
#include<string.h>



void prompt(){
    printf("> ");
}


void usage(){
    printf("Меню:");
    printf("\no <KEY_FILENAME> <DATA_FILENAME> - открыть нужные файлы");
    printf("\nr - обратная сортировка");
    printf("\ns - сортировка");
    printf("\nm - сортировка в случайном порядке");
    printf("\np вывод таблицы");
    printf("\nq - выход\n");
}

void parse_filenames(string keys, string data){
    char buf = (char)getchar();
    while(buf == ' ') buf = (char)getchar(); // skip whitespaces

    size_t i = 0, j = 0;

    bool is_key = true;

    while(buf != '\n' && buf != EOF){
        if(buf == ' '){
            is_key = false;
            buf = (char)getchar();
            continue;
        }
        if(is_key) keys[i++] = buf;
        else data[j++] = buf;

        buf = (char)getchar();
    }
}

int count_newlines(FILE *file){
    char buf = 'a';
    int cnt = 0;
    while(!feof(file) && buf != EOF){
        buf = (char)fgetc(file);
        if(buf == '\n') cnt++;
    }
    fseek(file, 0, SEEK_SET);
    return cnt;
}

array* read_arr(){
    string fnkeys = calloc(256, sizeof(char)), fndata = calloc(256, sizeof(char));
    parse_filenames(fnkeys, fndata);
    if(fnkeys == NULL || fndata == NULL){
        return NULL;
    }
    FILE* fkeys = fopen(fnkeys, "r"), *fdata = fopen(fndata, "r");
    free(fnkeys);free(fndata);
    if(fkeys == NULL || fdata == NULL)
        return NULL;

    int nlines1 = count_newlines(fkeys);
    int nlines2 = count_newlines(fdata);
    if(nlines1 != nlines2)
        return NULL;

    string* keys = calloc(nlines1, sizeof(string));
    string* data = calloc(nlines1, sizeof(string));

    for (size_t i = 0; i < nlines1; ++i) {
        string line = NULL, ptr = NULL;
        size_t size_line;

        if(getline(&line, &size_line, fkeys) == -1){
            return NULL;
        }
        keys[i] = line;
        

        if(getline(data + i, &size_line, fdata) == -1){
            return NULL;
        }
    }
    return array_create(keys, data, nlines1);
}

size_t bin_search(array* arr, char value){
    int l = -1, r = arr->len;
    int m;

    while(r-l > 1){
        m = (l+r) / 2;
        if(arr->array[m].key[0] > value){
            r = m;
        }else if(arr->array[m].key[0] < value){
            l = m;
        } else{
            l = m;
            break;
        }
    }
    return l;
}

int main(){
    srandom(time((NULL)));

    array *arr = NULL;
    bool sorted = false;

    char cmd;
    usage();
    while (true){
        prompt();
        cmd = (char)getchar();
        while(cmd == ' ' || cmd == '\n') cmd = (char)getchar(); // skip whitespaces

        if(cmd == 'q')break;
        if(cmd == 'h'){
            continue;
        }
        if(arr == NULL && cmd != 'o'){
            puts("введите файл");
            continue;
        }

        string sbuf, ssbuf;
        size_t ibuf;
        size_t index;
        usage();
        switch (cmd) {
            case 'o':
                arr = read_arr();
                sorted = false;
                if(arr == NULL){
                    puts("не корректные данные");
                }
                break;
            case 'p':
                getline(&sbuf, &ibuf, stdin);
                index = strtoul(sbuf, &ssbuf, 10);
                if(sbuf != ssbuf && index < arr->len){
                    printf("%s\n", arr->array[index].data);
                }else {
                    array_print(arr);
                }
                break;
            
            case 'f':
                array_free(arr);
                arr = NULL;
                sorted = false;
                break;
            case 'r':
                array_reverse(arr);
                sorted = false;
                break;
            case 's':
                array_quick_sort(arr);
                sorted = true;
                break;
            case 'm':
                array_shuffle(arr);
                sorted = false;
                break;
            default:
                usage();
                continue;
        }
    }

    if(arr != NULL)
        array_free(arr);

}

