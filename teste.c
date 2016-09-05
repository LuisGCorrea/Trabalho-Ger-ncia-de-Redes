#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int main()
{

int matriz[4][2];
int a,b,c,d;
int i, linha, coluna, j, contador;
char aux[4];
char ch;
FILE *Arquivo;
int teste;

a=192; b=168; c=0; d=0;
coluna = 0; contador = 0; linha = 0; j = 0, i = 0;

//abre o arquivo no modo leitura

if ((Arquivo = fopen("regras.txt","r")) == NULL) {
    printf("\n Arquivo TEXTO.TXT não pode ser aberto : TECLE ALGO");
 getch();
 }else
    {
        printf("1\n");
        while((ch = fgetc(Arquivo))!= EOF) //Lê até o final do arquivo
        {
            if(ch != '.' && ch != '\n')//para caracteres diferentes de '.' adiciona no vetor aux e incrementa i
            {
                //insere na matriz
                fflush(stdin);
                aux[contador]=ch;
                printf("\nvalor de ch = %c", ch);
                printf("\n%c primeiro if",aux[contador]);
                contador++;
                system("PAUSE");
                //printf("3\n");
            }
            else if(ch == '.')//teste se chegou no final da linha, se não, insere na matriz como string e adiciona \0 para retirar lixo de memória
            {

                fflush(stdin);
                aux[contador] = '\0';
                printf("\nterceiro if a matriz vai receber o valor");
                printf("\nValor de ch = %c", ch);
                matriz[linha][coluna] = atoi(aux);
                printf("\nValor da matriz = %d",matriz[linha][coluna]);
                coluna++;
                contador=0;
                system("PAUSE");

            }
            else//ignora e pula para a proxima linha
            {
                fflush(stdin);
                printf("\nvalor de ch se encontrar '\n' = %c", ch);
                printf("segundo if\n");
                system("PAUSE");
                linha++;
            }
        }

    }

//testa as regras
for(linha = 0; linha<2; linha++)
{
    if(matriz[linha][0] == a && matriz[linha][1] == b && matriz[linha][2] == c && matriz[linha][3] == d)
    {

        printf("\nregra %d testada\n", j);
        //libera o pacote
        printf("\nPacote Liberado\n");

    }else{

//bloqueia o pacote
printf("\nPacote bloqueado\n");

}
//fecha o arquivo

fclose(Arquivo);

//printa na tela

printf("\n%d.%d.%d.%d \n", a,b,c,d);

    for(linha=0;linha<2;linha++)
    {
        for(coluna=0;coluna<4;coluna++)
        {
        printf("%d.", matriz[linha][coluna]);
        }
    printf("\n");

    }

}
}
