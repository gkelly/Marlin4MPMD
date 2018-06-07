/**
  ******************************************************************************
  * @file    USB_Device/CDC_Standalone/Inc/usbd_cdc_interface.h
  * @author  MCD Application Team
  * @brief   Header for usbd_cdc_interface.c file.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2016 STMicroelectronics International N.V. 
  * All rights reserved.</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without 
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice, 
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other 
  *    contributors to this software may be used to endorse or promote products 
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this 
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under 
  *    this license is void and will automatically terminate your rights under 
  *    this license. 
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS" 
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT 
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT 
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USBD_CDC_IF_H
#define __USBD_CDC_IF_H

/* Includes ------------------------------------------------------------------*/
#include "usbd_cdc.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* User can use this section to tailor USARTx/UARTx instance used and associated 
   resources */
/* Definition for USARTx clock resources */
//#define USARTx                           USART2
//#define USARTx_CLK_ENABLE()              __USART2_CLK_ENABLE();
//#define DMAx_CLK_ENABLE()                __HAL_RCC_DMA1_CLK_ENABLE()
//#define USARTx_RX_GPIO_CLK_ENABLE()      __GPIOA_CLK_ENABLE()
//#define USARTx_TX_GPIO_CLK_ENABLE()      __GPIOA_CLK_ENABLE()

//#define USARTx_FORCE_RESET()             __USART2_FORCE_RESET()
//#define USARTx_RELEASE_RESET()           __USART2_RELEASE_RESET()

/* Definition for USARTx Pins */
//#define USARTx_TX_PIN                    GPIO_PIN_2
//#define USARTx_TX_GPIO_PORT              GPIOA
//#define USARTx_TX_AF                     GPIO_AF1_USART2
//#define USARTx_RX_PIN                    GPIO_PIN_3
//#define USARTx_RX_GPIO_PORT              GPIOA
//#define USARTx_RX_AF                     GPIO_AF1_USART2

     
/* Definition for USARTx's NVIC: used for receiving data over Rx pin */
//#define USARTx_IRQn                      USART2_IRQn
//#define USARTx_IRQHandler                USART2_IRQHandler

/* Definition for USARTx's DMA */
//#define USARTx_TX_DMA_STREAM              DMA1_Channel4
//#define USARTx_RX_DMA_STREAM              DMA1_Channel5

/* Definition for USARTx's NVIC */
//#define USARTx_DMA_TX_RX_IRQn             DMA1_Channel4_5_IRQn
//#define USARTx_DMA_TX_RX_IRQHandler       DMA1_CH4_5_IRQHandler

/* Definition for TIMx clock resources */
#define TIMx                             TIM6
#define TIMx_CLK_ENABLE                  __HAL_RCC_TIM6_CLK_ENABLE
//TODO: revisit this, this seems like a bug in the STM example but setting it to TIM6 breaks things
#define TIMx_FORCE_RESET()               /*__HAL_RCC_TIM6_FORCE_RESET()*/
#define TIMx_RELEASE_RESET()             /*__HAL_RCC_TIM6_RELEASE_RESET()*/

/* Definition for TIMx's NVIC */
#define TIMx_IRQn                        TIM6_IRQn
#define TIMx_IRQHandler                  TIM6_IRQHandler

/* Periodically, the state of the buffer "UserTxBuffer" is checked.
   The period depends on CDC_POLLING_INTERVAL */
#define CDC_POLLING_INTERVAL             5 /* in ms. The max is 65 and the min is 1 */

extern USBD_CDC_ItfTypeDef  USBD_CDC_fops;

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
uint8_t CDC_Itf_SetTxBuffer(uint8_t *Buf, uint32_t *Len);
uint8_t CDC_Itf_Transmit(uint32_t *Len);

#endif /* __USBD_CDC_IF_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
