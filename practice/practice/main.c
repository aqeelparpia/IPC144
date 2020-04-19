#include <stdio.h>

struct studentRec{
    int id;
    int sem;
    char name[31];
};


int saveRecord(FILE *,const struct studentRec *);
int loadRecord(FILE *, struct studentRec [], int*);
void displayRecords(const struct studentRec[],int );

int saveRecord(FILE *fp,const struct studentRec strec[]){
    int flag = 0;
    if (fp != NULL){
        fprintf(fp, "%d;%d;%30[]\n",&strec->id,&strec->sem,&strec->name);
        flag =1;
    }
    return flag;
}

int loadRecord(FILE *, struct studentRec [], int*);
