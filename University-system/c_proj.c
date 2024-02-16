#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int ftolist_student();
int ftolist_lesson();
int ftolist_class();
int ftolist_master();
int ftolist_term();
int add_st();
int add_les();
int add_cl();
int add_ms();
int create_t();
int Sst();
int Sma();

enum gender{male,female};
struct student{
    char name [20];
    char fname [20];
    char id [10];
    char number [10];
    char date_of_birth [10];
    char address [50];
    char ave [10];
    char gender [10];
    char type_of_acceptence [20];
    char field [20];
    char father_name [20];
    char phon_no [11];
    char cell_phon_no [11];
    struct node_lesson *takencourse_head;
    int number_of_courses;
    };
    struct lesson{
        char name [20];
        char unit [16];
        char code [15];
        char prerequist [20];
        char date [10];
        char nclass [15];
        char master [20];
        char ex_date [10];
        char hour[5];
       };
       struct clas{
        char no [10];
        char location [15];
        char extra_facility [40];
       };
       struct master{
        char name [20];
        char fname [20];
        char id [10];
        char code [15];
        char presentation_lessons [50];
        char date_of_birth [10];
        char address [50];
        enum gender G;
        char type_of_acceptence [20];
        char field [20];
        char father_name [20];
        char phon_no [11];
        char cell_phon_no [11];
        char type_of_field [20];
        char university [20];
        char ave [10];
        char year [10];
        struct node_lesson *taken_course;
       };
       struct term{
        char date [10];
        char situation [30];
        char lesson [30];
       };
       //////////////////////////////////////////////////////////////////////////////
       struct node_student{
       struct student data;
       struct node_student *next;
       }*head_student = NULL;

       struct node_lesson{
       struct lesson data;
       struct node_lesson *next;
       }*head_lesson = NULL ;

       struct node_class{
       struct clas data;
       struct node_class *next;
       }*head_class = NULL ;

       struct node_master{
       struct master data;
       struct node_master *next;
       }*head_master = NULL ;

         struct node_term{
       struct term data;
       struct node_term *next;
       }*head_term = NULL ;

////////////////////////////////////////////////////////////////
 int ftolist_student() {
        int i=0;
        int j=0;
        FILE *x;
        x=fopen("student.txt","a+b");
        struct student k;
        struct node_student *p;
        head_student=(struct node_student *)malloc(sizeof(struct node_student));
        p=head_student;
        while(!feof(x)) {
            fread(&k,sizeof(k),1,x);
            i++;
        }
        rewind(x);
        fread(&k,sizeof(k),1,x);
        p->data=k;
        p->next=NULL;
        for(j=0; j<i-2; j++) {
            fread(&k,sizeof(k),1,x);
            struct node_student *q=(struct node_student *)malloc(sizeof(struct node_student));
            q->data=k;
            q->next=NULL;
            p->next=q;
            p=q;
        }
        /*p = head_student;
        int kk = 0;
        for(kk=0; kk<i-1; kk++)
        {
            printf("%s    %s     %s\n",p->data.name,p->data.fname, p->data.id);
            p = p->next;
        }*/
        fclose(x);
        return head_student;
        getch();
     }
 /////////////////////////////////////////////////////////////////////////////////////////////
     int ftolist_lesson() {
        int i=0;
        int j=0;
        FILE *x;
        x=fopen("lesson.txt","a+b");
        struct lesson k;
        struct node_lesson *p;
        head_lesson=(struct node_lesson *)malloc(sizeof(struct node_lesson));
        p=head_lesson;
        while(!feof(x)) {
            fread(&k,sizeof(k),1,x);
            i++;
        }
        rewind(x);
        fread(&k,sizeof(k),1,x);
        p->data=k;
        p->next=NULL;
        for(j=0; j<i-2; j++) {
            fread(&k,sizeof(k),1,x);
            struct node_lesson *q=(struct node_lesson *)malloc(sizeof(struct node_lesson));
            q->data=k;
            q->next=NULL;
            p->next=q;
            p=q;
        }
        fclose(x);
        return head_lesson;
        getch();
     }
///////////////////////////////////////////////////////////////////////////////////////////////////
     int ftolist_class() {
        int i=0;
        int j=0;
        FILE *x;
        x=fopen("class.txt","a+b");
        struct clas k;
        struct node_class *p;
        head_class=(struct node_class *)malloc(sizeof(struct node_class));
        p=head_class;
        while(!feof(x)) {
            fread(&k,sizeof(k),1,x);
            i++;
        }
        rewind(x);
        fread(&k,sizeof(k),1,x);
        p->data=k;
        p->next=NULL;
        for(j=0; j<i-2; j++) {
            fread(&k,sizeof(k),1,x);
            struct node_class *q=(struct node_class *)malloc(sizeof(struct node_class));
            q->data=k;
            q->next=NULL;
            p->next=q;
            p=q;
        }
        fclose(x);
        return head_class;
        getch();
     }
     ///////////////////////////////////////////////////////////////////////////////////////////
        int ftolist_master() {
        int i=0;
        int j=0;
        FILE *x;
        x=fopen("master.txt","a+b");
        struct master k;
        struct node_master *p;
        head_master=(struct node_master *)malloc(sizeof(struct node_master));
        p=head_master;
        while(!feof(x)) {
            fread(&k,sizeof(k),1,x);
            i++;
        }
        rewind(x);
        fread(&k,sizeof(k),1,x);
        p->data=k;
        p->next=NULL;
        for(j=0; j<i-2; j++) {
            fread(&k,sizeof(k),1,x);
            struct node_master *q=(struct node_master *)malloc(sizeof(struct node_master));
            q->data=k;
            q->next=NULL;
            p->next=q;
            p=q;
        }
        fclose(x);
        return head_master;
        getch();
    }
    /////////////////////////////////////////////////////////////////
        int ftolist_term() {
        int i=0;
        int j=0;
        FILE *x;
        x=fopen("term.txt","a+b");
        struct term k;
        struct node_term *p;
        head_term=(struct node_term *)malloc(sizeof(struct node_term));
        p=head_term;
        while(!feof(x)) {
            fread(&k,sizeof(k),1,x);
            i++;
        }
        rewind(x);
        fread(&k,sizeof(k),1,x);
        p->data=k;
        p->next=NULL;
        for(j=0; j<i-2; j++) {
            fread(&k,sizeof(k),1,x);
            struct node_term *q=(struct node_term *)malloc(sizeof(struct node_term));
            q->data=k;
            q->next=NULL;
            p->next=q;
            p=q;
        }
        fclose(x);
        return head_term;
        getch();
    }


    ///////////////////////////////////////////////////////////////////////////////////////
    int check_status(struct student t)
    {
        if(strcmp(t.type_of_acceptence,"A")==0)
            return 24;
        if(strcmp(t.type_of_acceptence,"failed")==0)
            return 14;
        if(strcmp(t.type_of_acceptence,"usual")==0)
            return 20;
    }
    int check_time(struct node_lesson *p, struct lesson t, int num)
    {
        int i = 0;
        for(i=0; i<=num; i++)
        {
            if(p!=NULL)
                if(strcmp(p->data.date,t.date )==0)
                    if(strcmp(p->data.hour , t.hour )==0)
                        return 1; // 1 نشانده ی تداخل دروس است
            if(p!= NULL)
                p = p->next;
        }
        return 0; // 0 نشاندهنده ی تداخل نداشتن دروس است
    }
    struct lesson search_lesson(char t[15])
    {
        struct node_lesson *n=ftolist_lesson();
        while(n->next != NULL)
        {
            if(strcmp(n->data.code,t) == 0)
                return n->data;
            n = n->next;
        }
    }
    void add_course(struct student *t, char r[15])
    {
        struct lesson temp ;
        temp = search_lesson(r);
        //if(t.takencourse_head== NULL) puts("sssss");
        if( check_time(t->takencourse_head , temp,t->number_of_courses) == 1 )
            puts("there is tadakhol");
        else
        {
            int num = 0;
            int num2 = t->number_of_courses;
            num = check_status(*t);
            struct  node_lesson *q = t->takencourse_head ;
            struct  node_lesson k;
            int i=0;
            for(i=0; i<num2; i++)
            {
                q = q->next;
            }
            if(num > num2-1 )
            {
                k.data = temp;
                k.next = NULL;
                q->next = &k;
            }
            t->number_of_courses ++ ;
         }

    }
    ///////////////////////////////////////////////////////////////////////////////////////
     int add_st(){
     char s[2];
     system("cls");
     struct student s1;
     gets(s);
     printf("please enter student name:");
     gets(s1.name);
     printf("please enter student last name:");
     gets(s1.fname);
     printf("please enter id of student:");
     gets(s1.id);
     printf("please date of birth:");
     gets(s1.date_of_birth);
     printf("please enter address of student:");
     gets(s1.address);
     printf("please enter average:");
     gets(s1.ave);
     printf("please enter gender of student:");
     gets(s1.gender);
     printf("please enter number of student:");
     gets(s1.number);
     printf("please enter type of acceptence:");
     gets(s1.type_of_acceptence);
     printf("please enter type of field:");
     gets(s1.field);
     printf("please enter father name:");
     gets(s1.father_name);
     printf("please enter phone number:");
     gets(s1.phon_no);
     printf("please enter cell phone number:");
     gets(s1.cell_phon_no);
     struct lesson temp;
     strcpy(temp.code,"0");
     strcpy(temp.date,"0");
     strcpy(temp.ex_date,"0");
     strcpy(temp.hour,"0");
     strcpy(temp.master,"0");
     strcpy(temp.name,"0");
     strcpy(temp.nclass,"0");
     strcpy(temp.prerequist,"0");
     strcpy(temp.unit,"0");
    /* strcpy(temp.code,"000000000000000");
     strcpy(temp.date,"0000000000");
     strcpy(temp.ex_date,"0000000000");
     strcpy(temp.hour,"00000");
     strcpy(temp.master,"00000000000000000000");
     strcpy(temp.name,"00000000000000000000");
     strcpy(temp.nclass,"000000000000000");
     strcpy(temp.prerequist,"00000000000000000000");
     strcpy(temp.unit,"0000000000000000");*/
     struct node_lesson temp2;
     temp2.data = temp;
     temp2.next = NULL;
     s1.takencourse_head = &temp2;
     s1.number_of_courses = 0;
     struct node_student *n=ftolist_student();
        int c=0;
        while(n!=NULL) {
            if(strcmp(s1.number,n->data.number)==0) {
                printf("*************************************************************************\n");
                printf("ERROR\n");
                printf("The student number is Duplicated, Please Try a New One\n");
                printf("*************************************************************************\n");
                c=1;
            }
            n=n->next;
        }
        if(c==0) {
            FILE * fp;
            fp=fopen("student.txt","a+b");
            fwrite(&s1,sizeof(s1),1,fp);
            fclose(fp);
            puts("Adding Done");
        }
        puts("Press Any key To Continue:");
        getch();
        return 0;
     }
     //////////////////////////////////////////////////////////////////////////
     int add_les(){
      char s[2];
      system("cls");
      struct lesson l1;
      gets(s);
      printf("please enter lesson name:");
      gets(l1.name);
      printf("please enter lesson code:");
      gets(l1.code);
      printf("please enter the units:");
      gets(l1.unit);
      printf("please enter name of the prerequist:");
      gets(l1.prerequist);
      printf("please enter the date that class will be start:");
      gets(l1.date);
      printf("please enter the name of the master:");
      gets(l1.master);
      printf("please enter the hour:");
      gets(l1.hour);
      printf("please enter the date of examination:");
      gets(l1.ex_date);
      struct node_lesson *n=ftolist_lesson();
        int c=0;
        while(n!=NULL) {
            if(strcmp(l1.code,n->data.code)==0) {
                printf("*************************************************************************\n");
                printf("ERROR\n");
                printf("The lesson Code is Duplicated, Please Try a New One\n");
                printf("*************************************************************************\n");
                c=1;
            }
            n=n->next;
        }
        if(c==0) {
      FILE *fp;
      fp=fopen("lesson.txt","a+b");
      fwrite(&l1,sizeof(l1),1,fp);
      fclose(fp);
      puts("Adding Done");
      puts("Press Any key To Continue");
      getch();
      return 0;
     }
     }
     ///////////////////////////////////////////////////////////////////
     int add_cl(){
     char s[2];
     system("cls");
     struct clas c1;
     gets(s);
     printf("please enter number of class:");
     gets(c1.no);
     printf("please enter location:");
     gets(c1.location);
     printf("please enter extra facilities:");
     gets(c1.extra_facility);
     FILE *fp;
      fp=fopen("class.txt","a+b");
      fwrite(&c1,sizeof(c1),1,fp);
      fclose(fp);
      puts("Adding Done");
      puts("Press Any key To Continue");
      getch();
    return 0;

     }
     ///////////////////////////////////////////////////////////////////////
    int add_ms(){
    char s[2];
    system("cls");
    struct master m1;
    gets(s);
    printf("please enter master name:");
    gets(m1.name);
    printf("please enter family of master:");
    gets(m1.fname);
    printf("please enter id:");
    gets(m1.id);
    printf("please enter code:");
    gets(m1.code);
    printf("please enter date of birth:");
    gets(m1.date_of_birth);
    printf("please enter address of master:");
    gets(m1.address);
    int f = 0;
    while(f==0)
    {
    printf("please enter gender of master(male or female):");
    char s2[10];
    gets(s2);
    if(strcmp(s2,"male")==0)
    {
        m1.G = male;
        f =1;
    }
    else if(strcmp(s2,"female")==0)
    {
        m1.G = female;
        f=1;
    }
    else puts("wrong gender , try again ");
    }
    printf("please enter type of acceptence:");
    gets(m1.type_of_acceptence);
    printf("please enter type of field:");
    gets(m1.field);
    printf("please enter father name:");
    gets(m1.father_name);
    printf("please enter phon number:");
    gets(m1.phon_no);
    printf("please enter cell phon number:");
    gets(m1.cell_phon_no);
    printf("please enter type of field:");
    gets(m1.type_of_field);
    printf("please enter name of the university that the master studied:");
    gets(m1.university);
    printf("please enter the average of university:");
    gets(m1.ave);
    printf("please enter the year of graduate:");
    gets(m1.year);
    struct node_master *n=ftolist_master();
      int c=0;
        while(n!=NULL)
        {
            if(strcmp(m1.code,n->data.code)==0)
             {
                printf("*************************************************************************\n");
                printf("ERROR\n");
                printf("The master Code is Duplicated, Please Try a New One\n");
                printf("*************************************************************************\n");
                c=1;
            }
            n=n->next;
        }
        if(c==0) {
            FILE * fp;
            fp=fopen("master.txt","a+b");
            fwrite(&m1,sizeof(m1),1,fp);
            fclose(fp);
            puts("Adding Done");
        }
        puts("Press Any key To Continue:");
        getch();
        return 0;
    }
    ///////////////////////////////////////////////////////////////
    void listtof_ms(struct node_master *head)
    {
        struct node_master *p = head;
        FILE * fp;
        fp=fopen("master.txt","w");
        while(p->next != NULL)
        {
            fwrite(&p->data,sizeof(p->data),1,fp);
            p = p->next;
        }
    }
    void listtof_st(struct node_student *head)
    {
        struct node_student *p = head;
        FILE * fp;
        fp=fopen("student.txt","w");
        while(p != NULL)
        {
            fwrite(&p->data,sizeof(p->data),1,fp);
            p = p->next;
        }
    }
    ///////////////////////////////////////////////////////////////
     int create_t(){
         char s[2];
      system("cls");
      struct term t1;
      gets(s);
      puts("please enter the date that term will be started:");
      gets(t1.date);
      puts("please enter term situation:");
      gets(t1.situation);
      puts("please the lessons for one term:");
      gets(t1.lesson);
      struct node_term *n=ftolist_term();
        int c=0;
        while(n!=NULL) {
            if(strcmp(t1.situation,n->data.situation)==0) {
                printf("*************************************************************************\n");
                printf("ERROR\n");
                printf("The term situation is Duplicated, Please Try a New One\n");
                printf("*************************************************************************\n");
                c=1;
            }
            n=n->next;
        }
        if(c==0) {
            FILE * fp;
            fp=fopen("term.txt","a+b");
            fwrite(&t1,sizeof(t1),1,fp);
            fclose(fp);
            puts("Adding Done");
        }
        puts("Press Any key To Continue");


        getch();
        return 0;
    }
     /////////////////////////////////////////////////////////////////////////////////
         int Sst() {
        int choice = 0;
        system("cls");
        char key[10];
        puts("1- Searching by student number");
        puts("2- Searching by date of birth");
        puts("3-searching by gender");
        puts("4-searchin by type of acceptence");
        puts("5-searching by field of study");
        printf("Enter your choice please: ");
        scanf("%d",&choice);
        switch(choice) {
        case 1: {
            system("cls");
            printf("Enter student number To Search: ");
            scanf("%s",&key);
            struct node_student *head2=ftolist_student();
            puts("*************************************************************************************************************");
            puts("Name        Family        s-number     b-date        gender         acceptence-type        field        ");
            puts("**********************************************************************************************************");
            while(head2!=NULL) {
                if(strcmp(key,head2->data.number)==0) {
                    printf("%s     %s        %s         %s          %s         %s         %s \n",head2->data.name,head2->data.fname,head2->data.number,head2->data.date_of_birth,head2->data.gender,head2->data.type_of_acceptence,head2->data.field);

                }
                head2=head2->next;
            }
            puts("*******************************************************************************************************************");
            puts("Press Any key To Continue:");
        }
        break;

        case 2: {
            system("cls");
            printf("Enter date of birth of student To Search: ");
            scanf("%s",&key);
            struct node_student *head2=ftolist_student();
            printf("***********************************************************************************************");
            printf("Name        Family         b-date        gender         acceptence-type        field       ");
            printf("***********************************************************************************************");
            while(head2!=NULL){
                if(strcmp(key,head2->data.date_of_birth)==0) {
                    printf("%s     %s         %s           %s          %s        %s  \n",head2->data.name,head2->data.fname,head2->data.date_of_birth,head2->data.gender,head2->data.type_of_acceptence,head2->data.field);
                }
                head2=head2->next;
            }
            printf("**********************************************************************************************");
            puts("Press Any key To Continue:");
        }
        break;

        case 3:{
            system("cls");
            printf("enter gender of student to search");
            scanf("%s",&key);
            struct node_student *head2=ftolist_student();
            printf("***********************************************************************************************************");
            printf("Name        Family        s-number     b-date        gender         acceptence-type        field       ");
            printf("*****************************************************************************************************************");
            while(head2!=NULL){
                if(strcmp(key,head2->data.gender)==0) {
                    printf("%s     %s        %s          %s           %s          %s        %s  \n",head2->data.name,head2->data.fname,head2->data.number,head2->data.date_of_birth,head2->data.gender,head2->data.type_of_acceptence,head2->data.field);
                }
                head2=head2->next;
            }
            printf("****************************************************************************************************************************");
            puts("Press Any key To Continue:");
        }
        break;

        case 4:{
        system("cls");
        printf("enter type of acceptence of student to search");
        scanf("%s",&key);
        struct node_student *head2=ftolist_student();
            printf("***********************************************************************************************************");
            printf("Name        Family        s-number     b-date        gender         acceptence-type        field       ");
            printf("*****************************************************************************************************************");
            while(head2!=NULL){
                if(strcmp(key,head2->data.type_of_acceptence)==0) {
                    printf("%s     %s        %s          %s           %s          %s        %s  \n",head2->data.name,head2->data.fname,head2->data.number,head2->data.date_of_birth,head2->data.gender,head2->data.type_of_acceptence,head2->data.field);
                }
                head2=head2->next;
            }
            printf("***********************************************************************************************************");
            puts("Press Any key To Continue:");
        }
        break;


        case 5:{
        system("cls");
        printf("enter students field to search");
        scanf("%s",&key);
         struct node_student *head2=ftolist_student();
            printf("***********************************************************************************************************");
            printf("Name        Family        s-number     b-date        gender         acceptence-type        field       ");
            printf("*****************************************************************************************************************");
            while(head2!=NULL){
                if(strcmp(key,head2->data.field)==0) {
                    printf("%s     %s        %s          %s           %s          %s        %s  \n",head2->data.name,head2->data.fname,head2->data.number,head2->data.date_of_birth,head2->data.gender,head2->data.type_of_acceptence,head2->data.field);
                }
                head2=head2->next;
            }
            printf("***********************************************************************************************************");
            puts("Press Any key To Continue:");
        }
        break;
        }
        getch();
        }
    ////////////////////////////////////////////////////////////////////////////////////
        int Sma() {
            int choice = 0 ;
        system("cls");
        char key[10];
        puts("1- Searching by master code");
        puts("2-searching by gender");
        puts("3-searching by field of study");
        puts("4-searching by peresentation lessons");
        printf("Enter your choice please: ");
        scanf("%d",&choice);
        switch(choice) {
        case 1: {
            system("cls");
            printf("Enter master code To Search: ");
            scanf("%s",&key);
            struct node_master *head=ftolist_master();
            printf("*************************************************************************************************************");
            printf("Name        Family       code    b-date        gender            field       presentation lessons ");
            printf("**********************************************************************************************************");
            while(head!=NULL) {
                if(strcmp(key,head->data.code)==0) {
                    printf("%s     %s        %s          %s" ,head->data.name,head->data.fname,head->data.code,head->data.date_of_birth);
                    if(head->data.G =="male")
                        printf("male");
                    else if (head->data.G == "female")
                        printf("female");
                    printf ("%s       %s \n",head->data.field,head->data.presentation_lessons);
                }
                head=head->next;
            }
            printf("*******************************************************************************************************************");
            puts("Press Any key To Continue:");
        }
        break;

        case 2: {
            system("cls");
            printf("Enter gender of master To Search: ");
            scanf("%s",&key);
            struct node_master *head=ftolist_master();
            printf("***********************************************************************************************************");
            printf("Name        Family       code    b-date        gender            field       presentation lessons      ");
            printf("*****************************************************************************************************************");
            while(head!=NULL){
                //if(strcmp(key,head->data.gender)==0)
                 {
                    //printf("%s     %s        %s          %s           %s          %s        %s  \n",head->data.name,head->data.fname,head->data.code,head->data.date_of_birth,head->data.gender,head->data.field,head->data.presentation_lessons);
                }
                head=head->next;
            }
            printf("***********************************************************************************************************************");
            puts("Press Any key To Continue:");
        }
        break;

        case 3:{
            system("cls");
            printf("enter gender of master to search");
            scanf("%s",&key);
            struct node_master *head=ftolist_master();
            printf("***********************************************************************************************************");
            printf("Name        Family       code    b-date        gender            field       presentation lessons      ");
            printf("*****************************************************************************************************************");
            while(head!=NULL){
               // if(strcmp(key,head->data.gender)==0)
               {
                    //printf("%s     %s        %s          %s           %s          %s        %s  \n",head->data.name,head->data.fname,head->data.code,head->data.date_of_birth,head->data.gender,head->data.field,head->data.presentation_lessons);
                }
                head=head->next;
            }
            printf("****************************************************************************************************************************");
            puts("Press Any key To Continue:");
        }
        break;


        case 4:{
        system("cls");
        printf("enter students field to search");
        scanf("%s",&key);
         struct node_master *head=ftolist_master();
            printf("***********************************************************************************************************");
            printf("Name        Family       code    b-date        gender            field       presentation lessons        ");
            printf("*****************************************************************************************************************");
            while(head!=NULL){
                if(strcmp(key,head->data.field)==0) {
                    //printf("%s     %s        %s          %s           %s          %s        %s  \n",head->data.name,head->data.fname,head->data.code,head->data.date_of_birth,head->data.gender,head->data.field,head->data.presentation_lessons);
                }
                head=head->next;
            }
            printf("***********************************************************************************************************");
            puts("Press Any key To Continue:");
        }
        break;
        }
        getch();
        }
/////////////////////////////////////////////////////////////////
int main()
{  int choice,choice1,choice2;
char chABCD[5] = "abcd";
    char s[2];

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
       while(1){
        char key1[10];
        char key2[10];
        system("cls");
        puts("1-official \n2-student \n3-master\n");
        printf("please select your choice:");
        scanf("%d",&choice);
        system("cls");
        switch(choice)
        {case 1 :
               puts("1-enter master \n2-enter lessons \n3-enter student\n ");
               puts("4-enter class \n5-create term \n6-search \n7-back\n");
               printf("please enter your choice:");
               scanf("%d",&choice1);
               system("cls");
               switch(choice1)
               {
                case 1 :
                   add_ms();
                 break;

                case 2 :
                   add_les();
                 break;

                case 3 :
                add_st();
                 break;

                case 4 :
                add_cl();
                break;

                case 5 :
                create_t();
                break;

                case 6 :
                    puts("1-search master 2-search student");
                    printf("please enter your choice:");
                    scanf("%d",&choice2);
                    switch(choice2)
                    {
                    case 1 :
                        Sma();
                        break;

                    case 2 :
                        Sst();
                        break;
                    }
                  case 7:
                     break;
               }
               break;
          case 2:{
                system("cls");
                puts("enter your name:");/////به نظر من این جا بهتره یه منو تعریف بشه که گزینه های نمایش رو نشونمون بده
                scanf("%s",&key1);
                puts("enter your id:");
                scanf("%s",&key2);
                system("cls");
                struct node_student *head2=ftolist_student();
                struct node_student *p = head2;
                int r = 0;
                while( r!=1 || p != NULL )
                {
                    if(strcmp(key1,p->data.name)==0) {
                        if(strcmp(key2,p->data.id)==0){
                            r = 1;
                            printf("Hi %s ! \n",p->data.name);
                            puts("1.Add or Delete lesson  2.Choose lesson  3.Schedule  4.Marks report 5.show list of lessons");
                            printf("please enter your choice:");
                            scanf("%d", &choice1);
                            switch(choice1){
                                case 1:
                                    break;
                                case 2:
                                   {
                                    puts("Enter course code :");
                                    char temp[15];
                                    gets(temp);
                                    gets(temp);
                                    add_course(&p->data,temp);
                                    listtof_st(head2);
                                    puts("adding done, lessons are : \n");
                                    struct node_lesson* u ;
                                    u = p->data.takencourse_head->next;
                                    int i=0;
                                    printf("\n\nname      code     day\n");
                                    printf("%d",p->data.number_of_courses);
                                    for(i=0; i< p->data.number_of_courses; i++)
                                    {
                                        printf("%s    %s     %s\n",u->data.code, u->data.hour, u->data.name);
                                        u = u->next;
                                    }
                                   }
                                    break;
                                case 3:
                                    {
                                        struct node_lesson* u ;
                                        u = p->data.takencourse_head->next;
                                        printf("\n\nname      code     day\n");
                                        while(u != NULL)
                                        {
                                            printf("%s    %s     %s\n",u->data.code , u->data.hour, u->data.name);
                                            u = u->next;
                                        }
                                    }
                                    break;
                                case 4:
                                    break;
                                case 5:
                                    {
                                        struct node_lesson* u = ftolist_lesson();
                                        printf("\n\nname      code     day\n");
                                        while(u != NULL)
                                        {
                                            printf("%s      %s      %s\n", u->data.name,u->data.code , u->data.date);
                                            u = u->next;
                                        }
                                    }
                                    break;

                            }
                            getch();
                        }
                        }
                        if(r!=1 && p!= NULL)
                            p = p->next;
                }
                if(r==0){
                    puts("invalid name or id!");
                    puts("press any key to continue...");
                    getch();
                }
                break;
            };
            case 3:{
                system("cls");
                puts("enter your name:");
                scanf("%s",&key1);
                puts("enter your id:");
                scanf("%s",&key2);
                system("cls");
                struct node_master *head=ftolist_master();
                head=head->next;
                    if(strcmp(key1,head->data.name)==0) {
                        if(strcmp(key2,head->data.id)==0){
                            printf("Hi %s ! \n",head->data.name);
                            puts("1.Enter lesson  2.Enter marks  3.Objections  4.Schedule");
                            printf("please enter your choice:");
                            switch(choice1){
                                case 1:
                                    break;
                                case 2:
                                    break;
                                case 3:
                                    break;
                                case 4:
                                    break;

                            }
                            getch();
                        }
                        else{
                            puts("invalid name or id!");
                            puts("press any key to continue...");
                            getch();
                        }
                    }

                else{
                        puts("invalid name or id!");
                        puts("press any key to continue...");
                        getch();
                }
                break;
            };
        }
       }
       return 0;
}








