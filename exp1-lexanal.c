#include <string.h>
#include <ctype.h>
#include <stdio.h>

void main() {
	FILE *f;
	f = fopen("input.txt", "r");
	char c, str[10];
	int n = 0, i = 0;
	while ((c = getc(f)) != EOF) {
		// Reading and ignoring comments "//" and "/*"
		if (c == '/') {
			c = getc(f);
			// Reading and ignoring comment "//"
			if (c == '/') {
				// ignoring characters after "//"
				while (c != '\n') {
					c = getc(f);
				}
			}
			// Reading and ignoring comment "/*"
			else if (c == '*') {
				do {
					// ignoring characters after "/*" till "*" is encountered
					while (c != '*') {
						c = getc(f);
					}
					// reads the remaining "/" character in "*/"
					c = getc(f);
				} while (c != '/');
			}
			// "/" is not followed by "*" or "/" i.e. not "//" or "/*"
			else {
				// ungetc puts back the character to the stream (here FILE*)
				ungetc(c, f);
				// "/" could be division operator then
				printf("/ is an operator\n");
			}
		}
		// Finished analysing cases of "/", "//", and "/*"
		// If c is a digit
		else if (isdigit(c)) {
			// convert digit from char -> int type
			// 48 is ASCII of 0
			n = c - 48;
			c = getc(f);
			while (isdigit(c)) {
				// convert digit from char -> int and append to "n"
				n = n * 10 + (c - 48);
				c = getc(f);
			}
			// prints number stored in "n"
			printf("%d is a number\n", n);
			// puts back the last read non digit char back to stream (while fail condition character)
			ungetc(c, f);
		}
		// If c is an alphabet 
		else if (isalpha(c)) {	
			str[i++] = c;
			c = getc(f);
			// the alphabet string can contain digit, alphabets, "_" and "$"
			while (isdigit(c) || isalpha(c) || c == '_' || c == '$') {
				// adding the character to "str" character array
				str[i++] = c;
				c = getc(f);
			}
			// Appending '\0' to the end to convert the char array to a null terminated string
			str[i++] = '\0';
			// compare with keywords
			if ( strcmp("auto",str)==0 || strcmp("break",str)==0||strcmp("case",str)==0||strcmp("char",str)==0|| strcmp("const",str)==0||strcmp("continue",str)==0||    strcmp("default",str)==0||strcmp("do",str) ==0||  strcmp("double",str)==0||strcmp("else",str )==0||strcmp("enum",str)==0||strcmp("extern", str)==0||strcmp("float",str)==0||strcmp("for", str)==0||strcmp("goto",str)==0||strcmp("if",str )==0||  strcmp("int",str)==0||strcmp("long",str)==0||strcmp("register",str)==0||strcmp("return ",str)==0||strcmp("short",str)==0||strcmp(" signed",str)==0||strcmp("sizeof",str)==0|| strcmp("static",str)==0||strcmp("struct",str) ==0||strcmp("switch",str)==0||strcmp("typedef", str)==0||strcmp("union",str)==0||strcmp(" unsigned",str)==0||strcmp("void",str)==0|| strcmp("volatile",str)==0||strcmp("while",str) ==0 ) {
				printf("%s is a keyword \n",str);
			} 
			else {
				printf("%s is a identifier \n",str);
			}
			// put back last read non alphabet, digit, _, $ character (while fail condition)
			ungetc(c, f);
			// set index of char array "str" back to 0 
			i = 0;
		}
		// read and store operator symbols to char array
		else if (c=='+'||c=='-'||c=='*'||c=='/'||c=='='||c=='>'||c=='<'||c=='!'||c=='&'||c=='|'||c=='^') {
			str[i++] = c;
			c = getc(f);
			while(c=='+'||c=='-'||c=='*'||c=='/'||c=='='||c=='>'||c=='<'||c=='!'||c=='&'||c=='|'|| c=='^') {
				str[i++]=c;
				c=getc(f); 
			}
			// make it a string
			str[i++] = '\0';
			// compare string with all operators 
			if(strcmp("+",str)==0||strcmp("-",str)==0||strcmp("*",str)==0||strcmp("/",str)==0||strcmp("=",str)==0||strcmp("!",str) ==0||strcmp("&",str)==0||strcmp("|",str)==0|| strcmp("^",str)==0||strcmp(">",str)==0||strcmp ("<",str)==0||strcmp("+=",str)==0||strcmp("-=", str)==0||strcmp("*=",str)==0||strcmp("/=",str) ==0||strcmp(" =",str)==0||strcmp("==",str)==0|| strcmp("!=",str)==0||strcmp(">=",str)==0|| strcmp("<=",str)==0||strcmp("&&",str)==0|| strcmp("||",str)==0||strcmp("<<",str)==0|| strcmp(">>",str)==0||strcmp("++",str)==0|| strcmp("--",str)==0) {
				printf("%s is a operator \n",str);
			} else {
				printf("%s is a invalid operator \n",str);
			}
			// put back last character (while fail condition)
			ungetc(c, f);
			// set index of char array abck to 0
			i = 0;
		}
		// skip space, tabs and newlines
		else if (c == ' ' || c == '\t' || c == '\n') {
			continue;
		}
		else {
			printf("%c is a special symbol \n",c);
		}
	}
	fclose(f);
}
