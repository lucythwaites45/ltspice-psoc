#include <project.h>
#include <Timer_TS.h>
#include <isr_TS.h>
#include <LED.h>

CY_ISR(MYISR){
    uint8 datareg = LED_ReadDataReg();
    LED_Write(~datareg);
    Timer_TS_ReadStatusRegister();
}

int main(){
    
    Timer_TS_Start();
    isr_TS_StartEx(MYISR);
    
    for(;;){
    }
}
    

