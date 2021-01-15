#include <unistd.h>

int		main(int ac, char **av)
{
	int		ascii[255];
	int		i, j;

	if (ac == 3)
	{
		i = 0;
		while (i < 255)
			ascii[i++] = 0;
		i = 2;
		while (i > 0)
		{
			j = 0;
			while (av[i][j])
			{
				if (i == 2 && ascii[(unsigned char)av[i][j]] == 0)
					ascii[(unsigned char)av[i][j]] = 1;
				else if (i == 1 && ascii[(unsigned char)av[i][j]] == 1)
				{
					ascii[(unsigned char)av[i][j]] = 2;
					write(1, &av[i][j], 1);
				}
				j++;
			}
			i--;
		}
	}
	write(1, "\n", 1);
	return (0);
}