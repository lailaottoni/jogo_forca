#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include <time.h>
#include <strings.h> 
#include <ctype.h>

typedef struct
{
    int theme;
    int dificult;
    int win;
    int defeat;

}regreport;

/* imprime a forca*/
void print_forca(int x)
{
    
    switch(x)
    {
        case 0:
            printf("\n--------------------");
            printf("\n|                  |");
            printf("\n|");
            printf("\n|");
            printf("\n|");
            printf("\n|");
            printf("\n|");
            printf("\n-");
        break;

        case 1:

            printf("\n--------------------");
            printf("\n|                  |");
            printf("\n|                  O");
            printf("\n|");
            printf("\n|");
            printf("\n|");
            printf("\n|");
            printf("\n-");
        break;

        case 2:

            printf("\n--------------------");
            printf("\n|                  |");
            printf("\n|                  O");
            printf("\n|                  |");
            printf("\n|");
            printf("\n|");
            printf("\n|");
            printf("\n-");
        break;

        case 3:

            printf("\n--------------------");
            printf("\n|                  |");
            printf("\n|                  O");
            printf("\n|                 -|");
            printf("\n|");
            printf("\n|");
            printf("\n|");
            printf("\n-");
        break;

        case 4:

            printf("\n--------------------");
            printf("\n|                  |");
            printf("\n|                  O");
            printf("\n|                 -|-");
            printf("\n|");
            printf("\n|");
            printf("\n|");
            printf("\n-");
        break;

        case 5:

            printf("\n--------------------");
            printf("\n|                  |");
            printf("\n|                  O");
            printf("\n|                 -|-");
            printf("\n|                 /");
            printf("\n|");
            printf("\n|");
            printf("\n-");
        break;

         case 6:

            printf("\n--------------------");
            printf("\n|                  |");
            printf("\n|                  O");
            printf("\n|                 -|-");
            printf("\n|                 / \\");
            printf("\n|");
            printf("\n|   >> Perdeu o Jogo  ");
            printf("\n-");
        break;


    }
    
        
}

/*IMPRIME MENUS***/
void principal_menu()
{ 
    printf("\n");
    printf("*              MENU             *\n");
    printf("1- Escolha o grau de dificuldade \n2- Escolha o tema das palavras \n3- Começar o jogo \n4- Relatório \n0- sair \n");
    printf("\n");
}

void dificult_menu()
{
    printf("\n");
    printf("Escolha o grau de dificuldade: \n");
    printf("1- Fácil: 18 tentativas \n2- Médio: 12 tentativas \n3- Difícil: 6 tentativas\n");
    printf("\n");
}

void theme_menu()
{
    printf("\n");
    printf(" Esolha o tema das palavras \n");
    printf("1- Animais \n2- Países \n3- frutas \n");
    printf("\n");
}

void title_game()
{
    printf("*************************\n");
    printf("***** JOGO DA FORCA *****\n");
    printf("*************************\n");

    printf("\n\n>> Ao Navegar pelos Menus\n>> Você deve digitar o número referente a opção escolhida!\n");
}

void fileinvector(FILE *archive, char vetor[][100], int x)
{
    int i, z;
    char info[100];
    i = 0;
    z = 0;
    while (fscanf(archive, "%d,%[^\n]", &z, info) == 2)
    {
        if (z == x)
        {
            strcpy(vetor[i], info);
            i++;
        }
    }
}

/***ESCOLHE ALEATÓRIAMENTE UMA PALAVRA DO VETOR****/
void choiceword(char vetor[][100], char *vetorout)
{
    int i;
    i = rand()%10;
    strcpy(vetorout,vetor[i]);
}

int main(void) 
{
    int choice, choice2, choice3, attempts, i, x, game, tag, k, l, m, j, errors,z, out, same;
    char words[100][100], chosenword[100], letter, guess[100], formation[100];
    char gone[100];
    int dificult, theme, win, defeat;
    int win2;
    int defeat2;
    regreport regaux[100];

    FILE *list;

    game = 1;
    attempts = 0;
    choice3 = 0;
    
    m=0;
    l=0;

    srand(time(0));

    title_game();
    printf("\n");
    
    principal_menu();
    printf("\n");
    scanf("%d", &choice);
    while (choice != 0) /* NAVEGANDO MENU PRINCIPAL*/
    {
        if( choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 0)
        {
            printf("Digite uma opção válida\n");
        }

        switch (choice) 
        {
            case 1: /* ESCOLHA DA DIFICULDADE*/

                dificult = 0;

                dificult_menu();
                scanf("%d", &choice2);
                printf("\n");

                switch(choice2)
                {
                    case 1:

                        attempts = 18;
                        dificult = 1;

                    break;

                    case 2:

                        attempts = 12;
                        dificult = 2;

                    break;

                    case 3:

                        attempts = 6;
                        dificult = 3;

                    break;
                }

                printf("Dificuldade Escolhida com sucesso\n");
                printf("\n");

            break;

            case 2: /*ESCOLHENDO O TEMA */

                theme = 0;

                theme_menu();
                scanf("%d", &choice3);
                printf("\n");

                list = fopen("palavras.txt","r");
                        
                if(list == NULL)
                {
                    fprintf(stderr, "Não foi possível abrir o arquivo\n");
                    return 1;
                }
                else
                {
                    fileinvector(list, words, choice3);
                    fclose(list);
                }

                switch (choice3)
                {
                    case 1:

                        theme = 1;

                    break;

                    case 2:

                        theme = 2;
                       
                    break;

                    case 3:
                    
                        theme = 3;
                
                    break;
                
                }
                
                printf("Tema escolhido com sucesso\n\n");

                for(i=0;i<10;i++)
                {
                    printf("palavra: %s\n", words[i]);
                }

            break;

            case 3: /* COMEÇANDO O JOGO */

                if(attempts == 0 || choice3 == 0)
                {
                    printf("\nVocê deve escolher a dificuldade e tema primeiro.\n\n");
                    principal_menu();
                    printf("\n");
                    scanf("%d", &choice);
                }
                else
                {

                    win = 0;
                    defeat = 0;

                    choiceword(words, chosenword); /* ESCOLHENDO A PALAVRA*/
                    
                    printf("\n _________________________________\n");
                    printf("|                                 |\n");
                    printf("| >> Este é seu jogo número: %d    |\n", game);

                    switch (attempts)
                    {
                        case 18:
                            printf("| Sua dificuldade é: Fácil        |\n");
                        break;
                        case 12:
                            printf("| Sua dificuldade é: Média        |\n");
                        break;
                        case 6:
                            printf("| Sua dificuldade é: Difícil      |\n");
                        break;
                    };

                    switch (choice3)
                    {
                        case 1:
                            printf("| Seu tema é: Animais             |\n");
                        break;
                        case 2:
                            printf("| Seu tema é: Países              |\n");
                        break;
                        case 3:
                            printf("| Seu tema é: Frutas              |\n");
                        break;
                    };

                    printf("| >> A palavra tem: %ld letras <<   |\n", strlen(chosenword));
                    printf("|_________________________________|\n");


                    /*COLOCANDO OS '_'*/
                    for(i = 0; i < strlen(chosenword); i++)
                    {
                        formation[i]='_';
                    }
                    formation[i]= '\0';
                    
                    k=0;
                    gone[k]='\0';  
                    z=0;
                    errors = 0;
                    out = 0;
                    same = 0;

                    printf("\n|| Digite uma letra: \n");
                    scanf(" %c", &letter);
                    while(out == 0 && same == 0) /* JOGANDO A FOCA  */
                    {
                        tag = 0; /*VERIFICA AS LETRAS*/
                    
                        for(i = 0; i < strlen(chosenword); i++) /*SE A LETRA FOR IGUAL COLOCA NO VETOR EM FORMAÇÃO*/
                        {
                            
                            if(tolower(letter) == chosenword[i])
                            {
                                tag = 1;
                                formation[i] = chosenword[i];
                            }
                        }

                        if(tag == 0) /*SE NÃO TEM A LETRA COLOCA NO VETOR JÁ FOI*/
                        {
                            gone[k]= tolower(letter);
                            k= k + 1;
                            gone[k]= ' ';
                            k= k + 1;
                            gone[k]= '\0';

                            errors = errors + 1;

                            switch (attempts) /*TRATANDO AS != DIFICULDADES*/
                            {
                                case 6:
                              
                                    z = z + 1;

                                break;

                                case 12:

                                    if( errors % 2 == 0)
                                    {
                                        z = z + 1;
                                    }
                                
                                break;
                                
                                case 18:

                                    if( errors % 3 == 0)
                                    {
                                        z = z + 1;
                                    }
                                
                                break;

                            }

                            printf("\n>>>> Não tem essa letra!! \n\n");
                            printf("|| Letras que já foram: %s ||\n\n", gone);

                        }

                        print_forca(z);
                        l=0;
                        printf("\n");
                        while(formation[l] != '\0')
                        {
                            printf("%c ",formation[l]);
                            l=l+1;
                        }
                        printf("\n\n");

                        if(errors == attempts) /* CONTROLANDO A SAÍDA */
                        {
                            out = 1;
                            defeat = defeat + 1; /*É DERROTADO QUANDO ACABA AS TENTATIVAS, NÃO POR CHUTE ERRADO*/
                        }

                        if( strcasecmp(formation,chosenword) == 0) /* CONTROLANDO QNDO OS VETORES SÃO IGUAIS*/
                        {
                            same = 1;
                        }

                        if(out != 1 && same != 1) /* NÃO ACABOU AS TENTATIVAS E  NÃO COMPLETOU O VETOR FORMAÇÃO */
                        {
                            printf("\n>> Dejesa Chutar? 1-SIM / 2-Não\n\n");
                            scanf("%d", &x);

                            if( x == 1)
                            {
                                printf("Digite seu palpite:\n");
                                scanf("%s", guess);

                                if( strcasecmp(guess, chosenword) == 0 )
                                {
                                    printf("\nvocê acertou!!! \n");
                                    printf("Número de erros: %d\n", errors);
                                    out = 1;
                                    win = win + 1; /* VITORIA POR CHUTE */
                                }
                                else
                                {
                                    printf("\nvocê errou!!!\n");
                                }
                            }
                            else
                            {
                                
                                printf("|| Digite uma letra:\n");
                                scanf(" %c",&letter);

                                if( strchr(formation, letter) || strchr(gone, letter) )
                                {
                                    printf("\n>>>>> Você já digitou essa letra <<<<<<\n\n");
                                    printf("|| Digite uma letra:\n");
                                    scanf(" %c",&letter);
                                    while (strchr(formation, letter) || strchr(gone, letter))
                                    {
                                        printf("\n>>>>> Você já digitou essa letra <<<<<<\n\n");
                                        printf("|| Digite uma letra:\n");
                                        scanf(" %c",&letter);
                                    }  
                                }
                                
                            }
                        }

                        if( same == 1 )
                        {
                            printf("\nvocê acertou!!! \n");
                            printf("Número de erros: %d\n", errors);
                            win = win + 1; /* VITÓRIA POR COMPLETAR A PALAVRA ANTES DO LIMITE DE TENTATIVAS*/
                        } 

                    }

                    printf("\n >>>>>> A palavra é: %s\n\n", chosenword);

                    regaux[m].dificult = dificult;
                    regaux[m].theme = theme;
                    regaux[m].win =  win;
                    regaux[m].defeat = defeat;
                    m = m + 1;
                    game = game + 1;

                }

            break;

            case 4:

                printf("\n Você jogou %d vezes!\n\n", game-1);

                for(i=1;i<4;i++)
                {
                    for(j=1; j<4; j++)
                    {
                        win2 = 0;
                        defeat2 = 0;

                        for(k=0;k<m;k++)
                        {
                            if(regaux[k].theme == i && regaux[k].dificult == j)
                            {
                                win2 =win2 + regaux[k].win;
                                defeat2 = defeat2 + regaux[k].defeat;
                            }

                        }

                        if(win2 != 0 || defeat2 != 0)
                        {

                            if(i == 1)
                            {
                                if(j == 1)
                                {
                                    
                                    printf("tema: Animais\n");
                                    printf("Dificuldade: Fácil\n");
                                    printf("vitoria: %d\n", win2);
                                    printf("derrota: %d\n", defeat2);
                                }
                                else
                                {
                                    if(j==2)
                                    {
                                        printf("tema: Animais\n");
                                        printf("Dificuldade: Média\n");
                                        printf("vitoria: %d\n", win2);
                                        printf("derrota: %d\n", defeat2);
                                    }
                                    else
                                    {
                                        printf("tema: Animais\n");
                                        printf("Dificuldade: Difícil\n");
                                        printf("vitoria: %d\n", win2);
                                        printf("derrota: %d\n", defeat2);
                                    }
                                }
                            }
                            else
                            {
                                if(i == 2)
                                {
                                    if(j == 1)
                                    {
                                        
                                        printf("tema: Países\n");
                                        printf("Dificuldade: Fácil\n");
                                        printf("vitoria: %d\n", win2);
                                        printf("derrota: %d\n", defeat2);
                                    }
                                    else
                                    {
                                        if(j==2)
                                        {
                                            printf("tema: Países\n");
                                            printf("Dificuldade: Média\n");
                                            printf("vitoria: %d\n", win2);
                                            printf("derrota: %d\n", defeat2);
                                        }
                                        else
                                        {
                                            printf("tema: Países\n");
                                            printf("Dificuldade: Difícil\n");
                                            printf("vitoria: %d\n", win2);
                                            printf("derrota: %d\n", defeat2);
                                        }
                                    }
                                }
                                else
                                {
                                    if(j == 1)
                                    {
                                        
                                        printf("tema: frutas\n");
                                        printf("Dificuldade: Fácil\n");
                                        printf("vitoria: %d\n", win2);
                                        printf("derrota: %d\n", defeat2);
                                    }
                                    else
                                    {
                                        if(j==2)
                                        {
                                            printf("tema: Frutas\n");
                                            printf("Dificuldade: Média\n");
                                            printf("vitoria: %d\n", win2);
                                            printf("derrota: %d\n", defeat2);
                                        }
                                        else
                                        {
                                            printf("tema: Frutas\n");
                                            printf("Dificuldade: Difícil\n");
                                            printf("vitoria: %d\n", win2);
                                            printf("derrota: %d\n", defeat2);
                                        }
                                    }   
                                }
                            }

                        }

                    }
                }

            break;
        }

        principal_menu();
        scanf("%d", &choice);
    }
    
    return 0;
}