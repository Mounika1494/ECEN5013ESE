/*
 * led_config.c

 *
 *  Created on: Nov 9, 2016
 *      Author: moed4346
 */
#include <string.h>
#include "led.h"
#include "Message.h"
int str_cmp(char *s,char *d,int length)
{
	int i=0;
	while(i<length)
	{
		if(*(s+i)==*(d+i))
			i++;
		else
			return 1;
	}
	return 0;
}
void Led_config(CI_Msg *s)
{
	char str1[4],str2[4],str3[2];
        char b[]="blue";
	char r[]="red";
        char y[]="cyan";
	strncpy(str2,s->data,s->length);
		int r2=str_cmp(str2,b,(s->length-0x30));
		if(r2==0)
		{
		
	        Blue(32000);
		
		}
		int r1=str_cmp(str2,r,(s->length-0x30));
		if(r1==0)
		{
		
		Red(32000);
	    
		}
		int r3=str_cmp(str2,y,(s->length-0x30));
																											      if(r1==0)
		if(r3==0)
		{
		cyan(32000);
	        }
}


