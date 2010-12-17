
#include <time.h>
#include <stdio.h>

// measure  a elapsed time
#define	MEASURE_TIME_WITH_IDX_START(__idx__)	{						\
			clock_t		start_time_##__idx__, end_time_##__idx__;		\
			start_time_##__idx__  = clock();							



#define	MEASURE_TIME_WITH_IDX_END(__idx__)												\
			end_time_##__idx__	=	clock();											\
			printf("[Function : %s] [[Desc. : " #__idx__ " ]] Time : %f \n", \
					__FUNCTION__,														\
					(double) (end_time_##__idx__ - start_time_##__idx__) );				\
		 }
//

		


