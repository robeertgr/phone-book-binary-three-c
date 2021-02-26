# include <string.h>
# include <stdio.h>
# include <stdlib.h>

struct arvore{
       char Nome[100];
       int telefone;
       struct arvore *esq;
       struct arvore *dir;
};
typedef struct arvore Arvore;

void inserir(Arvore **raiz,char string[]);
void ordem(Arvore *raiz);
void busca(Arvore *raiz,char string[]);
void Altera( Arvore **raiz, char *string);
void excluir(Arvore **raiz,char string[]);
Arvore** menor_dir(Arvore *raiz);
Arvore** maior_esq (Arvore *raiz);
void ler_string(char string[]);
void ler_telefone(int *telefone);
void maiuscula(char string[]);
void Menu(int *num);
void opcao(char op[]);
void Menu_1();
void Menu_2();
void Menu_3();
void Menu_4();
void Menu_5();


void inserir(Arvore **raiz ,char string[]){
	int telefone;
	if(*raiz == NULL){
		*raiz = (Arvore*) malloc (sizeof(Arvore));
		strcpy((*raiz)->Nome,string);
		ler_telefone(&telefone);
		(*raiz)->telefone = telefone;
		(*raiz)->esq = NULL;
		(*raiz)->dir = NULL;              
		}else{
			if(strcasecmp((*raiz)->Nome,string)>0){
			inserir(&(*raiz)->esq,string);                     
			}else{
				if(strcasecmp((*raiz)->Nome,string)<0){
					inserir(&(*raiz)->dir,string);
					}else{
						if(strcmp((*raiz)->Nome,string)==0){
							printf("Nome ja foi registrado\n");
							getch();
					}
				}
			}
		}
	}
                                                               
void ordem(Arvore *raiz){
	if(raiz!=NULL) {
	ordem((raiz)->esq);
	printf("\n\nNome = ");
	printf("%s",(raiz)->Nome);
	printf("\nTelefone = ");
	printf("%d",(raiz)->telefone);
	ordem((raiz)->dir);
	}
}

void busca(Arvore *raiz,char string[]){
	if(raiz!=NULL) {
		if(strcasecmp((raiz)->Nome,string)>0){
			busca((raiz)->esq,string);
			}else{
				if(strcasecmp((raiz)->Nome,string)<0){	
				busca((raiz)->dir,string);
				}else{
					if(strcmp((raiz)->Nome,string)==0){
					system("cls");
					printf("REGISTRO ENCONTRADO!!\n");
					printf("\n\nNome = ");
					printf("%s",(raiz)->Nome);
					printf("\nTelefone = ");
					printf("%d",(raiz)->telefone);
					getch();
					}
				}
			}
		}else{
        system("cls");
        printf("*-----------------------*\n");
        printf("| Nome nao encontrado!! |\n");
        printf("*-----------------------*\n");
        getch();
	}	
}

void Altera( Arvore **raiz, char *string){
	if((*raiz)!=NULL){
		if(strcasecmp((*raiz)->Nome,string)>0){
			Altera(&(*raiz)->esq,string);
		}else{
		if(strcasecmp((*raiz)->Nome,string)<0){
			Altera(&(*raiz)->dir,string);
		}else{
        if(strcmp((*raiz)->Nome,string)==0){
        	system("cls");
        	int telefone;
	        printf("REGISTRO ENCONTRADO!!\n");
    	    printf("\n\nNome = ");
        	printf("%s",(*raiz)->Nome);
	        printf("\nNovo Telefone = ");
    	    scanf("%d",&telefone);
	        (*raiz)->telefone= telefone;
    	    system("cls");
           
        	printf("*-----------------*\n");
        	printf("| Dado Alterado!! |\n");
        	printf("*-----------------*\n");
        	getch();
			}
		}
	}
	}else{
         system("cls");
         
         printf("*-----------------------*\n");
         printf("| Nome nao encontrado!! |\n");
         printf("*-----------------------*\n");
         getch();

	}
}

void excluir(Arvore **raiz,char string[]){
 Arvore **aux2, *aux3;     
 if(*raiz!=NULL) {
  if( strcasecmp((*raiz)->Nome , string)==0 ){
   if((*raiz)->esq == (*raiz)->dir){
	free(*raiz);
	*raiz = NULL;
   }else{
	     if((*raiz)->esq != NULL){
          aux2 = maior_esq(*raiz);
	      aux3 = *aux2;
	      (*aux2) = (*aux2)->esq;
	     }else{
			   aux2 = menor_dir(*raiz);
			   aux3 = *aux2;
			   (*aux2) = (*aux2)->dir;
			  }
          strcpy((*raiz)->Nome, aux3->Nome);
	      free(aux3); aux3 = NULL;
	     }
		
  }else{
		if(strcasecmp(string,(*raiz)->Nome)<0)
		{
		 excluir(&(*raiz)->esq,string);
		}else{
		     excluir(&(*raiz)->dir,string);
			 }
	   }
}
        else{
            system("cls");
            
            printf("*-----------------------*\n");
            printf("| Nome nao encontrado!! |\n");
            printf("*-----------------------*\n");
            getch();
        } 
}

Arvore** maior_esq (Arvore *raiz){ 
 Arvore **aux = &(raiz);
 if((*aux)->esq != NULL){
   aux = &(*aux)->esq;
   while( (*aux)->dir != NULL ){
    aux = &(*aux)->dir;
  }}
  return aux;
}

Arvore** menor_dir(Arvore *raiz){
  Arvore **aux = &(raiz);
  if((*aux)->dir != NULL){
    aux = &(*aux)->dir;
    while((*aux)->esq != NULL){
      aux=&(*aux)->esq;
    }}
     return aux;
}

void Menu(int *num){
	printf("\t   AGENDA\n");       
	printf("|---------------------------|\n");
	printf("| 1 - Inserir Contatos      |\n");
	printf("|---------------------------|\n");
	printf("| 2 - Imprimir Contatos     |\n");
	printf("|---------------------------|\n");
	printf("| 3 - Pesquisar Contatos    |\n");
	printf("|---------------------------|\n");
	printf("| 4 - Remover Contato       |\n");
	printf("|---------------------------|\n");
	printf("| 5 - Alterar Contato       |\n");
	printf("|---------------------------|\n");
	printf("| 7 - Sair                  |\n");
	printf("*---------------------------*\n");
	
	printf("\nDigite uma opcao = ");
	scanf("%d",num);
	getchar();
}

void Menu_1(){
	system("cls");
	printf("*------------------*\n");
	printf("| INSERIR CONTATOS |\n");
	printf("*------------------* \n");
}

void Menu_2(){
	system("cls");
	printf("*---------------------*\n");
	printf("| IMPRIMIR CONTATOS   |\n");
	printf("*---------------------* ");
}

void Menu_3(){
	system("cls");
	printf("*-------------------*\n");
	printf("| PESQUISAR CONTATO |\n");
	printf("*-------------------* \n");
}

void Menu_4(){
	system("cls");
	printf("*-------------------*\n");
	printf("|  EXCLUIR CONTATO  |\n");
	printf("*-------------------* \n");
}

void Menu_5(){
	system("cls");
	printf("*-------------------*\n");
	printf("|  ALTERAR CONTATO  |\n");
	printf("*-------------------* \n");
}

void ler_telefone(int *telefone){
	printf("\nDigite o Telefone = ");
	scanf("%d",telefone);
}

void ler_string(char string[]){
	printf("\nDigite o Nome = ");
	fflush(stdin);
	
	gets(string);
	maiuscula(string);
}

void maiuscula(char string[]){
	int i;
	for(i=0;i<strlen(string);i++){
		if((string[i]>='a') && (string[i]<='z')){
			string[i]-=32;
		}
	}
}

void opcao(char op[]){
	printf("\nDeseja continuar cadastrando? Sim = s ou Nao = n: ");
	fflush(stdin);
	gets(op);
}

main(){
	int num;
	char Nome[100],op[2];
	      
	Arvore *raiz;
	raiz = NULL;
	      
	while(num!=7) {
		Menu(&num);
		switch(num){
			case 1:
			do{
				Menu_1();
				ler_string(Nome);
				inserir(&raiz,Nome);
				opcao(op);
			}while(*op == 's' || *op =='S');
				break;
			case 2:
				Menu_2();
				ordem(raiz);
				getch();
				break;
			case 3:
				Menu_3();
				ler_string(Nome);
				busca(raiz,Nome);
				break;
			case 4:
			do{
				Menu_4();
				ler_string(Nome);
				opcao(op);
				if(*op == 'n' || *op =='N')break;
				excluir(&raiz,Nome);break;
			}while(*op =='s' || *op =='S');           
				break;
			case 5:
				Menu_5();
				ler_string(Nome);
				Altera(&raiz,Nome);
				break;
		}
		system("cls");
	}
}
