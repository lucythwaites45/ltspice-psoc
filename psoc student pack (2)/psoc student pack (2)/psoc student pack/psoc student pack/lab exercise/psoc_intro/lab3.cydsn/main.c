
/* ========================================
 * Laboratory Exercise 3
 *
 * Program timer to flash LED at 1Hz, use interrupts
 *
 * Copyright Univ of Auckland, 2016
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF Univ of Auckland.
 *
 * ========================================
*/
#include <project.h>
#include <Timer_1.h>
#include <Timer_2.h>
#include <isr_TC1.h>
#include <isr_TC2.h>
#include <LED.h>
#include <PIN_OUTPUT.h>
#include <PIN_OUTPUT_2.h>

uint8 output_flag1 = 0;
uint8 output_flag2 = 0;

CY_ISR(MyISR1){
    
    uint8 datareg = PIN_OUTPUT_ReadDataReg();
    PIN_OUTPUT_Write(~datareg);
    
    Timer_1_ReadStatusRegister();
    
}

CY_ISR(MyISR2){
    
    uint8 datareg = PIN_OUTPUT_2_ReadDataReg();
    PIN_OUTPUT_2_Write(~datareg);
    
    
    Timer_2_ReadStatusRegister();
    
}

int main()
{
    
    Timer_1_Start();
    Timer_2_Start();
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    isr_TC1_StartEx(MyISR1);
    isr_TC2_StartEx(MyISR2);
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        /* Place your application code here. */
        
        
        
    }
}

/* [] END OF FILE */
