.global __start  
.text  
__start:  
    add $t0,$0, 0xbf000408 #LED address  
    add $t3,$0, 0xbf000418 #display char address  
    add $s2, $s2, 0x3ffffff #delay time  
    add $s0, $0,0x55 #LED: "# # # # "   
update:  
    sw $s0,0($t0) #send to LED  
    sw $s0,0($t3) #send to display  
    sw $s0,8($t3) #send to display  
    sw $s0,16($t3) #send to display  
    sw $s0,24($t3) #send to display  
    sw $s0,32($t3) #send to display  
    sw $s0,40($t3) #send to display  
    sw $s0,48($t3) #send to display  
    sw $s0,56($t3) #send to display  
  
    add $t1, $0, 0  
  
delay:  
    add $t1, $t1, 1  
    bne $t1, $s2, delay  
  
    add $s0, $s0, 1  
    b update
