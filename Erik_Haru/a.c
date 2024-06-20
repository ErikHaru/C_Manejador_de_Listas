#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include"lib.h"
// CREAR LO DE LAS LISTAS VACIAS
int main ()
{

   TVARS *TVS = (TVARS*)malloc(sizeof(TVARS));
   TVS->var1 = NULL;
   printf("\nNombre: \tErik\nApellido: \tHarutyunyan\nCorreo: \terik.harutyunya@goumh.umh.es\n\n");
   //save
   TVAR *aux=NULL;
   TNUM *num=NULL;

   int i=0, f=0, e=0, v=0, g=0, a=0,j=0;
   char *P1,*P2,*P3, *P4, *TK, *p, *pointer, *pn;

   //load
   char linea[1001];
   char var[1001];
   char valores[1001];
   FILE *fichero=NULL;
   int cont;

   char *RC[20], *RC2[20], *RC3[20];
   char promt[5000],promt2[5000],promt1[5000],promt3[5000],promt4[5000],promt5[5000];
   TNUM *TN=NULL, *TN2=NULL;
   TLISTA *list1=NULL,*T2aux=NULL,*T1aux=NULL,*TFaux=NULL;
   TVAR *TV=NULL;
   TVAR *TV2=NULL;
   TVAR *T1=NULL,*T2=NULL,*T3=NULL;
   while(1)
   {


      //DestruirValor(T1aux); DestruirValor(T2aux); DestruirValor(T3aux); 
      
      TextColor(WHITE);
      printf("<*>:");
      
      gets(promt);
      TextColor(GREEN);
      if(promt == NULL)
         continue;
         T2 = NULL;
         T3 = NULL;

      ////******************************************** ¿Como se ha planteado el proyecto? ***************************************************
      ////                                                                                                                                \\\\
      ////                                                                                                                                ////
      ////                                                                                                                                \\\\
      ////                                                                                                                                ////
      ////  Dividimos el promt en 3 partes depndiento de si es '+','-','#' o '=' y vemos que puede poner el usuario dentro de cada una.   \\\\
      ////                     Hay que tener en cuenta que no siempre se utilizaran las 3 partes.                                         ////
      ////                                                                                                                                \\\\
      ////                                                                                                                                ////
      ////                                                                                                                                \\\\
      ////                                                                                                                                ////
      ////******************************************** ¿Como se ha planteado el proyecto? ***************************************************


      ////******************************************** ESTRUCTURA ***************************************************
      //                                                                                                          \\\\
      // PROMT --> |*P1|  |*RC[1]|  |(*P2)*RC[2](*P2)|  |*RC[3]|  |(P3)*RC[4](P3)|  |RC[5]| |*P4|                 ////
      //*RC[1] --> Primera parte                                                                                  \\\\
      //*RC[2] --> #/=/+/-                                                                                        ////
      //*RC[3] --> Segunda parte                                                                                  \\\\
      //*RC[4] --> +/-                                                                                            ////
      //*RC[5] --> Tercera parte                                                                                  \\\\ 
      //                                                                                                          ////
      ////******************************************** ESTRUCTURA ***************************************************


      for (int i = 0; i < 20; i++) // Inicializamos a NULL
         RC[i] = NULL;
      
      strcpy(promt2,promt);
      P1 = &promt2[0]; // NO ENTIENDO *P1 = &promt2[0];


      if((P2=strchr(promt2, '='))!= NULL) // ALGO = (ALGO)/(ALGO +/- ALGO)
      {

         //copaimos en la posicion 1 toda la primera parte
         P1=P1-1;
         CopiarListaEnPosicion(RC,1,P1,P2);

         //Copiamos en la posicion 2 el '='
         CopiarListaEnPosicion(RC,2,P2,P2);
         
         for ( i = 0; P2[i] != '\0'; i++) // ALGO = ALGO +/- ALGO
         {
            if ((P2[i] == ' ' && P2[i+1] == '+' && P2[i+2] == ' ') || (P2[i] == ' ' && P2[i+1] == '-' && P2[i+2] == ' ')) 
            {

               P3 = &P2[i+1];
               // Copiamos en la posicion 3 todo la parte 2
               CopiarListaEnPosicion(RC,3,P2,P3);

               // Copiamos en la posicion 4, la suma o la resta
               CopiarListaEnPosicion(RC,4,P3,P3);

               // Copiamos en la posicion 5 la tercera parte
               P4=strchr(promt2, '\0');
               CopiarListaEnPosicion(RC,5,P3,P4);
               j=0;
               break;
            }
            j=1;

         }


         if(j==1) // ALGO = ALGO
         {
            // Copiamos en la posicion 3 la segunda parte
            P3=strchr(promt2, '\0');
            CopiarListaEnPosicion(RC,3,P2,P3);
         }
      }

      if((P2=strchr(promt2, '#'))!= NULL) // ALGO # ALGO
      {
         //copaimos en la posicion 1 en la primera parte
         P1=P1-1;
         CopiarListaEnPosicion(RC,1,P1,P2);

         // Copiamos en la posicion 2 el '#'
         CopiarListaEnPosicion(RC,2,P2,P2);

         // Copiamos en la posicion 3 la segunda parte
         P3=strchr(promt2, '\0');
         CopiarListaEnPosicion(RC,3,P2,P3);
         

      }

      if (1)   // ALGO +/- ALGO
      {
         P2 = &promt2[0];
         
         for (i = 0; P1[i] != '\0'; i++) 
         {
            if ((P1[i] == ' ' && P1[i+1] == '+' && P1[i+2] == ' ') || (P1[i] == ' ' && P1[i+1] == '-' && P1[i+2] == ' ')) 
            {
               f=1;

               P2 = &P1[i+1];
               // Copiamos en la posicion 1 todo la parte 1
               CopiarListaEnPosicion(RC,1,P1-1,P2);


               // Copiamos en la posicion 2, la suma o la resta
               CopiarListaEnPosicion(RC,2,P2,P2);

               // Copiamos en la posicion 3 la segunda parte
               P3=strchr(promt2, '\0');
               CopiarListaEnPosicion(RC,3,P2,P3);
               i--;
               break;
            }
         }

      }

      if((P2=strchr(promt2, '#'))== NULL && (P2=strchr(promt2, '='))== NULL && (f==0)) // ALGO
      {
         //copaimos en la posicion 1 toda la primera parte
         for ( i = 0; i < 2000; i++) 
            RC[1] = promt2;

      }
      f=0;


      //Vamos a ver si en alguna posicion hay un espacio en ese caso vamos a poner NULL.
      char *token;
      for (i = 1; i<=5; i++) // Hacemos una copia de RC y la tokenizamos para ver eso
      {

         if(i==1||i==3||i==5)
         {
            if(RC[i]!=NULL)
            {
               RC3[i] = strdup(RC[i]);
               token = strtok( RC3[i], " \t\n\r" );
               if(token == NULL)
                  {
                     RC[i] = NULL;
                  }
            }
               
            else
               RC3[i] = NULL;
         }
            
      }


      // printf("\n\nRC1 es [%s]\n",RC[1]);
      // printf("RC2 es [%s]\n",RC[2]);
      // printf("RC3 es [%s]\n",RC[3]);
      // printf("RC4 es [%s]\n",RC[4]);
      // printf("RC5 es [%s]\n\n",RC[5]);

      ////                                                                                            \\\\
      ////                                                                                            ////
      ////                                                                                            \\\\
      ////                                                                                            ////
      ////  Ahora vamos a crear el programa dependiendo de lo que se haya detectado en cada posicion  \\\\ 
      ////                                                                                            //// 
      ////                                                                                            \\\\
      ////                                                                                            ////
      ////                                                                                            \\\\
      
      for (i = 1; i<=5; i++) // Hacemos una copia de RC
      {

         if(i==1||i==3||i==5)
         {
            if(RC[i]!=NULL)
               RC2[i] = strdup(RC[i]);
            else
               RC2[i] = NULL;
         }
            
      }  

      // Vemos errores sintacticos

      int trc=0;
      if      ((RC[1]!=NULL) && (RC[2]==NULL) && (RC[3]==NULL) && (RC[4]==NULL) && (RC[5]==NULL)){trc=1;} // ALGO     
      else if ((RC[1]!=NULL) && (*RC[2]=='+') && (RC[3]!=NULL) && (RC[4]==NULL) && (RC[5]==NULL)){trc=2;} // ALGO + ALGO
      else if ((RC[1]!=NULL) && (*RC[2]=='-') && (RC[3]!=NULL) && (RC[4]==NULL) && (RC[5]==NULL)){trc=3;} // ALGO - ALGO
      else if ((RC[1]!=NULL) && (*RC[2]=='=') && (RC[3]!=NULL) && (RC[4]==NULL) && (RC[5]==NULL)){trc=4;} // ALGO = ALGO
      else if ((RC[1]!=NULL) && (*RC[2]=='=') && (RC[3]!=NULL) && (*RC[4]=='+') && (RC[5]!=NULL)){trc=5;} // ALGO = ALGO + ALGO
      else if ((RC[1]!=NULL) && (*RC[2]=='=') && (RC[3]!=NULL) && (*RC[4]=='-') && (RC[5]!=NULL)){trc=6;} // ALGO = ALGO - ALGO
      else if ((RC[1]!=NULL) && (*RC[2]=='#') && (RC[3]!=NULL) && (RC[4]==NULL) && (RC[5]==NULL)){trc=7;} // ALGO # ALGO
      else if ((RC[1]==NULL) && (RC[2]==NULL) && (RC[3]==NULL) && (RC[4]==NULL) && (RC[5]==NULL)){continue;}
      else
      {
         TextColor(RED);
         printf("ERROR. Sintaxis invalida\n");
         continue;
      }


      // Creamos copias
      char *RCT1[5000];
      char *RCT2[5000];
      char *RCT3[5000];
      if(RC[1]!=NULL)
      {   
         strcpy(promt3, RC[1]);  
         e = NumeroTokens(promt3,RCT1);      
      }

      if(RC[3]!=NULL)
      {   
         strcpy(promt4, RC[3]);
         v = NumeroTokens(promt4,RCT2);      
      }  

      if(RC[5]!=NULL)
      { 
         strcpy(promt5, RC[5]);
         g = NumeroTokens(promt5,RCT3);      
      }       



      if (trc==1) // ALGO
      { 
         if(strcmp(RCT1[0], "sum")!= 0 && strcmp(RCT1[0], "exit")!= 0 && strcmp(RCT1[0], "isIn")!= 0 && strcmp(RCT1[0], "vars")!= 0 && strcmp(RCT1[0], "save")!= 0 && strcmp(RCT1[0], "load")!= 0)
            T1 = CrearParte(TVS,RC[1]);
         if(RCT1[0][0]=='[')                       // [ALGO]
         {
            if(T1->valor !=NULL)
            {
               T1aux = DuplicarList(T1->valor);
               ImprimirLista(T1aux);
               DestruirLista(T1aux);
               DestruirLista(T1->valor);
            }
            else
            {
               TextColor(RED);
               printf("ERROR. No se ha generado correctamente la lista\n");
               continue;
            }

         }
         else if (strcmp(RCT1[0], "head") == 0)    // head
         {
            if(T1 != NULL)
            {
               T1aux = DuplicarList(T1->valor);
               T1aux = head(T1aux,atof(RCT1[1]));
               ImprimirLista(T1aux);
            }
            else
            {
               TextColor(RED);
               printf("ERROR. No se ha generado o encontrado correctamente la lista\n");
               continue;
            }

         }
         else if (strcmp(RCT1[0], "tail") == 0)    // tail
         {
            if(T1 != NULL)
            {
               T1aux = DuplicarList(T1->valor);
               T1aux = tail(T1aux,atof(RCT1[1]));
               ImprimirLista(T1aux);
            }
            else
            {
               TextColor(RED);
               printf("ERROR. No se ha generado o encontrado correctamente la lista\n");
               continue;
            }

         }
         else if (strcmp(RCT1[0], "map") == 0)    // map
         {
            if(T1 != NULL)
            {
               T1aux = DuplicarList(T1->valor);
               T1aux = map(T1aux,atof(RCT1[1]));
               ImprimirLista(T1aux);
            }
            else
            {
               TextColor(RED);
               printf("ERROR. No se ha generado o encontrado correctamente la lista\n");
               continue;
            }

         }
         else if (strcmp(RCT1[0], "isIn") == 0)   // isIn
         {
            if(ValidarNum(RCT1[1]) < 0) // Detector de errores
               T1aux = NULL;
            else
            {
              
               if(RCT1[2][0]=='[')
               {

                  for (i = 0; i < e; i++) 
                  {
                     if(p=strchr(RCT1[i], ']'))
                     {
                        if(RCT1[i+1]!=NULL)
                        {

                           T1aux = NULL;
                        }
                        else
                        {

                           for(a=0;RCT1[i][a]!='\0';a++)
                           {
                              if (RCT1[i][a] == ']')
                              {

                                 if(RCT1[i][a+1]!='\0')
                                 {

                                    T1aux = NULL;
                                 }
                                 else
                                 {                                   
                                    T1aux = CrearListaF(RC[1]);
                                 }

                              }

                           }

                        }

                     }
                  
                  }
                  
               }
               else 
               {
                  if(RCT1[3] != NULL)
                  {
                     TextColor(RED);
                     printf("ERROR. La variable no puede contener espacios\n");
                     continue;
                  }
                  
                  T1 = BuscarVar(TVS,RCT1[2]);
                  if(T1 != NULL)
                  {
                     T1aux = T1->valor;
                  }
                  else
                     T1aux = NULL;
               }
            }


            if(T1aux != NULL) // En caso de que no de error
            {
               if(BuscarNum(T1aux,atof(RCT1[1])) == NULL)
               {
                  printf("FALSE\n");
                  continue;
               }
                  
               else
               {
                  printf("TRUE\n");
                  continue;
               }     

            }
            else
            {
               TextColor(RED);
               printf("ERROR. No se ha generado o encontrado correctamente la lista\n");
               continue;;
               //free T1aux
            }

         }
         else if (strcmp(RCT1[0], "vars") == 0)   // vars
         {
            T1 = TVS->var1;
            while(T1 != NULL)
            {
               printf("%s --> %d\n",T1->nombre,T1->valor->n);
               T1 = T1->siguiente;

            }
            
         }
         else if (strcmp(RCT1[0], "sum") == 0)   // sum
         {
            if(RCT1[1][0] == '[')
            {
               for (i = 0; i < e; i++) 
               {
                  if(p=strchr(RCT1[i], ']'))
                  {
                     if(RCT1[i+1]!=NULL)
                     {
                        T1aux = NULL;
                     }
                     else
                     {

                        for(a=0;RCT1[i][a]!='\0';a++)
                        {
                           if (RCT1[i][a] == ']')
                           {

                              if(RCT1[i][a+1]!='\0')
                              {

                                 T1aux = NULL;
                              }
                              else
                              {                                   
                                 T1aux = CrearListaF(RC[1]);
                              }

                           }

                        }

                     }

                  }
               
               }       
                              
            }
            else 
            {
               if(RCT1[2] != NULL)
               {
                  TextColor(RED);
                  printf("ERROR. La variable no puede contener espacios\n");
                  continue;
               }
               T1 = BuscarVar(TVS,RCT1[1]);
               if(T1 != NULL)
               {
                  T1aux = T1->valor;
               }
               else
               {
                  TextColor(RED);
                  printf("ERROR. No se ha encontrado la varible\n");
                  continue;
               }
            }

            if(T1aux == NULL)
            {
               TextColor(RED);
               printf("ERROR. Lista invalida\n");
               continue;
            }
            float sum = 0;
            TNUM *sumTNUM;
            int dec=0;
            for(sumTNUM = T1aux->primero; sumTNUM !=NULL; sumTNUM->siguiente)
            {

               if(sumTNUM != NULL)
               {
                  if((sumTNUM->decimales) >= dec)
                     dec = sumTNUM->decimales;
               }
               sum = sum + sumTNUM->valor;
               sumTNUM = sumTNUM->siguiente;

            }
            printf("%.*f\n",dec,sum);
            




         }
         else if (strcmp(RCT1[0], "turn") == 0)    // turn
         {
            if(T1 != NULL)
            {
               T1aux = DuplicarList(T1->valor);
               T1aux = turn(T1aux);
               ImprimirLista(T1aux);
            }
            else
            {
               TextColor(RED);
               printf("ERROR. No se ha generado o encontrado correctamente la lista\n");
               continue;
            }

         }
         else if (strcmp(RCT1[0], "order") == 0)    // order
         {
            if(T1 != NULL)
            {
               T1aux = DuplicarList(T1->valor);
               T1aux = order(T1aux);
               ImprimirLista(T1aux);
            }
            else
            {
               TextColor(RED);
               printf("ERROR. No se ha generado o encontrado correctamente la lista\n");
               continue;
            }

         }
         else if (strcmp(RCT1[0], "exit") == 0)    // exit
         { 
            if (RCT1[1] == NULL) 
            {
               printf("Bye, bye");
               TextColor(WHITE);
               exit(0);
            } 
            else 
            {
               TextColor(RED);
               printf("ERROR. Comando invalido, 'exit' no puede ir seguido de ningun caracter o funcion\n");
               continue;
               //DestruirValor(T1);
            }
            
         }
         else if (strcmp(RCT1[0], "save") == 0) //save MEJORAR
         {
             if(strstr(RC[1],".txt") == NULL)
             {
               TextColor(RED);
               printf("ERROR. '.txt' no detectado");
               continue;
             }
               
         
            if(RCT1[2] != NULL)
            {
               TextColor(RED);
               printf("ERROR. No se admiten espacios en el nombre del fichero");
               continue;
            }

            aux = TVS->var1;
            ws = fopen(RCT1[1],"a");
            fprintf(ws,"LIST WORKSPACE\n");

            while (aux != NULL)
            {
               fprintf(ws, "---------------------------\n");
               fprintf(ws,"%s\n", aux->nombre);
               num = aux->valor->primero;
               while(num != NULL)
               {
                  fprintf(ws, "%.*f ",num->decimales,num->valor);
                  num = num->siguiente;
               }
               fprintf(ws,"\n");
               fflush(ws);
               aux = aux->siguiente;
            }
            fclose(ws);
            //atexit(cerrarArchivo);




         }
         else if (strcmp(RCT1[0], "load") == 0) //load MEJORAR
         {
            TVAR *V;
            TLISTA *L;
            char *valores2[1000];

            if(strstr(RC[1],".txt") == NULL)
            {
               TextColor(RED);
               printf("ERROR. '.txt' no detectado");
               continue;
            }
               
         
            if(RCT1[2] != NULL)
            {
               TextColor(RED);
               printf("ERROR. No se admiten espacios en el nombre del fichero");
               continue;
            }
 
            if((fichero = fopen(RCT1[1],"r")) == NULL)
            {
               TextColor(RED);
               printf("ERROR. No se ha abierto correctamente el fichero");
               continue;
            }

            cont = 0;
            fgets(linea,1000,fichero); // Titulo del fichero

            TVARS *TVS2 = (TVARS*)malloc(sizeof(TVARS));
            TVS2->var1 = NULL;
            while(!feof(fichero))
            {
               // linea 1 ----> se ignora
               if(fgets(linea,1000,fichero)==NULL)
                     break;
               // linea 2 ----> nombre de la variable
               fgets(var,1000,fichero);
               var[strlen(var)-1] = '\0';
               // linea 3 ----> valores
               fgets(valores,1000,fichero);
               if((valores[strlen(valores)-1]) == '\n')
                     valores[strlen(valores)-1] = '\0';
               cont++;

               V=CrearValor(var);
               NumeroTokens(valores,valores2);
               L = CreaListaExplicitaCH(valores2);
               V->valor = L;
               InsertarVarAlPrincipio(TVS2,V);



            }
            fclose(fichero);
            TVS = TVS2;

            

         }
         else // NOMBRE
         {
            
            if(T1!=NULL)
            {
               ImprimirLista(T1->valor);
            }

            if(T1==NULL)
            {
               TextColor(RED);
               printf("ERROR. No se ha encontrado correctamente la lista\n");
               continue;
            }

         }

         //Que no se te olvide Eliminar el TVS2 o TVS en el load.
         //Revisar la n del tail.

         if(RCT1[2] != NULL)
         {
            if(RCT1[2][0] == '[')
            {
               if(T1 != NULL)
               {
                  DestruirLista(T1aux);
                  DestruirLista(T1->valor);
               }
            }
         }

      
      }

      if (trc==2 || trc ==3) // ALGO +/- ALGO 
      {   
         TFaux = sumaresta(TVS,T1,T2,RCT1,RCT2,RC,trc);
         if(TFaux !=NULL)
         
            ImprimirLista(TFaux);
         else
         {
            TextColor(RED);
            printf("ERROR. No se ha podido ejecutar la operacion\n");
            continue;
         }
      }
 
      if(trc==4 || trc==5 || trc==6) // ALGO =
      {
         TFaux = sumaresta(TVS,T2,T3,RCT2,RCT3,RC,trc);
         if(TFaux !=NULL)
         {     

            if(ValidarNombre(RCT1[0]) == 1 && RC[2][0] == '=')
            {

               T1 = BuscarVar(TVS,RCT1[0]);

               if(T1 == NULL)
               {
                  T1 = CrearValor(RCT1[0]);
                  T1->valor = TFaux;
                  InsertarVarAlPrincipio(TVS,T1);
               }
               else
               {
                  T1->valor = TFaux;
                  InsertarVarAlPrincipio(TVS,T1);
               }
            }
            else
            {
               TextColor(RED);
               printf("ERROR. Nombre de lista invalido\n");
               continue;
               //Hay que destuir algo no se que pero algo.
            }
         }
         else
         {
            TextColor(RED);
            printf("ERROR. No se ha podido ejecutar la operacion\n");
            continue;         
         }
      }

      if (trc==7) // ALGO # ALGO
      {
         TFaux = sumaresta(TVS,T1,T2,RCT1,RCT2,RC,trc);
            continue;
      }

   }

}
