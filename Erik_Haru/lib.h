typedef struct Numero
{
    double valor;
    int decimales;
    struct Numero *siguiente, *anterior;

} TNUM;

typedef struct
{
    int n; // nº de elementos de la lista
    TNUM *primero, *ultimo;

} TLISTA;

typedef struct Var
{
    char nombre[20];
    TLISTA *valor;
    struct Var *siguiente, *anterior;

} TVAR;

typedef struct
{
    int n; // nº de elementos de la lista
    TVAR *var1;
    
} TVARS;





TLISTA *sumaresta(TVARS *TVS,TVAR *T1,TVAR *T2,char **RCT1,char **RCT2,char **RC, int t);

TLISTA *head(TLISTA *l, int a);
TLISTA *tail(TLISTA *l, int a);
TLISTA *map(TLISTA *l, int a);

TVAR *CrearParte(TVARS *TVS,char *parte);
int ValidarNombre(char *RC);
TVAR *BuscarVar(TVARS *prim,char *nomr);

TNUM *BuscarNum(TLISTA *l, float f);

int ValidarNum(char *num);
void EliminarNum(TLISTA *l, TNUM *n);

TLISTA *DuplicarList(TLISTA *l);

TNUM* CrerNumeroCh(char *token);
TNUM* CrearNumeroFl(float token,int nDec);

TVAR* CrearValor(char *nom);

TLISTA* CrearLista();

void DestruirLista(TLISTA *l);

void InsertarVarAlPrincipio(TVARS *p,TVAR *v);
void InsertarNumAlFinal(TLISTA *l,TNUM *n);

TLISTA* CreaListaExplicitaCH(char **tokens);

TLISTA* CreaListaExplicita(char **tokens,int nTokens);
TLISTA* CreaListaExplicita2(float ini,float fin,int dec);
TLISTA* CreaListaExplicita3(float ini,float fin,int nDec);
TLISTA* CreaListaExplicita4(float ini,float incr,float fin,int nDec);
TLISTA* CreaListaExplicita5(float ini,float incr,float fin,int nDec);

void ImprimirLista(TLISTA *l);

void cerrarArchivo();


TLISTA* turn(TLISTA *lista);
TLISTA* order(TLISTA *lista);


int NumeroTokens(char *cad, char **listaF1); // Contador de numero de Tokens en una lista
TLISTA *CrearListaF(char *comandP); // Creador de lista pasandole cualquier tipo de lista
int CopiarListaEnPosicion(char **RC, int pos, char *PP1,char *PP2); // Dado dos punteros. Lo que hay entre ellos lo copia en la posicion de array doble deseado
int TipoLista(char *list, float *t1, float *t3, float *t5); // Detector de tipo de lista TipoLista
int ValidarLista(char *cad); // Detector de errores por token en la lista ValidarLista
int ValidarNum (char *num); // Validador de un numero ValidarNum
void cerrarArchivo();
FILE *ws;


#define BLACK         0
#define BLUE          1
#define GREEN         2
#define CYAN          3
#define RED           4
#define MAGENTA       5
#define BROWN         6
#define LIGHTGRAY     7
#define DARKGRAY      8
#define LIGHTBLUE     9
#define LIGHTGREEN   10
#define LIGHTCYAN    11
#define LIGHTRED     12
#define LIGHTMAGENTA 13
#define YELLOW       14
#define WHITE        15

void TextColor(int color);
