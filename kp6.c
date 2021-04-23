#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char surname[31];
    char initials[3];
    char sex[7];
    int schoolNum;
    char Medal;
    int math, phys, rus;
    char Writing;
} Student;

int main(int argc, char* argv[]){
    char *filename;
    
    
    filename = "test1.txt";
    
    const int count = 30;
    
    int a[count];
    int m = 0;
    
    
    FILE *file = fopen(filename, "r");

    Student *students = (Student*)calloc(count, sizeof(Student));
    Student *result = (Student*)calloc(count, sizeof(Student));
    int i = 0, ires = 0;
    while(!feof(file)){
        Student s;
        fscanf(file, "%s %2s %s %d %c %d %d %d %c", s.surname, s.initials, s.sex, &s.schoolNum,
               &s.Medal, &s.math, &s.phys, &s.rus, &s.Writing);
        students[i++] = s;
        a[m] = s.math + s.phys + s.rus;
        m++; 
    }
    
    int y, z;
    for(y = 0 ; y < count - 1; y++) { 
       for(z = 0 ; z < count - y - 1 ; z++) {  
           if(a[z] > a[z+1]) {           
              int tmp = a[z];
              a[z] = a[z+1] ;
              a[z+1] = tmp; 
           }
        }
    }
    
    int p;
    printf("Enter number of places\n>>> ");
    scanf("%d", &p);
    int proh2 = a[count - p] / 2;
    printf("semi-bore bal = %d\n", proh2);

    printf("--------------------------------------------------------");
    printf("|Surname     |In|Sex|School|Medal|Math|Phys|Rus|Writing|");
    printf("--------------------------------------------------------");

    for (int j = 0; j < count; ++j) {
        Student s = students[j];
        if(s.math + s.phys + s.rus >= proh2){
            printf("|%12s|%2s|%6s|%6d|%2c|%4d|%4d|%3d|%7c|\n", s.surname, s.initials, s.sex,
                   s.schoolNum, s.Medal, s.math, s.phys, s.rus, s.Writing);
            result[ires++] = s;
            
        }
    }

    if(ires == 0){
        printf("|                       NOT FOUND                        |");
    }

    printf("--------------------------------------------------------");
    
    
    
    
    
    


    fclose(file);
}
