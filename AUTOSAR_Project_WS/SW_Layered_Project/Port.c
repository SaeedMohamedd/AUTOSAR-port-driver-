 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.c
 *
 * Description: Source file for Port Module.
 *
 * Author: Mohamed Tarek
 ******************************************************************************/
#include "Port.h"

#if (PORT_DEV_ERROR_DETECT == STD_ON)

#include "Det.h"
/* AUTOSAR Version checking between Det and Dio Modules */
#if ((DET_AR_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 || (DET_AR_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 || (DET_AR_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Det.h does not match the expected version"
#endif
#endif

STATIC Port_ConfigPins * Port_ConfigPin = NULL_PTR;
STATIC uint8 Port_Status = PORT_NOT_INITIALIZED;
/************************************************************************************
* Service Name: Port_Init
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): ConfigPtr - Pointer to configuration set
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Initializes the Port Driver module.
************************************************************************************/
void Port_Init(const Port_ConfigType *ConfigPtr)
{
	Port_PortType * DDR_Ptr = NULL_PTR;
	Port_PinNum  *  pin_num  = NULL_PTR;
		boolean error = FALSE;
#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* check if the input configuration pointer is not a NULL_PTR */
	if (NULL_PTR == ConfigPtr)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID,
		     PORT_E_PARAM_CONFIG);
	}
	else
#endif
		/* In-case there are no errors */
			if(FALSE == error)
			{
			  for(int i=0;i<PORTS_PINS_NUMBERS;i++)
			  {
				/* Point to the correct PORT register according to the Port Id stored in the Port_Num member */
				switch(Port_ConfigPin[i].port)
				{
					case 0:	DDR_Ptr = &DDRA_REG;
				        break;
					case 1:	DDR_Ptr = &DDRB_REG;
				        break;
					case 2:	DDR_Ptr = &DDRC_REG;
				        break;
					case 3:	DDR_Ptr = &DDRD_REG;
				        break;
				}
				/* Point to the correct PORT register according to the Port Id stored in the Port_Num member */
				switch(Port_ConfigPin[i].pin_num)
				{
					case 0:	pin_num = PinOne;
				        break;
					case 1:	pin_num = PinTwo;
				        break;
					case 2:	pin_num = PinThree;
				        break;
					case 3:	pin_num = PinFour;
				        break;
					case 4:	pin_num = PinFive;
				        break;
				    case 5:	pin_num = PinSix;
					    break;
					case 6:	pin_num = PinSeven;
					   break;
					case 7:	pin_num = PinEight;
					   break;
				}
				if(Port_ConfigPin[i].direction == OUTPUT)
				{
					/* Write Logic High */
					SET_BIT(*DDR_Ptr,*pin_num);
				}
				else if(Port_ConfigPin[i].direction== INPUT)
				{
					/* Write Logic Low */
					CLEAR_BIT(*DDR_Ptr,*pin_num);
				}
			}
		  }
			else
			{
				/* No Action Required */
			}

	{
		// Set the module state to initialized
		Port_Status       = PORT_INITIALIZED;

	}
}

/************************************************************************************
* Service Name: Port_SetPinDirection
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): Pin Port Pin ID number
*                  Direction Port Pin Direction
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Sets the port pin direction.
************************************************************************************/
/*
 * to store last pin direction for Refreash Function
 */
static uint8 g_Port_PinType;
static uint8  g_Port_PinDirectionType ;
static uint8  g_bool_first_use_PinDirection_test = FALSE ;
void Port_SetPinDirection(Port_PinType PinNumInTotalPinsNum,Port_PinDirectionType Direction)
{
	g_Port_PinType =PinNumInTotalPinsNum ;
	g_Port_PinDirectionType =Direction ;
	g_bool_first_use_PinDirection_test=TRUE;
if(PinNumInTotalPinsNum <= 7)
{
	if(Direction == OUTPUT)
	{
		/* Write Logic High */
		SET_BIT(DDRA_REG,PinNumInTotalPinsNum);
	}
	else if(Direction  == INPUT)
	{
		/* Write Logic Low */
		CLEAR_BIT(DDRA_REG,PinNumInTotalPinsNum);
	}
}
else if(PinNumInTotalPinsNum >7 && PinNumInTotalPinsNum <=15)
{
	if(Direction == OUTPUT)
	{

		/* Write Logic High */
		SET_BIT(DDRB_REG,(PinNumInTotalPinsNum-8));
	}
	else if(Direction  == INPUT)
	{
		/* Write Logic Low */
		CLEAR_BIT(DDRB_REG,(PinNumInTotalPinsNum-8));
	}
}
else if(PinNumInTotalPinsNum >15 && PinNumInTotalPinsNum <=23)
{
	if(Direction == OUTPUT)
	{
		/* Write Logic High */
		SET_BIT(DDRC_REG,(PinNumInTotalPinsNum-16));
	}
	else if(Direction  == INPUT)
	{
		/* Write Logic Low */
		CLEAR_BIT(DDRC_REG,(PinNumInTotalPinsNum-16));
	}
}
else if(PinNumInTotalPinsNum >23 && PinNumInTotalPinsNum <=31)
{
	if(Direction == OUTPUT)
	{
		/* Write Logic High */
		SET_BIT(DDRD_REG,(PinNumInTotalPinsNum-24));
	}
	else if(Direction  == INPUT)
	{
		/* Write Logic Low */
		CLEAR_BIT(DDRD_REG,(PinNumInTotalPinsNum-24));
	}
}
}

/************************************************************************************
* Service Name: Port_RefreshPortDirection
* Service ID[hex]: 0x02
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in):  None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description:Refreshes port direction
************************************************************************************/
void Port_RefreshPortDirection(void)
{
	if(g_bool_first_use_PinDirection_test == TRUE)
	{
	Port_SetPinDirection(g_Port_PinType,g_Port_PinDirectionType);
	}
}

/************************************************************************************
* Service Name: Port_GetVersionInfo
* Service ID[hex]: 0x03
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in):  None
* Parameters (inout): None
* Parameters (out): versioninfo - Pointer to where to store the version information of this module
* Return value: None
* Description:Returns the version information of this module
************************************************************************************/
#if (Port_GetVersionInfo == STD_ON)
void Port_GetVersionInfo(Std_VersionInfoType* versioninfo)
{
#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* Check if input pointer is not Null pointer */
	if(NULL_PTR == versioninfo)
	{
		/* Report to DET  */
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				PORT_GET_VERSION_INFO_SID,PORT_E_PARAM_POINTER);
	}
	else
#endif /* (PORT_DEV_ERROR_DETECT == STD_ON) */
	{
		/* Copy the vendor Id */
		versioninfo->vendorID = (uint16)PORT_VENDOR_ID;
		/* Copy the module Id */
		versioninfo->moduleID = (uint16)PORT_MODULE_ID;
		/* Copy Software Major Version */
		versioninfo->sw_major_version = (uint8)PORT_SW_MAJOR_VERSION;
		/* Copy Software Minor Version */
		versioninfo->sw_minor_version = (uint8)PORT_SW_MINOR_VERSION;
		/* Copy Software Patch Version */
		versioninfo->sw_patch_version = (uint8)PORT_SW_PATCH_VERSION;
	}
}
#endif


/************************************************************************************
* Service Name: Port_SetPinMode
* Service ID[hex]: 0x04
* Sync/Async: Synchronous
* Reentrancy:  Reentrant
* Parameters (in):  Pin Port Pin ID number
*                   Mode New Port Pin mode to be set on port pin.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description:Sets the port pin mode.
************************************************************************************/
void Port_SetPinMode(Port_PinType Pin,Port_PinModeType Mode)
{

}


