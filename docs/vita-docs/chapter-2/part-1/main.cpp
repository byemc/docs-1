#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <psp2/ctrl.h>
#include <psp2/kernel/processmgr.h>
#include <vita2d.h>


int main()
{
	vita2d_pgf *pgf;

	vita2d_init();
	vita2d_set_clear_color(RGBA8(0x40, 0x40, 0x40, 0xFF));

	pgf = vita2d_load_default_pgf();


	while (1) {
		vita2d_start_drawing();
		vita2d_clear_screen();

		vita2d_pgf_draw_text(pgf, 10, 10, RGBA8(0,255,0,255), 1.0f, "Hello World!");

		vita2d_end_drawing();
		vita2d_swap_buffers();

	}
	vita2d_fini();
	vita2d_free_pgf(pgf);

	sceKernelExitProcess(0);
	return 0;
}
