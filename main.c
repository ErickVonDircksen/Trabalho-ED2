#include <stdio.h>     //montar os exemplos de load para 10,100,1000, 1500 acessos. DONE
#include <stdlib.h>    // montar o marcador de tempo para as operaçoes de load   DONE
#include <string.h>    // montar o print bonito da estrela e da terra na tela com variação de tamanhos comforme algum dado.
#include <time.h>
#include "Avb.h"       
#include "Hash.h"

int main() {
  int Lydist, ch,i,aux=0,valList[2000],input;
  int M = 20000;      
   Hash *H = create_hash (M); //Cria a hash que vai armazenar a parte 'char' dos dados de uma determinada estrela
  double Tempo; 
  clock_t Ticks[2];

    char TEMPnome[256];
    char TEMPdist_ang[128];
    char TEMPdeclinacao[128];
    char TEMPmagnitude[64];
    char TEMPmagnitudeGeral[64];
    char TEMPclasse[128];
    char TEMPtrivia[512];

  FILE *fp;
      fp = fopen("DataStar.txt", "r");
      char buff[1024 * 4];
      if(fp != NULL)
      printf("Star Data carregado com sucesso!\n");

  while (fgets(buff, 1024 * 4, (FILE *)fp))
    {
    char delim[] = "$";
    char *ptr = strtok(buff, delim);

        int index = 0;
        Lydist=0;
        aux++; //auxilina na correta incerção dos valores "Lydist" no vertor auxiliar "valList".
        while (ptr != NULL){ 
            if (index == 0) {// Nome da estrela
                //printf("%s \n",ptr);
                strcpy(TEMPnome,ptr);
                //printf("%s",TEMPnome);
            }     
            else if (index == 1){ // Distancia angular
               //printf("%s \n",ptr);
                strcpy(TEMPdist_ang, ptr);}

            else if (index == 2){ // Declinação
                //printf("%s",ptr);
                strcpy(TEMPdeclinacao, ptr);
               }

            else if (index == 3) {// Magnitude
                 //printf("%s",ptr);
                strcpy(TEMPmagnitude, ptr);}

            else if (index == 4){ // Magnitude geral
               //printf("%s",ptr);
                strcpy(TEMPmagnitudeGeral,ptr);
                 //printf("%s",TEMPmagnitudeGeral);
              }   
            else if (index == 5) {// distancia
               // printf("%s\n",ptr);  
               Lydist= atoi(ptr);
              // printf("%d-\n",Lydist);
               insertion(Lydist);}
            else if (index == 6){ // Classe
              //printf("%s",ptr);
               strcpy(TEMPclasse,ptr);
            }
            else if (index == 7){ // Trivia
              //printf("%s \n",ptr);
               strcpy(TEMPtrivia,ptr);
            }

            if(index==7){
           insert_chained(H, Lydist, TEMPnome,TEMPdist_ang,TEMPdeclinacao,
           TEMPmagnitude,TEMPmagnitudeGeral,TEMPclasse,TEMPtrivia) ;
            valList[aux]=Lydist;
            }

            ptr = strtok(NULL, delim);
            index++;
            
        }

    }
  fclose(fp);
  
  while (1) {
                  printf("1. Mostar exemplo de 10 acessos\t2.Mostar exemplo de 100 acessos \n");
                  printf("3. Mostar exemplo de 1000 acessos\t4. Mostar exemplo de 1500 acessos\n");
                  printf("5. Mostar exemplo de N acessos\t6.Demonstração de N dados armazenados. \n");
                  printf("7. SAIR\nEnter your choice:");
                  scanf("%d", &ch);
                  switch (ch) {
                          case 1: 
                                 Ticks[0] = clock();
                                 for(i=0;i<10;i++){
                                    busca_exemplo(valList[i],root->Lydist,root);
                                 }
                                 Ticks[1] = clock();
                                 Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
                                 printf("Tempo gasto: %g ms. \n", Tempo);
                                  break;
                          case 2: Ticks[0] = clock();
                                  for(i=0;i<100;i++){
                                    busca_exemplo(valList[i],root->Lydist,root);
                                 }
                                 Ticks[1] = clock();
                                 Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
                                 printf("Tempo gasto: %g ms. \n", Tempo);
                                  break;
                          case 3:Ticks[0] = clock();
                                 for(i=0;i<1000;i++){
                                    busca_exemplo(valList[i],root->Lydist,root);
                                 }
                                 Ticks[1] = clock();
                                 Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
                                 printf("Tempo gasto: %g ms. \n", Tempo);

                                  break;
                          case 4: Ticks[0] = clock();
                                   for(i=0;i<1535;i++){
                                    busca_exemplo(valList[i],root->Lydist,root);
                                 } Ticks[1] = clock();
                                 Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
                                 printf("Tempo gasto: %g ms. \n", Tempo);

                                  break;
                          case 5: Ticks[0] = clock();
                                  printf("Digite o valor de acessos a serem efetuados(1~1500)");
                                  scanf("%d", &input);
                                  for(i=0;i<input;i++){
                                    busca_exemplo(valList[i],root->Lydist,root);
                                 } Ticks[1] = clock();
                                 Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
                                 printf("Tempo gasto: %g ms. \n", Tempo);

                           case 6:
                                  printf("Digite o nunmero de dados a serem exemplificados (1~1500)");
                                  scanf("%d", &input);
                                  Ticks[0] = clock();
                                   for(i=1;i<input;i++){
                                   print_hash(H,valList[i]);
                                 }Ticks[1] = clock();
                                 Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
                                 printf("Tempo gasto: %g ms. \n", Tempo);
                                  break;       
                          case 7:
                                   exit(0);
                                  break;
                          default:
                                  printf("Digite uma opçao válida.!!\n");
                                  break;
                  }
                  
                  
  }
}