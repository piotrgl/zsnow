#include "defines.h"
#include "gpio.h"

#define SPI0_CS     ((volatile unsigned int*)(MMIO_BASE+0x00204000))
#define SPI0_FIFO   ((volatile unsigned int*)(MMIO_BASE+0x00204004))
#define SPI0_CLK    ((volatile unsigned int*)(MMIO_BASE+0x00204008))
#define SPI0_DLEN   ((volatile unsigned int*)(MMIO_BASE+0x0020400C))
#define SPI0_LTOH   ((volatile unsigned int*)(MMIO_BASE+0x00204010))
#define SPI0_DC     ((volatile unsigned int*)(MMIO_BASE+0x00204014))
#define AUX_ENABLES ((volatile unsigned int*)(MMIO_BASE+0x00215004))

#define SPI0_CS_TA_BIT 7
#define SPI0_CS_TXD_BIT 18
#define SPI0_CS_RXD_BIT 17
#define SPI0_CS_DONE_BIT 16
#define SPI0_CS_REN_BIT 12

/*
Polling mode:

a) Set CS, CPOL, CPHA as required and set TA = 1.
b) Poll TXD writing bytes to SPI_FIFO, RXD reading bytes from SPI_FIFO until all data written.
c) Poll DONE until it goes to 1.
d) SetTA=0.
*/

void wait_txbuf_ready() {
    while (1) {
        if (*SPI0_CS & (1 << SPI0_CS_TXD_BIT)) break;
    }
}

void wait_rxbuf_ready() {
    while (1) {
        if (*SPI0_CS & (1 << SPI0_CS_RXD_BIT)) break;
    }
}

void wait_tx_done() {
    while (1) {
        if (*SPI0_CS & (1 << SPI0_CS_DONE_BIT)) break;
    }
}

void spi_enable() {
    *SPI0_CS = 0x000000B0; // TA = 1 and clear TX and RX FIFOs
}

void spi_disable() {
    *SPI0_CS &= ~(1 << SPI0_CS_TA_BIT);
}

void spi_set_3_wire_mode() {
    *SPI0_CS &= (~(1 << SPI0_CS_REN_BIT));
}

void configure_spi_pins() {
    *GPFSEL0 |= 0b100 << 24; //GPIO8 ALT 0, CE0_N
    *GPFSEL0 |= 0b100 << 27; //GPIO9 ALT 0, MISO

    *GPFSEL1 |= 0b100 << 0;  //GPIO10 ALT 0, MOSI
    *GPFSEL1 |= 0b100 << 3;  //GPIO11 ALT 0, SCLK
}

void spi_init() {
    *SPI0_CLK = 512;
    configure_spi_pins();
    spi_set_3_wire_mode();
    spi_disable();
}

void spi_tx_byte(uint8_t data) {
    spi_enable();
    wait_txbuf_ready();
    *SPI0_FIFO = (uint32_t)data;
    wait_tx_done();
    spi_disable();
}
