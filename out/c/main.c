// ./out/c//main.c

#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "main.h"



#define main_text_filename  "./main.bin"
#define main_showText  false
uint32_t loader(char *filename, uint8_t *bufptr, uint32_t buf_size);
void show_regs(core_Core *core);
void show_mem();







static core_Core core;

uint32_t loader(char *filename, uint8_t *bufptr, uint32_t buf_size)
{
	printf("LOAD: %s\n", filename);

	FILE *const fp = fopen(filename, "rb");

	if (fp == NULL) {
		printf("error: cannot open file '%s'", filename);
		return 0;
	}

	const size_t n = fread(bufptr, 1, (size_t)buf_size, fp);

	printf("LOADED: %zu bytes\n", n);

	if (main_showText) {
		size_t i;
		i = 0;
		while (i < n / 4) {
			printf("%08zx: 0x%08x\n", i, ((uint32_t *)bufptr)[i]);
			i = i + 4;
		}

		printf("-----------\n");
	}

	fclose(fp);

	return (uint32_t)n;
}

void show_regs(core_Core *core)
{
	int32_t i;
	i = 0;
	while (i < 16) {
		printf("x%02d = 0x%08x", i, core->reg[i]);
		printf("    ");
		printf("x%02d = 0x%08x\n", i + 16, core->reg[i + 16]);
		i = i + 1;
	}
}

void show_mem()
{
	int32_t i;
	i = 0;
	uint8_t *const ramptr = mem_get_ram_ptr();
	while (i < 256) {
		printf("%08X", i * 16);

		int32_t j;
		j = 0;
		while (j < 16) {
			printf(" %02X", ramptr[i + j]);
			j = j + 1;
		}

		printf("\n");

		i = i + 16;
	}
}

int main()
{
	printf("RISC-V VM\n");

	core_BusInterface memctl;
	memctl = (core_BusInterface){
		.read8 = &mem_read8,
		.read16 = &mem_read16,
		.read32 = &mem_read32,
		.write8 = &mem_write8,
		.write16 = &mem_write16,
		.write32 = &mem_write32
	};

	uint8_t *const romptr = mem_get_rom_ptr();
	const uint32_t nbytes = loader(main_text_filename, romptr, mem_romSize);

	if (nbytes <= 0) {
		exit(1);
	}

	core_init((core_Core *)&core, (core_BusInterface *)&memctl);

	printf("~~~ START ~~~\n");

	while (!core.end) {
		core_tick((core_Core *)&core);
	}

	printf("core.cnt = %u\n", core.cnt);

	printf("\nCore dump:\n");
	show_regs((core_Core *)&core);
	printf("\n");
	show_mem();

	return 0;
}

