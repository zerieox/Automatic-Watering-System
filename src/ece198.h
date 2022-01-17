// Header file for ece198.c

// Written by Bernie Roehl, July 2021

#include "stm32f4xx_hal.h"

void InitializePin(GPIO_TypeDef *port, uint16_t pins, uint32_t mode, uint32_t pullups, uint8_t alternate);

HAL_StatusTypeDef SerialSetup(uint32_t baudrate);

char SerialGetc();
void SerialGets(char *buff, int maxlen);

void SerialPutc(char c);
void SerialPuts(char *ptr);

// macro for reading an entire port (we provide this so students don't need to know about structs)
#define ReadPort(port) (port->IDR)

int ReadEncoder(GPIO_TypeDef *clkport, int clkpin, GPIO_TypeDef *dtport, int dtpin, bool *previous);

void InitializePWMTimer(TIM_HandleTypeDef *timer, TIM_TypeDef *whichTimer, uint16_t period, uint16_t prescale);
void InitializePWMChannel(TIM_HandleTypeDef *timer, uint32_t channel);
void SetPWMDutyCycle(TIM_HandleTypeDef *timer, uint32_t channel, uint32_t value);

void InitializeKeypad();
int ReadKeypad();

void Initialize7Segment();
void Display7Segment(int digit);

void InitializeADC(ADC_HandleTypeDef* adc, ADC_TypeDef* whichAdc);
uint16_t ReadADC(ADC_HandleTypeDef* adc, uint32_t channel);