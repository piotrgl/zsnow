#ifndef __GPIO_H__
#define __GPIO_H__

#include "defines.h"
#include "base.h"

#define GPFSEL0     ((volatile uint32_t*)(MMIO_BASE+0x00200000))
#define GPFSEL1     ((volatile uint32_t*)(MMIO_BASE+0x00200004))
#define GPFSEL2     ((volatile uint32_t*)(MMIO_BASE+0x00200008))

#define GPSET0      ((volatile uint32_t*)(MMIO_BASE+0x0020001C))
#define GPCLR0      ((volatile uint32_t*)(MMIO_BASE+0x00200028))

#define GPPUD       ((volatile uint32_t*)(MMIO_BASE+0x00200094))
#define GPPUDCLK0   ((volatile uint32_t*)(MMIO_BASE+0x00200098))

#define GPFEN0      ((volatile uint32_t*)(MMIO_BASE+0x00200058))
#define GPEDS0      ((volatile uint32_t*)(MMIO_BASE+0x00200040))

#endif
