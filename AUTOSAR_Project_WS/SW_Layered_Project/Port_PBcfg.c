/*
 * Port_PBcfg.c
 *
 *  Created on: Nov 1, 2019
 *      Author: saed_
 */


#include "Port.h"

/*
 * Module Version 1.0.0
 */
#define PORT_PBCFG_SW_MAJOR_VERSION              (1U)
#define PORT_PBCFG_SW_MINOR_VERSION              (0U)
#define PORT_PBCFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_PBCFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define PORT_PBCFG_AR_RELEASE_MINOR_VERSION     (0U)
#define PORT_PBCFG_AR_RELEASE_PATCH_VERSION     (3U)

/* AUTOSAR Version checking between Port_PBcfg.c and Port.h files */
#if ((PORT_PBCFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_PBCFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_PBCFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of PBcfg.c does not match the expected version"
#endif

/* Software Version checking between Port_PBcfg.c and Port.h files */
#if ((PORT_PBCFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_PBCFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_PBCFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
  #error "The SW version of PBcfg.c does not match the expected version"
#endif

/* PB structure used with Port_Init API */
const Port_ConfigType Port_Configuration =
                                   {
                                    portA,PinOne,INPUT,DIO,
									portA,PinTwo,INPUT,DIO,
									portA,PinThree,INPUT,DIO,
									portA,PinFour,INPUT,DIO,
									portA,PinFive,INPUT,DIO,
									portA,PinSix,INPUT,DIO,
									portA,PinSeven,INPUT,DIO,
									portA,PinEight,INPUT,DIO,

									portB,PinOne,INPUT,DIO,
						    		portB,PinTwo,INPUT,DIO,
									portB,PinThree,INPUT,DIO,
									portB,PinFour,INPUT,DIO,
									portB,PinFive,INPUT,DIO,
									portB,PinSix,INPUT,DIO,
									portB,PinSeven,INPUT,DIO,
									portB,PinEight,INPUT,DIO,

									portC,PinOne,INPUT,DIO,
									portC,PinTwo,INPUT,DIO,
									portC,PinThree,INPUT,DIO,																		portB,PinFour,INPUT,DIO,
					     			portC,PinFive,INPUT,DIO,
									portC,PinSix,INPUT,DIO,
									portC,PinSeven,INPUT,DIO,
									portC,PinEight,INPUT,DIO,

									portD,PinOne,INPUT,DIO,
									portD,PinTwo,INPUT,DIO,
									portD,PinThree,INPUT,DIO,																		portB,PinFour,INPUT,DIO,
									portD,PinFive,INPUT,DIO,
									portD,PinSix,INPUT,DIO,
									portD,PinSeven,INPUT,DIO,
									portD,PinEight,INPUT,DIO,

								   };
