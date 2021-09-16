/*
 * port_cfg.h
 *
 *  Created on: Oct 31, 2019
 *      Author: saed_
 */

#ifndef PORT_CFG_H_
#define PORT_CFG_H_

/*
 * Module Version 1.0.0
 */
#define PORT_CFG_SW_MAJOR_VERSION              (1U)
#define PORT_CFG_SW_MINOR_VERSION              (0U)
#define PORT_CFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define PORT_CFG_AR_RELEASE_MINOR_VERSION     (0U)
#define PORT_CFG_AR_RELEASE_PATCH_VERSION     (3U)

/* Pre-compile option for Development Error Detect */
#define PORT_DEV_ERROR_DETECT                (STD_ON)

/* Pre-compile option for Version Info API */
#define PORT_VERSION_INFO_API                (STD_OFF)

/* Number of MCU Pins */
#define PORTS_PINS_NUMBERS             (32U)


/* macro  for port you can change depend on the architecture  */
#define INPUT     (0U)   // 0 -> pin will be input
#define OUTPUT    (1U)  //  1 -> pin will be output


/*
 * Macros for Port Status
 */
#define PORT_INITIALIZED                (1U)
#define PORT_NOT_INITIALIZED            (0U)


/* Definition for PORTA Registers */
#define PORTA_REG	(*(volatile uint8 *)0x003B)
#define DDRA_REG	(*(volatile uint8 *)0x003A)
#define PINA_REG 	(*(volatile uint8 *)0x0039)

/* Definition for PORTB Registers */
#define PORTB_REG	(*(volatile uint8 *)0x0038)
#define DDRB_REG	(*(volatile uint8 *)0x0037)
#define PINB_REG 	(*(volatile uint8 *)0x0036)

/* Definition for PORTC Registers */
#define PORTC_REG	(*(volatile uint8 *)0x0035)
#define DDRC_REG	(*(volatile uint8 *)0x0034)
#define PINC_REG 	(*(volatile uint8 *)0x0033)

/* Definition for PORTD Registers */
#define PORTD_REG	(*(volatile uint8 *)0x0032)
#define DDRD_REG	(*(volatile uint8 *)0x0031)
#define PIND_REG 	(*(volatile uint8 *)0x0030)

/*
 * Macros for PORT MUMBER TYPE
 */
#define portA 0
#define portB 1
#define portC 2
#define portD 3


/*pin index in array structure*/
#define PortConfig_PINA0_ID_INDEX 0
#define PortConfig_PINA1_ID_INDEX 1
#define PortConfig_PINA2_ID_INDEX 2
#define PortConfig_PINA3_ID_INDEX 3
#define PortConfig_PINA4_ID_INDEX 4
#define PortConfig_PINA5_ID_INDEX 5
#define PortConfig_PINA6_ID_INDEX 6
#define PortConfig_PINA7_ID_INDEX 7

#define PortConfig_PINB0_ID_INDEX 8
#define PortConfig_PINB1_ID_INDEX 9
#define PortConfig_PINB2_ID_INDEX 10
#define PortConfig_PINB3_ID_INDEX 11
#define PortConfig_PINB4_ID_INDEX 12
#define PortConfig_PINB5_ID_INDEX 13
#define PortConfig_PINB6_ID_INDEX 14
#define PortConfig_PINB7_ID_INDEX 15

#define PortConfig_PINC0_ID_INDEX 16
#define PortConfig_PINC1_ID_INDEX 17
#define PortConfig_PINC2_ID_INDEX 18
#define PortConfig_PINC3_ID_INDEX 19
#define PortConfig_PINC4_ID_INDEX 20
#define PortConfig_PINC5_ID_INDEX 21
#define PortConfig_PINC6_ID_INDEX 22
#define PortConfig_PINC7_ID_INDEX 23

#define PortConfig_PIND0_ID_INDEX 24
#define PortConfig_PIND1_ID_INDEX 25
#define PortConfig_PIND2_ID_INDEX 26
#define PortConfig_PIND3_ID_INDEX 27
#define PortConfig_PIND4_ID_INDEX 28
#define PortConfig_PIND5_ID_INDEX 29
#define PortConfig_PIND6_ID_INDEX 30
#define PortConfig_PIND7_ID_INDEX 31

/* pins order */
#define PinOne      0
#define PinTwo      1
#define PinThree    2
#define PinFour     3
#define PinFive     4
#define PinSix      5
#define PinSeven    6
#define PinEight    7

#endif /* PORT_CFG_H_ */
