#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

int main()
{
	size_t		*tmp_1;
	uintptr_t	arr[2];
	int			*tmp_2;
	char		*tmp_3;
	size_t	i;

	
	i = 0;

	tmp_1 = malloc(sizeof(size_t));
	printf("tmp_1 = %p\n", tmp_1);
	arr[0] = (uintptr_t)tmp_1;
	arr[1] = (uintptr_t)tmp_1 + sizeof(size_t);
	free(tmp_1);
	tmp_1 = malloc(sizeof(int));
	tmp_2 = malloc(2 * sizeof(size_t));
	printf("tmp_2 = %p\n sizeof(tmp_2) = %ld\n", tmp_2, sizeof(tmp_2));
	if (tmp_2 >= arr[0] && tmp_2 < arr[1])
		printf("Eureka!\n");
/*	while(i++)
	{
		tmp_1 = malloc(i * sizeof(size_t));
		tmp_2 = malloc(i * sizeof(int));
	//	free(tmp);
	} */
}
