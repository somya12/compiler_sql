//name at the top
//line number by counting \n
// sql case insensitive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int line=1;
char array[55][10]={"int","float","binary","char","varchar","single","double","decimal","array","date","select","from","distinct","where","and","or","order","by","insert","into","update","delete","like","in","between","join","inner","left","right","full","union","create","table","db","use","NULL","not","unique","primary","foreign","default","drop","alter","autoincrement","view","constant","if","else","for","while","each","declare","begin","end","procedure"};
void check_insert(char *word,FILE *fp)
	{
	printf("insode check insert\n %s\n",word);
	int i=0;
	char word1[25];
	int size = sizeof(array)/(sizeof(char)*10);
	for(i=0;i<55;i++)
		{
		if(!strcmp(word,array[i]))
			{
			if(i>=0 && i<=9)
				{
				strcpy(word1,word);
				strcat(word1,"data_type_");
				fputc('\n',fp);
				fprintf(fp,"%d %s %s %s",line,word1,"\t",word);
				return;
				}
			else if(i>9 && i<55)
				{
				strcpy(word1,word);
				strcat(word1,"key_word_");
				fputc('\n',fp); //instead of this in fprintf only \n can be written
				//printf("keywords\n");
				fprintf(fp,"%d %s %s %s",line,word1,"\t",word);
				return;
				}
			}
		}
	if((word[0]>='a' && word[0]<='z') || word[0]=='_')
		{
		fputc('\n',fp); //instead of this in fprintf only \n can be written
		fprintf(fp,"%d %s %s %s",line,word,"\t","variable_name");
		return;
		}
	else if(word[0]>='0' && word[0]<='9')
		{
		int j;
		fputc('\n',fp); //instead of this in fprintf only \n can be written
		fprintf(fp,"%d %s %s %s",line,word,"\t","num");
		return;
		}
	else if(!strcmp(word,"\n"))
		{
			printf("in this \n");
			return;
		}
	else if(!strcmp(word,"\0"))
		{
			printf("space\n");	
			return;
		}
	else
		{
		printf("hello\n");
		fputc('\n',fp);
		fprintf(fp,"%d %s %s %s",line,word,"\t","invalid");
		return;
		}
	}
int main()
{
FILE *fp = fopen("symbol_table","w");
FILE *fp_read = fopen("input","r");
char c=getc(fp_read);
long int j=0;
char word[25];
fprintf(fp,"%s %s %s %s\n","Apoorva","Navya","Ria","Somya");
fprintf(fp,"%s %s\n","input_file","input");
while(c != EOF)
{
c = tolower(c);
printf("inside while\n");
printf("%c %ld",c,ftell(fp_read));
	if(c==' ' || c=='\n')
		{
		word[j]='\0';
		check_insert(word,fp);
		if(c=='\n')
			line++;
		j=0;
		//printf("inside    \n");
		}
	else if(c==';')
		{
		printf("semi colon\n");
		word[j]='\0';
		//if(word!=NULL)
		check_insert(word,fp);
		fputc('\n',fp);
		printf("semi colon\n");
		fprintf(fp,"%d %s %s %s",line,";","\t","semi_colon");
		
		j=0;
		}	
	else if(c==',')
		{
		word[j]='\0';
		check_insert(word,fp);
		fputc('\n',fp);
		fprintf(fp,"%d %s %s %s",line,",","\t","comma");
		
		j=0;
		}
	else if(c==':')
		{
		word[j]='\0';
		check_insert(word,fp);
		fputc('\n',fp);
		if(getc(fp_read)=='=')
		fprintf(fp,"%d %s %s %s",line,":=","\t","assign_operator");
		
		j=0;
		}
	else if(c=='=')
		{
		word[j]='\0';
		check_insert(word,fp);
		fputc('\n',fp);
		if(getc(fp_read)=='=')
		fprintf(fp,"%d %s %s %s",line,"==","\t","equal_relation");
		
		j=0;
		}
	else if(c=='>')
		{
		word[j]='\0';
		check_insert(word,fp);
		fputc('\n',fp);
		char d=getc(fp_read);
		if(d=='=')
		fprintf(fp,"%d %s %s %s",line,">=","\t","greater_equal_relation");
		else if(d=='<')
		fprintf(fp,"%d %s %s %s",line,"><","\t","greater_less_relation");
		else
		fprintf(fp,"%d %s %s %s",line,">","\t","greater_relation");
		
		j=0;
		}
	else if(c=='<')
		{
		word[j]='\0';
		check_insert(word,fp);
		fputc('\n',fp);
		char d=getc(fp_read);
		if(d=='=')
		fprintf(fp,"%d %s %s %s",line,"<=","\t","less_equal_relation");
		else if(d=='<')
		fprintf(fp,"%d %s %s %s",line,"<>","\t","less_greater_relation");
		else
		fprintf(fp,"%d %s %s %s",line,"<","\t","less_relation");
		
		j=0;
		}
	else if(c=='!')
		{
		word[j]='\0';
		check_insert(word,fp);
		fputc('\n',fp);
		char d=getc(fp_read);
		if(d=='=')
		fprintf(fp,"%d %s %s %s",line,"=","\t","not_equal_relation");
		else
		fprintf(fp,"%d %s %s %s",line,"!","\t","not_operator");
		
		j=0;
		}
	else if(c=='+')	
		{
		word[j]='\0';
		check_insert(word,fp);
		fputc('\n',fp);
		fprintf(fp,"%d %s %s %s",line,"+","\t","add_operator");
		
		j=0;
		}
	else if(c=='-')
		{
		word[j]='\0';
		check_insert(word,fp);
		fputc('\n',fp);
		fprintf(fp,"%d %s %s %s",line,"-","\t","subtract_operator");
		
		j=0;
		}
	else if(c=='*')
		{
		word[j]='\0';
		check_insert(word,fp);
		fputc('\n',fp);
		printf("multiplication\n"); 
		fprintf(fp,"%d %s %s %s",line,"*","\t","multiplication_operator");
		
		j=0;
		}
	else if(c=='/')
		{
		word[j]='\0';
		check_insert(word,fp);
		fputc('\n',fp);
		fprintf(fp,"%d %s %s %s",line,"/","\t","division_operator");
		
		j=0;
		}
	else if(c=='%')
		{
		word[j]='\0';
		check_insert(word,fp);
		fputc('\n',fp);
		fprintf(fp,"%d %s %s %s",line,"%","\t","modulo_operator");
		
		j=0;
		}
	else if(c=='"')
		{
		word[j]='\0';
		check_insert(word,fp);
		fputc('\n',fp);
		fprintf(fp,"%d %s %s %s",line,"'","\t","string_opening_closing");
		
		j=0;
		}
	else if(c=='.')
		{
		word[j]='\0';
		check_insert(word,fp);
		fputc('\n',fp);
		fprintf(fp,"%d %s %s %s",line,".","\t","dot");
		
		j=0;
		}
	else if(c=='(')
		{
		word[j]='\0';
		check_insert(word,fp);
		fputc('\n',fp);
		fprintf(fp,"%d %s %s %s",line,"(","\t","open_bracket");
		
		j=0;
		}
	else if(c==')')
		{
		word[j]='\0';
		check_insert(word,fp);
		fputc('\n',fp);
		fprintf(fp,"%d %s %s %s",line,")","\t","close_bracket");
		
		j=0;
		}
	else
		{
		word[j]=c;
		printf("inside last else %c\n",word[j]);
		j++;
		}
	c=getc(fp_read);
}
fclose(fp);
fclose(fp_read);
}
