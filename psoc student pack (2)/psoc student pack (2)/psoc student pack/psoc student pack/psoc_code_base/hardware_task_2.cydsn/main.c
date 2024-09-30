/* ========================================
 * Fully working code:
 * PWM      :
 * Encoder  :
 * ADC      :
 * USB      : port displays speed and position.
 * CMD: "PW xx"
 * Copyright Univ of Auckland, 2016
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF Univ of Auckland.
 *
 * ========================================
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <project.h>
#include <ADC.h>
#include <Timer_TS.h>
#include <isr_TS.h>
//* ========================================
#include "defines.h"
#include "vars.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
//* ========================================
void usbPutString(char *s);
void usbPutChar(char c);
void handle_usb();
//* ========================================
CY_ISR_PROTO(MyISR);

volatile uint16 result;
volatile uint8 num;
volatile uint8 i;
volatile uint16 result_array [20];

int main()
{
//    while(1)
//    {
//        LED_Write(~LED_Read());
//        CyDelay(2000);
//    }

// --------------------------------    
// ----- INITIALIZATIONS ----------
    CYGlobalIntEnable;

// ------USB SETUP ----------------    
#ifdef USE_USB    
    USBUART_Start(0,USBUART_5V_OPERATION);
#endif        
       
    RF_BT_SELECT_Write(0);

    ADC_Start();
    Timer_TS_Start();
   
    isr_TS_StartEx(MyISR);
    
    i=0;
   
   
    for(;;)
    {
        

       
        /* Place your application code here. */
        handle_usb();
        
        
        
        if (ADC_IsEndConversion(ADC_WAIT_FOR_RESULT) == 1)
        {
            
            result = ADC_GetResult16(1);
            result_array[i]=result;
            if (i==19){
                i=0;
            }
            
        }
        
        if (flag_KB_string == 1){
            for (int j = 0; j < 20; j++) {
                char buffer[10];
                snprintf(buffer, sizeof(buffer), "%d\n", result_array[j]);
                usbPutString(buffer);
            }
            flag_KB_string = 0; 
    }  
}
}

CY_ISR(MyISR){
    ADC_StartConvert();
    
    
    Timer_TS_ReadStatusRegister();
   
   
    }
//* ========================================
void usbPutString(char *s)
{
// !! Assumes that *s is a string with allocated space >=64 chars    
//  Since USB implementation retricts data packets to 64 chars, this function truncates the
//  length to 62 char (63rd char is a '!')

#ifdef USE_USB    
    while (USBUART_CDCIsReady() == 0);
    s[63]='\0';
    s[62]='!';
    USBUART_PutData((uint8*)s,strlen(s));
#endif
}
//* ========================================
void usbPutChar(char c)
{
#ifdef USE_USB    
    while (USBUART_CDCIsReady() == 0);
    USBUART_PutChar(c);
#endif    
}
//* ========================================
void handle_usb()
{
    // handles input at terminal, echos it back to the terminal
    // turn echo OFF, key emulation: only CR
    // entered string is made available in 'line' and 'flag_KB_string' is set
   
    static uint8 usbStarted = FALSE;
    static uint16 usbBufCount = 0;
    uint8 c;
   

    if (!usbStarted)
    {
        if (USBUART_GetConfiguration())
        {
            USBUART_CDC_Init();
            usbStarted = TRUE;
        }
    }
    else
    {
        if (USBUART_DataIsReady() != 0)
        {  
            c = USBUART_GetChar();

            if ((c == 13) || (c == 10))
            {
//                if (usbBufCount > 0)
                {
                    entry[usbBufCount]= '\0';
                    strcpy(line,entry);
                    usbBufCount = 0;
                    flag_KB_string = 1;
                }
            }
            else
            {
                if (((c == CHAR_BACKSP) || (c == CHAR_DEL) ) && (usbBufCount > 0) )
                    usbBufCount--;
                else
                {
                    if (usbBufCount > (BUF_SIZE-2) ) // one less else strtok triggers a crash
                    {
                       USBUART_PutChar('!');        
                    }
                    else
                        entry[usbBufCount++] = c;  
                }  
            }
        }
    }    
}


/* [] END OF FILE */
