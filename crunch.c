 /* 
   ___ ___ _   _ _  _  ___ _  _ 
  / __| _ \ | | | \| |/ __| || |
 | (__|   / |_| | .` | (__| __ |
  \___|_|_\\___/|_|\_|\___|_||_|
          By Prof. Marcelo Brito. 
 
*/

#include<stdio.h>
#define Max 100
int M[Max];

//Retorna o comprimento da string s recursivamente

int len(char *s)
{
   return (*s)?1+len(++s):0;
}


//Imprime os caracteres da string s 
//segundo as posições dadas pelo vetor M

void imprime(char *s, int p)
{  int i;
  for(i=0;i<p;i++)
    printf("%c",*(s+M[p-i-1]));

  printf("\n");
}


//Inicia o vetor M com valor zero para cada posição

void iniciaM(int n)
{
 for(int i=0;i<n;M[i++]=0);
}



//Incrementa as posições do vetor M recursivamente

void incrementa(int j,int n,int p)
{
    if(M[j]<n-1)
        M[j]++;
    else{ M[j]=0;
          incrementa(++j,n,p);
         };
}


//---- Retorna 0 (falso) se todos os 
//(p) valores de M forem iguais a (n-1)

int continua(int p, int n)
{ int i;
  for(i=0;i<p;i++)
    if(M[i]!=n-1) break;
  return (i!=p);
}


//Imprime todas as permutações com repetição
// de comprimento c0 ao comprimento c1

void crunch(char *s, int c0, int c1)
{ if(c0&&(c0<=c1))
  {
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
}


//Retorna verdadeiro se a string s 
//correponder a  um valor inteiro

int ehnumero(char *s)
{
  int r=1;
  for(;*s&&r;r=(((int)*s)>47)&&(((int)*s++<58)));
  return r;
}


//Retorna o valor inteiro correspondente à string

int val(char *s)
{ int b,v;
  char *p =(s+len(s)-1);
  for(b=1,v=0;*s;v+=b*((int)(*p--)-48),b*=10,s++);
  return v;
}


//Imprime a sintaxe ou a falta de argumentos

void help(int i)
{
 if(i)
    { printf("-------------------------------------------------------\n");
      printf("| sintaxe:  crunch <string> <min> <max>               |\n");
      printf("| example1: crunch 123abc  3  5                       |\n");
      printf("| example2: crunch 123abc  3  7                       |\n");
      printf("| example3: crunch 123abc  6  6  >  passwordlist.txt  |\n");
      printf("|                                                     |\n");
      printf("|   by prof. Marcelo de Brito Castro                  |\n");
      printf("-------------------------------------------------------\n");
    }
  else printf(" [ missing arguments! ]\n\n");
}


//-------- Rotina Principal-------//
int main(int argc, char *argv[])
{
  if(argc==4)
   {
    if(ehnumero(argv[2])&&ehnumero(argv[3]))
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
//----------- FIM -------------//
