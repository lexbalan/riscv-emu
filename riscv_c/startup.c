
#include <stdint.h>


void __rt0() {
#if 0
  // Зануление BSS сегмента
  {
    extern void _bss_start, _bss_end;
    uint8_t *const p = &_bss_start;
    const uint32_t bss_size = (uint32_t)&_bss_end - (uint32_t)&_bss_start;

    uint32_t i = 0;
    while (i < bss_size) {
      p[i] = 0;
      ++i;
    }
  }
#endif


#if 1
  // Копирование .data сегмента из FLASH в RAM
  {
    extern void _data_start, _data_end, _data_flash_start;
    uint8_t *const dst = &_data_start;
    uint8_t *const src = &_data_flash_start;
    const uint32_t data_size = (uint32_t)&_data_end - (uint32_t)&_data_start;

    uint32_t i = 0;
    while (i < data_size) {
      dst[i] = src[i];
      ++i;
    }
  }
#endif
}


extern int main();

// if not defined boot section, will be defined firstly (!)
__attribute__ ((section ("boot"))) void __boot() {
	__rt0();
	main();

	asm("ebreak");
}




