#include <stdio.h>
#include <string.h>

typedef struct{
    char name[6];
    int year, month, day;
}Person;

int main() {
    printf("Hellow World!\n");
    int n, validCount = 0;
    int min =-1, max = -1;
    char birthday[11], name[6];
    scanf("%d", &n);
    
    Person People[2];
    
    for (int i=0; i<n; i++) {
        scanf("%s %s", name, birthday);
        int year = (birthday[0]-48)*1000 + (birthday[1]-48)*100 + (birthday[2]-48)*10 + (birthday[3]-48);
        int month = (birthday[5]-48)*10 + birthday[6]-48;
        int day = (birthday[8]-48)*10 + birthday[9]-48;
        if (!((year>2014 || (year==2014&&month>9) || (year==2014&&month==9&&day>6)) || (year<1814 || (year==1814&&month<9) || (year==1814&&month==9&&day<6)))) {
            validCount++;
            if (min==-1) {
                min = i;
                max = i;
                sprintf(People[0].name, "%s", name);
                People[0].year = year;
                People[0].month = month;
                People[0].day = day;
                sprintf(People[1].name, "%s", name);
                People[1].year = year;
                People[1].month = month;
                People[1].day = day;
            } else {
                if (year<People[0].year || (year==People[0].year&&month<People[0].month) || (year==People[0].year&&month==People[0].month&&day<People[0].day)) {
                    sprintf(People[0].name, "%s", name);
                    People[0].year = year;
                    People[0].month = month;
                    People[0].day = day;
                } else if (year>People[1].year || (year==People[1].year&&month>People[1].month) || (year==People[1].year&&month==People[1].month&&day>People[1].day)) {
                    sprintf(People[1].name, "%s", name);
                    People[1].year = year;
                    People[1].month = month;
                    People[1].day = day;
                }
            }
        }
    }
    
    if (validCount == 0) {
        printf("0");
        return 0;
    }
    printf("%d %s %s", validCount, People[0].name, People[1].name);
    
    return 0;
}


