#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int main()
{

int matriz[4][2];
int a,b,c,d;
int i, j, cont;
char aux[4];
char ch;
FILE *Arquivo;
int teste;

a=192; b=168; c=0; d=0;
cont = 0; i = 0; j = 0;

//abre o arquivo no modo leitura

if ((Arquivo = fopen("regras.txt","r")) == NULL) {
    printf("\n Arquivo TEXTO.TXT não pode ser aberto : TECLE ALGO");
 getch();
 }else
    {
        printf("1\n");
        while((ch = fgetc(Arquivo))!= EOF) //Lê até o final do arquivo
        {
            if(ch != '.' || ch != '\n')//para caracteres diferentes de '.' adiciona no vetor aux e incrementa i
            {
                //insere na matriz
                fflush(stdin);
                aux[i]=ch;
                printf("\nvalor de ch = %c", ch);
                printf("\n%c primeiro if",aux[i]);
                i++;
                system("PAUSE");
                //printf("3\n");
            }
            else if(ch != '\n')//teste se chegou no final da linha, se não, insere na matriz como string e adiciona \0 para retirar lixo de memória
            {

                fflush(stdin);
                aux[i] = '\0';
                printf("\nterceiro if a matriz vai receber o valor");
                printf("\nValor de ch = %c", ch);
                matriz[j][cont] = atoi(aux);
                printf("\nValor da matriz = %d",matriz[j][cont]);
                cont++;
                i=0;
                system("PAUSE");

            }
            else//ignora e pula para a proxima linha
            {
                fflush(stdin);
                printf("\nvalor de ch se encontrar '\n' = %c", ch);
                printf("segundo if\n");
                system("PAUSE");
                j++;
            }
        }

    }

//testa as regras
for(j = 0; j<2; j++)
{
    if(matriz[i][j] == a && matriz[i][j+1] == b && matriz[i][j+2] == c && matriz[i][j+3] == d)
    {

        printf("\nregra %d testada\n", j);

    }else{

//bloqueia o pacote
printf("\nPacote bloqueado\n");

}

//libera o pacote
printf("\nPacote Liberado\n");

//fecha o arquivo

fclose(Arquivo);

//printa na tela

printf("%d.%d.%d.%d \n", a,b,c,d);

    for(j=0;j<2;j++)
    {
        for(i=0;i<4;i++)
        {
        printf("%d.", matriz[i][j]);
        }
    printf("\n");

    }



}
}
