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
    printf("\n Arquivo TEXTO.TXT n�o pode ser aberto : TECLE ALGO");
 getch();
 }else
    {
        printf("1\n");
        while((ch = fgetc(Arquivo))!= EOF) //L� at� o final do arquivo
        {
            if(ch != '.')//para caracteres diferentes de '.' adiciona no vetor aux e incrementa i
            {
                //insere na matriz
                fflush(stdin);
                aux[i]=ch;
                i++;
                printf("\nvalor de ch = %c", ch);
                printf("\n%c primeiro if",aux[i]);
                system("PAUSE");
                //printf("3\n");
            }
            else if(ch == '\n')//teste se chegou no final da linha, se n�o, insere na matriz como string e adiciona \0 para retirar lixo de mem�ria
            {
                fflush(stdin);
                printf("\nvalor de ch se encontrar '\n' = %c", ch);
                printf("segundo if\n");
                system("PAUSE");
                j++;

            }
            else//ignora e pula para a proxima linha
            {
                fflush(stdin);
                aux[i+1] = '\0';
                printf("\nterceiro if a matriz vai receber o valor");
                printf("\nValor de ch = %c", ch);
                matriz[cont][j] = atoi(aux);
                printf("\nValor da matriz = %d",matriz[cont][j]);
                cont++;
                i=0;
                system("PAUSE");
            }
        }

    }

//testa as regras
for(j = 0; j<2; j++)
{
    if(matriz[i][j] == a && matriz[i+1][j] == b && matriz[i+2][j] == c && matriz[i+3][j] == d)
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