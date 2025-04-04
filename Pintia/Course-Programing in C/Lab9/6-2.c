#include <stdio.h>
#define MAXN 10

struct student{
    int num;
    char name[20];
    int score;
    char grade;
};

int set_grade( struct student *p, int n );

int main()
{   struct student stu[MAXN], *ptr;
    int n, i, count;
    
    ptr = stu;
    scanf("%d\n", &n);
    for(i = 0; i < n; i++){
       scanf("%d%s%d", &stu[i].num, stu[i].name, &stu[i].score);
    } 
   count = set_grade(ptr, n);
   printf("The count for failed (<60): %d\n", count);
   printf("The grades:\n"); 
   for(i = 0; i < n; i++)
       printf("%d %s %c\n", stu[i].num, stu[i].name, stu[i].grade);
    return 0;
}

int set_grade( struct student *p, int n ){
    int sum = 0;
    for(int i = 0; i < n; i++){
        char grade;
        int sc = p[i].score;
        if(sc >= 85 && sc <= 100){
            grade = 'A';
        }
        if(sc >= 70 && sc <= 84){
            grade = 'B';
        }
        if(sc >= 60 && sc <= 69){
            grade = 'C';
        }
        if(sc >= 0 && sc <= 59){
            grade = 'D';
            sum++;
        }
        p[i].grade = grade;
    }
    return sum;
}