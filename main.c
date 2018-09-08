#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int * getWidth(FILE *image){
    int iHeight=0, iWidth=0, iPos, i;
    int *vetor = malloc (sizeof (int) * 2);
     //pegando o final do arquivo
        fseek(image,0,SEEK_END);
        //pega o ponteiro que esta apontando para o arquivo
        long len = ftell(image); //onde está o ponteiro
        //pegando o coemço do arquivo
        fseek(image,0,SEEK_SET);
        //lendo o arquivo com alocação de memoria
        unsigned char *ucpImageBuffer = (unsigned char*) malloc (len+1);
        fread(ucpImageBuffer,1,len,image);
        fclose(image);
    //peguei função na internet
    /*andando de posição em posição no arquivo*/
    for(i=0;i<len;i++)
    {
        if((ucpImageBuffer[i]==0xFF) && (ucpImageBuffer[i+1]==0xC0) )
        {
            printf("%d\n", i);
            iPos=i;
            break;
        }
    }

    /*Moving to the particular byte position and assign byte value to pointer variable*/
    iPos = iPos + 5;
    printf("%d", iPos);
    iHeight = ucpImageBuffer[iPos]<<8|ucpImageBuffer[iPos+1];
    iWidth = ucpImageBuffer[iPos+2]<<8|ucpImageBuffer[iPos+3];

    printf("\nWxH = %dx%d\n\n", iWidth, iHeight);
    vetor[0] = iHeight;
    vetor[1] = iWidth;


    free(ucpImageBuffer);
    return vetor;

 	}

int main()
{

    int *vectorHW = malloc (sizeof (int) * 2);


    //parametrizar argv
    FILE *image = fopen("C:\\Users\\celso\\Desktop\\CELSO\\FACULDADE- IFCE\\s6\\SEMB\\PixelAveraging\\download.jpg", "rb");
    //todo como pegar rbg de uma iamgem ? por enquanto usar imagem em tons de cinza
   if (!image)
	{
		printf("Imagem não encontrada,tente novamente\n");
		exit(1);
	}

	else{

        printf("Imagem carregada com sucesso com sucesso !");
        vectorHW = getWidth(image);
        printf("%d\n", vectorHW[0]);
        printf("%d\n", vectorHW[1]);

	}

    return 0;
}
