    #include"student.h"
    //登陆端 初始密码 abcdef
    //学生端 初始密码 12345678
    //主函数
    int main(void)
    {
    	Creat();
    	denglu();
    	system("pause");
    	return 0;
    }
    //所有的文件创建都在这里了
    void Creat()
    {
    	Create_Managers();
    	Create_Users();//学生信息都在这里！
    }
    //创建用户文件
    void Create_Users()
    {
    	errno_t err;
    	FILE *fp;
    	err = fopen_s(&fp, "users.txt", "r+");
    	if (err!=0)//如果此文件不存在
    	{
    		err = fopen_s(&fp, "users.txt", "w+");
    		if (err != 0)
    		{
    			printf("无法建立文件！");
    		}
    	}
    	fclose(fp);
    }
    //创建管理员文件(就一个密码）
    void Create_Managers()
    {
    	char ch1;
    	char manager[7];
    	errno_t err;
    	FILE *fp;
    	err = fopen_s(&fp, "manager.txt", "r+");
    	if (err != 0)//如果此文件不存在
    	{
    		err = fopen_s(&fp, "manager.txt", "w+");
    		if (err != 0)
    		{
    			printf("无法建立文件！");
    		}
    	}
    	ch1 = getc(fp);
    	if (ch1 == EOF)
    	{
    		strcpy_s(manager,7,"abcdef");
    		fputs(manager, fp);
    	}
    	fclose(fp);
    }
    //添加学生 从管理员里面进入
    void Add_student()//删掉regist();
    {
    	Node *pa, *pb;//pa就是新结点！
    	char ch, chioce;
    	int p, math;
    	FILE *fp;
    	chioce = '1';
    	pa = (Node*)malloc(sizeof(Node));
    	pb = (Node*)malloc(sizeof(Node));
    	fp = fopen("users.txt", "r+");
    	fread(pb, sizeof(Node), 1, fp);		//读入一个结构体字符块到b
    	//一串非常长的关于 学号输入的 只能输入8个数字的代码！
    flag_Add_student_num_input:
    	system("cls");
    	printf("\n\n\t\t  请问您是否要继续输入！按0则停止输入，按1则继续输入！\n");
    	chioce = getche();
    	while (chioce == '1')
    	{
    		rewind(fp);
    		p = 0;
    		printf("\n\t\t  请输入新的的学号：");
    		while ((ch = getche()) != '\r')//判断是否是回车  
    		{
    			if (ch == 8)//backspace键的ascii码是8
    			{
    				putchar(' ');
    				putchar('\b');
    				if (p>0)//最多只能删到没有字符
    					p--;
    			}//删除键实现
    			if (!isdigit(ch))//判断是否是数字
    			{
    				if (ch != 8)
    				{
    					continue;
    				}
    			}
    			pa->denglu.num[p++] = ch;//保存学号
    		}
    		if (p != 8)
    		{
    			printf("\n\t\t  请输入8位有效数字！\n");
    			continue;//回到开始 输入学号的时候
    		}
    		pa->denglu.num[p] = 0;
    		while (1)
    		{
    			if (strcmp(pa->denglu.num, pb->denglu.num))//如果两串不相等
    			{
    				if (!feof(fp))//如果没到文件尾
    				{
    					fread(pb, sizeof(Node), 1, fp);
    				}
    				else
    				{
    					break;//出来到信息输入了
    				}
    			}
    			else//这是到了最后都没有出来的！
    			{
    				printf("\n\t\t  此用户名已存在！\n");
    				goto flag_Add_student_num_input;//回到一开始问要不要继续输入！
    			}
    		}
    		//进入信息输入环节！
    		strcpy(pa->denglu.password, "123456780");//初始密码 12345678！
    		pa->denglu.password[8] = '\0';
    		printf("\n\n\t\t  请输入学生姓名：");
    		scanf("%s", pa->name);
    /*
    		int pname=0;
    		char chname;
    		char name[20];
    */
    		printf("\n\t\t  请输入学生班级：");
    		scanf("%d", &pa->class);
    	flag_math:
    		printf("\n\t\t  请输入学生数学成绩：");
    		scanf("%d", &math);
    		if (math > 100 || math < 0)
    		{
    			printf("\n\t\t  成绩只能在100到0之间！\n");
    			Sleep(500);
    			goto flag_math;
    		}
    		pa->score.math = math;
    	flag_English:
    		printf("\n\t\t  请输入学生英语成绩：");
    		scanf("%d", &math);
    		if (math > 100 || math < 0)
    		{
    			printf("\n\t\t  成绩只能在100到0之间！\n");
    			Sleep(500);
    			goto flag_English;
    		}
    		pa->score.English = math;
    	flag_C:
    		printf("\n\t\t  请输入学生C语言成绩：");
    		scanf("%d", &math);
    		if (math > 100 || math < 0)
    		{
    			printf("\n\t\t  成绩只能在100到0之间！\n");
    			Sleep(500);
    			goto flag_C;
    		}
    		pa->score.C_language = math;
    		pa->score.aver = ((float)pa->score.C_language + (float)pa->score.English + (float)pa->score.math) / 3;
    		//信息输入结束！这里没有链表的操作
    		//进入文件操作
    		fp = fopen("users.txt", "r+");
    		while (!feof(fp))
    		{
    			fread(pb, sizeof(Node), 1, fp);
    		}
    		fwrite(pa, sizeof(Node), 1, fp);
    
    		//文件操作结束
    		printf("\t\t  请问您是否要继续输入！按0则停止输入，按1则继续输入！\n");
    		chioce = getche();
    		if (chioce == '0')
    		{
    			fclose(fp);
    		}
    		system("cls");
    	}
    	menu_manager();
    }
    //登录
    void denglu()//结束
    {
    	FILE *fp;
    	int p;
    	char denglu;
    	char manager[7], mana2[7], ch;
    beginning_dl:
    	system("cls");
    	printf("\t\t------------------------------------------------------------\n");
    	printf("\t\t|  |\n");
    	printf("\t\t| 登录界面 |\n");
    	printf("\t\t| 1.学生登录   |\n");
    	printf("\t\t| 2.管理登录   |\n");
    	printf("\t\t| 3.退出   |\n");
    	printf("\t\t|  |\n");
    	printf("\t\t------------------------------------------------------------\n");
    	denglu = 0;
    	denglu = getche();
    	if (denglu == '1')//这一步做完了
    	{
    		password_student();
    	}
    	if (denglu == '2')//没写完
    	{
    flag_registers_pwd:
    		p = 0;
    		printf("\t\t  请输入管理员密码（6位）：");
    		while ((ch = getch()) != '\r')//判断是否是回车
    		{
    			if (ch == 8)//backspace键的ascii码是8
    			{
    				putchar('\b');
    				putchar(' ');//？？？
    				putchar('\b');
    				if (p>0)//最多只能删到没有字符
    					p--;
    			}
    			if (!isdigit(ch) && !isalpha(ch))//判断是否是数字或字符
    			{
    				continue;
    			}
    			putchar('*');//在屏幕上打印星号
    
    			if (p > 5)
    			{
    				printf("\n\n\t\t  只能输入6位！稍后请重新输入！\n");
    				Sleep(500);
    				goto flag_registers_pwd;
    			}
    			manager[p++] = ch;//保存密码
    		}
    		manager[p] = 0;//结束字符串
    		fp = fopen("manager.txt", "r");
    		fread(mana2, 6, 1, fp);
    		mana2[6] = '\0';
    		if (strcmp(mana2, manager) == 0)
    		{
    			printf("\n\n\t\t  登录成功，即将进入管理原界面！\n");
    			Sleep(500);
    			menu_manager();
    		}
    		else
    		{
    			printf("\n\n\t\t  密码错误，即将回到登录界面！\n");
    			Sleep(500);
    			goto beginning_dl;
    		}
    	}
    	if (denglu == '3')//ok
    	{
    		exit(0);
    	}
    	else if (denglu != '1' && denglu != '2' && denglu != '3')
    	{
    		goto beginning_dl;
    	}
    }
    //密码输入
    void password_student()
    {
    	Node *pn;
    	int p,p1,i;
    	char ch,ch1, pwd[17],number[9];
    	pn = (Node*)malloc(sizeof(Node));
    flag_password_student:
    	p1 = 0;
    	printf("\n\t\t  请输入你的8位学号：");
    	while ((ch1 = getche()) != '\r')//判断是否是回车  
    	{
    		if (ch1 == 8)//backspace键的ascii码是8
    		{
    			putchar(' ');//？？？
    			putchar('\b');
    			if (p1>0)//最多只能删到没有字符
    				p1--;
    		}//删除键实现
    		if (!isdigit(ch1))//判断是否是数字
    		{
    			if (ch1 != 8)
    			{
    				goto flag_password_student;
    			}
    		}
    		//printf("%c", ch1);//回显学号
    		if (p1 > 7)
    		{
    			goto flag_password_student;
    		}
    		number[p1++] = ch1;//保存学号
    	}
    	number[p1] = 0;//结束字符串
    	if (p1 != 8)
    	{
    		printf("\n\t\t  请输入8位有效学号作为登录账号！\n\n");
    		Sleep(500);
    		goto flag_password_student;
    	}
    
    	strcpy_s(pn->denglu.num, 9, number);
    	i = 3;
    flag_password_pwd:
    	p = 0;
    	printf("\n\t\t  请输入你的密码（16位，由英文字母和数字组成）：");
    	while ((ch = getch()) != '\r')//判断是否是回车  
    	{
    		if (ch == 8)//backspace键的ascii码是8
    		{
    			putchar('\b');
    			putchar(' ');//？？？
    			putchar('\b');
    			if (p>0)//最多只能删到没有字符
    				p--;
    		}
    		if (!isdigit(ch) && !isalpha(ch))//判断是否是数字或字符 
    			continue;
    		if (p > 15)
    		{
    			printf("\n\t\t  最多输入16位密码！稍后请重新输入！\n");
    			Sleep(500);
    			goto flag_password_pwd;
    		}
    		putchar('*');//在屏幕上打印星号  
    		pwd[p++] = ch;//保存密码  
    	}
    	pwd[p] = 0;//结束字符串
    	strcpy_s(pn->denglu.password, strlen(pwd) + 1, pwd);
    	//这个时候就要进入到密码比对了！
    	Input_login(pn);
    }
    //学生的菜单界面
    void menu_student(Node *p)//没写完
    {
    	char i;
    flag_menu_student:
    	system("cls");
    	printf("\t\t------------------------------------------------------------\n");
    	printf("\t\t| 学生菜单界面 |\n");
    	printf("\t\t|  |\n");
    	printf("\t\t| 1.查询信息   |\n");
    	printf("\t\t| 2.修改密码   |\n");
    	printf("\t\t| 3.退出   |\n");
    	printf("\t\t|  |\n");
    	printf("\t\t------------------------------------------------------------\n");
    	i = getche();
    	if (i != '1' && i != '2' && i != '3')
    	{
    		goto flag_menu_student;
    	}
    	else if (i == '1')
    	{
    		Print_one_student(p);
    		printf("\t\t  按任何键回到学生菜单！\n");
    		getch();
    		menu_student(p);
    	}
    	else if (i == '2')
    	{
    		password_student_modify(p);
    	}
    	else if (i == '3')
    	{
    		denglu();
    	}
    }
    //管理员的菜单界面
    void menu_manager()
    {
    	char i;
    	system("cls");
    	printf("\t\t------------------------------------------------------------\n");
    	printf("\t\t| 管理原菜单界面   |\n");
    	printf("\t\t|  |\n");
    	printf("\t\t| 1.添加学生信息   |\n");
    	printf("\t\t| 2.修改学生信息   |\n");
    	printf("\t\t| 3.输出全部学生信息   |\n");
    	printf("\t\t| 4.查询学生信息   |\n");
    	printf("\t\t| 5.删除学生信息   |\n");
    	printf("\t\t| 6.修改密码   |\n");
    	printf("\t\t| 7.成绩分析   |\n");
    	printf("\t\t| 8.退出登录   |\n");
    	printf("\t\t|  |\n");
    	printf("\t\t------------------------------------------------------------\n");
    	i = getche();
    	switch (i)
    	{
    	case '1':Add_student(); break;
    	case '2':Modify_student(1); break;
    	case '3':Output(); break;
    	case '4':Modify_student(2); break;
    	case '5':Modify_student(3); break;
    	case '6':password_managers_modify(); break;
    	case '7':Analysis_student(); break;
    	case '8':denglu(); break;
    	default: menu_manager();
    	}
    }
    //学生登录的密码用户比对
    void Input_login(Node *p)
    {
    	Node *a;
    	FILE * fp;
    	a = (Node*)malloc(sizeof(Node));
    	fp = fopen("users.txt", "r");
    	fread(a, sizeof(Node), 1, fp);//读一个结构体大小的字符块给a
    	while (1)
    	{
    		if (strcmp(a->denglu.num, p->denglu.num) == 0)//如果有这个用户名
    		{
    			break;
    		}
    		else
    		{
    			if (!feof(fp))//如果文件没有读完
    			{
    				fread(a, sizeof(Node), 1, fp);
    			}
    			else
    			{
    				printf("\n\t\t  此用户名不存在！");
    				Sleep(500);
    				fclose(fp);
    				denglu();
    			}
    		}
    	}
    	if (strcmp(a->denglu.password, p->denglu.password) == 0)//密码对了
    	{
    		fclose(fp);
    		printf("\n\t\t  登录成功，欢迎使用！\n");
    		Sleep(500);
    		menu_student(a);
    	}
    	else
    	{
    		printf("\n\t\t  密码错误，登录失败！\n");
    		fclose(fp);
    		Sleep(500);
    		denglu();
    	}
    }
    //链表创建
    linklist link_list(int *n)
    {
    	FILE *fp;		//文件指针
    	Node * p,*pnew;	//链表结点
    	linklist phead;	//头结点的指针	
    	Node temp;
    	*n = 0;			//存链表个数
    	phead = (linklist)malloc(sizeof(Node));//给头指针空间
    	phead->next = NULL;//指向空
    	p = (Node *)malloc(sizeof(Node));//给遍历结点空间
    	p = phead;//让遍历结点从头节点开始遍历
    	fp = fopen("users.txt", "r");//打开文件
    	while (fread(&temp, sizeof(Node), 1, fp) != 0)//不用feof();
    	{
    		pnew = (Node*)malloc(sizeof(Node));//给新结点空间
    
    		strcpy(pnew->denglu.num, temp.denglu.num);
    		strcpy(pnew->denglu.password, temp.denglu.password);
    		strcpy(pnew->name, temp.name);
    		pnew->class = temp.class;
    		pnew->score.aver = temp.score.aver;
    		pnew->score.C_language = temp.score.C_language;
    		pnew->score.English = temp.score.English;
    		pnew->score.math = temp.score.math;
    
    		pnew->next = NULL;//新结点的NEXT指向空
    		p->next = pnew;//p指向Pnew
    		p = p->next;//p向后走一个
    		*n += 1;//这一句是 必须使用*n+=1,不能用*n++;(优先级的问题)
    	}
    	fclose(fp);//关闭文件
    	return phead;//返回值是头指针
    }
    //修改学生信息
    void Modify_student(int cho)
    {
    	Node *pa,*pb;
    	FILE *fp;
    
    	pa = (Node*)malloc(sizeof(Node));
    	pb = (Node*)malloc(sizeof(Node));
    	fp = fopen("users.txt", "r+");//打开文件！
    	printf("\t\t  请输入学生的学号：");
    	scanf("%s", pa->denglu.num);
    	fread(pb, sizeof(Node), 1, fp);
    	while (1)
    	{
    		if (strcmp(pa->denglu.num, pb->denglu.num))//如果两串不相等
    		{
    			if (!feof(fp))//如果没到文件尾
    			{
    				fread(pb, sizeof(Node), 1, fp);
    			}
    			else
    			{
    				printf("\t\t  该用户不存在！\n");
    				printf("\t\t  稍后将回到管理员菜单！\n");
    				Sleep(500);
    				menu_manager();
    			}
    		}
    		else//有这个用户 pb现在就是这个学生的链表结点了！
    		{
    			Print_one_student(pb);//没关fp
    			if (cho == 1)
    			{
    				Modify_student_1(pb, fp);
    			}
    			if (cho == 2)
    			{
    				printf("\t\t  按任意值回到管理员菜单！\n");
    				getch();
    			}
    			if (cho == 3)
    			{
    				Del_student(pb,fp);
    			}
    			printf("\t\t  稍后将回到管理员菜单！\n");
    			Sleep(1000);
    			menu_manager();
    			break;
    		}
    	}
    }
    //输出单人的信息（需要链表的指针）
    void Print_one_student(Node *p)
    {
    	printf("\t\t  学号为：%s的学生\n", p->denglu.num);
    	printf("\t\t  该学生的姓名为：%s\n", p->name);
    	printf("\t\t  该学生的班级为：%d\n", p->class);
    	printf("\t\t  该学生的数学成绩为：%d\n", p->score.math);
    	printf("\t\t  该学生的英语成绩为：%d\n", p->score.English);
    	printf("\t\t  该学生的C语言成绩为：%d\n", p->score.C_language);
    	printf("\t\t  该学生的平均成绩为：%.3f\n", p->score.aver);
    	printf("\n");
    }
    //修改单人的信息 
    void Modify_student_1(Node *p, FILE *fp)
    {
    	char i;
    	int change = 0;
    	system("cls");
    	Print_one_student(p);
    	fseek(fp, -sizeof(Node), SEEK_CUR);
    	printf("\t\t------------------------------------------------------------\n");
    	printf("\t\t|  |\n");
    	printf("\t\t| 请选择您要修改的个人信息！   |\n");
    	printf("\t\t| 1、姓名  |\n");
    	printf("\t\t| 2、班级  |\n");
    	printf("\t\t| 3、所有成绩  |\n");
    	printf("\t\t| 4、数学成绩  |\n");
    	printf("\t\t| 5、英语成绩  |\n");
    	printf("\t\t| 6、C语言成绩 |\n");
    	printf("\t\t| 7、退出修改  |\n");
    	printf("\t\t|  |\n");
    	printf("\t\t------------------------------------------------------------\n");
    	i = getche();
    	if (i == '1')
    	{
    		printf("\t\t  请输入该学生姓名：");
    		scanf("%s", p->name);
    		change = 1;
    	}
    	if (i == '2')
    	{
    		printf("\t\t  请输入该学生班级：");
    		scanf("%d", &p->class);
    		change = 1;
    	}
    	if (i == '3')
    	{
    		printf("\t\t  请输入该学生数学成绩：");
    		scanf("%d", &p->score.math);
    		printf("\t\t  请输入该学生英语成绩");
    		scanf("%d", &p->score.English);
    		printf("\t\t  请输入该学生C语言成绩");
    		scanf("%d", &p->score.C_language);
    		p->score.aver = ((float)p->score.C_language + (float)p->score.English + (float)p->score.math) / 3;
    		change = 1;
    	}
    	if (i == '4')
    	{
    		printf("\t\t  请输入该学生数学成绩：");
    		scanf("%d", &p->score.math);
    		p->score.aver = ((float)p->score.C_language + (float)p->score.English + (float)p->score.math) / 3;
    		change = 1;
    	}
    	if (i == '5')
    	{
    		printf("\t\t  请输入该学生英语成绩");
    		scanf("%d", &p->score.English);
    		p->score.aver = ((float)p->score.C_language + (float)p->score.English + (float)p->score.math) / 3;
    		change = 1;
    	}
    	if (i == '6')
    	{
    		printf("\t\t  请输入该学生C语言成绩");
    		scanf("%d", &p->score.C_language);
    		p->score.aver = ((float)p->score.C_language + (float)p->score.English + (float)p->score.math) / 3;
    		change = 1;
    	}
    	if (i == '7')
    	{
    		printf("\t\t  稍后将回到管理员菜单！\n");
    		fclose(fp);
    		Sleep(1000);
    		menu_manager();
    
    	}
    	if (change == 0)
    	{
    		Modify_student_1(p, fp);
    	}
    	fwrite(p, sizeof(Node), 1, fp);
    	fclose(fp);
    }
    //排序输出菜单
    void Output()
    {
    	//用 linklist phead;全局变量
    	char i;
    	int change = 1;
    	system("cls");
    	printf("\t\t------------------------------------------------------------\n");
    	printf("\t\t|  |\n");
    	printf("\t\t| 请选择您输出学生信息的顺序   |\n");
    	printf("\t\t| 1、学号  |\n");
    	printf("\t\t| 2、姓名  |\n");
    	printf("\t\t| 3、平均成绩  |\n");
    	printf("\t\t| 4、数学成绩  |\n");
    	printf("\t\t| 5、英语成绩  |\n");
    	printf("\t\t| 6、C语言成绩 |\n");
    	printf("\t\t| 7、退出输出  |\n");
    	printf("\t\t|  |\n");
    	printf("\t\t------------------------------------------------------------\n");
    	i = getche();
    	if (i == '1')
    	{
    		sort_num();
    		change = 0;
    	}
    	if (i == '2')
    	{
    		sort_name();
    		change = 0;
    	}
    	if (i == '3')
    	{
    		sort_aver();
    		change = 0;
    	}
    	if (i == '4')
    	{
    		sort_math();
    		change = 0;
    	}
    	if (i == '5')
    	{
    		sort_English();
    		change = 0;
    	}
    	if (i == '6')
    	{
    		sort_C_language();
    		change = 0;
    	}
    	if (i == '7')
    	{
    		change = 0;;
    		menu_manager();
    	}
    	if(change)
    	{
    		printf("\t\t  请输入正确的输入值！稍后请重新输入！\n");
    		Sleep(500);
    		Output();
    	}
    	printf("\t\t  这是全部的学生信息！\n");
    	printf("\t\t  按任意值返回管理员界面！\n");
    	getch();
    	menu_manager();
    }
    //按照学号排序且输出
    void sort_num()
    {
    	Node * p, *pre;
    	linklist phead;
    	int n, i, j;
    	p = (Node*)malloc(sizeof(Node));
    	pre = (Node*)malloc(sizeof(Node));
    	phead = (linklist)malloc(sizeof(Node));
    	phead = link_list(&n);					//把学生信息从链表里面读出来！
    	for (i = 0; i < n - 1; i++)	//排序
    	{
    		pre = phead;
    		p = pre->next;
    		for (j = 0; j < n - i - 1; j++)
    		{
    			if (strcmp(pre->next->denglu.num, p->next->denglu.num) > 0)
    			{
    				pre->next = p->next;
    				p->next = p->next->next;
    				pre->next->next = p;
    
    				pre = pre->next;		//p这个时候不动
    			}
    			else
    			{
    				pre = pre->next;
    				p = pre->next;
    			}
    		}
    	}
    	output_students(phead);
    }
    //按照姓名排序且输出
    void sort_name()
    {
    	Node * p, *pre;
    	linklist phead;
    	int n, i, j;
    	p = (Node*)malloc(sizeof(Node));
    	pre = (Node*)malloc(sizeof(Node));
    	phead = (linklist)malloc(sizeof(Node));
    	phead = link_list(&n);					//把学生信息从链表里面读出来！
    	for (i = 0; i < n - 1; i++)	//排序
    	{
    		pre = phead;
    		p = pre->next;
    		for (j = 0; j < n - i - 1; j++)
    		{
    			if (strcmp(pre->next->name, p->next->name) > 0)
    			{
    				pre->next = p->next;
    				p->next = p->next->next;
    				pre->next->next = p;
    
    				pre = pre->next;		//p这个时候不动
    			}
    			else
    			{
    				pre = pre->next;
    				p = pre->next;
    			}
    		}
    	}
    	output_students(phead);
    }
    //按照平均分排序
    void sort_aver()
    {
    	Node * p, *pre;
    	linklist phead;
    	int n, i, j;
    	p = (Node*)malloc(sizeof(Node));
    	pre = (Node*)malloc(sizeof(Node));
    	phead = (linklist)malloc(sizeof(Node));
    	phead = link_list(&n);					//把学生信息从链表里面读出来！
    	for (i = 0; i < n - 1; i++)	//排序
    	{
    		pre = phead;
    		p = pre->next;
    		for (j = 0; j < n - i - 1; j++)
    		{
    			if (pre->next->score.aver > p->next->score.aver)
    			{
    				pre->next = p->next;
    				p->next = p->next->next;
    				pre->next->next = p;
    
    				pre = pre->next;		//p这个时候不动
    			}
    			else
    			{
    				pre = pre->next;
    				p = pre->next;
    			}
    		}
    	}
    	output_students(phead);
    }
    //按照数学成绩排序
    void sort_math()
    {
    	Node * p, *pre;
    	linklist phead;
    	int n, i, j;
    	p = (Node*)malloc(sizeof(Node));
    	pre = (Node*)malloc(sizeof(Node));
    	phead = (linklist)malloc(sizeof(Node));
    	phead = link_list(&n);					//把学生信息从链表里面读出来！
    	for (i = 0; i < n - 1; i++)	//排序
    	{
    		pre = phead;
    		p = pre->next;
    		for (j = 0; j < n - i - 1; j++)
    		{
    			if (pre->next->score.math > p->next->score.math)
    			{
    				pre->next = p->next;
    				p->next = p->next->next;
    				pre->next->next = p;
    
    				pre = pre->next;		//p这个时候不动
    			}
    			else
    			{
    				pre = pre->next;
    				p = pre->next;
    			}
    		}
    	}
    	output_students(phead);
    }
    //按照英语成绩排序
    void sort_English()
    {
    	Node * p, *pre;
    	linklist phead;
    	int n, i, j;
    	p = (Node*)malloc(sizeof(Node));
    	pre = (Node*)malloc(sizeof(Node));
    	phead = (linklist)malloc(sizeof(Node));
    	phead = link_list(&n);					//把学生信息从链表里面读出来！
    	for (i = 0; i < n - 1; i++)	//排序
    	{
    		pre = phead;
    		p = pre->next;
    		for (j = 0; j < n - i - 1; j++)
    		{
    			if (pre->next->score.English > p->next->score.English)
    			{
    				pre->next = p->next;
    				p->next = p->next->next;
    				pre->next->next = p;
    
    				pre = pre->next;		//p这个时候不动
    			}
    			else
    			{
    				pre = pre->next;
    				p = pre->next;
    			}
    		}
    	}
    	output_students(phead);
    }
    //按照C语言成绩排序
    void sort_C_language ()
    {
    	Node * p, *pre;
    	linklist phead;
    	int n, i, j;
    	p = (Node*)malloc(sizeof(Node));
    	pre = (Node*)malloc(sizeof(Node));
    	phead = (linklist)malloc(sizeof(Node));
    	phead = link_list(&n);					//把学生信息从链表里面读出来！
    	for (i = 0; i < n - 1; i++)	//排序
    	{
    		pre = phead;
    		p = pre->next;
    		for (j = 0; j < n - i - 1; j++)
    		{
    			if (pre->next->score.C_language > p->next->score.C_language)
    			{
    				pre->next = p->next;
    				p->next = p->next->next;
    				pre->next->next = p;
    
    				pre = pre->next;		//p这个时候不动
    			}
    			else
    			{
    				pre = pre->next;
    				p = pre->next;
    			}
    		}
    	}
    	output_students(phead);
    }
    //输出全部学生信息（输出输出，需要已经创建好链表）
    void output_students(linklist phead)
    {
    	Node *p;
    	p = (Node*)malloc(sizeof(Node));
    	p = phead->next;//直接跳过头指针啦！
    	while (p)
    	{
    		Print_one_student(p);
    		p = p->next;
    	}
    }
    //删除学生
    void Del_student(Node *p, FILE *fp)
    {
    	char i;
    	FILE *fp1;
    	Node *p1;
    	p1 = (Node*)malloc(sizeof(Node));
    	fseek(fp, 0, SEEK_SET);//让原文件从一开始进行操作
    	printf("\t\t  请问您确认要删除 %s 吗？如果确认请按1，按其余键则回到管理员界面！\t", p->name);
    	i = getche();
    	if (i != '1')
    	{
    		menu_manager();
    	}
    	fp1 = fopen("linshi.txt", "w+");//读写新建一个临时文件
    	if (fp == NULL || fp1 == NULL)
    	{
    		printf("\t\t  文件打开失败！\n");
    		printf("\t\t  稍后将回到管理员菜单！\n");
    		Sleep(500);
    		menu_manager();
    	}
    	while (fread(p1, sizeof(Node), 1, fp))//从原文件读一个结点
    	{
    		if (strcmp(p->denglu.num, p1->denglu.num) != 0)//不是要删除的内容
    		{
    			fwrite(p1, sizeof(Node), 1, fp1);
    		}
    	}
    	fclose(fp);
    	fclose(fp1);
    //	remove("users.txt");				//日常vs这两个函数翻车，明天去找一下原因
    //	rename("linshi.txt", "users.txt");
    	fp1 = fopen("linshi.txt", "r");
    	fp = fopen("users.txt", "w+");//刷新 用户 文件
    	while (fread(p1, sizeof(Node), 1, fp1))
    	{
    		fwrite(p1, sizeof(Node), 1, fp);
    	}
    	fclose(fp);
    	fclose(fp1);
    	menu_manager();
    }
    //管理员密码修改
    void password_managers_modify()
    {
    	FILE *fp;
    	int p;
    	char manager[7],ch,manager1[7];
    	fp = fopen("manager.txt", "w+");
    flag1:
    	printf("\t\t  请输入您的新六位密码：");
    	p = 0;
    	while ((ch = getch()) != '\r')//判断是否是回车
    	{
    		if (ch == 8)//backspace键的ascii码是8
    		{
    			putchar('\b');
    			putchar(' ');//？？？
    			putchar('\b');
    			if (p>0)//最多只能删到没有字符
    				p--;
    		}
    		if (!isdigit(ch) && !isalpha(ch))//判断是否是数字
    		{
    			continue;
    		}
    		putchar('*');//在屏幕上打印星号
    		if (p > 5)
    		{
    			printf("\n\t\t  只能输入6位！稍后请重新输入！\n");
    			Sleep(500);
    			goto flag1;
    		}
    		manager[p++] = ch;//保存密码
    	}
    	manager[p] = 0;//结束字符串
    	if (p != 6)
    	{
    		printf("\n\t\t  密码格式错误，请重新输入！\n");
    		Sleep(500);
    		goto flag1;
    	}
    flag2:
    	printf("\n\t\t  请确认您的新六位密码：");
    	p = 0;
    	while ((ch = getch()) != '\r')//判断是否是回车
    	{
    		if (ch == 8)//backspace键的ascii码是8
    		{
    			putchar('\b');
    			putchar(' ');//？？？
    			putchar('\b');
    			if (p>0)//最多只能删到没有字符
    				p--;
    		}
    		if (!isdigit(ch) && !isalpha(ch))//判断是否是数字
    			{
    			continue;
    		}
    		putchar('*');//在屏幕上打印星号
    		if (p > 5)
    		{
    			printf("\n\t\t  只能输入6位！稍后请重新输入！\n");
    			Sleep(500);
    			goto flag2;
    		}
    		manager1[p++] = ch;//保存密码
    	}
    	manager1[p] = 0;//结束字符串
    	if (strcmp(manager, manager1) != 0)
    	{
    		printf("\n\t\t  两次输入的密码不一致！请重新输入！\n");
    		Sleep(500);
    		goto flag1;
    	}
    	fwrite(manager, 7, 1, fp);
    	fclose(fp);
    	printf("\n\t\t  密码修改成功！稍后将回到登录界面！\n");
    	Sleep(1000);
    	denglu();
    }
    //学生密码修改
    void password_student_modify(Node *pa)
    {
    	FILE *fp;
    	Node *pb;
    	int p;
    	char ch, pwd[17], pwd1[17];
    	pb = (Node*)malloc(sizeof(Node));
    	fp = fopen("users.txt", "r+");
    
    	fread(pb, sizeof(Node), 1, fp);
    	while (1)
    	{
    		if (strcmp(pa->denglu.num, pb->denglu.num))//如果两串不相等
    		{
    			if (!feof(fp))//如果没到文件尾
    			{
    				fread(pb, sizeof(Node), 1, fp);
    			}
    			else
    			{
    				break;
    			}
    		}
    		else//找到了
    		{
    			break;
    		}
    	}
    //开始输新密码！
    flag_password_pwd:
    	p = 0;
    	printf("\n\t\t  请输入新密码（16位，由英文字母和数字组成）：");
    	while ((ch = getch()) != '\r')//判断是否是回车  
    	{
    		if (ch == 8)//backspace键的ascii码是8
    		{
    			putchar('\b');
    			putchar(' ');//？？？
    			putchar('\b');
    			if (p > 0)//最多只能删到没有字符
    				p--;
    		}
    		if (!isdigit(ch) && !isalpha(ch))//判断是否是数字或字符 
    			continue;
    		if (p > 15)
    		{
    			printf("\n\t\t  最多输入16位密码！稍后请重新输入！\n");
    			Sleep(500);
    			goto flag_password_pwd;
    		}
    		putchar('*');//在屏幕上打印星号  
    		pwd[p++] = ch;//保存密码  
    	}
    	pwd[p] = 0;//结束字符串
    //确认密码！
    	p = 0;
    	printf("\n\t\t  请确认新密码：");
    	while ((ch = getch()) != '\r')//判断是否是回车  
    	{
    		if (ch == 8)//backspace键的ascii码是8
    		{
    			putchar('\b');
    			putchar(' ');//？？？
    			putchar('\b');
    			if (p > 0)//最多只能删到没有字符
    				p--;
    		}
    		if (!isdigit(ch) && !isalpha(ch))//判断是否是数字或字符 
    			continue;
    		if (p > 15)
    		{
    			printf("\n\t\t  最多输入16位密码！稍后请重新输入！\n");
    			Sleep(500);
    			goto flag_password_pwd;
    		}
    		putchar('*');//在屏幕上打印星号  
    		pwd1[p++] = ch;//保存密码  
    	}
    	pwd1[p] = 0;//结束字符串
    	if (strcmp(pwd, pwd1) != 0)
    	{
    		printf("\n\t\t  两次密码不一致！\n");
    		printf("\t\t  稍后将回到学生界面！\n");
    		Sleep(500);
    		menu_student(pa);
    	}
    //两次密码一致！
    	strcpy_s(pa->denglu.password, strlen(pwd) + 1, pwd);
    	fseek(fp, -sizeof(Node), SEEK_CUR);
    	fwrite(pa, sizeof(Node), 1, fp);
    	fclose(fp);
    	printf("\n\t\t  稍后将回到登录界面！\n");
    	Sleep(500);
    	denglu();
    }
    //学生成绩分析
    void Analysis_student()
    {
    	char i;
    	system("cls");
    	printf("\t\t------------------------------------------------------------\n");
    	printf("\t\t| 成绩分析界面 |\n");
    	printf("\t\t|  |\n");
    	printf("\t\t| 1.各科平均分 |\n");
    	printf("\t\t| 2.各科成绩分段   |\n");
    	printf("\t\t| 3.各科最高最低分 |\n");
    	printf("\t\t| 4.各科难度系数   |\n");
    	printf("\t\t| 5.退出成绩分析   |\n");
    	printf("\t\t|  |\n");
    	printf("\t\t------------------------------------------------------------\n");
    	i = getche();
    	switch (i)
    	{
    	case '1':student_aver_all(); break;
    	case '2':student_grade_output(); break;
    	case '3':student_grade_max_min(); break;
    	case '4':degree_of_difficulty(); break;
    	case '5':menu_manager(); break;
    	default:Analysis_student();
    	}
    }
    //各科平均分
    void student_aver_all()
    {
    	linklist phead;
    	Node *p;
    	int n,i;
    	double math = 0, English = 0, C_language = 0, all = 0;
    	phead = link_list(&n);//从文件取出来
    	p = (Node*)malloc(sizeof(Node));
    	p = phead->next;
    	i = n;
    	while (i--)
    	{
    		math = math + p->score.math;
    		English += p->score.English;
    		C_language += p->score.C_language;
    		all += p->score.aver;
    		p = p->next;
    	}
    	math /= n;
    	English /= n;
    	C_language /= n;
    	all /= n;
    
    	printf("\t\t  总数学平均分为 %.3lf ！\n", math);
    	printf("\t\t  总英语平均分为 %.3lf ！\n", English);
    	printf("\t\t  总C语言平均分为 %.3lf ！\n", C_language);
    	printf("\n\t\t  总平均分为 %.3lf ！\n", all);
    	printf("\n\t\t  按任意值回到成绩分析菜单！\n");
    	getch();
    	Analysis_student();
    }
    //成绩分段输出
    void student_grade_output()
    {
    	linklist phead;
    	Node *p;
    	int n, i;
    	int score_m[6] = { 0 }, score_C[6] = { 0 }, score_E[6] = { 0 }, score_A[6] = { 0 };
    	phead = link_list(&n);//从文件取出来
    	p = (Node*)malloc(sizeof(Node));
    	p = phead->next;
    	i = n;
    	while (i--)
    	{
    		switch (p->score.math / 10)
    		{
    		case 10:score_m[0]++; break;
    		case 9:score_m[1]++; break;
    		case 8:score_m[2]++; break;
    		case 7:score_m[3]++; break;
    		case 6:score_m[4]++; break;
    		default:score_m[5]++; break;
    		}
    		switch (p->score.C_language / 10)
    		{
    		case 10:score_C[0]++; break;
    		case 9:score_C[1]++; break;
    		case 8:score_C[2]++; break;
    		case 7:score_C[3]++; break;
    		case 6:score_C[4]++; break;
    		default:score_C[5]++; break;
    		}
    		switch (p->score.English / 10)
    		{
    		case 10:score_E[0]++; break;
    		case 9:score_E[1]++; break;
    		case 8:score_E[2]++; break;
    		case 7:score_E[3]++; break;
    		case 6:score_E[4]++; break;
    		default:score_E[5]++; break;
    		}
    		switch (((int)p->score.aver) / 10)
    		{
    		case 10:score_A[0]++; break;
    		case 9:score_A[1]++; break;
    		case 8:score_A[2]++; break;
    		case 7:score_A[3]++; break;
    		case 6:score_A[4]++; break;
    		default:score_A[5]++; break;
    		}
    		p = p->next;
    	}
    	printf("\t\t  数学成绩分段！\n");
    	printf("\t\t  100	90	80	70	60	不及格\n");
    	printf("\t\t  %d	%d	%d	%d	%d	%d\n",score_m[0],score_m[1],score_m[2], score_m[3], score_m[4], score_m[5]);
    	printf("\t\t  英语成绩分段！\n");
    	printf("\t\t  100	90	80	70	60	不及格\n");
    	printf("\t\t  %d	%d	%d	%d	%d	%d\n", score_E[0], score_E[1], score_E[2], score_E[3], score_E[4], score_E[5]);
    	printf("\t\t  C语言成绩分段！\n");
    	printf("\t\t  100	90	80	70	60	不及格\n");
    	printf("\t\t  %d	%d	%d	%d	%d	%d\n", score_C[0], score_C[1], score_C[2], score_C[3], score_C[4], score_C[5]);
    	printf("\t\t  平均分成绩分段！\n");
    	printf("\t\t  100	90	80	70	60	不及格\n");
    	printf("\t\t  %d	%d	%d	%d	%d	%d\n", score_A[0], score_A[1], score_A[2], score_A[3], score_A[4], score_A[5]);
    
    	printf("\n\t\t  按任意键回到成绩分析菜单！\n");
    	getch();
    	Analysis_student();
    }
    //成绩最大最小差值
    void student_grade_max_min()
    {
    	linklist phead;
    	Node *p;
    	int n, i;
    	int max[4] = { 0 }, min[4] = { 100,100,100,100 };
    	phead = link_list(&n);//从文件取出来
    	p = (Node*)malloc(sizeof(Node));
    	p = phead->next;
    	i = n;
    	while (n--)
    	{
    		if (max[0] < p->score.math)
    		{
    			max[0] = p->score.math;
    		}
    		if (max[1] < p->score.English)
    		{
    			max[1] = p->score.English;
    		}
    		if (max[2] < p->score.C_language)
    		{
    			max[2] = p->score.C_language;
    		}
    		if (max[3] < p->score.aver)
    		{
    			max[3] = p->score.aver;
    		}
    
    		if (min[0] > p->score.math)
    		{
    			min[0] = p->score.math;
    		}
    		if (min[1] > p->score.English)
    		{
    			min[1] = p->score.English;
    		}
    		if (min[2] > p->score.C_language)
    		{
    			min[2] = p->score.C_language;
    		}
    		if (min[3] > p->score.aver)
    		{
    			min[3] = p->score.aver;
    		}
    		p = p->next;
    	}
    	printf("\t\t  数学！最高分为 %d 最低分为 %d 差值为 %d\n", max[0], min[0], max[0] - min[0]);
    	printf("\t\t  英语！最高分为 %d 最低分为 %d 差值为 %d\n", max[1], min[1], max[1] - min[1]);
    	printf("\t\t  C语言！最高分为 %d 最低分为 %d 差值为 %d\n", max[2], min[2], max[2] - min[2]);
    	printf("\n\t\t  平均分！最高分为 %d 最低分为 %d 差值为 %d\n", max[3], min[3], max[3] - min[3]);
    	printf("\n\t\t  按任意值回到成绩分析菜单！\n");
    	getch();
    	Analysis_student();
    }
    //试卷难度系数
    void degree_of_difficulty()
    {
    	linklist phead;
    	Node *p;
    	int n, i;
    	double aver[4] = { 0 };
    	double difficulty[4];
    	phead = link_list(&n);//从文件取出来
    	p = (Node*)malloc(sizeof(Node));
    	p = phead->next;
    	i = n;
    	while (i--)
    	{
    		aver[0] += p->score.math;
    		aver[1] += p->score.English;
    		aver[2] += p->score.C_language;
    		aver[3] += p->score.aver;
    		p = p->next;
    	}
    	i = 4;
    	while (i--)
    	{
    		aver[i] = aver[i] / n;
    		difficulty[i] = 1 - aver[i] / 100;
    	}
    	printf("\t\t  难度系数在0.3~0.7的范围内较为合理\n");
    	printf("\t\t  建议老师将难度系数控制在0.5左右！\n\n");
    	printf("\t\t  数学试卷的难度系数是 %.4lf \n", difficulty[0]);
    	printf("\t\t  英语试卷的难度系数是 %.4lf \n", difficulty[1]);
    	printf("\t\t  C语言试卷的难度系数是 %.4lf \n", difficulty[2]);
    	printf("\n\t\t  考试的难度系数是 %.4lf \n", difficulty[3]);
    	printf("\n\t\t  输入任何值回到成绩分析菜单！\n");
    	getch();
    	Analysis_student();
    }
    
