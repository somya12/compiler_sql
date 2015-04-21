#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int arr[36][36];

#define START 0
#define STMTLIST 1
#define STMT 2
#define CREATE_DB 3
#define USE_STMT 4
#define CREATE_STMT 5
#define COLUMN 6
#define TYPE 7
#define COL_NAME 8
#define ALTER_STMT 9
#define CONSTRAINT 10
#define COL 11
#define INSERT_STMT 12
#define VALS 13
#define SELECT_STMT 14
#define SEARCH_CND 15
#define DELETE_STMT 16
#define DROP_TABLE 17
#define UPDATE_STMT 18
#define SET_STMT 19
#define EXPN 20
#define EXPN_STMT 21
#define IF_STMT 22
#define VAR_DECL 23
#define VAR_LIST 24
#define WHILE_STMT 25
#define FOR_STMT 26

//#define data_type [0]
#define int_dt [0]
#define decimal [1]
#define id [2]
#define open_brac [3]
#define close_brac [4]
#define dot [5]
#define num [6]
#define create [7]
#define database [8]
#define use [9]
#define table [10]
#define varchar [11]
#define alter [12]
#define add [13]
#define constraint [14]
#define drop [15]
#define primary_key [16]
#define insert [17]
#define into [18]
#define values [19]
#define select [20]
#define all [21]
#define distinct [22]
#define from [23]
#define where [24]
#define and [25]
#define or [26]
#define delete [27]
#define update [28]
#define set [29]
#define if_kw [30]
#define else_kw [31]
#define for_kw [32]
#define while_kw [33]
#define begin [34]
#define end [35]
#define dollar [36]
#define semicolon [37]
#define mul [38]
#define sub [39]
#define div [40]
#define modulo [41]
#define relop [42]
#define addo [43] 

char stack[50][10];
int index1 = -1;

void ( *farr[20]) (void);

void func1()
{
  push("1");
  push("end"); 
}


char * pop()
{
	char string[10] ;
	strcpy(string,stack[index1]);
	index1--;
	return string;
	}

void push(char* arr)
	{
	index1++;
	strcpy(stack[index1],arr);
	}

main()
	{
	FILE *fp = fopen("symbol_table","r");
	char string[25];
	char tab[1];
	char string2[30];
	int line_number;

	//farr[0] = func1;


	int i;
	char str2[7] = "func";
	char str[2];
	
	(*farr[0])();
	
	 START begin = 1;
	 START dollar = 0;
	 STMTLIST create = 2;
	 STMTLIST update = 2;
	 STMTLIST use = 2;
	 STMTLIST alter = 2;
	 STMTLIST insert = 2;
	 STMTLIST select = 2;
	 STMTLIST delete = 2;
	 STMTLIST drop = 2;
	 STMTLIST update = 2;
	 STMTLIST if_kw = 2;
	 STMTLIST for_kw = 2;
	 STMTLIST while_kw = 2;
	 //STMTLIST dollar = 2;
	 STMTLIST end = 4;

	 STMT create = 3;
	 STMT update = 3;
	 STMT use = 3;
	 STMT alter = 3;
	 STMT insert = 3;
	 STMT select = 3;
	 STMT delete = 3;
	 STMT drop = 3;
	 STMT update = 3;
	 STMT if_kw = 3;
	 STMT for_kw = 3;
	 STMT while_kw = 3;
	 //STMT dollar = 4;
	 
	 CREATE_DB create = 5;
	 CREATE_DB database = 0;
	 CREATE_DB id = 0;
	
	
	 USE_STMT use = 6;
	 USE_STMT id = 0;
	
	 CREATE_STMT create = 7;
	 CREATE_STMT table = 0;
	 CREATE_STMT open_brac = 0;
	 CREATE_STMT close_brac = 0;
	
	 COLUMN id = 8;
	 COLUMN close_brac = 9;
	
	 COL_NAME id = 10;
	 COL_NAME int_dt = 0;
	 COL_NAME decimal = 0;
	 COL_NAME id = 0;
 
	 /* datatype taken lite */

  	ALTER_STMT alter = 11;
	ALTER_STMT table = 0;
	ALTER_STMT id = 0;
	ALTER_STMT add = 0;

	CONSTRAINT constraint = 12;
	CONSTRAINT  primary_key = 0;
	CONSTRAINT id = 0;
 	
	COL id = 13;
	COL semicolon = 0;

	INSERT_STMT insert = 14;
	INSERT_STMT into = 0;
	INSERT_STMT id = 0;
	INSERT_STMT values = 0;
	INSERT_STMT open_brac = 0;
	INSERT_STMT semicolon = 0;
	
	VALS id = 0;
	VALS num = 0;
 /* num me we check if it is number or decimal */
	VALS close_brac = 0;

	SELECT_STMT select = 15;
	SELECT_STMT mul = 0;
	SELECT_STMT from = 0;
	SELECT_STMT id = 0;
/* in select funstion we'll do a look ahead */
	//printf("%s",string);
	SEARCH_CND id = 16;
	SEARCH_CND relop = 0;
	SEARCH_CND semicolon = 0;

 	DELETE_STMT delete = 17;
	DELETE_STMT from  = 0;
	DELETE_STMT id = 0;
	DELETE_STMT where = 0;
	
	DROP_TABLE drop = 18;
	DROP_TABLE id = 0;

	UPDATE_STMT update = 19;
	UPDATE_STMT id = 0;
	UPDATE_STMT where = 0;
	
	SET_STMT set = 20;
	SET_STMT where = 0;

	/*EXPN*/
	push(0);

	fscanf(fp,"%s %s %s %s",string,string,string,string);
	fscanf(fp,"%s %s",string,string);
	//printf("%s",string);
	while(!feof(fp))
		{
		fscanf(fp,"%d %s %s",&line_number,string,string2);
		printf("%d %s %s\n",line_number,string,string2);

		int d = atoi(pop());
		int go_to;
		// = arr[d] string;
		if(strcmp(string,"begin")
			{
			go_to = array[d][0];
			
			}

		if(go_to != -1 || go_to != 0)
		(*farr[go_to])();
		else
			if(go_to == -1)
				{
				printf("invalid token in line number %d\n ",line_number);
				}
			else
				{
				printf("missing token in line number %d\n",line_number);
				}
		//parse(string, string2);	
		}
	}

