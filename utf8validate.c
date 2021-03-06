 //utf8validate
#include <stdio.h>
int main(void){
int i,ch,codepoint,ASCII=0,MULTIB=0;

while ((ch=getchar())!=EOF){

	if ((ch&0x80)==0){	//the header byte points to a 1 byte encoding so i dont have to check anything
		codepoint=ch;
		ASCII++;	//i found an ASCII encoding
	}
//.............................................................................................................................................	
	else{
		 if ((ch&0xE0)==0xC0){	//the header byte points to a 2 bytes encoding
			codepoint=(ch&0x1F);	//i keep the first 5 bits
			
			if((ch=getchar())==EOF){	//i get the next byte (tail byte) and it's EOF
				printf("Unexpected EOF\n");
				return 1;	//i got EOF unexpectedly so i stop and return 1
			}
			if ((ch&0xC0)!=0x80){	//i get the next byte (tail byte) and it's not 10xxxxxx
				printf("Invalid UTF-8 tail byte: 0x%02X\n",ch);
				return 2;	//i got ivalid tail byte so i stop and return 2
			}
			codepoint<<=6;	//i make space for the next 6 bits
			codepoint+=(ch&0x3F);
		
			if(codepoint<0x80){	//i check if it's oversized
			printf("Oversised UTF-8 code point: U+%04X\n",codepoint);
			return 5;
			}
			else{
			MULTIB++;	//i found encoding of >=2 bytes	
			}
		}
//.............................................................................................................................................	
		else if ((ch&0xF0)==0xE0){	//the header byte points to a 3 bytes encoding
			codepoint=(ch&0x0F);	//i keep the first 4 bits
			
			for(i=1;i<=2;i++){
				if((ch=getchar())==EOF){	//i get the next byte (tail byte) and it's EOF
					printf("Unexpected EOF\n");
					return 1;	//i got EOF unexpectedly so i stop and return 1
				}
				if ((ch&0xC0)!=0x80){	//i get the next byte (tail byte) and it's not 10xxxxxx
					printf("Invalid UTF-8 tail byte, 0x%02X\n",ch);
					return 2;	//i got ivalid tail byte so i stop and return 2
				}
				codepoint<<=6;	//i make space for the next 6 bits
				codepoint+=(ch&0x3F);
			}
			
			
			
			if(codepoint>=0xD800&&codepoint<=0xDFFF){	//i check if i'm inside the limits
				printf("Invalid UTF-8 code point: U+%04X\n",codepoint);
				return 3;
			}
	
			if(codepoint<0x800){	//i check if it's oversized
			printf("Oversised UTF-8 code point: U+%04X\n",codepoint);
			return 5;
			}
			else{
			MULTIB++;	//i found encoding of >=2 bytes	
			}
}
//............................................................................................................................	
		else if ((ch&0xF8)==0xF0){	//the header byte point to a 4 bytes encoding
			codepoint=(ch&0x07);	//i keep the first 3 bits
		
			for(i=1;i<=3;i++){
				if((ch=getchar())==EOF){	//i get the next byte (tail byte) and it's EOF
					printf("Unexpected EOF\n");
					return 1;	//i got EOF unexpectedly so i stop and return 1
				}
				if ((ch&0xC0)!=0x80){	//i get the next byte (tail byte) and it's not 10xxxxxx
					printf("Invalid UTF-8 tail byte: 0x%02X\n",ch);
					return 2;	//i got ivalid tail byte so i stop and return 2
				}
				codepoint<<=6;	//i make space for the next 6 bits
				codepoint+=(ch&0x3F);
			}
		
			if(codepoint>0x10FFFF){	//i check if i'm inside the limits
				printf("Invalid UTF-8 code point: U+%04X\n",codepoint);
				return 3;
			}
	
		if(codepoint<0x10000){	//i check if it's oversized
			printf("Oversised UTF-8 code point: U+%04X\n",codepoint);
			return 5;
		}
		else{
			MULTIB++;	//i found encoding of >=2 bytes	
		}
	
		}
		
		else{
			printf("Invalid UTF-8 header byte: 0x%2X\n",ch);
			return 4;	
		}
	
//...........................................................................................................................		
	}
 
}

printf("Found %d ASCII and %d multi-byte UTF-8 characters.\n", ASCII, MULTIB);

return 0;
}
