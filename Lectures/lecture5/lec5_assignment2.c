#include <stdio.h>
#include <stdlib.h>

void class_init(int* class, int students);
int passed(int* class, int students);
int max_grade(int* class, int students);
int min_grade(int* class, int students);
float avg_grade(int* class, int students);

int main()
{
    int students = 10;
    int class1[students], class2[students], class3[students];
    int total_passed, total_failed, abs_max, abs_min;
    int max1, max2, max3;
    int min1, min2, min3;
    float total_avg;

    class_init(class1, students);
    class_init(class2, students);
    class_init(class3, students);

    total_passed = passed(class1, students) + passed(class2, students) + passed(class3, students);
    total_failed = 3 * students - total_passed;

    max1 = max_grade(class1, students);
    max2 = max_grade(class2, students);
    max3 = max_grade(class3, students);
    min1 = min_grade(class1, students);
    min2 = min_grade(class2, students);
    min3 = min_grade(class3, students);

    abs_max = max1 > max2 && max1 > max3 ? max1 : max2 > max3 ? max2 : max3;
    abs_min = min1 < min2 && min1 < min3 ? min1 : min2 < min3 ? min2 : min3;

    total_avg = (avg_grade(class1, students) + avg_grade(class2, students) + avg_grade(class3, students)) / 3;

    printf("Number of passed students: %d\n", total_passed);
    printf("Number of failed students: %d\n", total_failed);
    printf("Higest grade: %d\n", abs_max);
    printf("Lowest grade: %d\n", abs_min);
    printf("Average grade: %.2f\n", total_avg);

    return 0;
}

void class_init(int* class, int students)
{
    int i, random;
    for (i = 0; i < students; i++)
    {
        random = rand() % 80 + 20;
        class[i] = random;
    }
}

int passed(int* class, int students)
{
    int passed = 0, i;
    for (i = 0; i < students; i++)
    {
        if (class[i] > 49)
        {
            passed++;
        }
    }
    return passed;
}

int max_grade(int* class, int students)
{
    int maximum = class[0], i;
    for (i = 1; i < students; i++)
    {
        maximum = class[i] > maximum ? class[i] : maximum;
    }
    return maximum;
}

int min_grade(int* class, int students)
{
    int minimum = class[0], i;
    for (i = 1; i < students; i++)
    {
        minimum = class[i] > minimum ? minimum : class[i];
    }
    return minimum;
}

float avg_grade(int* class, int students)
{
    int sum = 0, i;
    for (i = 0; i < students; i++)
    {
        sum += class[i];
    }
    float avg = (float)sum / students;
    return avg;
}