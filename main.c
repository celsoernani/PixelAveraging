#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    //parametrizar argv
    FILE *file = fopen("C:\\Users\\celso\\Desktop\\CELSO\\FACULDADE- IFCE\\s6\\SEMB\\PixelAveraging\\download.jpg", "rb");

   if (!file)
	{
		printf("File not found!\n");
		exit(1);
	}

	else{
        printf("Imagem linda com sucesso !");
 	}

    return 0;
}
