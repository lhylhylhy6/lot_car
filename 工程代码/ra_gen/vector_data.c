/* generated vector source file - do not edit */
        #include "bsp_api.h"
        /* Do not build these data structures if no interrupts are currently allocated because IAR will have build errors. */
        #if VECTOR_DATA_IRQ_COUNT > 0
        BSP_DONT_REMOVE const fsp_vector_t g_vector_table[BSP_ICU_VECTOR_MAX_ENTRIES] BSP_PLACE_IN_SECTION(BSP_SECTION_APPLICATION_VECTORS) =
        {
                        [0] = sci_uart_rxi_isr, /* SCI7 RXI (Received data full) */
            [1] = sci_uart_txi_isr, /* SCI7 TXI (Transmit data empty) */
            [2] = sci_uart_tei_isr, /* SCI7 TEI (Transmit end) */
            [3] = sci_uart_eri_isr, /* SCI7 ERI (Receive error) */
            [4] = r_icu_isr, /* ICU IRQ0 (External pin interrupt 0) */
            [5] = sci_uart_rxi_isr, /* SCI0 RXI (Receive data full) */
            [6] = sci_uart_txi_isr, /* SCI0 TXI (Transmit data empty) */
            [7] = sci_uart_tei_isr, /* SCI0 TEI (Transmit end) */
            [8] = sci_uart_eri_isr, /* SCI0 ERI (Receive error) */
            [9] = sci_uart_rxi_isr, /* SCI1 RXI (Received data full) */
            [10] = sci_uart_txi_isr, /* SCI1 TXI (Transmit data empty) */
            [11] = sci_uart_tei_isr, /* SCI1 TEI (Transmit end) */
            [12] = sci_uart_eri_isr, /* SCI1 ERI (Receive error) */
        };
        const bsp_interrupt_event_t g_interrupt_event_link_select[BSP_ICU_VECTOR_MAX_ENTRIES] =
        {
            [0] = BSP_PRV_IELS_ENUM(EVENT_SCI7_RXI), /* SCI7 RXI (Received data full) */
            [1] = BSP_PRV_IELS_ENUM(EVENT_SCI7_TXI), /* SCI7 TXI (Transmit data empty) */
            [2] = BSP_PRV_IELS_ENUM(EVENT_SCI7_TEI), /* SCI7 TEI (Transmit end) */
            [3] = BSP_PRV_IELS_ENUM(EVENT_SCI7_ERI), /* SCI7 ERI (Receive error) */
            [4] = BSP_PRV_IELS_ENUM(EVENT_ICU_IRQ0), /* ICU IRQ0 (External pin interrupt 0) */
            [5] = BSP_PRV_IELS_ENUM(EVENT_SCI0_RXI), /* SCI0 RXI (Receive data full) */
            [6] = BSP_PRV_IELS_ENUM(EVENT_SCI0_TXI), /* SCI0 TXI (Transmit data empty) */
            [7] = BSP_PRV_IELS_ENUM(EVENT_SCI0_TEI), /* SCI0 TEI (Transmit end) */
            [8] = BSP_PRV_IELS_ENUM(EVENT_SCI0_ERI), /* SCI0 ERI (Receive error) */
            [9] = BSP_PRV_IELS_ENUM(EVENT_SCI1_RXI), /* SCI1 RXI (Received data full) */
            [10] = BSP_PRV_IELS_ENUM(EVENT_SCI1_TXI), /* SCI1 TXI (Transmit data empty) */
            [11] = BSP_PRV_IELS_ENUM(EVENT_SCI1_TEI), /* SCI1 TEI (Transmit end) */
            [12] = BSP_PRV_IELS_ENUM(EVENT_SCI1_ERI), /* SCI1 ERI (Receive error) */
        };
        #endif