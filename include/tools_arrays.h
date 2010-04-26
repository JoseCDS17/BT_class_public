/** 
 * definitions for module thermodynamics.c 
 */

#include "precision.h"

#ifndef __TOOLS_ARRAYS__
#define __TOOLS_ARRAYS__

#define _SPLINE_NATURAL_ 0 /**< natural spline: ddy0=ddyn=0 */
#define _SPLINE_EST_DERIV_ 1 /**< spline with estimation of first derivative on both edges */

/**
 * Boilerplate for C++ 
 */
#ifdef __cplusplus
extern "C" {
#endif

  int array_derive(
		   double * array,
		   int n_columns,
		   int n_lines,
		   int index_x,   /** from 0 to (n_columns-1) */
		   int index_y,
		   int index_dydx,
		   char *errmsg);

  int array_derive_spline(
			  double * x_array,
			  int n_lines,
			  double * array,
			  double * array_splined,
			  int n_columns,
			  int index_y,
			  int index_dydx,
			  char *errmsg);

  int array_derive_spline_table_line_to_line(
				       double * x_array,
				       int n_lines,
				       double * array,
				       int n_columns,
				       int index_y,
				       int index_ddy,
				       int index_dy,
				       char * errmsg);

  int array_derive1_order2_table_line_to_line(
				       double * x_array,
				       int n_lines,
				       double * array,
				       int n_columns,
				       int index_y,
				       int index_dy,
				       char * errmsg);

  int array_derive2_order2_table_line_to_line(
				       double * x_array,
				       int n_lines,
				       double * array,
				       int n_columns,
				       int index_y,
				       int index_dy,
				       int index_ddy,
				       char * errmsg);

  int array_derive_two(
		   double * array,
		   int n_columns,
		   int n_lines,
		   int index_x,   /** from 0 to (n_columns-1) */
		   int index_y,
		   int index_dydx,
		   int index_ddydxdx,
		   char *errmsg);



  int array_spline(
		   double * array,
		   int n_columns,
		   int n_lines,
		   int index_x,   /** from 0 to (n_columns-1) */
		   int index_y,
		   int index_ddydx2,
		   short spline_mode,
		   char * errmsg);

  int array_spline_table_line_to_line(
				      double * x, /* vector of size x_size */
				      int x_size,
				      double * array,
				      int n_columns,
				      int index_y,
				      int index_ddydx2,
				      short spline_mode,
				      char * errmsg);
       
  int array_spline_table_columns(
		       double * x,
		       int x_size,
		       double * y_array,
		       int y_size,    
		       double * ddy_array,
		       short spline_mode,
		       char * errmsg);

  int array_spline_table_lines(
		       double * x,
		       int x_size,
		       double * y_array,
		       int y_size, 
		       double * ddy_array,
		       short spline_mode,
		       char * errmsg
		       );

int array_integrate_all_spline(
		   double * array,
		   int n_columns,
		   int n_lines,
		   int index_x,
		   int index_y,
		   int index_ddy,
		   double * result,
		   char * errmsg
		   );

  int array_integrate(
		      double * array,
		      int n_columns,
		      int n_lines,
		      int index_x,   /** from 0 to (n_columns-1) */
		      int index_y,
		      int index_int_y_dx,
		      char *errmsg);
  
  int array_integrate_all(
		      double * array,
		      int n_columns,
		      int n_lines,
		      int index_x,   /** from 0 to (n_columns-1) */
		      int index_y,
		      double * result);
  
  int array_integrate_ratio(
			    double * array,
			    int n_columns,
			    int n_lines,
			    int index_x,   /** from 0 to (n_columns-1) */
			    int index_y1,
			    int index_y2,
			    int index_int_y1_over_y2_dx,
			    char *errmsg);

  int array_interpolate(
			double * array,
			int n_columns,
			int n_lines,
			int index_x,   /** from 0 to (n_columns-1) */
			double x,
			int * last_index,
			double * result,
			int result_size,
			char *errmsg); /** from 1 to n_columns */

  int array_interpolate_spline(
			       double * x_array,
			       int n_lines,
			       double * array,
			       double * array_splined,
			       int n_columns,
			       double x,
			       int * last_index,
			       double * result,
			       int result_size, /** from 1 to n_columns */
			       char * errmsg);

  int array_interpolate_growing_closeby(
			double * array,
			int n_columns,
			int n_lines,
			int index_x,   /** from 0 to (n_columns-1) */
			double x,
			int * last_index,
			double * result,
			int result_size,
			char *errmsg); /** from 1 to n_columns */

  int array_interpolate_spline_growing_closeby(
					       double * x_array,
					       int n_lines,
					       double * array,
					       double * array_splined,
					       int n_columns,
					       double x,
					       int * last_index,
					       double * result,
					       int result_size, /** from 1 to n_columns */
					       char * errmsg);

  int array_interpolate_spline_growing_hunt(
					       double * x_array,
					       int n_lines,
					       double * array,
					       double * array_splined,
					       int n_columns,
					       double x,
					       int * last_index,
					       double * result,
					       int result_size, /** from 1 to n_columns */
					       char * errmsg);

  /** interpolate to get y_i(x), when x and y_i are in two different arrays*/
  int array_interpolate_two(
			    double * array_x,
			    int n_columns_x,
			    int index_x,   /** from 0 to (n_columns_x-1) */
			    double * array_y,
			    int n_columns_y,
			    int n_lines,  /** must be the same for array_x and array_y */
			    double x,
			    double * result,
			    int result_size, /** from 1 to n_columns_y */
			    char * errmsg);

  int array_interpolate_equal(
			    double * array,
			    int n_colums,
			    int n_lines,
			    double x,
			    double x_min,
			    double x_max,
			    double * result,
			    char * errmsg);

  int array_smooth(double * array,
		   int n_columns,
		   int n_lines,
		   int index, /** from 0 to (n_columns-1) */
		   int radius,
		   char * errmsg);


#ifdef __cplusplus
}
#endif

#endif