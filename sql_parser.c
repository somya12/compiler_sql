#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int arr[50][50];
int d;
FILE *fp;
int dt;
int line_number;
struct node
	{
	int ind;
	char value[15];
	};

struct node *stack;
int index1 = -1;
char string[20],string4[20],string2[20],string3[20];
struct node * pop()
{
	struct node *temporary = malloc(sizeof(struct node));
	strcpy(temporary->value,stack[index1].value);
	temporary->ind = stack[index1].ind;
	index1--;
	return temporary;
	}

void push(struct node *arr)
	{
	index1++;
	strcpy(stack[index1].value,arr->value);
	stack[index1].ind = arr->ind;
	}
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
#define ELSE_STMT 27
#define EXP_STMT 28
#define VAR_ALLOT 29
//#define data_type [0]
#define int_dt 100
#define decimal 101
#define id 102
#define open_brac 103
#define close_brac 104
#define dot 105
#define num 106
#define create 107
#define database 108
#define use 109
#define table 110
#define varchar 111
#define alter 112
#define add 113
#define constraint 114
#define drop 115
#define primary 116
#define insert 117
#define into 118
#define values 119
#define select 120
#define all 121
#define distinct 122
#define from 123
#define where 124
#define and 125
#define or 126
#define delete 127
#define update 128
#define set 129
#define if_kw 130
#define else_kw 131
#define for_kw 132
#define while_kw 133
#define begin 134
#define end 135
#define semicolon 137
#define op 138
#define modulo 141
#define relop 142
#define id_num 144
#define comma 145
#define assign 146
#define curly_brac 147
#define curly_close_brac 148
#define string_opening 149
#define datatype 136
struct node *temp2;
void func(int i)
	{
	struct node *temp1=malloc(sizeof(struct node));
	switch(i)
		{
		case -1:
			{
			printf("error in line_number %d and token  %s\n",line_number,string);
			push(temp2);
			break;
			}
		case 1:
			{
			
			strcpy(temp1->value,"end");
			temp1->ind = end;
			push(temp1);
			
			strcpy(temp1->value,"STMTLIST");
			temp1->ind = STMTLIST; 
			push(temp1);
			
			break;
			}
		case 2:
			{
			strcpy(temp1->value,"VALS");
			temp1->ind = VALS; 
			push(temp1);
			strcpy(temp1->value,"id_num");
			temp1->ind = id_num; 
			push(temp1);
			break;
			}
		case 3:
			{
			temp1 = pop();
			if(!strcmp(temp1->value,")"))
				{
				}
			else 
				{
				printf("some error in close bracket in line number %d\n",line_number);
				}
			break;
			}
		case 4:
			{
			struct node *temp3 = pop();
			int g = temp3->ind;
			if(g==135)
				{
				if(index1 == -1)
					{
					printf("parse done\n");
					exit(0);
					}

				}
			break;
			}
		case 5:
			{
			// for create
			
				strcpy(temp1->value,"STMTLIST");
				temp1->ind = STMTLIST;
				push(temp1);
			fscanf(fp,"%d %s %s",&line_number,string3,string4);
			if(!strcmp(string3,"table"))
				{
				temp1->ind = semicolon;
				strcpy(temp1->value,";");
				push(temp1);
				strcpy(temp1->value,")");
				temp1->ind = close_brac;
				push(temp1);
				temp1->ind = COLUMN;
				strcpy(temp1->value,"COLUMN");
				push(temp1);
				temp1->ind = datatype;
				strcpy(temp1->value,"datatype");
				push(temp1);
				temp1->ind = id;
				strcpy(temp1->value,"id");
				push(temp1);
				strcpy(temp1->value,"(");
				temp1->ind = open_brac;
				push(temp1);
				
				strcpy(temp1->value,"id");
				temp1->ind = id;
				push(temp1);
				
				
				
				}
			else if(!strcmp(string3,"database"))
				{
				
				strcpy(temp1->value,";");
				temp1->ind = semicolon;
				push(temp1);
				strcpy(temp1->value,"id");
				temp1->ind = id;
				push(temp1);
				
				
				}
			break;
			}
		case 6:
			{
			strcpy(temp1->value,"STMTLIST");
			temp1->ind = STMTLIST;
			push(temp1);
			strcpy(temp1->value,";");
			temp1->ind = semicolon;
			push(temp1);
			
			strcpy(temp1->value,"id");
			temp1->ind = id;
			push(temp1);
			break;
			}
		case 8:
			
			{
			strcpy(temp1->value,"COLUMN");
			temp1->ind = COLUMN;
			push(temp1);
			strcpy(temp1->value,"datatype");
			temp1->ind = datatype;
			push(temp1);
			strcpy(temp1->value,"id");
			temp1->ind = id;
			push(temp1);
			
			break;
			}
		case 9:
			{
			
			temp1 = pop();
			if(!strcmp(temp1->value,")"))
				{
				
				}
			else
				{
				printf("error in line number %d\n",line_number);
				}
			break;
			}
		case 11:	
			{
			strcpy(temp1->value,"STMTLIST");
			temp1->ind = STMTLIST;
			push(temp1);
			strcpy(temp1->value,";");
			temp1->ind = semicolon;
			push(temp1);
			strcpy(temp1->value,")");
			temp1->ind = close_brac;
			push(temp1);
			strcpy(temp1->value,"id");
			temp1->ind = id;
			push(temp1);
			strcpy(temp1->value,"(");
			temp1->ind = open_brac;
			push(temp1);
			strcpy(temp1->value,"primary");
			temp1->ind = primary;
			push(temp1);
			strcpy(temp1->value,"constraint");
			temp1->ind = constraint;
			push(temp1);
			strcpy(temp1->value,"add");
			temp1->ind = add;
			push(temp1);

			strcpy(temp1->value,"id");
			temp1->ind = id;
			push(temp1);
			strcpy(temp1->value,"table");
			temp1->ind = table;
			push(temp1);
			
			
			break;
			}
		
		case 14:
			{
			strcpy(temp1->value,"STMTLIST");
			temp1->ind = STMTLIST;
			push(temp1);
			strcpy(temp1->value,";");
			temp1->ind = semicolon;
			push(temp1);
			strcpy(temp1->value,")");
			temp1->ind = close_brac;
			push(temp1);
			strcpy(temp1->value,"VALS");
			temp1->ind = VALS;
			push(temp1);
			strcpy(temp1->value,"id_num");
			temp1->ind = id_num;
			push(temp1);
			strcpy(temp1->value,"(");
			temp1->ind = open_brac;
			push(temp1);
			strcpy(temp1->value,"values");
			temp1->ind = values;
			push(temp1);
			strcpy(temp1->value,"id");
			temp1->ind = id;
			push(temp1);
			strcpy(temp1->value,"into");
			temp1->ind = into;
			push(temp1);
			break;
			}
		case 15:
			{
			strcpy(temp1->value,"STMTLIST");
			temp1->ind = STMTLIST;
			push(temp1);
			strcpy(temp1->value,";");
			temp1->ind = semicolon;
			push(temp1);
			strcpy(temp1->value,"EXPN");
			temp1->ind = EXPN;
			push(temp1);
			strcpy(temp1->value,"where");
			temp1->ind = where;
			push(temp1);
			strcpy(temp1->value,"id");
			temp1->ind = id;
			push(temp1);
			strcpy(temp1->value,"from");
			temp1->ind = from;
			push(temp1);
			strcpy(temp1->value,"COL");
			temp1->ind = COL;
			push(temp1);
			strcpy(temp1->value,"id");
			temp1->ind = id;
			push(temp1);
			
			break;
			}
		case 17:
			{
			strcpy(temp1->value,"STMTLIST");
			temp1->ind = STMTLIST;
			push(temp1);
			strcpy(temp1->value,";");
			temp1->ind = semicolon;
			push(temp1);
			strcpy(temp1->value,"EXPN");
			temp1->ind = EXPN;
			push(temp1);
			strcpy(temp1->value,"where");
			temp1->ind = where;
			push(temp1);
			strcpy(temp1->value,"id");
			temp1->ind = id;
			push(temp1);
			strcpy(temp1->value,"from");
			temp1->ind = from;
			push(temp1);
			
			break;
			}
		case 18:
			{
			strcpy(temp1->value,";");
			temp1->ind = semicolon;
			push(temp1);
			strcpy(temp1->value,"id");
			temp1->ind = id;
			push(temp1);
			strcpy(temp1->value,"table");
			temp1->ind = table;
			push(temp1);
			break;
			}
		case 19:
			{
			strcpy(temp1->value,"STMTLIST");
			temp1->ind = STMTLIST;
			push(temp1);
			strcpy(temp1->value,";");
			temp1->ind = semicolon;
			push(temp1);
			strcpy(temp1->value,"EXPN");
			temp1->ind = EXPN;
			push(temp1);
			strcpy(temp1->value,"where");
			temp1->ind = where;
			push(temp1);
			strcpy(temp1->value,"SET_STMT");
			temp1->ind = SET_STMT;
			push(temp1);
			strcpy(temp1->value,"set");
			temp1->ind = set;
			push(temp1);
			strcpy(temp1->value,"id");
			temp1->ind = id;
			push(temp1);
			strcpy(temp1->value,"table");
			temp1->ind = table;
			push(temp1);
			break;
			}
		case 20:
			{
			strcpy(temp1->value,"id_num");
			temp1->ind = id_num;
			push(temp1);
			strcpy(temp1->value,":=");
			temp1->ind = assign;
			push(temp1);
			strcpy(temp1->value,"id");
			temp1->ind = id;
			push(temp1);
			break;
			}
		case 21:
			{
			strcpy(temp1->value,"STMTLIST");
			temp1->ind = STMTLIST;
			push(temp1);
			strcpy(temp1->value,"}");
			temp1->ind = curly_brac;
			push(temp1);
			strcpy(temp1->value,"STMTLIST");
			temp1->ind = STMTLIST;
			push(temp1);
			strcpy(temp1->value,"{");
			temp1->ind = curly_close_brac;
			push(temp1);
			strcpy(temp1->value,")");
			temp1->ind = close_brac;
			push(temp1);
			strcpy(temp1->value,"EXP_STMT");
			temp1->ind = EXP_STMT;
			push(temp1);
			strcpy(temp1->value,";");
			temp1->ind = semicolon;
			push(temp1);
			strcpy(temp1->value,"EXPN");
			temp1->ind = EXPN;
			push(temp1);
			strcpy(temp1->value,"VAR_ALLOT");
			temp1->ind = VAR_DECL;
			push(temp1);
			strcpy(temp1->value,"(");
			temp1->ind = open_brac;
			push(temp1);
			
			
			break;
			}
		case 22:
			{
			strcpy(temp1->value,"STMTLIST");
			temp1->ind = STMTLIST;
			push(temp1);
			strcpy(temp1->value,"}");
			temp1->ind = curly_brac;
			push(temp1);
			strcpy(temp1->value,"STMTLIST");
			temp1->ind = STMTLIST;
			push(temp1);
			strcpy(temp1->value,"{");
			temp1->ind = curly_close_brac;
			push(temp1);
			strcpy(temp1->value,")");
			temp1->ind = close_brac;
			push(temp1);
			strcpy(temp1->value,"EXPN");
			temp1->ind = EXPN;
			push(temp1);
			strcpy(temp1->value,"(");
			temp1->ind = open_brac;
			push(temp1);
			break;
			}
		case 24:
			{
			strcpy(temp1->value,"STMTLIST");
			temp1->ind = STMTLIST;
			push(temp1);
			if(!strcmp(string,"int"))
				{
				dt = 0;
				strcpy(temp1->value,";");
				temp1->ind = semicolon;
				push(temp1);
				strcpy(temp1->value,"num");
				temp1->ind = num;
				push(temp1);
				strcpy(temp1->value,":=");
				temp1->ind = assign;
				push(temp1);
				strcpy(temp1->value,"id");
				temp1->ind = id;
				push(temp1);
				
				}
			else if(!strcmp(string,"varchar"))
				{
				dt = 1;
				strcpy(temp1->value,";");
				temp1->ind = semicolon;
				push(temp1);
				strcpy(temp1->value,"'");
				temp1->ind = string_opening;
				push(temp1);
				strcpy(temp1->value,"id");
				temp1->ind = id;
				push(temp1);
				strcpy(temp1->value,"'");
				temp1->ind = string_opening;
				push(temp1);
				strcpy(temp1->value,":=");
				temp1->ind = assign;
				push(temp1);
				strcpy(temp1->value,"id");
			temp1->ind = id;
			push(temp1);	
				strcpy(temp1->value,")");
				temp1->ind = close_brac;
				push(temp1);
				strcpy(temp1->value,"num");
				temp1->ind = num;
				push(temp1);
				strcpy(temp1->value,"(");
				temp1->ind = open_brac;
				push(temp1);
				}
			else  if(!strcmp(string,"decimal"))
				{
				dt = 2;
				strcpy(temp1->value,";");
				temp1->ind = semicolon;
				push(temp1);
				strcpy(temp1->value,"num");
				temp1->ind = num;
				push(temp1);
				strcpy(temp1->value,".");
				temp1->ind = dot;
				push(temp1);
				strcpy(temp1->value,"num");
				temp1->ind = num;
				push(temp1);
				strcpy(temp1->value,":=");
				temp1->ind = assign;
				push(temp1);
				strcpy(temp1->value,"id");
				temp1->ind = id;
				push(temp1);
				}
			/*strcpy(temp1->value,";");
			temp1->ind = semicolon;
			push(temp1);*/
			
			break;
			}
		case 23:
			{
			fscanf(fp,"%d %s %s",&line_number,string3,string4);
			if(!strcmp(string3,":="))
				{
				strcpy(temp1->value,"id_nuum");
				temp1->ind = id_num;
				push(temp1);
				}
			}
		
		case 25:
			{
			strcpy(temp1->value,"COL");
			temp1->ind = COL;
			push(temp1);
			strcpy(temp1->value,"id");
			temp1->ind = id;
			push(temp1);
			break;
			}
		case 26:
			{
			temp1 = pop();
			if(!strcmp(temp1->value,"from"))
				{
				
				}
			else
				{
				printf("not successful, error at line number %d\n",line_number);
				}

			break;
			}
		case 27:
			{
			//printf("enteres in EXPN\n");
			strcpy(temp1->value,"id_num");
			temp1->ind = id_num;
			push(temp1);
			strcpy(temp1->value,"relop");
			temp1->ind = relop;
			push(temp1);
			break;
			}
		
		case 29:
			{
			pop();
			break;
			}
		case 28:
			{
			temp1 = pop();
			break;
			}
		case 30:
			{

			strcpy(temp1->value,"id_num");
			temp1->ind = id_num;
			push(temp1);
			break;
			}
		case 31:
			{
			strcpy(temp1->value,";");
			temp1->ind = semicolon;
			push(temp1);
			strcpy(temp1->value,"id_num");
			temp1->ind = id_num;
			push(temp1);
			strcpy(temp1->value,"op");
			temp1->ind = op;
			push(temp1);
			strcpy(temp1->value,"id_num");
			temp1->ind = id_num;
			push(temp1);
			strcpy(temp1->value,":=");
			temp1->ind = assign;
			push(temp1);
			break;
			
			}
		case 32:
			{
			strcpy(temp1->value,"id_num");
			temp1->ind = id_num;
			push(temp1);
			strcpy(temp1->value,"op");
			temp1->ind = op;
			push(temp1);
			strcpy(temp1->value,"id_num");
			temp1->ind = id_num;
			push(temp1);
			strcpy(temp1->value,":=");
			temp1->ind = assign;
			push(temp1);
			break;
			}
		case 33:
			{
			strcpy(temp1->value,";");
			temp1->ind = semicolon;
			push(temp1);
			strcpy(temp1->value,"id_num");
			temp1->ind = id_num;
			push(temp1);
			strcpy(temp1->value,":=");
			temp1->ind = assign;
			push(temp1);
			break;
			}
		case 34:
			{
			strcpy(temp1->value,"STMTLIST");
			temp1->ind = STMTLIST;
			push(temp1);
			strcpy(temp1->value,"}");
			temp1->ind = curly_close_brac;
			push(temp1);
			strcpy(temp1->value,"STMTLIST");
			temp1->ind = STMTLIST;
			push(temp1);
			strcpy(temp1->value,"{");
			temp1->ind = curly_brac;
			push(temp1);
			strcpy(temp1->value,"else");
			temp1->ind = else_kw;
			push(temp1);
			strcpy(temp1->value,"}");
			temp1->ind = curly_close_brac;
			push(temp1);
			strcpy(temp1->value,"STMTLIST");
			temp1->ind = STMTLIST;
			push(temp1);
			strcpy(temp1->value,"{");
			temp1->ind = curly_brac;
			push(temp1);
			strcpy(temp1->value,")");
			temp1->ind = close_brac;
			push(temp1);
			strcpy(temp1->value,"EXPN");
			temp1->ind = EXPN;
			push(temp1);
			strcpy(temp1->value,"(");
			temp1->ind = open_brac;
			push(temp1);
			break;
			}
		case 35:
			{
			
			break;
			}


		default:
			{
			printf("error in line number %d in token %s\n",line_number,string);
			}
		
		}
	}





main()
	{
	int row=0,column=0;
	for(row=0;row<50;row++)
		{
		for(column=0;column<50;column++)
			arr[row][column]=-1;
		}
	fp = fopen("symbol_table","r");
	stack = malloc(sizeof(struct node)*20);
	int i;
	char str2[7] = "func";
	char str[2];
	 arr[START] [begin-100] = 1;
	 arr[STMTLIST] [create-100] = 5;
	 arr[STMTLIST] [update-100] = 19;
	 arr[STMTLIST] [use-100] = 6;
	 arr[STMTLIST] [alter-100] = 11;
	 arr[STMTLIST] [insert-100] = 14;
	 arr[STMTLIST] [select-100] = 15;
	 arr[STMTLIST] [delete-100] = 17;
	 arr[STMTLIST] [drop-100] = 18;
	 arr[STMTLIST] [update-100] = 19;
	 arr[STMTLIST] [if_kw-100] = 34;
	 arr[STMTLIST] [for_kw-100] = 21;
	 arr[STMTLIST] [while_kw-100] = 22;
	arr [STMTLIST] [id] = 31;
	arr[STMTLIST] [int_dt-100] = 24;
	arr[STMTLIST] [decimal-100] = 24;
	arr[STMTLIST] [varchar-100] = 24;
	 arr[STMTLIST] [end-100] = 4;
	arr[STMTLIST] [curly_close_brac-100] = 28;
	
	arr[VAR_DECL] [int_dt-100] = 24;
	//arr[VAR_DECL] [float-100] = 24;
	arr[VAR_DECL] [decimal-100] = 24;
	arr[VAR_DECL] [varchar-100] = 24;
	
	arr[VAR_ALLOT] [id-100] = 33;

	arr[VAR_LIST] [id-100] = 23;
	arr[VAR_LIST] [assign-100] = 0;
	arr[VAR_LIST] [id_num-100] = 0;

	 arr[STMT] [create-100] = 5;
	 arr[STMT] [update-100] = 19;
	 arr[STMT] [use-100] = 6;
	 arr[STMT] [alter-100] = 11;
	 arr[STMT] [insert-100] = 14;
	 arr[STMT] [select-100] = 15;
	 arr[STMT] [delete-100] = 17;
	 arr[STMT] [drop-100] = 18;
	 arr[STMT] [update-100] = 19;
	 arr[STMT] [if_kw-100] = 34;
	 arr[STMT] [for_kw-100] = 21;
	 arr[STMT] [while_kw-100] = 22;
	 //STMT dollar = 4;
	 
	 arr[CREATE_DB] [create-100] = 5;
	 arr[CREATE_DB] [database-100] = 0;
	 arr[CREATE_DB] [id-100] = 0;
	arr[ELSE_STMT] [else_kw-100] = 35;
	
	
	 arr[USE_STMT] [use-100] = 6;
	 arr[USE_STMT] [id-100] = 0;
	
	// arr[CREATE_STMT] [create-100] = 7;
	 arr[CREATE_STMT] [table-100] = 0;
	 arr[CREATE_STMT] [open_brac-100] = 0;
	 arr[CREATE_STMT] [close_brac-100] = 0;
	
	arr [COLUMN] [comma-100] = 8;
	 arr[COLUMN] [id-100] = 0;
	 arr[COLUMN] [close_brac-100] = 9;
	
	 arr[COL_NAME] [id-100] = 10;
	 arr[COL_NAME] [int_dt-100] = 0;
	 arr[COL_NAME] [decimal-100] = 0;
	 arr[COL_NAME] [id-100] = 0;
 
	 /* datatype taken lite */

  	arr[ALTER_STMT] [alter-100] = 11;
	arr[ALTER_STMT] [table-100] = 0;
	arr[ALTER_STMT] [id-100] = 0;
	arr[ALTER_STMT] [add-100] = 0;

	arr[CONSTRAINT] [constraint-100] = 12;
	arr[CONSTRAINT] [primary-100] = 0;
	arr[CONSTRAINT] [id-100] = 0;
 	
	arr[COL] [id-100] = 13;
	arr[COL] [from-100] = 28;
	arr[COL] [semicolon-100] = 0;

	arr[INSERT_STMT] [insert-100] = 14;
	arr[INSERT_STMT] [into-100] = 0;
	arr[INSERT_STMT] [id-100] = 0;
	arr[INSERT_STMT] [values-100] = 0;
	arr[INSERT_STMT] [open_brac-100] = 0;
	arr[INSERT_STMT] [semicolon-100] = 0;
		
	arr[VALS] [comma] = 30;	
	arr[VALS] [id-100] = 0;
	arr[VALS] [num-100] = 0;
 /* num me we check if it is number or decimal */
	arr[VALS] [close_brac-100] = 29;

	arr[SELECT_STMT] [select-100] = 15;
	//arr[SELECT_STMT] [mul-100] = 0;
	arr[SELECT_STMT] [from-100] = 0;
	arr[SELECT_STMT] [id-100] = 0;
	arr[SELECT_STMT][where] = 0;
	arr[COL][comma-100] = 25;
	arr[COL][id-100] = 0;
	arr[COL][from-100] = 29;	
	
	arr[VALS][comma-100] = 2;
	arr[VALS][id_num] = 0;
	arr[VALS][close_brac] = 3;

	arr[SEARCH_CND] [id-100] = 16;
	arr[SEARCH_CND] [relop-100] = 0;
	arr[SEARCH_CND] [semicolon-100] = 0;

 	arr[DELETE_STMT] [delete-100] = 17;
	arr[DELETE_STMT] [from-100]  = 0;
	arr[DELETE_STMT] [id-100] = 0;
	arr[DELETE_STMT] [where-100] = 0;
	
	arr[EXPN] [where-100] = 27;
	arr[EXPN] [id-100] = 27;
	arr[EXPN] [relop-100] = 0;
	arr[EXPN] [id_num] = 0;
	arr[EXPN] [semicolon] = 28;


	arr[EXP_STMT] [id-100] = 32;
	arr[EXPN_STMT] [op-100] = 31;
	
	arr[DROP_TABLE] [drop-100] = 18;
	arr[DROP_TABLE] [id-100] = 0;

	arr[UPDATE_STMT] [update-100] = 19;
	arr[UPDATE_STMT] [id-100] = 0;
	arr[UPDATE_STMT] [where-100] = 0;
	
	arr[SET_STMT] [set-100] = 20;
	arr[SET_STMT] [where-100] = 0;

	struct node *first = malloc(sizeof(struct node));
	first->ind = 0;
	strcpy(first->value,"START");
	push(first);
	fscanf(fp,"%s %s %s %s",string,string,string,string);
	fscanf(fp,"%s %s",string,string);
	int k=0;
	while(!feof(fp))
		{
		fscanf(fp,"%d %s %s",&line_number,string,string2);
		temp2 = pop();
		d = temp2->ind;
		char string5[20];
		strcpy(string5,temp2->value);
		int go_to;
		if(!strcmp("datatype",temp2->value))
			{
			if(!strcmp(string,"int") || !strcmp(string,"decimal") || !strcmp(string,"varchar"))
				{	
				if(!strcmp(string,"varchar"))
					{
					fscanf(fp,"%d %s %s",&line_number,string,string2);
						{
						if(strcmp(string,"("))
							{
							printf("error in line number %d\n",line_number);
							}
						else{
							fscanf(fp,"%d %s %s",&line_number,string,string2);
							if(string[0]>='0' && string[0]<='9')
								{
								fscanf(fp,"%d %s %s",&line_number,string,string2);
								if(strcmp(string,")"))
									printf("error in line number %d in token %s\n",line_number,string); 	
								}}
								
								
				
						}
					}
				}
			else
				{
				printf("error in line number %d in datatype %s\n",line_number,string);
				}
			}
		else if(!strcmp(temp2->value,"op"))
			{
			if(!strcmp(string,"+") || !strcmp(string,"-") || !strcmp(string,"*") || !strcmp(string,"/") || !strcmp(string,"%"))
				{
				}
			else
				{
				printf("error in line number %d in operator %s\n",line_number,string);
				}
			}
		else if(!strcmp(string,temp2->value))
			{
			// do nothing
			if(!strcmp("end",string))
				{
				printf("parse completed\n");
				exit(0);
				}
			}
		
		else if(!strcmp("VAR_ALLOT",temp2->value) && !strcmp("variable_name",string2))
			{
			func(33);
			}
		else if(!strcmp(string,"begin"))
			{
			go_to = arr[d][134-100];
			func(go_to);
			}
		else if(k==0 && strcmp(string,"begin"))
			{
			printf("error in line number %d in begin\n",line_number);
			func(1);
			}
		else if(!strcmp(string,"int"))
			{
			go_to = arr[d][0];
			func(go_to);
			}
		else if(!strcmp(string,"decimal"))
			{
			go_to = arr[d][1];
			func(go_to);
			}
		
		else if(!(strcmp(string,"if")))
			{
			go_to = arr[d][if_kw-100];
			func(go_to);
			}
		else if(!(strcmp(string,"else")))
			{
			go_to = arr[d][else_kw-100];
			func(go_to);
			}
		else if(!strcmp(string,"create"))
			{
			go_to = arr[d][7];
			func(go_to);
			}
		else if(!strcmp(string,"database"))
			{
			go_to = arr[d][8];
			func(go_to);
			}
		else if(!strcmp(string,"use"))
			{
			go_to = arr[d][9];
			func(go_to);
			}
		else if(!strcmp(string,"table"))
			{
			go_to = arr[d][10];
			func(go_to);
			}
		else if(!strcmp(string,"varchar"))
			{
			go_to = arr[d][11];
			func(go_to);
			}
		else if(!strcmp(string,"alter"))
			{
			go_to = arr[d][12];
			func(go_to);
			}
		else if(!strcmp(string,"add"))
			{
			go_to = arr[d][13];
			func(go_to);
			}
		else if(!strcmp(string,"constraint"))
			{
			go_to = arr[d][14];
			func(go_to);
			}
		else if(!strcmp(string,"drop"))
			{
			go_to = arr[d][15];
			func(go_to);
			}
		else if(!strcmp(string,"primary"))
			{
			//fscanf(fp,"%s",string);
			go_to = arr[d][16];
			func(go_to);
			}
		else if(!strcmp(string,"insert"))
			{
			go_to = arr[d][17];
			func(go_to);
			}
		else if(!strcmp(string,"into"))
			{
			
			go_to = arr[d][18];
			func(go_to);
			
			}
		else if(!strcmp(string,"values"))
			{
			go_to = arr[d][19];
			func(go_to);
			}
		else if(!strcmp(string,"select"))
			{
			go_to = arr[d][20];
			func(go_to);
			}
		else if(!strcmp(string,"all"))
			{
			go_to = arr[d][21];
			func(go_to);
			}
		else if(!strcmp(string,"distinct"))
			{
			go_to = arr[d][22];
			func(go_to);
			}
		else if(!strcmp(string,"from"))
			{
			//printf("in fron %d\n",d);
			go_to = arr[d][23];
			//printf("goto %d\n",go_to);
			func(go_to);
			}
		else if(!strcmp(string,"where"))
			{
			printf("wheere %d\n",d);
			temp2 = pop();
			d = temp2->ind;
			go_to = arr[d][24];
			printf("%d %s\n",go_to,temp2->value);
			func(go_to);
			}
		else if(!strcmp(string,"and"))
			{
			go_to = arr[d][25];
			func(go_to);
			}
		else if(!strcmp(string,"or"))
			{
			go_to = arr[d][26];
			func(go_to);
			}
		else if(!strcmp(string,"delete"))
			{
			go_to = arr[d][27];
			func(go_to);
			}
		else if(!strcmp(string,"update"))
			{
			go_to = arr[d][28];
			func(go_to);
			}
		else if(!strcmp(string,"set"))
			{
			go_to = arr[d][29];
			func(go_to);
			}
		else if(!strcmp(string,"if"))
			{
			go_to = arr[d][30];
			func(go_to);
			}
		else if(!strcmp(string,"else"))
			{
			go_to = arr[d][31];
			func(go_to);
			}
		else if(!strcmp(string,"for"))
			{
			//printf("entering here %d \n",d);
			go_to = arr[d][32];
			func(go_to);
			}
		else if(!strcmp(string,"while"))
			{
			go_to = arr[d][33];
			func(go_to);
			}
		else if(!strcmp(string,"end"))
			{
			go_to = arr[d][35];
			func(go_to);
			}
		else if(!strcmp(string2,"variable_name") && d<=34)
			{
			go_to = arr[d][id-100];
			func(go_to);
			}
		else if(!strcmp(string2,"num") && d<=34)
			{
			go_to = arr[d][num-100];
			func(go_to);
			}
		else if(!strcmp(string2,"id_num") && d<=34)
			{
			go_to = arr[d][id_num-100];
			func(go_to);
			}
		else if(!strcmp(string,","))
			{
			go_to = arr[d][comma-100];
			func(go_to);
			}
		else if(!strcmp(string,")"))
			{
			go_to = arr[d][close_brac-100];
			func(go_to);
			}
		else if(!strcmp(string,"}"))
			{
			go_to = arr[d][curly_close_brac-100];
			func(go_to);
			}
		
		else if(d>34)
			{
			// compare them with input string
			if(!strcmp(temp2->value,"id"))
				{
				//printf("id name\n");
				int len = strlen(string);
				int i=0;
				if((string[i]>='a' && string[i]<='z')|| string[i]=='_')
					{
					}
				else
					{
					printf("error in token %s\n",string);
					}
				i=1;
				for(i=1;i<len;i++)
				{
				if((string[i]>='a' && string[i]<='z')||(string[i]>='0' && string[i]<='9') || string[i]=='_')
					{
					}
				else
					{
					printf("error in the token at line number %d\n",line_number);
					}
				}			
				}
			else if(!strcmp(temp2->value,"num"))
				{
				int len = strlen(string);
				int i=1;
				for(i=1;i<len;i++)
				{
				if(string[i]>='0' && string[i]<='9')
				{
				}
				else
				{
				printf("error in the token at line number %d\n",line_number);
				}
				}
				// check that the number is num
				}
			else if(!strcmp(temp2->value,"id_num"))
				{
				// check if it is id or num
				int len = strlen(string);
				if(string[0]>='0' && string[0]<='9')
					{
					int i=1;
					for(i=1;i<len;i++)
					{
					if(!(string[i]>='0' && string[i]<='9'))
					printf("error in the token at line number %d\n",line_number);
					}
					}
				
			else if((string[0]>='a' && string[0]<='z') && string[0]=='_')
				{
				int len = strlen(string);
				int i=1;
				for(i=1;i<len;i++)
					{
					if(!(string[i]>='0' && string[i]<='9') && !(string[i]>='a' && string[i]<='z') && !(string[i]=='_'))
					printf("error in the token at line number %d\n",line_number);
					}
				}	
			}
			else if(!strcmp(temp2->value,"relop"))
				{
				//check relational operator
				if(!strcmp(string,"<=")||!strcmp(string,"==")||!strcmp(string,">=")||!strcmp(string,"!=")||!strcmp(string,"<")||!strcmp(string,">"))
				{
				
				}
				else
				{
				printf("wrong relational operator\n");
				}
				}
			else if(!strcmp(temp2->value,string))
				{
				printf("here\n");
				}
			else if(!(strcmp(temp2->value,"invalid")))
				{
				printf("invalid character in line\n");
				}
			
			else if(!strcmp(string2,"invalid"))
				{
				printf("invalid symbol found in the symbol table\n");
				}
			else 
				{
				if(d>50)
					printf("error in line number %d in %s\n",line_number,string);
				fscanf(fp,"%d %s %s",&line_number,string,string2);
				int initial = line_number;
				int j=0;
				while(strcmp(string,temp2->value) && j<5)
					{
					fscanf(fp,"%d %s %s",&line_number,string,string2);
					j++;
					}	
				/*if(line_number < initial+1)
					{
					while(line_number<initial+1)
						{
						fscanf(fp,"%d %s %s",&line_number,string,string2);
						}
					}*/

				}
		}
		k++;	
		}
	}


