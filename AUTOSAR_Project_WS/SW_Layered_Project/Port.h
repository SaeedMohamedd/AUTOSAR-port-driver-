 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.h
 *
 * Description: Header file for Port Module.
 *
 * Author: Mohamed Tarek
 ******************************************************************************/

#ifndef PORT_H
#define PORT_H

#include "Common_Macros.h"
#include "Micro_Config.h"
#include "Port_Cfg.h"
#include "Std_Types.h"

/* Id for the company in the AUTOSAR
 * for example Mohamed Tarek's ID = 1000 :) */
#define PORT_VENDOR_ID    (1000U)

/* Port Module Id */
#define PORT_MODULE_ID    (130U)

/* Port Instance Id */
#define PORT_INSTANCE_ID  (0U)

/*
 * Module Version 1.0.0
 */
#define PORT_SW_MAJOR_VERSION           (1U)
#define PORT_SW_MINOR_VERSION           (0U)
#define PORT_SW_PATCH_VERSION           (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_AR_RELEASE_MAJOR_VERSION   (4U)
#define PORT_AR_RELEASE_MINOR_VERSION   (0U)
#define PORT_AR_RELEASE_PATCH_VERSION   (3U)


/* AUTOSAR checking between Std Types and Port Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif


/* AUTOSAR Version checking between Port_Cfg.h and Port.h files */
#if ((PORT_CFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Dio_Cfg.h does not match the expected version"
#endif

/* Software Version checking between Port_Cfg.h and Port.h files */
#if ((PORT_CFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_CFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_CFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
  #error "The SW version of Dio_Cfg.h does not match the expected version"
#endif


/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/
/* Service ID for Port_SetDirection */
#define Port_SetPinDirection_SID             (uint8)0x00
#define PORT_INIT_SID                        (uint8)0x01
#define Port_SetPinMode_SID                  (uint8)0x02
#define Port_GetVersionInfo_SID              (uint8)0x03
#define Port_RefreshPortDirection_SID        (uint8)0x04


/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/
/* DET code to report  Invalid Port Pin ID requested */
#define PORT_E_PARAM_PIN (uint8)0x0A

/* DET code to report Port Pin not configured as changeable */
#define PORT_E_DIRECTION_UNCHANGEABLE             (uint8)0x0B

/* DET code to report API Port_Init service */
#define  PORT_E_PARAM_CONFIG    (uint8)0x0C

/* DET code to report API Port_SetPinMode service called when mode is unchangeable */
#define PORT_E_PARAM_INVALID_MODE       (uint8)0x0D
#define PORT_E_MODE_UNCHANGEABLE       (uint8)0x0E

/* DET code to report API service called without module initialization */
#define  PORT_E_UNINIT    (uint8)0x0F

/* DET code to report APIs called with a Null Pointer */
#define  PORT_E_PARAM_POINTER    (uint8)0x10

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

/*************************************************************************/
/* Description: Different port pin modes
 *	A port pin shall be configurable with a number of port pin modes (type
 *  Port_PinModeType).
 */
typedef enum{
	DIO,UART,SPI
}Port_PinModeType ;

/*************************************************************************/
/* Description: Data type for the symbolic name of a port pin
 *	The type Port_PinType shall be used for the symbolic name of a Port
 *  Pin.
 */
typedef uint8 Port_PortType  ;

/*************************************************************************/
/* Description: Data type for the symbolic number of a port pin
 *	The type Port_PinType shall be used for the symbolic pins number in port.
 */
typedef uint8 Port_PinNum  ;

/*************************************************************************/
/* Description: Data type for the symbolic number of a port pin
 *	The type Port_PinType shall be used for the symbolic pins number in microcontroller.
 */
typedef uint8 Port_PinType  ;

/***********************************************************************/
/* Description: Structure to describe Possible directions of a port pin.
 *	The type Port_PinDirectionType is a type for defining the direction
 *  of a Port Pin
 */
typedef enum{
	PORT_PIN_IN,PORT_PIN_OUT
}Port_PinDirectionType;


/*******************************************************************************/
/* Description: Structure to describe each individual PIN contains:
 *	1. the PORT Which the pin belongs to. 0, 1, 2 or 3
 *	2. the number of the pin in the PORT.
 *  3. the direction of pin --> INPUT or OUTPUT
 *  4. the mode of the pin
 */
typedef struct
{
	uint8 port;
	uint8 pin_num;
	uint8 direction;
	Port_PinModeType pin_mode;
}Port_ConfigPins;


typedef struct
{
	Port_ConfigPins Pins[PORTS_PINS_NUMBERS];
}Port_ConfigType;


/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/
/*shall initialize ALL ports and port pins with the
configuration set pointed to by the parameter ConfigPtr.*/

void Port_Init(const Port_ConfigType *ConfigPtr);

/* configure the PIN to input or output pin */
void Port_SetPinDirection(Port_PinType Pin,Port_PinDirectionType Direction);

/***********************************************************************************
* Description:Refreshes port direction
************************************************************************************/
void Port_RefreshPortDirection(void);

/***********************************************************************************
* Description:Sets the port pin mode.
************************************************************************************/
void Port_SetPinMode(Port_PinType Pin,Port_PinModeType Mode);

/* Function for PORT Get Version Info API */
#if (PORT_VERSION_INFO_API == STD_ON)
void PORT_GetVersionInfo(Std_VersionInfoType *versioninfo);
#endif

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

/* Extern PB structures to be used by Dio and other modules */
extern const Port_ConfigType Port_Configuration;


/***************************************************************************************************************/



#endif /* PORT_H */
