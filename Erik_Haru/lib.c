#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>
#include"lib.h"

TLISTA *sumaresta(TVARS *TVS,TVAR *T1,TVAR *T2,char **RCT1,char **RCT2,char **RC, int t)
{

    TLISTA *T2aux,*T1aux;
    TNUM *TN,*TN2;
    if(t == 2 || t == 3 || t == 7)
        T1 = CrearParte(TVS,RC[1]);
    if(t == 5 || t == 4 || t == 6)
        T1 = CrearParte(TVS,RC[3]);
    
    //T1
    if(RCT1[0][0]=='[') // [ALGO]
    {
        if(T1->valor!=NULL)
        {
            T1aux = DuplicarList(T1->valor);
        }

        if(T1->valor==NULL)
        {

            //DestruirValor(T1);
            return NULL;
        }

    }
    else if (strcmp(RCT1[0], "head") == 0)
    {
        if(T1 == NULL)
            return NULL;
        if(T1->valor!=NULL)
        {
            T1aux = DuplicarList(T1->valor);
            T1aux = head(T1aux,atof(RCT1[1]));
        }

        if(T1->valor==NULL)
        {
            //DestruirValor(T1);
            return NULL;
        }


    }
    else if (strcmp(RCT1[0], "tail") == 0)
    {
        if(T1 == NULL)
            return NULL;        
        if(T1->valor!=NULL)
        {
            T1aux = DuplicarList(T1->valor);
            T1aux = tail(T1aux,atof(RCT1[1]));
        }

        if(T1->valor==NULL)
        {
            //DestruirValor(T1);
            return NULL;
        }

    }
    else if (strcmp(RCT1[0], "map") == 0)
    {
        if(T1 == NULL)
            return NULL;
        if(T1->valor!=NULL)
        {
            T1aux = DuplicarList(T1->valor);
            T1aux = map(T1aux,atof(RCT1[1]));
        }

        if(T1->valor==NULL)
        {
            //DestruirValor(T1);
            return NULL;
        }


    }
    else if (strcmp(RCT1[0], "turn") == 0)
    {
        if(T1 == NULL)
            return NULL;
        if(T1->valor!=NULL)
        {
            T1aux = DuplicarList(T1->valor);
            T1aux = turn(T1aux);
        }

        if(T1->valor==NULL)
        {
            //DestruirValor(T1);
            return NULL;
        }

    }
    else if (strcmp(RCT1[0], "order") == 0)
    {
        if(T1 == NULL)
            return NULL;
        if(T1->valor!=NULL)
        {
            T1aux = DuplicarList(T1->valor);
            T1aux = order(T1aux);
        }

        if(T1->valor==NULL)
        {
            //DestruirValor(T1);
            return NULL;
        }

    }
    else
    {
        //T1
        if(T1!=NULL)
        {
            if(T1->valor != NULL)
                T1aux = DuplicarList(T1->valor);
            else
                return NULL;
        }

        if(T1==NULL)
        {
            return NULL;
        }            
    }

    if(t == 4 && RC[5] == NULL)
        return T1aux;    
    if(t == 2 || t == 3|| t == 7)
        T2 = CrearParte(TVS,RC[3]);
    if(t == 5 || t == 6)
        T2 = CrearParte(TVS,RC[5]);
    //T2
    if(RCT2[0][0]=='[') // [ALGO]
    {

        if(T2->valor!=NULL)
        {
            T2aux = DuplicarList(T2->valor);
        }

    }
    else if (strcmp(RCT2[0], "head") == 0)
    {
        if(T2 == NULL)
            return NULL;
        if(T2->valor!=NULL)
        {
            T2aux = DuplicarList(T2->valor);
            T2aux = head(T2aux,atof(RCT2[1]));
        }
    }
    else if (strcmp(RCT2[0], "tail") == 0)
    {
        if(T2 == NULL)
            return NULL;
        if(T2->valor!=NULL)
        {

            T2aux = DuplicarList(T2->valor);
            T2aux = tail(T2aux,atof(RCT2[1]));
        }
    }
    else if (strcmp(RCT2[0], "map") == 0)
    {
        if(T2 == NULL)
            return NULL;
        if(T2->valor!=NULL)
        {
            T2aux = DuplicarList(T2->valor);
            T2aux = map(T2aux,atof(RCT2[1]));
        }
    }
    else if (strcmp(RCT2[0], "turn") == 0)
    {
        if(T2 == NULL)
            return NULL;
        if(T2->valor!=NULL)
        {
            T2aux = DuplicarList(T2->valor);
            T2aux = turn(T1aux);
        }

        if(T2->valor==NULL)
        {
            //DestruirValor(T1);
            return NULL;
        }

    }
    else if (strcmp(RCT2[0], "order") == 0)
    {
        if(T2 == NULL)
            return NULL;
        if(T2->valor!=NULL)
        {
            T2aux = DuplicarList(T2->valor);
            T1aux = order(T1aux);
        }

        if(T2->valor==NULL)
        {
            //DestruirValor(T1);
            return NULL;
        }

    }
    else
    {
        if(T2!=NULL)
        {
            if(T2->valor != NULL)
                T2aux = DuplicarList(T2->valor);
            else
                return NULL;
        }

        if(T2==NULL)
        {
            return NULL;
        } 
    }

    if(T2->valor==NULL) // En caso de que la T1 este bien, pero la T2 mal
    {
        if(RCT1[0][0]=='[')
        {
            //DestuirValor(T1);
            //DestuirValor(T1aux);
        }
        
        if(RCT1[2][0]=='[')
        {
            //DestuirValor(T2);
        }
        
        if(RCT1[0][0]!='[')
        {
            //DestuirValor(T1);
        }        
        
        return NULL;
    }

    //ImprimirLista(T1aux); 
    //ImprimirLista(T2aux);
    if(t == 7)
    {
        int i=0, j=0;

        for(TN = T1aux->primero; TN != NULL; TN = TN->siguiente)
        {        
            if(BuscarNum(T2->valor,TN->valor) == NULL)
            {
                printf("FALSE\n");
                return NULL;
            }

        }
            printf("TRUE\n");
            return NULL;
   
    }
    if(t == 3 || t == 6)
    {          
        TN = T2aux->primero;

        while (TN!=NULL)
        {
            TN2 = BuscarNum(T1aux,TN->valor);

            if(TN2!=NULL)
                EliminarNum(T1aux,TN2);

            TN = TN->siguiente;
        }

    }

    if(t == 2 || t == 5)
    {
        T1aux->ultimo->siguiente = T2aux->primero;
        T2aux->primero->anterior = T1aux->ultimo;
        T1aux->ultimo = T2aux->ultimo;
        T1aux->n = T1aux->n + T2aux->n;                      
    }
    return T1aux;

    // if(RCT1[0][0]=='[' || RCT1[2][0]=='[')
    //    //DestruirValor(T1)
    // if(RCT2[0][0]=='[' || RCT2[2][0]=='[')
    //    //DestruirValor(T2)

}

TVAR *CrearParte(TVARS *tvs,char *parte)
{
    //[ALGO]
    //NOMBRE
    //head n L1
    //tail n L1
    //turn L1
    //order L1
    //map n L1


    TLISTA *LS;
    TVAR *TR;
    


    size_t src_len = strlen(parte);
    char *parte2 = malloc((src_len + 1) * sizeof(char));
    strcpy(parte2, parte);

    char *p;
    char *TK[1000];
    int i,a,e;

    e = NumeroTokens(parte2,TK);



    ////
    //// [ALGO]
    ////

    if(TK[0][0] == '[')
    {
        TR = CrearValor(NULL);
        TR->valor  = CrearListaF(parte);
        return TR;   
    }

    ////
    //// HEAD
    //// TAIL
    ////

    if (strcmp(TK[0], "head") == 0 || strcmp(TK[0], "tail") == 0 || strcmp(TK[0], "map") == 0)
    {

        i = ValidarNum(TK[1]);
        if(i!=0)
        {
            return NULL;
        }
        if(TK[2][0] == '[')
        {       
            TR = CrearValor(NULL);
            TR->valor = CrearListaF(parte);
            if(TR != NULL)
            {
                if(TR->valor == NULL)
                {
                    return NULL;
                }
            }
            return TR;
        }
        else
        {
            if(TK[2]== NULL)
            {
                return NULL;
            }
            if(TK[3]!=NULL)
                return NULL;
            else
            {
                TR = BuscarVar(tvs,TK[2]);
                return TR;
            }
        }   
    }

    ////
    //// TURN
    //// ORDER
    ////

    if (strcmp(TK[0], "turn") == 0 || strcmp(TK[0], "order") == 0)
    {        
        if(TK[1][0] == '[')
        {           
            TR = CrearValor(NULL);
            TR->valor = CrearListaF(parte);
            if(TR != NULL)
            {
                if(TR->valor == NULL)
                    return NULL;
            }
            return TR;
        }
        else
        {
            if(TK[2]!=NULL)
                return NULL;
            else
            {
                TR = BuscarVar(tvs,TK[1]);
                if(TR==NULL)
                    return NULL;
                return TR;
            }
        }            
    }


    //Esta tiene que ir al final siempre
    ////
    //// NOMBRE
    ////
    if(TK[0]!=NULL && TK[1]==NULL)
    {
        TR = BuscarVar(tvs,TK[0]);
        if(TR!= NULL)
            return TR;
        if(TR==NULL)
            return NULL;
    }
    
    return NULL;
    
}

// 
// 
/// FUNCIONES
// 
//

TLISTA *map(TLISTA *l, int a)
{
    TNUM *p = l->primero;
    int i;

    for(i=0; i<l->n; i++)
    {
        p->valor = p->valor + a;
        p = p->siguiente;
    }
    return l;
  
}


TLISTA *order(TLISTA *lista)
{
    TNUM *current, *next;
    int swap;
    do {
        swap = 0;
        current = lista->primero;
        while (current->siguiente != NULL) {
            next = current->siguiente;
            if (current->valor > next->valor) {
                double temp_valor = current->valor;
                int temp_decimales = current->decimales;
                current->valor = next->valor;
                current->decimales = next->decimales;
                next->valor = temp_valor;
                next->decimales = temp_decimales;
                swap = 1;
            }
            current = current->siguiente;
        }
    } while (swap);
    return lista;
}

TLISTA* turn(TLISTA *lista)
{
    TLISTA *nuevaLista = (TLISTA*)malloc(sizeof(TLISTA));
    nuevaLista->n = lista->n;
    nuevaLista->primero = NULL;
    nuevaLista->ultimo = NULL;
    TNUM *current = lista->primero;

    while (current != NULL) {
        TNUM *nuevoNodo = (TNUM*)malloc(sizeof(TNUM));
        nuevoNodo->valor = current->valor;
        nuevoNodo->decimales = current->decimales;
        nuevoNodo->siguiente = nuevaLista->primero;
        nuevoNodo->anterior = NULL;
        if (nuevaLista->primero != NULL) {
            nuevaLista->primero->anterior = nuevoNodo;
        }
        nuevaLista->primero = nuevoNodo;
        if (nuevaLista->ultimo == NULL) {
            nuevaLista->ultimo = nuevoNodo;
        }
        current = current->siguiente;
    }
    return nuevaLista;
}

TLISTA *head(TLISTA *l, int a)
{
    TNUM *p=l->ultimo;
    int i,e;

    if(a<1) // 0 
    {
        e = l->n;

        for(i=0; i<e; i++)
        {


            l->ultimo = l->ultimo->anterior;
            EliminarNum(l,p);
            p=l -> ultimo;

        }
        l->n = a;
        return l;
    }

    else if(a >= l->n) // Lista completa
    {
        return l;
    }
    else // L a funcion 
    {

        e = l->n - a;

        for(i=0; i<e; i++)
        {

            l->ultimo = l->ultimo->anterior;
            EliminarNum(l,p);
            p = l->ultimo;

        }
        l->n = a;
        return l;
    }

}

TLISTA *tail(TLISTA *l, int a) 
{
    TNUM *p=l->primero;
    int i,e;

    if(a<1)
    {
        e = l->n;

        for(i=0; i<e; i++)
        {


            l->primero = l->primero->siguiente;
            EliminarNum(l,p);
            p=l -> primero;

        }
        l->n = a;
        return l;
    }

    else if(a >= l->n)
    {
        return l;
    }
    else
    {

        e = l->n - a;

        for(i=0; i<e; i++)
        {

            l->primero = l->primero->siguiente;
            EliminarNum(l,p);
            p = l->primero;

        }
        l->n = a;
        return l;
    }

}

// 
// 
/// BUSCAR
// 
//

TNUM *BuscarNum(TLISTA *l, float f)
{
    TNUM *n= l->primero;
    while(n != NULL)
    {
        if(n->valor==f)
            return n;
        n = n->siguiente;
    }
    return NULL;
}

int ValidarNombre (char *variable)
{
    int i;
    if(!((variable[0] >= 'a' && variable[0] <= 'z') || (variable[0] >= 'A' && variable[0] <= 'Z')))
        return 0;

    for(i=1;variable[i] != '\0';i++)
    {
        if(!((variable[i] >= 'a' && variable[i] <= 'z') || (variable[0] >= 'A' && variable[0] <= 'Z') || (variable[i] >= '0' && variable[i] <= '9')))
            return 0;
    }
    return 1;
}

TVAR *BuscarVar(TVARS *tvars,char *variable)
{
    TVAR *aux;
    aux = NULL;
    if (tvars->var1 != NULL)
    {
        for(aux = tvars->var1; aux != NULL; aux = aux->siguiente)
        {
            if(strcmp(aux->nombre,variable) == 0)
            {
                return (aux);
            }
        }
    }
    return (aux);
}

// 
// 
/// CREAR
// 
//

TNUM* CrearNumeroCh(char *token)
{
    TNUM *num = (TNUM*)malloc(sizeof(TNUM));

    if(num==NULL)
    {
        TextColor(RED);
        printf("ERROR de memeoria\n"); // en rojo
        exit(0);
    }
    num -> valor = atof(token);
    num -> decimales = ValidarNum(token);
    num -> siguiente = num -> anterior = NULL;

    //printf("%f ",num -> valor);
    //printf("%d ",num -> decimales);
    //printf("%s ",num -> siguiente);
    
    return num;
}
TNUM* CrearNumeroFl(float token,int nDec)
{
    TNUM *num = (TNUM*)malloc(sizeof(TNUM));

    if(num==NULL)
    {
        TextColor(RED);
        printf("ERROR de memeoria\n"); // en rojo
        exit(0);
    }
    num -> valor = token;
    num -> decimales = nDec;
    num -> siguiente = num -> anterior = NULL;

    //printf("%f ",num -> valor);
    //printf("%d ",num -> decimales);
    //printf("%s ",num -> siguiente);
    
    return num;
}

TLISTA* CrearLista()
{
    TLISTA *l = (TLISTA*)malloc(sizeof(TLISTA));
    if(l==NULL)
    {
        TextColor(RED);
        printf("ERROR de memoria\n");  // En rojo
        exit(0);
    }
    l->n=0;
    l->primero = l->ultimo = NULL;
    return l;
}

TVAR* CrearValor(char *nom)
{
    int i;
    TVAR *val = (TVAR*)malloc(sizeof(TVAR));

    if(val==NULL)
    {
        TextColor(RED);
        printf("ERROR de memeoria\n"); // en rojo
        exit(0);
    }

    if(sizeof(nom)>=20)
    {
        TextColor(RED);
        printf("ERROR. El nombre introducido contiene demasiados caracteres\n"); // en rojo
        exit(0);
    }

    if(nom!=NULL)
        strcpy(val->nombre, nom);

    val->siguiente = NULL;
    val->anterior = NULL;
    
    
    //printf("%s\n ",val->nombre);
    //printf("%s\n ",val->siguiente);
    //printf("%s\n",val->anterior);

    return val;
}


// 
// 
/// INSERTAR
// 
//

void InsertarVarAlPrincipio(TVARS *tvs,TVAR *var)
{
    if(tvs->var1 == NULL)
    {
        var->anterior = NULL;
        var->siguiente = NULL;
    }
    if(tvs->var1 != NULL)
    {
        var->anterior = NULL;
        var->siguiente = tvs->var1;
        tvs->var1->anterior = var;
    }
    tvs->var1 = var;
    tvs->n++;

}

void InsertarNumAlFinal(TLISTA *l,TNUM *nodo)
{
    if(l->primero==NULL)
        l -> primero=nodo;
    nodo->anterior = l->ultimo;

    if(l -> ultimo!=NULL)
        l -> ultimo -> siguiente=nodo;

    l->ultimo=nodo;
    l->n++;
}

// 
// 
/// CREAR LISTAS EXPLPLICITAS
// 
//

TLISTA* CreaListaExplicitaCH(char **tokens)
{

    TLISTA *list = CrearLista();
    TNUM *num;
    int i;

    for(i=0;tokens[i] != NULL;i++)
    {
        num = CrearNumeroCh(tokens[i]);
        InsertarNumAlFinal(list,num);
    }
    return list;
}

TLISTA* CreaListaExplicita(char **tokens,int nTokens)
{

    TLISTA *list = CrearLista();
    TNUM *num;
    int i;

    for(i=0;i<nTokens;i++)
    {
        num = CrearNumeroCh(tokens[i]);
        InsertarNumAlFinal(list,num);
    }
    return list;
}
TLISTA* CreaListaExplicita2(float ini,float fin,int nDec)
{
    TLISTA *list = CrearLista();
    TNUM *num;
    float i;

    for(i=ini;i<=fin; i++)
    {   
        num = CrearNumeroFl(i,nDec);
        InsertarNumAlFinal(list,num);
    }
    return list;
}
TLISTA* CreaListaExplicita3(float ini,float fin,int nDec)
{
    TLISTA *list = CrearLista();
    TNUM *num;
    float i;

    for(i=ini;i>=fin; i--)
    {   
        num = CrearNumeroFl(i,nDec);
        InsertarNumAlFinal(list,num);
    }
    return list;
}
TLISTA* CreaListaExplicita4(float ini,float incr,float fin,int nDec)
{
    TLISTA *list = CrearLista();
    TNUM *num;
    float i;

    for(i=ini;i<=fin; i=i+incr)
    {   
        num = CrearNumeroFl(i,nDec);
        InsertarNumAlFinal(list,num);
    }
    return list;
}
TLISTA* CreaListaExplicita5(float ini,float incr,float fin,int nDec)
{
    TLISTA *list = CrearLista();
    TNUM *num;
    float i;

    for(i=ini;i>=fin; i=i+incr)
    {   
        num = CrearNumeroFl(i,nDec);
        InsertarNumAlFinal(list,num);
    }
    return list;
}

// 
// 
/// OLD MAIN
// 
//

void cerrarArchivo()
{
   fclose(ws);
}

int ValidarNum (char *num) // Validador de un numero ValidarNum
{
   int i, nDec=0, puntos=0;

   if(num==NULL || num[0]=='\0') // Si cad es nula o vacia dev -1
      return -1;

   if(num[0]== '-' || num[0]== '+') // Si en la posicion 0 hay algun signo dar el valor 1 a i
   {
      i=1;
      if(num[1]>='0' && num[1]<='9')
         i=1;
      else
         return -1;
   }
   else
   {
      i=0;
   }

   if(num[0]=='.') // si empieza por un '.' ERROR
      return -1;

   while(num[i] != '\0') //  para que vaya leyendo la cadena 
   {
      
      if(num[i]=='.')
      {
         if(num[i+1]== '\0')
            return -1;
         puntos++;
         if(puntos>1)
            return -1;
      }
      else if(num[i]<'0' || num[i]>'9')
         return -1;
      else if(puntos==1)
         nDec++;
      i++;
   }

   return nDec;
}

int ValidarLista(char *cad) // Detector de errores por token en la lista ValidarLista
{
   int i=0, nDec=0, puntos=0, e=0, n;
   char *tok;
   tok = strtok( cad, " \t\n\r" );

   while(tok!=NULL)
   {
      e++;

      if(e==1)
      {
         n=ValidarNum(tok);

         if(n==-1)
            return -1;
      }

      if(e==2 && tok[0]!='$' && tok[0]!=':')
      {
         n=ValidarNum(tok);
         if(n==-1)
            return -2;
      }
      
      if(e==3)
      {
         n=ValidarNum(tok);
         if(n==-1)
            return -3;         
      }

      if(e==4)
      {
         if(tok[0]!=':')
         {
            n=ValidarNum(tok);
            if(n==-1)
               return -4;
         }
      }

      if(e>=5)
      {
         n=ValidarNum(tok);
         if(n==-1)
            return -5;         
      }

     tok=strtok(NULL, " \t\n\r");

   }

}

int TipoLista(char *list, float *t1, float *t3, float *t5) // Detector de tipo de lista TipoLista
{
   int e=0;
   float t2,t4;
   char *tok;
   int l1=0,l2=0,l3=0;

   tok = strtok( list, " \t\n\r" );
   //if (list==NULL)

   while(tok!=NULL)
   {
      e++;

      
      if(e==1) // NUMERO
      {
         *t1=atof(tok);
         l1=1;
         l2=0;
         l3=0;
      }

      if(e==2) // CARACTER
      {
         if (tok[0]!=':' && tok[0]!='$') // l1 y atof
         {
            t2=atof(tok);
            l1=1;
            l2=0;
            l3=0;
         }
         if (tok[0]==':') //l2
         {
            l1=0;
            l2=1;
            l3=0;
         }
         if (tok[0]=='$')// l3
         {
            l1=0;
            l2=0;
            l3=1;
         }
      }

      if(e==3) // NUMERO
      {
         *t3=atof(tok);
      }


      if(e==4) // CARACTER
      {
         if(l1==1)
         {
            if(tok[0]==':')
            {
               l1=0;
               l2=0;
               l3=0;
            }
            else 
               t4=atof(tok);
         }

         if(l2==1)
         {
            l1=0;
            l2=0;
            l3=0;         
         }

         if(l3==1)
         {
            if(tok[0]==':')
            {
               l1=0;
               l2=0;
               l3=1;
            }
            if(tok[0]!=':')
            {
               l1=0;
               l2=0;
               l3=0;                
            }
         }
      }

      if(e==5) // NUMERO
      {
         *t5=atof(tok);
      }
 
      tok=strtok(NULL, " \t\n\r");
   }
   
   // Casos particulares que tambien deben dar error
   
   if(e==4 && l3==1)//printf("ERROR. No se ha detectado ningun valor en la quinta posicion.");
      return 0;

   
   if(e==3 && l3==1)
      l3=0;

   if (l1==0 && l2==0 && l3==0) //printf("ERROR. Solo admiten 3 tipos de listas:\n1. [3 1.43 -12.3 234 7 etc.]\n2. [13 : 4]\n3. [1 $ 2 : 5]\n");
   {
      return 0;
   }

   if (l1==1 && l2==0 && l3==0)
      return 1;

   // Ahora devolvemos el tipo de lista exacto dependiendo de si es incremento o decremento en el tipo 2.

   if (l1==0 && l2==1 && l3==0)
   {
      if(*t1<*t3)
         return 2;
      if(*t1>*t3)
         return 3;
      if(*t1==*t3) 
         return 2;
   }

   // Ahora devolvemos el tipo de lista exacto dependiendo de si es incremento o decremento en el tipo 3.

   if (l1==0 && l2==0 && l3==1)
   {
      if(*t1<*t5)
      {
         if(*t3>0)
            return 4;
         if(*t3<0) //printf("ERROR. Tercera posicion invalida, no se puede realizar un incremento negativo en este caso\n");
            return 0;
         if(*t3==0) //printf("ERROR. Tercera posiccion invalida, no se puede realizar un incremento de 0\n");
            return 0;
            
      }

      if(*t1>*t5)
      {
         if(*t3<0)
            return 5;
         if(*t3>0) //printf("ERROR. Tercera posicion invalida, no se puede realizar un incremento positivo en este caso\n");
            return 0;
            
         if(*t3==0) //printf("ERROR. Tercera posiccion invalida, no se puede realizar un incremento de 0\n");
            return 0;
            
      }

      if(*t1==*t5) //printf("ERROR. Primera y quinta posicion invalidas, no se admiten numeros iguales\n");
         return 0;
         
   }

}

int NumeroTokens(char *cad,char **listaF1) // Contador de numero de Tokens en una lista y tranformador de tokens a doble array
{
   int i=0;

   listaF1[i] = strtok( cad, " \t\n\r" );
   while(listaF1[i]!=NULL)
   {
      i++;
      listaF1[i]=strtok(NULL, " \t\n\r");
   }
   return i;
}
int CopiarListaEnPosicion(char **RC, int pos, char *PP1,char *PP2)
{
   int i, iguales;
   char *AUX;
   iguales = strcmp(PP1,PP2);
   if(iguales == 0)
   {
      AUX = malloc(2 * sizeof(char));
      AUX[0] = *PP1;
      AUX[1] = '\0';
      RC[pos] = AUX;
   }
   else
   {
      AUX = malloc((PP2-PP1) * sizeof(char));
      strncpy(AUX, PP1+1,PP2-PP1-1);
      AUX[PP2-PP1-1]='\0';
      RC[pos] = AUX;
   }
   return 0;
}
TLISTA *CrearListaF(char *comandP) // Creador de lista pasandole cualquier tipo de lista
{
   char lista1[2500], lista2[2500],lista1F[2500];
   char lista11[2500], lista12[2500], lista13[2500], comandP1[5000], comandP2[5000];
   char listaC1[2500];
   char *listaF1[2500];
   char  *p1, *p2, *tok, *TOK, *token;
   int nTokens=0;
   int i=0, vl=0, tl=0;
   float t1, t3, t5;
   int nDec1,nDec3,nDec5;
   
   TLISTA *lista;


    strcpy(comandP2,comandP);      
    if((p1=strchr(comandP2, '['))!= NULL)// Aqui conseguimos lo que hay entre dos corchetes sin contar los corchetes
    {
        if((p2=strchr(comandP2, ']'))!= NULL)
        {
            strncpy(lista1, p1+1,p2-p1-1);
            lista1[p2-p1-1]='\0';
        }
        else
        {
            //printf("ERROR. Puede que le falte introducir \"]\" o le  sobra \"[\" \n");
            return NULL;         
        }
        
        if(strtok(p2+1, " \n\t\r") != NULL)
            return NULL;


        if(p2+1 != NULL)
        {
            token = strtok( p2+1, " \t\n\r" );
            if(token != NULL)
                return NULL;
        }

        

        
        strcpy(lista11,lista1);
        vl=ValidarLista(lista11);// Detector de errores por token en la lista ValidarLista
        if(vl<0 && vl>-6)
        {
            if(vl==-5)//printf("ERROR. Quinta o superores posicion/es no valida/s, solo se admiten nuemros.\n");
                return NULL;
            
            if(vl==-4)//printf("ERROR. Cuarta posicion no valida, solo se admite un numero o \":\"\n");
                return NULL;
            
            if(vl==-3)//printf("ERROR. Tercera posicion no valida, solo se admite un numero, \"$\" o \":\".\n");
                return NULL;
            
            if(vl==-2)//printf("ERROR. Segunda posicion no valida, solo se admite un numero, \"$\" o \":\".\n");
                return NULL;
            
            if (vl==-1)//printf("ERROR. Primera posicion no valida, solo se admite un numero.\n");
                return NULL;
        }

        strcpy(lista12,lista1);
        if(vl!=-1 && vl!=-2 && vl!=-3 && vl!=-4 && vl!=-5) // Detector de tipo de lista TipoLista
            tl = TipoLista(lista12, &t1, &t3, &t5);
        
        if(tl==0)
            return NULL;

        strcpy(lista13,lista1);
        if(tl==1||tl==2||tl==3||tl==4||tl==5) // Creador de lista segun el tipo en que se encunetra
        {

            
            if(tl==1)
            {
                strcpy(listaC1,lista1);
                nTokens = NumeroTokens(listaC1, listaF1); // Contador de numero de Tokens en una lista y conversor de de un array 1D a un array de 2D

                lista = CreaListaExplicita(listaF1,nTokens);
                return lista;

            }
            if(tl==2)
            {
                strcpy(listaC1,lista1);
                nTokens = NumeroTokens(listaC1, listaF1); // Contador de numero de Tokens en una lista y conversor de de un array 1D a un array de 2D

                nDec1 = ValidarNum(listaF1[0]);

                lista = CreaListaExplicita2(t1,t3,nDec1);
                return lista;


            }
            if(tl==3)
            {
                strcpy(listaC1,lista1);
                nTokens = NumeroTokens(listaC1, listaF1); // Contador de numero de Tokens en una lista y conversor de de un array 1D a un array de 2D

                nDec1 = ValidarNum(listaF1[0]);

                lista = CreaListaExplicita3(t1,t3,nDec1);
                return lista;              
            }
            if(tl==4)
            {
                strcpy(listaC1,lista1);
                nTokens = NumeroTokens(listaC1, listaF1); // Contador de numero de Tokens en una lista y conversor de de un array 1D a un array de 2D

                nDec1 = ValidarNum(listaF1[0]);
                nDec3 = ValidarNum(listaF1[2]);

                if(nDec1>nDec3)
                nDec1 = nDec1;
                else
                nDec1 = nDec3;            

                lista = CreaListaExplicita4(t1,t3,t5,nDec1);
                return lista;            
            }
            if(tl==5)
            {
                strcpy(listaC1,lista1);
                nTokens = NumeroTokens(listaC1, listaF1); // Contador de numero de Tokens en una lista y conversor de de un array 1D a un array de 2D

                nDec1 = ValidarNum(listaF1[0]);
                nDec3 = ValidarNum(listaF1[2]);
                if(nDec1>nDec3)
                nDec1 = nDec1;
                else
                nDec1 = nDec3;

                lista = CreaListaExplicita5(t1,t3,t5,nDec1);
                return lista;
            }   
        }      
    }
    else
        return NULL;
}

//
//
// OTROS
//
//

void DestruirLista(TLISTA *l)
{
    TNUM *p=l->ultimo;
    while(l->ultimo)
    {
        l->ultimo = l->ultimo->anterior;
        free(p);
        p=l -> ultimo;
    }
    free(l);
}
void EliminarNum(TLISTA *l, TNUM *n)
{
    if(l->primero == l->ultimo)
    {
        l->n--;
        free(n);
        return;
    }
    if(n->anterior == NULL)
    {
        n->siguiente->anterior = NULL;
        l->primero = n->siguiente;

    }
    else if(n->siguiente == NULL)
    {
        n->anterior->siguiente = NULL;
        l->ultimo = n->anterior;

    }
    else
    {
        n->anterior->siguiente = n->siguiente;
        n->siguiente->anterior = n->anterior;
    }

    l->n--;
    free(n);
}
TLISTA *DuplicarList(TLISTA *l)
{
    TLISTA *aux=CrearLista();
    TNUM *aux2,*num;
    aux2 = l->primero;

    for (int i=0; i<l->n;i++)
    {
        num = CrearNumeroFl(aux2->valor,aux2->decimales);
        InsertarNumAlFinal(aux,num);
        aux2 = aux2->siguiente;
    }
    return (aux);
}
void ImprimirLista(TLISTA *l)
{
    TNUM *pAux;

    if(l->n == 0)
    {
        printf ("[]\n");
        return;
    }

    printf("[ ");

    for(pAux = l->primero; pAux != NULL; pAux = pAux->siguiente)
    {
        printf("%.*f ",pAux -> decimales,pAux -> valor);
    }

    printf("]\n");
}

void TextColor(int color)
{
    static int __BACKGROUND;

    HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

    GetConsoleScreenBufferInfo(h, &csbiInfo);
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), color + (__BACKGROUND << 4));
}