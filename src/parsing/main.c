#include "../../includes/cube3d.h"

// int main()
// {
// 	t_data data;

// 	data.map = testing_map();
// 	if (check_for_surround_vertical(data.map, 15,15) == true)
// 		printf("true\n");
// 	else
// 		printf("false\n");
// 	if (check_for_surround_horizontal(data.map, 15,15) == true)
// 		printf("true\n");
// 	else
// 		printf("false\n");
// }



// int main(int argc, char **argv)
// {
// 	printf("%s\n", argv[1]);
// 	if (check_rgb_line(argv[1]))
// 		printf("true\n");
// 	else
// 		printf("false\n");

	// printf("%d\n",get_colour(argv[1]));
// }

int main(int argc, char **argv)
{
	t_data data;
	if (get_map(&data, argv[1]))
		printf("true\n");
	else
		printf("false\n");
}