ENTRY(__start) 
SECTIONS 
{ 
    . = 0x80100000; 
    .text : { *(.text) } 
    .data : { *(.data) } 
    .bss : { *(.bss) } 
    . = . + 0x1000; /* 4kB of stack memory */ 
    stack_top = .; 
}
