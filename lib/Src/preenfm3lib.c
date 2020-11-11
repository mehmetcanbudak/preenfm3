/**
  ******************************************************************************
  * @file     lib.c
  * @author   Auto-generated by STM32CubeIDE
  * @version  V1.0
  * @date     23/02/2020 15:03:40
  * @brief    Default under dev library file.
  ******************************************************************************
*/

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"
#include "preenfm3_pins.h"
#include "adafruit_802_sd.h"
#include "fatfs.h"
/** Functions ----------------------------------------------------------------*/


void preenfm3LibInitGpio() {


    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /* GPIO Ports Clock Enable */
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOD_CLK_ENABLE();
    __HAL_RCC_GPIOE_CLK_ENABLE();
#ifdef LQFP144
    __HAL_RCC_GPIOF_CLK_ENABLE();
    __HAL_RCC_GPIOG_CLK_ENABLE();
#endif
    __HAL_RCC_GPIOH_CLK_ENABLE();


    /*Configure GPIO pin : HC165_DATA_Pin */
    GPIO_InitStruct.Pin = HC165_DATA_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(HC165_DATA_GPIO_Port, &GPIO_InitStruct);

#ifdef LQFP100_OLD
    /*Configure GPIO pin Output Level */
    HAL_GPIO_WritePin(GPIOE, HC165_CLK_Pin|HC165_LOAD_Pin|SD_CS_Pin|TFT_CS_Pin
                            |TFT_DC_Pin|TFT_RESET_Pin, GPIO_PIN_RESET);

    /*Configure GPIO pins : HC165_CLK_Pin HC165_LOAD_Pin SD_CS_Pin TFT_CS_Pin
                             TFT_DC_Pin TFT_RESET_Pin */
    GPIO_InitStruct.Pin = HC165_CLK_Pin|HC165_LOAD_Pin|SD_CS_Pin|TFT_CS_Pin
                            |TFT_DC_Pin|TFT_RESET_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

    // DEBUG LED BACKLIGHT
    /*Configure GPIO pin Output Level */

//    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET);
//    GPIO_InitStruct.Pin = GPIO_PIN_1;
//    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
//    GPIO_InitStruct.Pull = GPIO_NOPULL;
//    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
//    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
//
//    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_SET);

#endif

#ifdef LQFP100
    /*Configure GPIO D */
    HAL_GPIO_WritePin(GPIOD, HC165_CLK_Pin | HC165_LOAD_Pin, GPIO_PIN_RESET);

    GPIO_InitStruct.Pin = HC165_CLK_Pin | HC165_LOAD_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    /*Configure GPIO E */
    HAL_GPIO_WritePin(GPIOD, SD_CS_Pin | TFT_CS_Pin | TFT_DC_Pin | TFT_RESET_Pin, GPIO_PIN_RESET);
    GPIO_InitStruct.Pin = SD_CS_Pin | TFT_CS_Pin | TFT_DC_Pin | TFT_RESET_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);


    // DEBUG LED BACKLIGHT
    /*Configure GPIO pin Output Level */

//    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET);
//    GPIO_InitStruct.Pin = GPIO_PIN_1;
//    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
//    GPIO_InitStruct.Pull = GPIO_NOPULL;
//    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
//    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
//
//    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_SET);


#endif

#ifdef LQFP144
    /*Configure GPIO pin Output Level */
    HAL_GPIO_WritePin(GPIOE, SD_CS_Pin|LED_TEST_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_CONTROL_GPIO_Port, LED_CONTROL_Pin, GPIO_PIN_RESET);

    /*Configure GPIO pin Output Level */
    HAL_GPIO_WritePin(GPIOD, TFT_DC_Pin|TFT_RESET_Pin|TFT_CS_Pin|HC165_LOAD_Pin
                            |HC165_CLK_Pin, GPIO_PIN_RESET);

    /*Configure GPIO pins : SD_CS_Pin LED_Pin */
    GPIO_InitStruct.Pin = SD_CS_Pin | LED_TEST_Pin ;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

    /*Configure GPIO pins : TFT_DC_Pin TFT_RESET_Pin TFT_CS_Pin HC165_LOAD_Pin
                             HC165_LCK_Pin */
    GPIO_InitStruct.Pin = TFT_DC_Pin|TFT_RESET_Pin|TFT_CS_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);


    GPIO_InitStruct.Pin = HC165_LOAD_Pin | HC165_CLK_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = LED_CONTROL_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_MEDIUM;
    HAL_GPIO_Init(LED_CONTROL_GPIO_Port, &GPIO_InitStruct);


    HAL_GPIO_WritePin(GPIOE, LED_TEST_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED_CONTROL_GPIO_Port, LED_CONTROL_Pin, GPIO_PIN_SET);


#endif
}

void preenfm3ForceTftBacklight() {
#if defined(LQFP100) || defined(LQFP100_OLD)
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET);
    GPIO_InitStruct.Pin = GPIO_PIN_1;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_SET);
#endif


#ifdef LQFP144
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_RESET);
    GPIO_InitStruct.Pin = GPIO_PIN_11;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_SET);
#endif
}

uint32_t preenfm3LibInitSD() {
    uint32_t sdReturn = ADAFRUIT_802_SD_Init(0);
    uint32_t sdReturn2  = 0;
    if (sdReturn == 0) {
        sdReturn2 = f_mount(&USERFatFS, USERPath, 1);
    }
    return sdReturn + sdReturn2 * 1000;
}

