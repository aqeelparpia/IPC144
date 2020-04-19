
/*-------------------------------------------------
// Walkthrough Practice Question-3
-------------------------------------------------*/

#include<stdio.h>
#include<string.h>

struct StudentRecord {
    int id;
    char first[31];
    char last[31];
};

void somethingFunny(struct StudentRecord *rec, char ch)
{
    // Replace 1st character with new character (less one)
    rec->first[0] = ch-1;
}

void swapLastnames(struct StudentRecord *recs, int i1, int i2) 
{
    // Temporary placeholder for swapped value:
    char tmp[31] = { '\0' };
    
    // Swap lastnames:
    strcpy(tmp, recs[i1].last);
    strcpy(recs[i1].last, recs[i2].last);
    strcpy(recs[i2].last, tmp);

    // Alter data a little more:
    somethingFunny(&recs[i1], recs[i2].last[0]);
}

int main(void)
{
    struct StudentRecord student[3] = {
            { 1, "Silly", "Sally" },
            { 2, "Happy", "Henry" },
            { 3, "Grumpy", "Guss" } };

    int i, j = 1;

    // Alter the data:
    for (i = 0; i < 3; i++, i > 1 ? j = 0 : j++) {
        swapLastnames(student, j, i);
    }

    // Display results:
    for (i = 0; i < 3; i++) {
        printf("%d: %-10s %-10s\n", student[i].id, student[i].first, student[i].last);
    }
    
    return 0;
}
