
#ifndef __DEFINES_H_
#define __DEFINES_H_

#define __I     volatile    // defines 'read only' permissions
#define __O     volatile    // defines 'write only' permissions
#define __IO    volatile    // defines 'read/write' permissions

typedef uint64_t  u64;
typedef uint32_t  u32;
typedef uint16_t  u16;
typedef uint8_t   u8;

// memory mapped structure for SysTick
typedef struct
{   __IO u32 CTLR;  // 0x00
    __IO u32 SR;    // 0x04
    __IO u64 CNT;   // 0x08
    __IO u64 CMP;   // 0x0C
} SysTick_Type;

// Reset and Clock Control
typedef struct
{   __IO uint32_t CTLR;       // 0x00
    __IO uint32_t CFGR0;      // 0x04
    __IO uint32_t INTR;       // 0x08
    __IO uint32_t APB2PRSTR;  // 0x0C
    __IO uint32_t APB1PRSTR;  // 0x10
    __IO uint32_t AHBPCENR;   // 0x14
    __IO uint32_t APB2PCENR;  // 0x18
    __IO uint32_t APB1PCENR;  // 0x1C
    __IO uint32_t BDCTLR;     // 0x20
    __IO uint32_t RSTSCKR;    // 0x24
    __IO uint32_t AHBRSTR;    // 0x28
    __IO uint32_t CFGR2;      // 0x2C
} RCC_TypeDef;

// General Purpose I/O
typedef struct
{   __IO uint32_t CFGLR;  // 0x00
    __IO uint32_t CFGHR;  // 0x04
    __IO uint32_t INDR;   // 0x08
    __IO uint32_t OUTDR;  // 0x0C
    __IO uint32_t BSHR;   // 0x10
    __IO uint32_t BCR;    // 0x14
    __IO uint32_t LCKR;   // 0x18
} GPIO_TypeDef;

// Enhanced Registers
typedef struct
{   __IO uint32_t EXTEN_CTR;  // 0x00
} EXTEN_TypeDef;

/* Universal Synchronous Asynchronous Receiver Transmitter */
typedef struct
{   __IO uint16_t STATR;
    uint16_t  RESERVED0;
    __IO uint16_t DATAR;
    uint16_t  RESERVED1;
    __IO uint16_t BRR;
    uint16_t  RESERVED2;
    __IO uint16_t CTLR1;
    uint16_t  RESERVED3;
    __IO uint16_t CTLR2;
    uint16_t  RESERVED4;
    __IO uint16_t CTLR3;
    uint16_t  RESERVED5;
    __IO uint16_t GPR;
    uint16_t  RESERVED6;
} USART_TypeDef;

#define SET         1
#define RESET       0

#define LED_R       3 // PB3
#define LED_G       4 // PB4
#define LED_B       5 // PB5

#define PA9         9

#define GPIO_Msk        0b1111
#define GPIO_Speed_50   0b0011
#define GPIO_AF_50      0b1011 // Alternate Functions (50Hz)
#define GPIO_IPU        0b1000 // Input Pull Up

// Peripheral memory map
#define FLASH_BASE             ((uint32_t)0x08000000)
#define SRAM_BASE              ((uint32_t)0x20000000)
#define PERIPH_BASE            ((uint32_t)0x40000000)

#define APB2PERIPH_BASE        (PERIPH_BASE + 0x10000)      // 0x40010000
#define AHBPERIPH_BASE         (PERIPH_BASE + 0x20000)      // 0x40020000

#define GPIOA_BASE             (APB2PERIPH_BASE + 0x0800)   // 0x40010800
#define GPIOB_BASE             (APB2PERIPH_BASE + 0x0C00)   // 0x40010C00
#define USART1_BASE            (APB2PERIPH_BASE + 0x3800)   // 0x40013800
#define RCC_BASE               (AHBPERIPH_BASE + 0x1000)    // 0x40021000
#define EXTEN_BASE             (AHBPERIPH_BASE + 0x3800)    // 0x40023800

#define SysTick                ((SysTick_Type *) 0xE000F000)

#define GPIOA                  ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB                  ((GPIO_TypeDef *) GPIOB_BASE)
#define USART1                 ((USART_TypeDef *) USART1_BASE)
#define RCC                    ((RCC_TypeDef *) RCC_BASE)
#define EXTEN                  ((EXTEN_TypeDef *) EXTEN_BASE)

#define RCC_APB2PCENR_IOPAEN   ((uint32_t)0x00000004) // (1 << 2)
#define RCC_APB2PCENR_IOPBEN   ((uint32_t)0x00000008) // (1 << 3)
#define RCC_APB2PCENR_USART1EN ((uint32_t)0x00004000) // (1 << 14)

#define EXTEN_PLL_HSI_PRE      ((uint32_t)0x00000010) // (1 << 4)

#define RCC_HPRE               ((uint32_t)0x000000F0) // HPRE[3:0] bits (AHB prescaler)
#define RCC_HPRE_DIV1          ((uint32_t)0x00000000) // SYSCLK not divided
#define RCC_PPRE2_DIV1         ((uint32_t)0x00000000) // HCLK not divided
#define RCC_PPRE1_DIV2         ((uint32_t)0x00000400) // HCLK divided by 2
#define RCC_PLLSRC             ((uint32_t)0x00010000) // PLL entry clock source
#define RCC_PLLXTPRE           ((uint32_t)0x00020000) // HSE divider for PLL entry
#define RCC_PLLMULL            ((uint32_t)0x003C0000) // PLLMUL[3:0] bits (PLL multiplication factor)
#define RCC_PLLSRC_HSI_Div2    ((uint32_t)0x00000000) // HSI clock divided by 2 selected as PLL entry clock source
#define RCC_PLLMULL6           ((uint32_t)0x00100000) // PLL input clock*6
#define RCC_PLLON              ((uint32_t)0x01000000) // PLL enable
#define RCC_PLLRDY             ((uint32_t)0x02000000) // PLL clock ready flag
#define RCC_SW                 ((uint32_t)0x00000003) // SW[1:0] bits (System clock Switch)
#define RCC_SW_PLL             ((uint32_t)0x00000002) // PLL selected as system clock
#define RCC_SWS                ((uint32_t)0x0000000C) // SWS[1:0] bits (System Clock Switch Status)

#define HSE_VALUE              ((uint32_t)8000000) // внешний осцилятор
#define HSI_VALUE              ((uint32_t)8000000) // внутренний осцилятор

#define SYSCLK_FREQ_48MHz_HSI  48000000



#define CTLR1_UE_Set              ((uint16_t)0x2000) // USART Enable Mask
#define CTLR1_UE_Reset            ((uint16_t)0xDFFF) // USART Disable Mask

#define CTLR2_STOP_CLEAR_Mask     ((uint16_t)0xCFFF) // USART CR2 STOP Bits Mask
#define CTLR1_CLEAR_Mask          ((uint16_t)0xE9F3) // USART CR1 Mask
#define CTLR3_CLEAR_Mask          ((uint16_t)0xFCFF) // USART CR3 Mask
              
// USART_Word_Length
#define USART_WordLength_8b       ((uint16_t)0x0000)
#define USART_WordLength_9b       ((uint16_t)0x1000)

// USART_Stop_Bits  
#define USART_StopBits_1          ((uint16_t)0x0000)
#define USART_StopBits_0_5        ((uint16_t)0x1000)
#define USART_StopBits_2          ((uint16_t)0x2000)
#define USART_StopBits_1_5        ((uint16_t)0x3000)

// USART_Parity  
#define USART_Parity_No           ((uint16_t)0x0000)
#define USART_Parity_Even         ((uint16_t)0x0400)
#define USART_Parity_Odd          ((uint16_t)0x0600) 

// USART_Mode 
#define USART_Mode_Rx             ((uint16_t)0x0004)
#define USART_Mode_Tx             ((uint16_t)0x0008)

/* USART_Hardware_Flow_Control */
#define USART_HardwareFlowControl_None       ((uint16_t)0x0000)
#define USART_HardwareFlowControl_RTS        ((uint16_t)0x0100)
#define USART_HardwareFlowControl_CTS        ((uint16_t)0x0200)
#define USART_HardwareFlowControl_RTS_CTS    ((uint16_t)0x0300)

// USART_Flags
#define USART_FLAG_CTS            ((uint16_t)0x0200)
#define USART_FLAG_LBD            ((uint16_t)0x0100)
#define USART_FLAG_TXE            ((uint16_t)0x0080)
#define USART_FLAG_TC             ((uint16_t)0x0040)
#define USART_FLAG_RXNE           ((uint16_t)0x0020)
#define USART_FLAG_IDLE           ((uint16_t)0x0010)
#define USART_FLAG_ORE            ((uint16_t)0x0008)
#define USART_FLAG_NE             ((uint16_t)0x0004)
#define USART_FLAG_FE             ((uint16_t)0x0002)
#define USART_FLAG_PE             ((uint16_t)0x0001)




#endif /* __DEFINES_H_ */