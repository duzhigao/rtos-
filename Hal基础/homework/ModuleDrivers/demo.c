#include "stdio.h"
#include "string.h"
#include "driver_uart.h"

#define GET_ADDRESS(TYPE,MEM_VAR_NAME,MEM_VAR_ADDR) (MEM_VAR_ADDR-((TYPE)0x00).MEM_VAR_NAME)
enum person_type {
   PERSON_TYPE_STUDENT,
   PERSON_TYPE_WORKER,
} ;
struct person {
   int age;
   int sex;
   enum person_type type;
};
struct student {
   struct person parent;
   int grade;
};
struct worker {
   struct person parent;
   int department;
};
void demo(void){
   struct person p_s = {0,1,PERSON_TYPE_STUDENT};
   struct person p_w = {0,1,PERSON_TYPE_WORKER};
   struct student st = {p_s,4};
   struct worker w = {p_w,3};
   // printf("%d\n",&s);
   // printf("%d\n",&s.grade);
    printf("%d\n",&st.parent);
   // printf("%d",&p_s);
   struct person *p = &st.parent;
   printf("%d\n",&(((struct student *)0x00)->parent));
   //struct student *s_point = (struct student *)(p-&(((struct student *)0x00)->parent));

}