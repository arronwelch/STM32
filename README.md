# STM32

## volatile & pointer
    > #define MEM_ADDR(addr)  *((volatile unsigned long  *)(addr))  
 
 ### 
     1.volatile：volatile unsigned long addr;
     2.pointer: (unsigned long *) addr;
     2.pointer to unsigned long: get_addr = *addr;