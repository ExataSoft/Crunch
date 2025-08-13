
     /*-----------------------------------------------------------------------/|
    /                       By Prof. Marcelo Brito.                          / |
   /                        email: profmarcelobc@gmail.com                  /  |
  /                         website: www.exatasoft.com                     /   |
 /                                                                        /    |
/------------------------------------------------------------------------/     |
|  ______    ________  ___    ___  _____    ___   _______  ___    ___    |     |
| / _____/  /_______/  | |    | |  | |\ \   | |  / _____/  | |    | |    |     |
| | |       | |   | |  | |    | |  | | \ \  | |  | |       | |    | |    |     |
| | |       | |___|_|  | |    | |  | |  \ \ | |  | |       | |____| |    |     |
| | |       | \_____/  | |    | |  | |   \ \| |  | |       | \____| |    |    /
| | |____   | | \ \    | |____| |  | |    \ \ |  | |____   | |    | |    |   /
| \______\  | |  \ \   \________/  \_|     \_\|  \______\  \_|    \_|    |  /
|                                                                        | /
-------------------------------------------------------------------------*/
#include<stdio.h>
#define Max 50 // Tamanho Máximo do Vetor M que corresponde ao tamanho máximo da palavra.
int M[Max];


//---- Retorna o comprimento da string s iterativamente ---//
int len(char *s)
{ int c;
  for(c=0;*s++;c++);
  return c; 
}


//---- Imprime os caracteres da string s segundo as posições dadas pelo vetor M ---//
void imprime(char *s, int p)
{  int i;
  for(i=0;i<p;i++)
    printf("%c",*(s+M[p-i-1]));

  printf("\n");
}


//---- Inicia o vetor M com valor zero para cada posição ---//
void iniciaM(int n)
{
 for(int i=0;i<n;M[i++]=0);
}


//---- Incrementa as posições do vetor M recursivamente ---//
void incrementa(int j,int n,int p)
{
    if(M[j]<n-1)
        M[j]++;
    else{ M[j]=0;
          incrementa(++j,n,p);
         };
}


//---- Retorna 0 (falso) se todos os (p) valores de M forem iguais a (n-1) ---//
int continua(int p, int n)
{ int i;
  for(i=0;i<p;i++)
    if(M[i]!=n-1) break;
  return (i!=p);
}


//---- Imprime todas as permutações com repetição de comprimento c0 ao comprimento c1 ---//
int crunch(char *s, int c0, int c1)
{ if((c0<=0)||(c0>c1)||(c0>Max)||(c1>Max))
   {
     printf("[ Nota: 0<min<=max<=50 ]\n");
     return 0;
   }

  int n = len(s);
  int p;
  for(p=c0;p<=c1;p++)
  {
      iniciaM(p);
      imprime(s,p);
         do{
            incrementa(0,n,p);
            imprime(s,p);

           }while(continua(p,n));
  } 
}

//---- Retorna verdadeiro se a string s corresponder a  um valor natural ---//
int ehnatural(char *s)
{
  int r=1;
  if(*s=='-')s++;
  for(;*s&&r;r=(((int)*s)>47)&&(((int)*s++<58)));
  return r;
}

//---- Retorna o valor natural correspondente à string ---//
int val(char *s)
{ int b,v;
  char *p =(s+len(s)-1);
  for(b=1,v=0;*s;v+=b*((int)(*p--)-48),b*=10,s++);
  return v;
}

//---- Imprime a sintaxe ou a falta de argumentos ---//
void help(int i)
{ 
      printf("\n      (            )          )  \n");
      printf("    (   )\\ )      ( /(   (   ( /(  \n");
      printf("    )\\ (()/(   (  )\\())  )\\  )\\()) \n");
      printf("  (((_) /(_))  )\\((_)\\ (((_)((_)\\  \n");
      printf("  )\\___(_)) _ ((_)_((_))\\___ _((_) \n");
      printf(" ((/ __| _ \\ | | | \\| ((/ __| || | \n");
      printf("  | (__|   / |_| | .` || (__| __ | \n");
      printf("   \\___|_|_\\\\___/|_|\\_| \\___|_||_| \n");

      printf("-------------------------------------------------------\n");
      printf("| sintaxe:  crunch <string> <min> <max>               |\n");
      printf("| example1: crunch '#$Ab5' 3  5                       |\n");
      printf("| example2: crunch 123abc  6  6  >  passwordlist.txt  |\n");
      printf("| nota: 0<min<=max<=50                                |\n");
      printf("|                                                     |\n");
      printf("|   by Prof. Marcelo de Brito Castro                  |\n");
      printf("|      email: profmarcelobc@gmail.com                 |\n");
      printf("|      website: www.exatasoft.com                     |\n");
      printf("-------------------------------------------------------\n\n");
    
      if(!i) 
        printf("[ missing arguments! ]\n\n");
}


//------------------- Rotina Principal--------------------//
int main(int argc, char *argv[])
{
  if(argc==4)
   {
    if(ehnatural(argv[2])&&ehnatural(argv[3]))
     crunch(argv[1],val(argv[2]),val(argv[3]));
     else help(1);
   }
  else if(argc==2)
         { if(((argv[1][0]=='-')&&((argv[1][1]=='h')||(argv[1][1]=='H'))) ||(argv[1][0]=='?'))
             help(1);
           else help(0);
         }
       else help(0);

  return 0;
}
//---------------------------------------------------------//
