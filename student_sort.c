#include <stdio.h>
#include <stdlib.h>

struct Student
{
    int age, grade;
    char name[20];
};

/* Student 2개를 grade 기준 오름차순으로 비교 */
int comparator(const void *p, const void *q)
{
    int leftGrade  = ((struct Student *)p)->grade;
    int rightGrade = ((struct Student *)q)->grade;   /* <- 빈칸 정답 */
    return (leftGrade - rightGrade);
}

int main()
{
    struct Student students[4] = {
        {20, 3, "투기"}, {22, 1, "무진"}, {21, 4, "태영"}, {19, 2, "Anu"}
    };
    int studentCount = 4;
    int index;

    qsort(students, studentCount, sizeof(struct Student), comparator);

    for (index = 0; index < studentCount; index++)
        printf("%d %d %s\n", students[index].age, students[index].grade, students[index].name);
    return 0;
}
