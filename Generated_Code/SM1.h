/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : SM1.h
**     Project     : SORT
**     Processor   : MC9S08QE128CLK
**     Component   : SynchroMaster
**     Version     : Component 02.347, Driver 01.30, CPU db: 3.00.067
**     Compiler    : CodeWarrior HCS08 C Compiler
**     Date/Time   : 2017-11-18, 23:58, # CodeGen: 38
**     Abstract    :
**         This component "SynchroMaster" implements MASTER part of synchronous
**         serial master-slave communication.
**     Settings    :
**         Synchro type                : MASTER
**
**         Serial channel              : SPI1
**
**         Protocol
**             Init baud rate          : 2_5us
**             Clock edge              : rising
**             Width                   : 8 bits (always)
**             Empty character         : 0
**             Empty char. on input    : RECEIVED
**
**         Registers
**             Input buffer            : SPI1D     [$002D]
**             Output buffer           : SPI1D     [$002D]
**             Control register        : SPI1C1    [$0028]
**             Mode register           : SPI1C2    [$0029]
**             Baud setting reg.       : SPI1BR    [$002A]
**
**             Priority                : 
**
**             Priority                : 
**
**         Used pins                   :
**         ----------------------------------------------------------
**              Function    | On package |    Name
**         ----------------------------------------------------------
**               Input      |     70     |  PTE2_MISO1
**               Output     |     75     |  PTE1_MOSI1
**               Clock      |     76     |  PTE0_TPM2CLK_SPSCK1
**         ----------------------------------------------------------
**
**     Contents    :
**         RecvChar        - byte SM1_RecvChar(SM1_TComData *Chr);
**         SendChar        - byte SM1_SendChar(SM1_TComData Chr);
**         GetCharsInRxBuf - word SM1_GetCharsInRxBuf(void);
**         GetCharsInTxBuf - word SM1_GetCharsInTxBuf(void);
**         GetError        - byte SM1_GetError(SM1_TError *Err);
**
**     Copyright : 1997 - 2014 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file SM1.h
** @version 01.30
** @brief
**         This component "SynchroMaster" implements MASTER part of synchronous
**         serial master-slave communication.
*/         
/*!
**  @addtogroup SM1_module SM1 module documentation
**  @{
*/         

#ifndef __SM1
#define __SM1

/* MODULE SM1. */

#include "Cpu.h"



#define SM1_EOF 0x00U                  /* Value of the empty character defined in the Empty character property. */

#ifndef __BWUserType_SM1_TComData
#define __BWUserType_SM1_TComData
  typedef byte SM1_TComData;           /* User type for communication. */
#endif

#ifndef __BWUserType_SM1_TError
#define __BWUserType_SM1_TError
  /*lint -save  -esym(960,18.4) Disable MISRA rule (18.4) checking. */
  typedef union {
    byte err;
    struct {
      /*lint -save  -e46 Disable MISRA rule (6.4) checking. */
      bool OverRun  : 1;   /* OverRun error flag - the data overflow on the input has been detected. Both hardware detection (if supported) and software detection (when the value of Input buffer size property is 0) is used. */
      bool RxBufOvf : 1;   /* Rx buffer full error flag - the input circular buffer defined by the Input buffer size property has overrun. */
      bool FaultErr : 1;   /* Fault mode error flag - only if supported by hardware */
      /*lint -restore Enable MISRA rule (6.4) checking. */
    }errName;
  } SM1_TError;                        /* Error flags. For languages which don't support bit access is byte access only to error flags possible.  */
  /*lint -restore  +esym(960,18.4) Enable MISRA rule (18.4) checking. */
#endif




byte SM1_RecvChar(SM1_TComData *Chr);
/*
** ===================================================================
**     Method      :  SM1_RecvChar (component SynchroMaster)
**     Description :
**         If any data is received, this method returns one character,
**         otherwise it returns an error code (it does not wait for
**         data). 
**         For information about SW overrun behavior please see
**         <General info page>.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Chr             - A pointer to the received character
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK - The valid data is received.
**                           ERR_SPEED - This device does not work in
**                           the active speed mode.
**                           ERR_RXEMPTY - No data in receiver.
**                           ERR_OVERRUN - Overrun error was detected
**                           from the last char or block received. In
**                           polling mode, this error code is returned
**                           only when the hardware supports detection
**                           of the overrun error. If interrupt service
**                           is enabled, and input buffer allocated by
**                           the component is full, the component
**                           behaviour depends on <Input buffer size>
**                           property : if property is 0, last received
**                           data-word is preserved (and previous is
**                           overwritten), if property is greater than 0,
**                           new received data-word are ignored.
**                           ERR_FAULT - Fault error was detected from
**                           the last char or block received. In the
**                           polling mode the ERR_FAULT is return until
**                           the user clear the fault flag bit, but in
**                           the interrupt mode ERR_FAULT is returned
**                           only once after the fault error occured.
**                           This error is supported only on the CPUs
**                           supports the faul mode function - where
**                           <Fault mode> property is available.
** ===================================================================
*/

byte SM1_SendChar(SM1_TComData Chr);
/*
** ===================================================================
**     Method      :  SM1_SendChar (component SynchroMaster)
**     Description :
**         Sends one character to the channel.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Chr             - Character to send
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_DISABLED - Device is disabled (only if
**                           output DMA is supported and enabled)
**                           ERR_TXFULL - Transmitter is full
** ===================================================================
*/

word SM1_GetCharsInRxBuf(void);
/*
** ===================================================================
**     Method      :  SM1_GetCharsInRxBuf (component SynchroMaster)
**     Description :
**         Returns the number of characters in the input buffer.
**         Note: If the Interrupt service is disabled, and the Ignore
**         empty character is set to yes, and a character has been
**         received, then this method returns 1 although it was an
**         empty character.
**     Parameters  : None
**     Returns     :
**         ---             - Number of characters in the input buffer.
** ===================================================================
*/

word SM1_GetCharsInTxBuf(void);
/*
** ===================================================================
**     Method      :  SM1_GetCharsInTxBuf (component SynchroMaster)
**     Description :
**         Returns the number of characters in the output buffer.
**     Parameters  : None
**     Returns     :
**         ---             - Number of characters in the output buffer.
** ===================================================================
*/

byte SM1_GetError(SM1_TError *Err);
/*
** ===================================================================
**     Method      :  SM1_GetError (component SynchroMaster)
**     Description :
**         Returns a set of errors on the channel (errors that cannot
**         be returned in given methods). The component accumulates
**         errors in a set; after calling [GetError] this set is
**         returned and cleared. This method is available only if the
**         "Interrupt service/event" property is enabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Err             - A pointer to the returned set of errors
**     Returns     :
**         ---             - Error code (if GetError did not succeed),
**                           possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/

__interrupt void SM1_Interrupt(void);
/*
** ===================================================================
**     Method      :  SM1_Interrupt (component SynchroMaster)
**
**     Description :
**         The method services the error interrupt of the selected 
**         peripheral(s) and eventually invokes the component's event(s).
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

void SM1_Init(void);
/*
** ===================================================================
**     Method      :  SM1_Init (component SynchroMaster)
**
**     Description :
**         Initializes the associated peripheral(s) and the component 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/


/* END SM1. */

#endif /* ifndef __SM1 */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.09]
**     for the Freescale HCS08 series of microcontrollers.
**
** ###################################################################
*/
