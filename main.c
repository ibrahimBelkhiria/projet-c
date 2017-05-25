#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
/* voici ma premier commentaire */
/*
les valeurs:
0: noir
1: bleu foncé
2: vert
3: bleu-gris
4: marron
5: pourpre
6: kaki
7: gris clair
8: gris
9: bleu
10: vert fluo
11: turquoise
12: rouge
13: rose fluo
14: jaune fluo
15: blanc

*/

int L=0;
int rows=0,cols=9;
enum Bool { false = 0, true = 1};
//**************************************************************************************
void color(int t,int f)
{
        //color(Foreground, Background);
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,f*16+t);
}
//**************************************************************************************
void gotoxy(int x,int y)
{
        HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD cursorLoc;
        cursorLoc.X = x;
        cursorLoc.Y = y;
        SetConsoleCursorPosition(H, cursorLoc);
}

//**************************************************************************************

void setTailleInfo(int val) { L=val; }      int getTailleInfo() { return L; }
void setRows(int val) { rows=val; }         int getRows() { return rows; }
void setCols(int val) { cols=val; }         int getCols() { return cols; }

//**************************************************************************************
char * getMessage(char * msg)
{
     int i=0;
     char * msgFinal=(char *)malloc(L*sizeof(char));
     int longeur=strlen(msg);
     
     char  * espace=(char *)malloc((L-longeur)*sizeof(char));
     strcpy(espace,"");
     
     if(longeur<getTailleInfo())
     {
          for(i=0;i<(getTailleInfo()-longeur);i++)
          {
               strcat(espace," ");            
          }
          
     }
     else return msg;
     strcpy(msgFinal,msg);
     strcat(msgFinal,espace);
 return msgFinal;     
}

//**************************************************************************************
void addInfo(char * msg, int pos)
{
     //type=1: add in menu / type=2: add in form
     int i;
     gotoxy(3,4+(pos*2)); //reposition cursor
     color(1, 15);
     printf("%s",getMessage(msg));
     color(15, 9);
     gotoxy(getTailleInfo()+5,4+(pos*2)); //reposition cursor
     printf("%s",getMessage(" "));
     
     gotoxy(getTailleInfo()+5,4+(pos*2)); //reposition cursor 
     color(15, 9);
}

//**************************************************************************************

void showMenu(char * title, int rows, int cols)
{
     
     setTailleInfo(cols-4);
     int i=2,j=2;
     
     color(7, 0);
     system("cls");
     color(15, 8);
     gotoxy(3,2); //reposition cursor
     for(i=2;i<cols;i++)
     {
         gotoxy(i,2);
         printf(" ");
     }
     color(15, 12);gotoxy(2,2);
     printf("+");
     gotoxy(3,2);
     color(15, 8);
     printf(" %s",getMessage(title));
     
     gotoxy(2,3); //reposition cursor
     color(11, 7);
     rows=(rows*2)+4;
     for(i=2;i<cols;i++)
     {
         for(j=3;j<rows;j++)
         {
              gotoxy(i,j);
              printf(" ");              
         }             
     }
     color(7, 0);
     printf("\n");
}


void addMenu(char * msg, int pos)
{
     
     gotoxy(3,4+(pos*2)); //reposition cursor
     color(1, 15);
     printf(getMessage(msg));
}

int getMenuResponse(int NbrMenu)
{
     int res;
     
     color(15, 9);
     gotoxy(2,7+(NbrMenu*2)); //reposition cursor
     printf("Put your choice here: ");
     
     color(12, 14);
     gotoxy(27,7+(NbrMenu*2));
     printf("_");
     
     gotoxy(27,7+(NbrMenu*2));
     scanf("%d",&res);
     color(7, 0);
     return res;
}
//**************************************************************************************

//**************************************************************************************

void showFormulaire(char * title, int rows, int cols)
{
     setRows(rows);
     setCols(cols*2);
     setTailleInfo(cols-4);
     
     int i=2,j=2;
     system("cls");
     color(15, 8);
     gotoxy(3,2); //reposition cursor
     for(i=2;i<cols*2;i++)
     {
         gotoxy(i,2);
         printf(" ");
     }
     color(15, 9);
     gotoxy(2,2);
     printf("+");
     gotoxy(3,2);
     color(15, 8);
     //printf("%d",strlen(getMessage(title)));
     printf(" %s",getMessage(title));
     
     gotoxy(2,3); //reposition cursor
     color(11, 7);
     rows=(rows*2)+4;
     for(i=2;i<cols*2;i++)
     {
         for(j=3;j<rows;j++)
         {
              gotoxy(i,j);
              printf(" ");              
         }             
     }
     color(7, 0);
     printf("\n"); 
     
}





//Ajouter Personne****************************
void AjouterPersonne()
{
  char nom[20], prenom[20], date[20], adresse[20], rep[10];
  int cin;
  
  system("cls");
  color(7, 0);
  //showFormulaire(Titre,Nbr des lignes,Nombre de colonnes);
  showFormulaire("Ajouter un personne",5,30);
  
  
  addInfo("Cin:",0);
  scanf("%d",&cin);
  
  addInfo("Nom:",1);
  scanf("%s",&nom);
  
  addInfo("Prenom:",2);
  scanf("%s",&prenom);
  
  /*addInfo("Date de naissance:",3);
  scanf("%s",&date);*/
  
  addInfo("Adresse:",3);
  scanf("%s",&adresse);
  
  addInfo("Enregistrer O/N:",4);
  scanf("%s",&rep);
  
  
}
//Ajouter Voiture****************************
void AjouterVoiture()
{
  char nom[20];
  
  system("cls");
  color(7, 0);
  //setTailleInfo(22);
  showFormulaire("Ajouter une voiture",6,25);
  
  addInfo("Marque:",0);
  scanf("%s",&nom);
  
  addInfo("Modele:",1);
  scanf("%s",&nom);
  
  addInfo("Matricule:",2);
  scanf("%s",&nom);
  
  addInfo("Couleur:",3);
  scanf("%s",&nom);
  
  addInfo("Puissance:",4);
  scanf("%s",&nom);
  
  addInfo("Enregistrer O/N:",5);
  scanf("%s",&nom);
  

}

//Apropos de MiniProjet****************************
void Apropos()
{
  char nom[20];
  
  system("cls");
  color(7, 0);
  showFormulaire("A Propos de MiniProjet",6,30);
  
  addInfo("Developped by:",0);
  addInfo("Mouhieddine Belguith:",1);
  
  

}




void menuPrincipal()
{
  int rep = -1;
  while(rep!=0 )
  {
      system("cls"); 
      showMenu("Menu Principal", 6,30);
      addMenu("1] Gestion de Personne",0);
      addMenu("2] Gestion de Voiture",1);
      addMenu("3] Gestion de Location",2);
      addMenu("4] Gestion de Profile",3);
      addMenu("5] A Propos de ..",4);
      addMenu("0] Exit",5);
      
      rep=getMenuResponse(5);
      switch(rep)
      {
                 case 0:break;
                 case 1:
                 {
                      int rep1=-1;
                      while(rep1!=5 && rep1!=0)
                      {
                          system("cls");       
                          showMenu("Gestion de personne",6,25);
                          addMenu("1] Ajouter",0);
                          addMenu("2] Supprimer",1);
                          addMenu("3] Modifier",2);
                          addMenu("4] Consulter",3);
                          addMenu("5] Menu Principal",4);
                          addMenu("0] Exit",5);
                          rep1=getMenuResponse(5);
                          switch(rep1)
                          {
                                     case 0:rep=0; break;
                                     case 1:AjouterPersonne(); break;
                                     case 2:printf("ok1");       break;
                                     case 3:printf("ok1");       break;
                                     case 4:printf("ok1");       break; 
                                     case 5:printf("ok1");       break;             
                          }
                      }
                      break;
                 }
                 case 2:
                 {
                      int rep1=-1;
                      while(rep1!=5 && rep1!=0)
                      {
                          system("cls");       
                          showMenu("Gestion de voiture",6,25);
                          addMenu("1] Ajouter",0);
                          addMenu("2] Supprimer",1);
                          addMenu("3] Modifier",2);
                          addMenu("4] Consulter",3);
                          addMenu("5] Menu Principal",4);
                          addMenu("0] Exit",5);
                          rep1=getMenuResponse(5);
                          switch(rep1)
                          {
                                    case 0:rep=0; break;
                                    case 1:AjouterVoiture(); break;           
                          }
                      }
                      break;
                 }
                 case 3:
                 {
                      int rep1=-1;
                      while(rep1!=4 && rep1!=0)
                      {
                          system("cls");       
                          showMenu("Gestion de location",5,25);
                          addMenu("1] Ajouter",0);
                          addMenu("2] Supprimer",1);
                          addMenu("3] Consulter",2);
                          addMenu("4] Menu Principal",3);
                          addMenu("0] Exit",4);
                          rep1=getMenuResponse(5);
                          switch(rep1)
                          {
                                     case 0:rep=0; break;
                                     case 1:AjouterPersonne(); break;           
                          }
                      }
                      break;
                 }
                 case 4:
                 {
                      int rep1=-1;
                      while(rep1!=3 && rep1!=0)
                      {
                          system("cls");       
                          showMenu("Gestion de profile",4,25);
                          addMenu("1] Consulter",0);
                          addMenu("2] Modifier",1);
                          addMenu("3] Menu Principal",2);
                          addMenu("0] Exit",3);
                          rep1=getMenuResponse(5);
                          switch(rep1)
                          {
                                     case 0:rep=0; break;
                                     case 1:AjouterPersonne(); break;           
                          }
                      }
                      break;
                 }
                 case 5:
                 {
                      int rep1=-1;
                      while(rep1!=3 && rep1!=0)
                      {
                          system("cls");       
                          showMenu("A Propos de",4,25);
                          addMenu("1] Aide",0);
                          addMenu("2] A Propos de",1);
                          addMenu("3] Menu Principal",2);
                          addMenu("0] Exit",3);
                          rep1=getMenuResponse(3);
                          switch(rep1)
                          {
                                     case 0:rep=0; break;
                                     case 1:AjouterPersonne(); break;
                                     case 2:Apropos(); break;           
                          }
                      }
                      break;
                 }
                 
      }
  }
}



//**************************************************************************************

int main()
{

  

  
  
  menuPrincipal();

  
  color(7, 0);
  printf("\n");
  
  //system("PAUSE");
  
  //getch();
  return 0;
}
