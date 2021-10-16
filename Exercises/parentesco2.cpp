#include <iostream>
#include <stdio.h>
#include <string.h>
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
    Filho *pai = createFilho("Juca");
    Filho *mae = createFilho("Caju");
    Filho *filho = createFilho("Olivier");

    filho->mae = mae;
    filho->pai = pai;

    list = insertFilhoList(mae);
    list = insertFilhoList(pai);
    list = insertFilhoList(filho);
    
    // Juca Caju Gin
    pai = createFilho("Juca");
    mae = createFilho("Caju");
    filho = createFilho("Gin");

    filho->mae = mae;
    filho->pai = pai;
    
    list = insertFilhoList(mae);
    list = insertFilhoList(pai);
    list = insertFilhoList(filho);

    // Alice Bob Gina
    pai = createFilho("Alice");
    mae = createFilho("Bob");
    filho = createFilho("Gina");

    filho->mae = mae;
    filho->pai = pai;

    list = insertFilhoList(mae);
    list = insertFilhoList(pai);
    list = insertFilhoList(filho);

    // Alice Bob Bonnie
    pai = createFilho("Alice");
    mae = createFilho("Bob");
    filho = createFilho("Bonnie");

    filho->mae = mae;
    filho->pai = pai;

    list = insertFilhoList(mae);
    list = insertFilhoList(pai);
    list = insertFilhoList(filho);

    //  Bonnie Perf Elis
    pai = createFilho("Bonnie");
    mae = createFilho("Perf");
    filho = createFilho("Elis");

    filho->mae = mae;
    filho->pai = pai;

    list = insertFilhoList(mae);
    list = insertFilhoList(pai);
    list = insertFilhoList(filho);

    //  Gin Gina Ped
    pai = createFilho("Gin");
    mae = createFilho("Gina");
    filho = createFilho("Ped");

    filho->mae = mae;
    filho->pai = pai;

    list = insertFilhoList(mae);
    list = insertFilhoList(pai);
    list = insertFilhoList(filho);

    // Marie Olivier Zec
    pai = createFilho("Marie");
    mae = createFilho("Olivier");
    filho = createFilho("Zec");

    filho->mae = mae;
    filho->pai = pai;

    list = insertFilhoList(mae);
    list = insertFilhoList(pai);
    list = insertFilhoList(filho);

    //FilhoList *aux = list;
    // while(aux != NULL){
    //     std::cout << aux->filho->nome << std::endl;
    //     // pai 
    //     if(aux->filho->pai != NULL){
    //         std::cout << "\t\t pai: " << aux->filho->pai->nome << std::endl;
    //     }
    //     // mae
    //     if(aux->filho->mae != NULL){
    //         std::cout << "\t\t mae: " << aux->filho->mae->nome << std::endl;
    //     }
    //     aux = aux->next;
    // }

    std::cout << verificaParentesco(createFilho("Juca"),createFilho("Caju")) << std::endl;
    std::cout << verificaParentesco(createFilho("Elis"),createFilho("Ped")) << std::endl;
    std::cout << verificaParentesco(createFilho("Zec"),createFilho("Perf")) << std::endl;


    return 0;
}
   

   
