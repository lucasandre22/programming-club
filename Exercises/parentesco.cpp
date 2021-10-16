
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <string>
/**
 * Make a arvore genealogica
 * a search parentesco
 */


typedef struct FilhoNode
{
    std::string nome;
    struct FilhoNode *mae;
    struct FilhoNode *pai;
} Filho;


typedef struct FilhoList{
    Filho *filho;
    struct FilhoList *next;
} FilhoList;

FilhoList * createFilhoList(){
    return NULL;
}
FilhoList *list = createFilhoList();

FilhoNode* existFilhoInList(std::string nome){
    FilhoList *aux = list;
    while(aux != NULL){
        if(aux->filho->nome == nome){
            return aux->filho;
        }
        aux = aux->next;
    }
    return NULL;
}


FilhoList* insertFilhoList(Filho *filho){
    // inser if not exist
    if(existFilhoInList(filho->nome) == NULL){
        FilhoList *newFilho = (FilhoList*) malloc(sizeof(FilhoList));
        newFilho->filho = filho;
        newFilho->next = list;
        return newFilho;
    }
    return list;
}
    


FilhoNode* createFilho(std::string nome){
    // if exist in list
    FilhoNode *filho = existFilhoInList(nome);
    if(filho != NULL){
        return filho;
    }
    // create new
    filho = (FilhoNode*) malloc(sizeof(FilhoNode));
    filho->nome = nome;
    filho->mae = NULL;
    filho->pai = NULL;
    list = insertFilhoList(filho);
    return filho;
}
   


    
int verificaParentesco(FilhoNode *filho1,FilhoNode *filho2){
        if(filho1 == NULL || filho2 == NULL){
            return 0;
        }
        if(filho1->nome == filho2->nome){
            return 1;
        }
        return verificaParentesco(filho1->mae,filho2) + 
                verificaParentesco(filho1->pai,filho2) + 
                    verificaParentesco(filho2->mae,filho1->mae) + 
                        verificaParentesco(filho2->pai,filho1->pai);
}

int main()
{
   
    // Juca Caju Olivier
    Filho *pai = NULL;
    Filho *mae = NULL;
    Filho *filho = NULL;

    std::vector<std::string> cavalos;
    std::string Spai, Smae, Sfilho;
    std::string filho1, filho2;

    int N,C,T;

    scanf("%d %d %d", &N, &C, &T);
    for(int i = 0; i < C; i++) {
        std::cin >> Spai;
        std::cin >> Smae;
        std::cin >> Sfilho;
        pai = createFilho(Spai);
        mae = createFilho(Smae);
        filho = createFilho(Sfilho);
        filho->mae = mae;
        filho->pai = pai;

        list = insertFilhoList(mae);
        list = insertFilhoList(pai);
        list = insertFilhoList(filho);
    }
    
    for(int i = 0; i < T; i++) {
        std::cin >> filho1;
        std::cin >> filho2;
        int la = verificaParentesco(createFilho(filho1),createFilho(filho2));
        std::string saida = la > 0 ? "verdadeiro" : "falso";
        std::cout << saida << std::endl;
    }

    return 0;
}
