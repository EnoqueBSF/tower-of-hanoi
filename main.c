/* Torre de Hanói é um "quebra-cabeça" que consiste em uma base contendo três pinos, \
em um dos quais são dispostos alguns discos uns sobre os outros, em ordem crescente de diâmetro, \
de cima para baixo. O problema consiste em passar todos os discos de um pino para outro qualquer, \
usando um dos pinos como auxiliar, de maneira que um disco maior nunca fique em cima de outro \
menor em nenhuma situação. O número de discos pode variar sendo que o mais simples contém apenas três.

De forma explícita, portanto, as regras a serem implementadas são:

> Movimentar uma só peça (disco) de cada vez.
> Uma peça maior não pode ficar acima de uma menor.
> Não é permitido movimentar uma peça que esteja abaixo de outra.

*/

#include <stdio.h>
#include <stdlib.h> //para limprar a tela: system("cls");
#include <windows.h> //para beep: Beep(500, 500);
void mover();
int a, b;
int level[3] = {3, 0, 0};
int i, j;
int torre[3][4] = {
    {4, 3, 2, 1},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
};
char pos_0[400] = {"\
\n       ||           ||           || \
\n      OOOO          ||           || \
\n     OOOOOO         ||           || \
\n    OOOOOOOO        ||           || \
\n   OOOOOOOOOO       ||           || \
\n========================================== \
\n|     T  0         T  1         T  2     |\
\n==========================================\n"
};

char pos_1[400] = {"\
\n       ||           ||           || \
\n       ||           ||           || \
\n     OOOOOO         ||           || \
\n    OOOOOOOO        ||           || \
\n   OOOOOOOOOO      OOOO          || \
\n========================================== \
\n|     T  0         T  1         T  2     |\
\n==========================================\n"
};

char pos_2[400] = {"\
\n       ||           ||           || \
\n       ||           ||           || \
\n     OOOOOO         ||           || \
\n    OOOOOOOO        ||           || \
\n   OOOOOOOOOO       ||          OOOO\
\n========================================== \
\n|     T  0         T  1         T  2     |\
\n==========================================\n"
};

char pos_3[400] = {"\
\n       ||           ||           || \
\n       ||           ||           || \
\n       ||           ||           || \
\n    OOOOOOOO        ||           || \
\n   OOOOOOOOOO     OOOOOO        OOOO\
\n========================================== \
\n|     T  0         T  1         T  2     |\
\n==========================================\n"
};

char pos_4[400] = {"\
\n       ||           ||           || \
\n       ||           ||           || \
\n       ||           ||           || \
\n    OOOOOOOO       OOOO          || \
\n   OOOOOOOOOO     OOOOOO         ||\
\n========================================== \
\n|     T  0         T  1         T  2     |\
\n==========================================\n"
};

char pos_5[400] = {"\
\n       ||           ||           || \
\n       ||           ||           || \
\n       ||           ||           || \
\n       ||          OOOO          || \
\n   OOOOOOOOOO     OOOOOO      OOOOOOOO\
\n========================================== \
\n|     T  0         T  1         T  2     |\
\n==========================================\n"
};

char pos_6[400] = {"\
\n       ||           ||           || \
\n       ||           ||           || \
\n       ||           ||           || \
\n      OOOO          ||           || \
\n   OOOOOOOOOO     OOOOOO      OOOOOOOO\
\n========================================== \
\n|     T  0         T  1         T  2     |\
\n==========================================\n"
};

char pos_7[400] = {"\
\n       ||           ||           || \
\n       ||           ||           || \
\n       ||           ||           || \
\n      OOOO          ||         OOOOOO \
\n   OOOOOOOOOO       ||        OOOOOOOO\
\n========================================== \
\n|     T  0         T  1         T  2     |\
\n==========================================\n"
};

char pos_8[400] = {"\
\n       ||           ||           || \
\n       ||           ||           || \
\n       ||           ||          OOOO \
\n       ||           ||         OOOOOO \
\n   OOOOOOOOOO       ||        OOOOOOOO\
\n========================================== \
\n|     T  0         T  1         T  2     |\
\n==========================================\n"
};

char pos_9[400] = {"\
\n       ||           ||           || \
\n       ||           ||           || \
\n       ||           ||           || \
\n    OOOOOOOO        ||           || \
\n   OOOOOOOOOO      OOOO        OOOOOO \
\n========================================== \
\n|     T  0         T  1         T  2     |\
\n==========================================\n"
};

int main(void)
{
	char sair = 'n'; 

    printf("%s", pos_0);
	
	while (sair == 'n') {
	printf("\nDe que torre gostaria de mover? ");
    scanf("%d", &a);
    printf("Para que torre gostaria de mover? ");
    scanf("%d", &b);
    mover(a, b);
	}

    return 0;
}

    void mover(int a, int b)
    {
    	system("cls");

		if (torre[a][0] != 0 && torre[b][0] == 0){
			torre[b][level[b]] = torre[a][level[a]];
            torre[a][level[a]] = 0;
            if (level[a] != 0){
            	level[a] -= 1;
			}
			if (level[b] != 0){
            level[b] += 1;
        	}

           	

		} else if (torre[a][0] != 0 && torre[b][0] != 0 && torre[b][level[b]] > torre[a][level[a]]){
			torre[b][level[b]+1] = torre[a][level[a]];
            torre[a][level[a]] = 0;
            if (level[a] != 0){
            	level[a] -= 1;
			}
			if (level[b] != 0){
            level[b] += 1;
        	}

		}
		
		else {
			printf("\nMOVIMENTO NAO PERMITIDO!\n");
			Beep(500, 500);
		}
        
        if (torre[0][3] == 1) {
            printf("%s", pos_0);
        } else if  (torre[0][3] == 0 && torre[1][0] == 1 && torre[2][0] == 0){
			printf("%s", pos_1);
		} else if  (torre[0][3] == 0 && torre[1][0] == 0 && torre[2][0] == 1){
			printf("%s", pos_2);
		} else if  (torre[1][0] == 2 && torre[2][0] == 1 && torre[0][0] == 4){
			printf("%s", pos_3);
		} else if  (torre[1][0] == 2 && torre[1][1] == 1 && torre[2][0] == 0){
			printf("%s", pos_4);
		} else if  (torre[1][0] == 2 && torre[1][1] == 1 && torre[2][0] == 3){
			printf("%s", pos_5);
		} else if  (torre[1][0] == 4 && torre[0][1] == 1 && torre[2][0] == 3){
			printf("%s", pos_6);
		} else if  (torre[0][0] == 4 && torre[0][1] == 1 && torre[1][0] == 0){
			printf("%s", pos_7);
		} else if  (torre[2][0] == 3 && torre[2][1] == 2 && torre[2][2] == 1){
			printf("%s", pos_8);
		} else if  (torre[1][0] == 1 && torre[2][0] == 2 && torre[0][0] == 4){
			printf("%s", pos_9);
		} else {
            printf("\n");
        int i, j;
	        for (i = 0; i < 3; i++)
	        {
	            for (j = 0; j < 4; j++)
	            {
	                printf("%d ", torre[i][j]);
	            }
	            printf("\n");
        }
        }

		
        //printf("Level da torre 0: %d ", level[0]);
        //printf("Level da torre 1: %d ", level[1]);
        //printf("Level da torre 2: %d ", level[2]);
    }


