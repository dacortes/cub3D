#include <stdio.h>
int	main(void)
{
	#ifdef INC_MAC
		printf("hola\n");
	#endif
      printf("sdaf %d\n", INC_MAC);
}
