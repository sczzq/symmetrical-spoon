/*************************************************************************
	> File Name: git.c
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Fri 06 Apr 2018 06:42:38 PM CST
 ************************************************************************/

#include <stdio.h>
#include <plot.h>
int main()
{
	plPlotter *plotter;
	plPlotterParams *plotter_params;
	int i;
	/* set Plotter parameters */
	plotter_params = pl_newplparams ();
	pl_setplparam (plotter_params, "BITMAPSIZE", "150x100");
	pl_setplparam (plotter_params, "BG COLOR", "orange");
	pl_setplparam (plotter_params, "TRANSPARENT COLOR", "orange");
	pl_setplparam (plotter_params, "GIF ITERATIONS", "100");
	pl_setplparam (plotter_params, "GIF DELAY", "5");
	/* create a GIF Plotter with the specified parameters */
	plotter = pl_newpl_r ("gif", stdin, stdout, stderr, plotter_params);

	pl_openpl_r (plotter);
	/* begin page of graphics */
	pl_fspace_r (plotter,
			-0.5, -0.5, 149.5, 99.5); /* set user coor system */
	pl_pencolorname_r (plotter, "red");
	pl_linewidth_r (plotter, 5);
	pl_filltype_r (plotter, 1);
	pl_fillcolorname_r (plotter, "black");
	/*  use red pen 
		set line thickness 
		objects will be filled 
		set the fill color */
		for (i = 0; i < 180000 ; i += 15)
		{
			pl_erase_r (plotter);
			/* begin new GIF image */
			pl_ellipse_r (plotter, 75, 50, 40, 20, i); /* draw an ellipse */
		}
	pl_closepl_r (plotter);
	pl_deletepl_r (plotter);
	return 0;
	/* end page of graphics */
	/* delete Plotter */
}
