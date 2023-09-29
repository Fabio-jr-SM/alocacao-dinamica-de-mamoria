#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int tam, i, *vet;

    scanf("%d",&tam);
    srand(time(NULL));
    
    vet = malloc(tam * sizeof(int));
    
    if(vet){
        for(i=0;i<tam;i++){
            *(vet + i) = rand()%100;
        }
        
        for(i=0;i<tam;i++){
            printf("%d ",*(vet+i));
        }
        
        free(vet);
        
    }else{
        printf("Erro ao alocar memoria");
    }
    
    return 0;
}


