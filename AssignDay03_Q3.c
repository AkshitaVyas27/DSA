#include<stdio.h>
typedef struct{

    int roll;
    char name[32];
    int marks;

}st;
    void sort_stu(st t[10]){
        for(int i=0;i<8;i++){
            for(int j=0;j<10;j++){
                if(t[i].marks>t[j].marks){
                    st temp=t[i];
                    t[i]=t[j];
                    t[j]=temp;
                }
            }
        }
       
    }

int main(){
    st t[10];
    for(int i=0; i<10;i++){
printf("Enter the student information: 1.Roll number\n2.Name\nMarks");
scanf("%d%s%d", &t[i].roll, &t[i].name, &t[i].marks);
    }
   sort_stu(t);
     printf("\nSorted order:");
        for(int i=0;i<10;i++){
        printf("\nname:%s  roll number: %d  marks: %d", t[i].name, t[i].roll, t[i].marks);
        }
    return 0;
}