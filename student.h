    #include<stdlib.h>
    #include<malloc.h>
    #include<stdio.h>
    #include<string.h>
    #include<ctype.h>
    #include<windows.h>
    struct id {
    	char num[9];//8位学号
    	char password[17];//16位密码
    };
    struct Score {
    	int math;
    	int English;
    	int C_language;
    	float aver;
    };
    typedef struct Stduent {	//学生的信息结点
    	struct id denglu;
    	char name[20];
    //	char sex;//W M
    //	char major[15];//专业
    //	int year;//入学年份
    	int class;//班级
    	//char address[50];//地址
    //	char phone_number[12];//电话号码
    	struct Score score;//成绩 数学/语文/英语/C语言
    	struct Stduent* next;//这一行有点问题，要不要换？？？
    }Node,*linklist;
    
    void denglu();
    void menu_student(Node *p);
    void menu_manager();
    void password_student();
    void Create_Users();
    void Create_Managers();
    void Creat();
    void Input_login(Node *p);
    void Add_student();
    void Modify_student(int cho);//修改的英文
    void sort_num();
    void sort_name();
    void sort_math();
    void sort_English();
    void sort_C_language();
    void sort_aver();
    void Del_student(Node *p,FILE *fp);
    void Output();
    void Analysis_student();
    linklist link_list(int *n);
    void Print_one_student(Node *p);
    void Modify_student_1(Node *p,FILE *fp);
    void output_students(linklist phead);//输出全部的学生信息
    void password_managers_modify();
    void password_student_modify(Node *p);
    void student_aver_all();
    void student_grade_output();
    void student_grade_max_min();
    void degree_of_difficulty();
