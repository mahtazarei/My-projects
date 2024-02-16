#include <stdio.h>
#include <stdlib.h>
#include <sring.h>



int main()
{
int;
   struct student {
    char name[20];
    char suename[20];
    int num_shenasname;
    char birth_date[10];
    char shahr sokoonat[30];
    float mean;
    char sex[10];
    char paziresh[15];
    char majar[25];
    char father name[15];
    int telephon_num;
    int sellphone_num;
    };
   struct lesson{
    char lesson name[20];
    int vahed;
    char pishniaz[20];
    char date of lesson starting[10];
    char ostad name ,surname[30];
    char emtehan date[10];
    int classnumber;
    };
   struct clas{
    int classnumber;
    char classplace[100];
    char classproperty[200];
    };
   struct ostad{
    char ostad name[20];
    char ostad surname[20];
    int ostad num_shenasname[10];
    char ostad birth_date[10];
    char ostad shahr skoonat[20];
    char sex[10];
    char ostad_paziresh[25];
    char ostad madrak[40];


    };
    struct node_student {
        struct student data;
        struct node_student *next;
    }*head_student= NULL;
    struct node_lesson {
        struct lesson data;
        struct node_lesson *next;
    }*head_lesson= NULL;
    struct node_clas {
        struct clas data;
        struct node_clas *next;
    }*head_clas= NULL;
    struct node_ostad {
        struct ostad data;
        struct node_proff *next;
    }*head1_proff= NULL;

    ////////////////////////////////////////

    int ftolist_student(){
    int i=0 , j=0;
    file *x;
    x= fopen("student.txt" , "a+b");
    struct student k;

    head_student=()

    };



{
    puts("1-students");
    puts("\n");
    puts("2-edari");
    puts("\n");
    puts("3-asatid");

}


}


