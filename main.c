/*
* Engenharia de Computação (2020)
* Programação Imperativa TDE 1 - JOGO DA FORCA
* Erick Lemmy dos Santos Oliveira  
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h> 
#include <string.h>
#include <ctype.h>
#include <windows.h>

void menu();
int life(int secretSize, char letter, char *usedLetters, char *secret[][12], int xRand, int yRand);
int score(int secretSize, char letter, char *usedLetters, char *secret[][12], int xRand, int yRand);
void letters(char *usedLetters);
void resetLetters(char *usedLetters);
int isRepeated(char *usedLetters, char letter);
void checkLetter(int secretSize, char *usedLetters, char *secret[][12], int xRand, int yRand);
void hang(int lifes);

int main(){
    char *keyword[] = {"ANIMAL", "COMIDA", "PROFISSAO", "FRUTA", "INFORMATICA"};
    char *secret[][12] = {{"AVESTRUZ", "BORBOLETA", "CARANGUEJO", "ORANGOTANGO", "CROCODILO", "DROMEDARIO", "ROUXINOL", "CENTOPEIA", "GAFANHOTO", "PINTASSILGO", "HIPOPOTAMO", "LEOPARDO", "GUAXINIM","JAGUATIRICA", "OSTRA", "MICO", "CHIMPANZE", "CARNEIRO", "GOLFINHO","MINHOCA"},
                           {"EMPADA", "FARINHA", "FEIJOADA", "COXINHA", "BRIGADEIRO", "CHURRASCO", "LASANHA", "MACARRONADA", "TORTA", "TORRADA", "PIZZA", "PANQUECA", "PIPOCA", "PAMONHA", "OVO","ACARAJE", "CROISSANT", "HAMBURGUER", "BISCOITO", "BOLO" },
                           {"ADVOGADO", "BOMBEIRO", "CARPINTEIRO", "DESENHISTA", "ENGENHEIRO", "ESCRITOR", "FERREIRO", "GUARDA", "HISTORIADOR", "JORNALISTA", "LEILOEIRO", "MARINHEIRO", "OURIVES", "PROGRAMADOR", "PADEIRO", "RELOJOEIRO", "SILVICULTOR", "TRADUTOR", "VETERINARIO", "ZOOLOGO"},
                           {"ABACATE", "BANANA", "CARAMBOLA", "DAMASCO", "FIGO","GOIABA", "JABUTICABA", "KIWI", "LARANJA", "MELANCIA", "MANGA","MARACUJA", "PESSEGO", "PITOMBA", "ROMA", "TANGERINA", "TOMATE","TAMARINDO", "UVA", "UMBU" },
                           {"LINUX", "WINDOWS", "C", "PROCESSADOR", "TECLADO", "MOUSE", "PROGRAMA", "ALGORITMO", "HACKER", "TOUCHPAD", "ASCII", "JAVA", "JAVASCRIPT", "PROGRAMADOR", "PYTHON", "INTERNET", "ROTEADOR", "SERVIDOR", "GOOGLE", "APPLE"}};

    int xRand, yRand, secretSize;
    int choice;
    char letter;
    char usedLetters[26] = {' '};

    do {
        menu();
        scanf("%d", &choice);
        setbuf(stdin, NULL);

        switch(choice){
            case 1:
                srand(time(NULL));
                xRand = rand() % 5;
                yRand = rand() % 12;
                secretSize = strlen(secret[xRand][yRand]);

                int pos = 0;
                int hits = 0;
                int lifes = 6;

                do {            
                    printf("\n|------------|                       [score: %d / %d]\n|            |                       [lifes: %d]\n", hits, secretSize, lifes);       
                    hang(lifes);
                    checkLetter(secretSize, usedLetters, secret, xRand, yRand);
                    letters(usedLetters);

                    printf("\nkeyword: %s\n", keyword[xRand]);
                    printf("\nType a letter:  ");
                    scanf("%c", &letter);
                    setbuf(stdin, NULL);

                    if(isRepeated(&usedLetters, letter) == 1){
                        printf("Repeated Letter");
                        continue;
                    }

                    usedLetters[pos] = letter;              
                    pos++;

                    hits += score(secretSize, letter, usedLetters, secret, xRand, yRand);
                    lifes -= life(secretSize, letter, usedLetters, secret, xRand, yRand);
                    
                    system("CLS");
                    if(hits >= secretSize) {
                        printf("         CONGRATS YOU WON!!\n");            
                        printf("         Answer: %s\n", secret[xRand][yRand]);
                        break;
                    }
                } while(lifes > 0);
                
                printf("\n|------------|                       [score: %d / %d]\n|            |                       [lifes: %d]\n", hits, secretSize, lifes);       
                hang(lifes);
                printf("\nRight answer: %s\n", secret[xRand][yRand]);
                resetLetters(usedLetters);

                break;
            case 2:
                exit(0);
                break;
            default:
                printf("Invalid Input!!\n");
                break;
        }    
        sleep(3);
        system("CLS");
    } while(choice != 2);
    return 0;
}

void menu(){
    printf("|--------------HANGMAN--------------|\n");
    printf("|            [1] - play             |\n");
    printf("|            [2] - exit             |\n");
    printf("|-----------------------------------|\n");
    printf("Choice: ");    
}

int life(int secretSize, char letter, char *usedLetters, char *secret[][12], int xRand, int yRand){
    for(int j = 0; j < strlen(usedLetters); j++){
        if(usedLetters[j] != letter){
            for(int i = 0; i < secretSize; i++){
                if(toupper(letter) == *(secret[xRand][yRand]+i)){
                    return 0;
                }
            }
        }
    }
    return 1;
}

int score(int secretSize, char letter, char *usedLetters, char *secret[][12], int xRand, int yRand){
    int score = 0;
    for(int i = 0; i < secretSize; i++){       
        if(toupper(letter) == *(secret[xRand][yRand] + i)){
            score += 1;
        }
    }
    return score;
}

void letters(char *usedLetters){
    printf("\nUsed Letters: ");
    for(int i = 0; i <= strlen(usedLetters); i++){
        printf(" %c ", toupper(usedLetters[i]));
    }
}

int isRepeated(char *usedLetters, char letter){
    for(int i = 0; i < strlen(usedLetters); i++){
        if(toupper(usedLetters[i]) == toupper(letter)){
            return 1;
        }
    }
    return 0;
}

void resetLetters(char *usedLetters){
    for(int i = 0; i < strlen(usedLetters); i++){
        usedLetters[i] = ' ';
    }
}

void checkLetter(int secretSize, char *usedLetters, char *secret[][12], int xRand, int yRand){
    int hasLetter;
    for(int i = 0; i < secretSize; i++){
        hasLetter = 0;
        
        for(int j = 0; j < strlen(usedLetters); j++){
            if(toupper(usedLetters[j]) == *(secret[xRand][yRand] + i)){
                printf("%c ", toupper(usedLetters[j]));
                hasLetter = 1;
                break;
            }
        }

        if(hasLetter == 0)
            printf("_ ");
    }
}

void hang(int lifes){
    switch(lifes){
        case 0: 
            printf("|           \\0/                      \n|\n| YOU LOST!!\n");
            break;
        case 1:
            printf("|            0                       \n|\n|   ");
            break;
        case 2:
            printf("|            0                       \n|            |\n|\n|   ");
            break;        
        case 3: 
            printf("|            0                       \n|            |\\\n|\n|   ");
            break;
        case 4:
            printf("|            0                       \n|           /|\\\n|\n|   ");
            break;
        case 5:
            printf("|            0                       \n|           /|\\\n|             \\\n|\n|   ");
            break;
        case 6:
            printf("|            0                      \n|           /|\\\n|           / \\\n|\n|    ");
            break;
        default:
            break;
    }
}