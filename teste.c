#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int main()
{

int matriz[4][3];
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
    printf("\n Arquivo REGRAS.TXT não pode ser aberto : TECLE ALGO");
 getch();
 }else
    {
        while((ch = fgetc(Arquivo))!= EOF) //Lê até o final do arquivo
        {
            if(ch != '.')//para caracteres diferentes de '.' adiciona no vetor aux e incrementa i
            {
                    if(ch != '\n')
                    {
                        //insere na variavel auxiliar
                        fflush(stdin);
                        aux[contador]=ch;
                        contador++;
                    }
                    else //insere na matriz de regras e incrementa a linha
                    {
                        fflush(stdin);
                        printf("\nvalor de ch se encontrar '\n' = %c", ch);
                        printf("segundo if\n");
                        linha++;
                        contador = 0;
                        coluna = 0;
                        aux[0] = '\0'; aux[1] = '\0'; aux[2] = '\0'; aux[3] = '\0';
                        printf("\nPrinta o valor da matriz:\n");
                        printf("\n %d.%d.%d.%d", matriz[linha-1][0], matriz[linha-1][1], matriz[linha-1][2], matriz[linha-1][3]);
                        system("PAUSE");
                    }
            }
            else//insere na matriz realizando a conversão de char para int, incrementa a coluna
            {
                fflush(stdin);
                aux[contador] = '\0';
                printf("\nValor de ch = %c", ch);
                matriz[linha][coluna] = atoi(aux);
                aux[0] = '\0'; aux[1] = '\0'; aux[2] = '\0'; aux[3] = '\0';
                printf("\nValor da matriz = %d",matriz[linha][coluna]);
                coluna++;
                contador=0;
                system("PAUSE");

            }
        }
    }

    //fecha o arquivo

fclose(Arquivo);

//testa as regras
for(linha = 0; linha<3; linha++)
{
    if(matriz[linha][0] == a && matriz[linha][1] == b && matriz[linha][2] == c && matriz[linha][3] == d)
    {

        printf("\nregra %d testada\n", linha);
        //libera o pacote
        printf("\nPacote Liberado\n");
        break;

    }else{

//bloqueia o pacote
printf("\nPacote bloqueado\n");

}
//printa na tela

printf("\nIP do pacote: %d.%d.%d.%d \n\n", a,b,c,d);

    for(linha=0;linha<3;linha++)
    {
        for(coluna=0;coluna<4;coluna++)
        {
        printf("%d.", matriz[linha][coluna]);
        }
    printf("\n");

    }

}
}
