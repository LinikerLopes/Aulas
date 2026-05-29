#include <stdio.h>
#include <stdint.h> 
#include <inttypes.h>

int main(void) {
    

    int i = 1234;
    printf("i = %d\n", i);
    printf("&i = %p\n", (void*)&i);

    uintptr_t addr = (uintptr_t)(void *)&i; 
    
    printf("endereco numero (HEX) = 0x%" PRIxPTR "\n", addr);
    
    printf("sizeof(int) = %zu, sizeof(void*) = %zu\n", sizeof i, sizeof(void*));

    return 0;
}