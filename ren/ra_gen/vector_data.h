/* generated vector header file - do not edit */
        #ifndef VECTOR_DATA_H
        #define VECTOR_DATA_H
                /* Number of interrupts allocated */
        #ifndef VECTOR_DATA_IRQ_COUNT
        #define VECTOR_DATA_IRQ_COUNT    (12)
        #endif
        /* ISR prototypes */
        void spi_rxi_isr(void);
        void r_icu_isr(void);
        void ctsu_read_isr(void);
        void ctsu_end_isr(void);
        void sci_uart_rxi_isr(void);
        void sci_uart_txi_isr(void);
        void sci_uart_tei_isr(void);
        void sci_uart_eri_isr(void);
        void ctsu_write_isr(void);
        void spi_tei_isr(void);
        void spi_eri_isr(void);
        void spi_txi_isr(void);

        /* Vector table allocations */
        #define VECTOR_NUMBER_SPI0_RXI ((IRQn_Type) 0) /* SPI0 RXI (Receive buffer full) */
        #define SPI0_RXI_IRQn          ((IRQn_Type) 0) /* SPI0 RXI (Receive buffer full) */
        #define VECTOR_NUMBER_ICU_IRQ1 ((IRQn_Type) 1) /* ICU IRQ1 (External pin interrupt 1) */
        #define ICU_IRQ1_IRQn          ((IRQn_Type) 1) /* ICU IRQ1 (External pin interrupt 1) */
        #define VECTOR_NUMBER_CTSU_READ ((IRQn_Type) 2) /* CTSU READ (Measurement data transfer request interrupt) */
        #define CTSU_READ_IRQn          ((IRQn_Type) 2) /* CTSU READ (Measurement data transfer request interrupt) */
        #define VECTOR_NUMBER_CTSU_END ((IRQn_Type) 3) /* CTSU END (Measurement end interrupt) */
        #define CTSU_END_IRQn          ((IRQn_Type) 3) /* CTSU END (Measurement end interrupt) */
        #define VECTOR_NUMBER_SCI9_RXI ((IRQn_Type) 4) /* SCI9 RXI (Received data full) */
        #define SCI9_RXI_IRQn          ((IRQn_Type) 4) /* SCI9 RXI (Received data full) */
        #define VECTOR_NUMBER_SCI9_TXI ((IRQn_Type) 5) /* SCI9 TXI (Transmit data empty) */
        #define SCI9_TXI_IRQn          ((IRQn_Type) 5) /* SCI9 TXI (Transmit data empty) */
        #define VECTOR_NUMBER_SCI9_TEI ((IRQn_Type) 6) /* SCI9 TEI (Transmit end) */
        #define SCI9_TEI_IRQn          ((IRQn_Type) 6) /* SCI9 TEI (Transmit end) */
        #define VECTOR_NUMBER_SCI9_ERI ((IRQn_Type) 7) /* SCI9 ERI (Receive error) */
        #define SCI9_ERI_IRQn          ((IRQn_Type) 7) /* SCI9 ERI (Receive error) */
        #define VECTOR_NUMBER_CTSU_WRITE ((IRQn_Type) 9) /* CTSU WRITE (Write request interrupt) */
        #define CTSU_WRITE_IRQn          ((IRQn_Type) 9) /* CTSU WRITE (Write request interrupt) */
        #define VECTOR_NUMBER_SPI0_TEI ((IRQn_Type) 10) /* SPI0 TEI (Transmission complete event) */
        #define SPI0_TEI_IRQn          ((IRQn_Type) 10) /* SPI0 TEI (Transmission complete event) */
        #define VECTOR_NUMBER_SPI0_ERI ((IRQn_Type) 11) /* SPI0 ERI (Error) */
        #define SPI0_ERI_IRQn          ((IRQn_Type) 11) /* SPI0 ERI (Error) */
        #define VECTOR_NUMBER_SPI0_TXI ((IRQn_Type) 13) /* SPI0 TXI (Transmit buffer empty) */
        #define SPI0_TXI_IRQn          ((IRQn_Type) 13) /* SPI0 TXI (Transmit buffer empty) */
        #endif /* VECTOR_DATA_H */