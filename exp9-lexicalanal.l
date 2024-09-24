identifier [a-zA-Z][a-zA-Z0-9]*
%%
#.* { printf("\n %s is a PREPROCESSOR DIRECTIVE",yytext);}
int |
float |
char |
double |
while |
for |
do |
if |
break |
continue |
void |
switch |
case |
long |
struct |
const |
typedef |
return |
else |
printf |
scanf |
goto {printf("\n\t %s is a KEYWORD",yytext);}
{identifier}\(\) {printf("\n\nFUNCTION\n\t %s",yytext);}
\{ { printf("\n BLOCK BEGINS");}
\} { printf("\n BLOCK ENDS");}
{identifier}(\[[0-9]*\])? { printf("\n %s IDENTIFIER",
yytext);}
[0-9]+ {printf("\n\t %s is a NUMBER",yytext);}
= {printf("\n\t %s is an ASSIGNMENT OPERATOR",yytext);}
\<= |
\>= |
\< |
== |
\!= |
\> { printf("\n\t %s is a RELATIONAL OPERATOR",yytext);}
\+ |
\- |
\* |
\% |
\/ {printf("\n\t %s is a ARITHMETIC OPERATOR",yytext);}
\; |
\: |
\, |
\" |
\\ |
\( |
\) |
\& |
\’ {printf("\n\t %s is a SPECIAL OPERATOR",yytext);}
\\n |
\\t |
\\0 | {printf("\n\t %s is a ESCAPE SEQUENCE",yytext);}
\%s |
\%f |
\%d |
\%c {printf("\n\t %s is a FORMAT SPECIFIER",yytext);} 
%%
int main()
{
FILE *file;
file = fopen("exp9-prg.c","r");
if(!file)
{
printf("could not open file \n");
exit(0);
}
yyin = file;
yylex();
return 0;
}
int yywrap()
{
return 1;
}
  
