/*******************************************************************************
* File Name: PIN_OUTPUT.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_PIN_OUTPUT_H) /* Pins PIN_OUTPUT_H */
#define CY_PINS_PIN_OUTPUT_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PIN_OUTPUT_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 PIN_OUTPUT__PORT == 15 && ((PIN_OUTPUT__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    PIN_OUTPUT_Write(uint8 value);
void    PIN_OUTPUT_SetDriveMode(uint8 mode);
uint8   PIN_OUTPUT_ReadDataReg(void);
uint8   PIN_OUTPUT_Read(void);
void    PIN_OUTPUT_SetInterruptMode(uint16 position, uint16 mode);
uint8   PIN_OUTPUT_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the PIN_OUTPUT_SetDriveMode() function.
     *  @{
     */
        #define PIN_OUTPUT_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define PIN_OUTPUT_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define PIN_OUTPUT_DM_RES_UP          PIN_DM_RES_UP
        #define PIN_OUTPUT_DM_RES_DWN         PIN_DM_RES_DWN
        #define PIN_OUTPUT_DM_OD_LO           PIN_DM_OD_LO
        #define PIN_OUTPUT_DM_OD_HI           PIN_DM_OD_HI
        #define PIN_OUTPUT_DM_STRONG          PIN_DM_STRONG
        #define PIN_OUTPUT_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define PIN_OUTPUT_MASK               PIN_OUTPUT__MASK
#define PIN_OUTPUT_SHIFT              PIN_OUTPUT__SHIFT
#define PIN_OUTPUT_WIDTH              1u

/* Interrupt constants */
#if defined(PIN_OUTPUT__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in PIN_OUTPUT_SetInterruptMode() function.
     *  @{
     */
        #define PIN_OUTPUT_INTR_NONE      (uint16)(0x0000u)
        #define PIN_OUTPUT_INTR_RISING    (uint16)(0x0001u)
        #define PIN_OUTPUT_INTR_FALLING   (uint16)(0x0002u)
        #define PIN_OUTPUT_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define PIN_OUTPUT_INTR_MASK      (0x01u) 
#endif /* (PIN_OUTPUT__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PIN_OUTPUT_PS                     (* (reg8 *) PIN_OUTPUT__PS)
/* Data Register */
#define PIN_OUTPUT_DR                     (* (reg8 *) PIN_OUTPUT__DR)
/* Port Number */
#define PIN_OUTPUT_PRT_NUM                (* (reg8 *) PIN_OUTPUT__PRT) 
/* Connect to Analog Globals */                                                  
#define PIN_OUTPUT_AG                     (* (reg8 *) PIN_OUTPUT__AG)                       
/* Analog MUX bux enable */
#define PIN_OUTPUT_AMUX                   (* (reg8 *) PIN_OUTPUT__AMUX) 
/* Bidirectional Enable */                                                        
#define PIN_OUTPUT_BIE                    (* (reg8 *) PIN_OUTPUT__BIE)
/* Bit-mask for Aliased Register Access */
#define PIN_OUTPUT_BIT_MASK               (* (reg8 *) PIN_OUTPUT__BIT_MASK)
/* Bypass Enable */
#define PIN_OUTPUT_BYP                    (* (reg8 *) PIN_OUTPUT__BYP)
/* Port wide control signals */                                                   
#define PIN_OUTPUT_CTL                    (* (reg8 *) PIN_OUTPUT__CTL)
/* Drive Modes */
#define PIN_OUTPUT_DM0                    (* (reg8 *) PIN_OUTPUT__DM0) 
#define PIN_OUTPUT_DM1                    (* (reg8 *) PIN_OUTPUT__DM1)
#define PIN_OUTPUT_DM2                    (* (reg8 *) PIN_OUTPUT__DM2) 
/* Input Buffer Disable Override */
#define PIN_OUTPUT_INP_DIS                (* (reg8 *) PIN_OUTPUT__INP_DIS)
/* LCD Common or Segment Drive */
#define PIN_OUTPUT_LCD_COM_SEG            (* (reg8 *) PIN_OUTPUT__LCD_COM_SEG)
/* Enable Segment LCD */
#define PIN_OUTPUT_LCD_EN                 (* (reg8 *) PIN_OUTPUT__LCD_EN)
/* Slew Rate Control */
#define PIN_OUTPUT_SLW                    (* (reg8 *) PIN_OUTPUT__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PIN_OUTPUT_PRTDSI__CAPS_SEL       (* (reg8 *) PIN_OUTPUT__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PIN_OUTPUT_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PIN_OUTPUT__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PIN_OUTPUT_PRTDSI__OE_SEL0        (* (reg8 *) PIN_OUTPUT__PRTDSI__OE_SEL0) 
#define PIN_OUTPUT_PRTDSI__OE_SEL1        (* (reg8 *) PIN_OUTPUT__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PIN_OUTPUT_PRTDSI__OUT_SEL0       (* (reg8 *) PIN_OUTPUT__PRTDSI__OUT_SEL0) 
#define PIN_OUTPUT_PRTDSI__OUT_SEL1       (* (reg8 *) PIN_OUTPUT__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PIN_OUTPUT_PRTDSI__SYNC_OUT       (* (reg8 *) PIN_OUTPUT__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(PIN_OUTPUT__SIO_CFG)
    #define PIN_OUTPUT_SIO_HYST_EN        (* (reg8 *) PIN_OUTPUT__SIO_HYST_EN)
    #define PIN_OUTPUT_SIO_REG_HIFREQ     (* (reg8 *) PIN_OUTPUT__SIO_REG_HIFREQ)
    #define PIN_OUTPUT_SIO_CFG            (* (reg8 *) PIN_OUTPUT__SIO_CFG)
    #define PIN_OUTPUT_SIO_DIFF           (* (reg8 *) PIN_OUTPUT__SIO_DIFF)
#endif /* (PIN_OUTPUT__SIO_CFG) */

/* Interrupt Registers */
#if defined(PIN_OUTPUT__INTSTAT)
    #define PIN_OUTPUT_INTSTAT            (* (reg8 *) PIN_OUTPUT__INTSTAT)
    #define PIN_OUTPUT_SNAP               (* (reg8 *) PIN_OUTPUT__SNAP)
    
	#define PIN_OUTPUT_0_INTTYPE_REG 		(* (reg8 *) PIN_OUTPUT__0__INTTYPE)
#endif /* (PIN_OUTPUT__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_PIN_OUTPUT_H */


/* [] END OF FILE */
