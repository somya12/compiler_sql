#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int arr[36][36];
int d;
FILE *fp;
int line_number;
char string[20],string4[20],string2[20],string3[20];
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
#define primary_key 116
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
#define dollar 136
#define semicolon 137
#define mul 138
#define sub 139
#define div 140
#define modulo 141
#define relop 142
#define addo 143 

struct node
	{
	int ind;
	char value[15];
	};

struct node stack[20];
int index1 = -1;

void func(int i)
	{
	struct node *temp1=malloc(sizeof(struct node));
	switch(i)
		{
		case 1:
			{
			pop();
			printf("in switch case\n");
			
			strcmp(temp1->value,"end");
			temp1->ind = end;
			push(temp1);
			
			strcmp(temp1->value,"STMTLIST");
			temp1->ind = STMTLIST; 
			push(temp1);
			
			break;
			}
		/*case 2:
			{
			printf("in stmt list\n");
			//fscanf(fp,"%d %s %s",&line_number,string,string2);
			pop();
			strcmp(temp1->value,"STMTLIST");
			temp1->ind = STMTLIST;
			push(temp1);
			strcmp(temp1->value,"STMT");
			temp1->ind = STMT;
			d = pop();
			if(!strcmp(string,"create"))
			{
			go_to = arr[d][7];
			func(go_to);
			}
		
		else if(!strcmp(string,"use"))
			{
			go_to = arr[d][9];
			func(go_to);
			}
		
		else if(!strcmp(string,"alter"))
			{
			go_to = arr[d][12];
			func(go_to);
			}
		
		else if(!strcmp(string,"drop"))
			{
			go_to = arr[d][15];
			func(go_to);
			}
		
		else if(!strcmp(string,"insert"))
			{
			go_to = arr[d][17];
			func(go_to);
			}
		
		else if(!strcmp(string,"select"))
			{
			go_to = arr[d][20];
			func(go_to);
			}
		
		else if(!strcmp(string,"where"))
			{
			go_to = arr[d][24];
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
		else if(!strcmp(string,"create"))
			{
			go_to = arr[d][7];
			func(go_to);
			}
			break;
			//struct node *temp1
			}*/
		case 5:
			{
			// for create
			if(d == 1)
				{
				strcmp(temp1->value,"STMTLIST");
				temp1->ind = STMTLIST;
				push(temp1);
				}
			fscanf(fp,"%d %s %s",line_number,string3,string4);
			if(!strcmp(string3,"table"))
				{
				//printf("create\t);
				//printf("database\t");
				strcmp(temp1->value,"id");
				temp1->ind = id;
				push(temp1);
				strcmp(temp1->value,"(");
				temp1->ind = open_brac;
				push(temp1);
				temp1->ind = COLUMN;
				strcmp(temp1->value,"COLUMN");
				push(temp1);
				}
			else if(!strcmp(string3,"database"))
				{
				//printf("create\t");
				//printf("database\t");
				strcmp(temp1->value,id);
				temp1->ind = id;
				push(temp1);
				}
			break;
			}
		case 6:
			{
			strcmp(temp1->value,"id");
			temp1->ind = id;
			push(temp1);
			}
		case 8:
			/* not done completely */
			{
			int len = strlen(string);
			int i;
			for(i=0;i<len;i++)	
				{
				char c = string[i];
				if((c>='a' && c<='z')||c=='_')
					{
					}
				else
					{
					printf("invalid id token, should only contain values from a to z or _\n");
					}
				}
			fscanf(fp,"%s %s %s",line_number,string3,string4);
			if(!(strcmp(string3,"int") || strcmp(string3,"decimal") || strcmp(string3,"varchar")))
				{
				if(!(strcmp(string3,"varchar")))
					{
					fscanf(fp,"%s %s %s",line_number,string3,string4);
					if(!(strcmp(string3,"("))
						{
						fscanf(fp,"%s %s %s",line_number,string3,string4);
						len = strlen(string3)
						for(i=0;i<len;i++)
							{
							char c = string[i];
							if(c>='0' && c<='9')
								{
								}
							else
								{
								printf("wrong declaration of varchar\n");
								}
							}
						fscanf(fp,"%s %s %s",line_number,string3,string4);
						if((strcmp(string3,")"))
							{
							printf("wrong declaration of varchar\n");
							}	
					
						}
					}
				}
			else
				{
				printf("data type needed\n");
				}
			break;
			}
		case 11:	
			{
			break;
			}
		}
	}


int pop()
{
	struct node temp;
	strcpy(temp.value,stack[index1].value);
	temp.ind = stack[index1].ind;
	index1--;
	return temp.ind;
	}

void push(struct node *arr)
	{
	index1++;
	strcpy(stack[index1].value,arr->value);
	stack[index1].ind = arr->ind;
	//free(arr);
	}


main()
	{
	fp = fopen("symbol_table","r");
	//char string[25];
	//char tab[1];
	//char string2[30];
	//int line_number;

	//farr[0] = func1;


	int i;
	char str2[7] = "func";
	char str[2];
	
	//(*farr[0])();
	
	 arr[START] [begin-100] = 1;
	 arr[START] [dollar-100] = 0;
	 arr[STMTLIST] [create-100] = 5;
	 arr[STMTLIST] [update-100] = 19;
	 arr[STMTLIST] [use-100] = 6;
	 arr[STMTLIST] [alter-100] = 11;
	 arr[STMTLIST] [insert-100] = 14;
	 arr[STMTLIST] [select-100] = 15;
	 arr[STMTLIST] [delete-100] = 17;
	 arr[STMTLIST] [drop-100] = 18;
	 arr[STMTLIST] [update-100] = 19;
	 arr[STMTLIST] [if_kw-100] = 2;
	 arr[STMTLIST] [for_kw-100] = 2;
	 arr[STMTLIST] [while_kw-100] = 2;
	 //STMTLIST dollar = 2;
	 arr[STMTLIST] [end-100] = 4;

	 arr[STMT] [create-100] = 5;
	 arr[STMT] [update-100] = 19;
	 arr[STMT] [use-100] = 6;
	 arr[STMT] [alter-100] = 11;
	 arr[STMT] [insert-100] = 14;
	 arr[STMT] [select-100] = 15;
	 arr[STMT] [delete-100] = 17;
	 arr[STMT] [drop-100] = 18;
	 arr[STMT] [update-100] = 19;
	 arr[STMT] [if_kw-100] = 3;
	 arr[STMT] [for_kw-100] = 3;
	 arr[STMT] [while_kw-100] = 3;
	 //STMT dollar = 4;
	 
	 arr[CREATE_DB] [create-100] = 5;
	 arr[CREATE_DB] [database-100] = 0;
	 arr[CREATE_DB] [id-100] = 0;
	
	
	 arr[USE_STMT] [use-100] = 6;
	 arr[USE_STMT] [id-100] = 0;
	
	// arr[CREATE_STMT] [create-100] = 7;
	 arr[CREATE_STMT] [table-100] = 0;
	 arr[CREATE_STMT] [open_brac-100] = 0;
	 arr[CREATE_STMT] [close_brac-100] = 0;
	
	 arr[COLUMN] [id-100] = 8;
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
	arr[CONSTRAINT] [primary_key-100] = 0;
	arr[CONSTRAINT] [id-100] = 0;
 	
	arr[COL] [id-100] = 13;
	arr[COL] [semicolon-100] = 0;

	arr[INSERT_STMT] [insert-100] = 14;
	arr[INSERT_STMT] [into-100] = 0;
	arr[INSERT_STMT] [id-100] = 0;
	arr[INSERT_STMT] [values-100] = 0;
	arr[INSERT_STMT] [open_brac-100] = 0;
	arr[INSERT_STMT] [semicolon-100] = 0;
	
	arr[VALS] [id-100] = 0;
	arr[VALS] [num-100] = 0;
 /* num me we check if it is number or decimal */
	arr[VALS] [close_brac-100] = 0;

	arr[SELECT_STMT] [select-100] = 15;
	arr[SELECT_STMT] [mul-100] = 0;
	arr[SELECT_STMT] [from-100] = 0;
	arr[SELECT_STMT] [id-100] = 0;
/* in select funstion we'll do a look ahead */
	//printf("%s",string);
	arr[SEARCH_CND] [id-100] = 16;
	arr[SEARCH_CND] [relop-100] = 0;
	arr[SEARCH_CND] [semicolon-100] = 0;

 	arr[DELETE_STMT] [delete-100] = 17;
	arr[DELETE_STMT] [from-100]  = 0;
	arr[DELETE_STMT] [id-100] = 0;
	arr[DELETE_STMT] [where-100] = 0;
	
	arr[DROP_TABLE] [drop-100] = 18;
	arr[DROP_TABLE] [id-100] = 0;

	arr[UPDATE_STMT] [update-100] = 19;
	arr[UPDATE_STMT] [id-100] = 0;
	arr[UPDATE_STMT] [where-100] = 0;
	
	arr[SET_STMT] [set-100] = 20;
	arr[SET_STMT] [where-100] = 0;

	/*EXPN*/
	struct node *first;
	first->ind = 0;
	strcmp(first->value,"START");
	push(first);
	
	fscanf(fp,"%s %s %s %s",string,string,string,string);
	fscanf(fp,"%s %s",string,string);
	//printf("%s",string);
	while(!feof(fp))
		{
		fscanf(fp,"%d %s %s",&line_number,string,string2);
		printf("%d %s %s\n",line_number,string,string2);

		d = pop();
		int go_to;
		// = arr[d] string;
		if(!strcmp(string,"begin"))
			{
			//printf("went here\n");
			go_to = arr[d][134-100];
			func(go_to);
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
		else if(!strcmp(string2,"variable_name"))
			{
			go_to = arr[d][2];
			func(go_to);
			}
		else if(!strcmp(string,"("))
			{
			go_to = arr[d][3];
			func(go_to);
			}
		else if(!strcmp(string,")"))
			{
			go_to = arr[d][4];
			func(go_to);
			}
		else if(!strcmp(string,"."))
			{
			go_to = arr[d][5];
			func(go_to);
			}
	else if(!strcmp(string2,"num"))
			{
			go_to = arr[d][6];
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
			go_to = arr[d][23];
			func(go_to);
			}
		else if(!strcmp(string,"where"))
			{
			go_to = arr[d][24];
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
		else if(!strcmp(string,";"))
			{
			go_to = arr[d][37];
			func(go_to);
			}
		else if(!strcmp(string,"*"))
			{
			go_to = arr[d][38];
			func(go_to);
			}
		else if(!strcmp(string,"-"))
			{
			go_to = arr[d][39];
			func(go_to);
			}
		else if(!strcmp(string,"/"))
			{
			go_to = arr[d][40];
			func(go_to);
			}
		else if(!strcmp(string,"%"))
			{
			go_to = arr[d][41];
			func(go_to);
			}
		else if(!strcmp(string,"<=")||!strcmp(string,"==")||!strcmp(string,">=")||!strcmp(string,"!=")||!strcmp(string,"<")||!strcmp(string,">"))
			{
			go_to = arr[d][42];
			func(go_to);
			}
		else if(!strcmp(string,"+"))
			{
			go_to = arr[d][43];
			func(go_to);
			}
		else if(!strcmp(string2,"invalid"))
			{
			printf("invalid symbol found in the symbol table\n");
			}
		if(go_to != -1 || go_to != 0)
			printf("gher\n");
		//(*farr[go_to])();
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
		printf("goimg for next loop\n");	
		}
	}


