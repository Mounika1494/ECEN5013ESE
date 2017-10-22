#include "MKL25Z4.h"
#include<stdint.h>
#include<string.h>
#include"log.h"
#include<stdlib.h>

void start();
void TPM2_Setup();
int stop();


void my_ftoa(float n, char *res, int afterpoint);
int intToStr(int x, char str[], int d);
void reverse(char *str, int len);
int32_t my_atoi(int8_t *str);


void TPM2_Setup()
{
	SIM_BASE_PTR->SCGC6 |= SIM_SCGC6_TPM2_MASK;
	SIM_BASE_PTR->SOPT2 |= SIM_SOPT2_TPMSRC(1);
	TPM2_BASE_PTR->SC = TPM_SC_CMOD(1) | TPM_SC_PS(0);
	TPM2_BASE_PTR->MOD = 32000;
	TPM2_BASE_PTR->CONTROLS[0].CnSC=TPM_CnSC_MSB_MASK|TPM_CnSC_ELSA_MASK;
	TPM2_BASE_PTR->CONTROLS[0].CnV=TPM2_BASE_PTR->MOD;
}

void start()
{
	TPM2_Setup();
}

int stop()
{
	TPM2_BASE_PTR->SC = TPM_SC_CMOD(0);
	int count=TPM2_CNT;
	int x=count/21;
	return x;
}

void main()
{
	structure a;
	a.Buffer=d;
	a.HEAD=d;
	a.TAIL=d;
	float param=123.44;
	char par[10];
        start();
        my_ftoa(param,par,3);
        int time2=stop();
        char str1[]="time for ftoa in us :";
        int l1=strlen(str1);
        LOG1(str1,l1,time2,8);
	int y=0;


}

int32_t my_atoi(int8_t *str)
{
	if(str!=NULL)
	{
		while(*str!='\0')
		{
		if(*str>='0' && *str<='9' || *str=='-')
		{
			//printf("%d",*str);
		}
		else return 0;
		str++;
	}
	}
	*str=0;
}

void my_ftoa(float n, char *res, int afterpoint)
{
    // Extract integer part
    int ipart = (int)n;

    // Extract floating part
    float fpart = n - (float)ipart;

    // convert integer part to string
    int i = intToStr(ipart, res, 0);

    // check for display option after point
    if (afterpoint != 0)
    {
        res[i] = '.';  // add dot

        // Get the value of fraction part upto given no.
        // of points after dot. The third parameter is needed
        // to handle cases like 233.007
        fpart = fpart * pow(10, afterpoint);

        intToStr((int)fpart, res + i + 1, afterpoint);
    }
}
int intToStr(int x, char str[], int d)
{
    int i = 0;
    while (x)
    {
        str[i++] = (x%10) + '0';
        x = x/10;
    }

    // If number of digits required is more, then
    // add 0s at the beginning
    while (i < d)
        str[i++] = '0';

    reverse(str, i);
    str[i] = '\0';
    return i;
}
void reverse(char *str, int len)
{
    int i=0, j=len-1, temp;
    while (i<j)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++; j--;
    }
}
