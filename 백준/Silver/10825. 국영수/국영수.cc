#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

struct str{
    char name[20];
    int kor;
    int eng;
    int math;
};

str student[100001];

bool comp(const str &a,const str &b) {
    if(a.kor != b.kor)
    return a.kor > b.kor;
    if(a.eng != b.eng)
    return a.eng < b.eng;
    if(a.math != b.math)
    return a.math > b.math;
    if(strcmp(a.name, b.name) < 0)
    return true;
    else
    return false;
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s %d %d %d", student[i].name, &student[i].kor, &student[i].eng, &student[i].math);
    }
    std::sort(student, student + n, comp);
    for(int i = 0; i < n; i++) {
        printf("%s\n", student[i].name);
    }
    

    return 0;
}