#include <stdio.h>
#include <stdlib.h>

struct times{
    int time;
    int vitorias;
    int pontos;
    int sofridos;
    float media;
};
typedef struct times TIMES;

int main(){
    int n, i, h = 1, x, y, w, z, j, p;
    TIMES *team = NULL;
    TIMES aux;

    printf("Digite o numero de times: ");
    scanf("%d", &n);

    while(n != 0){

    team = (TIMES*)malloc(n*sizeof(TIMES));

    for (i=0; i<n; i++){
        team[i].time = i+1;
        team[i].vitorias = 0;
        team[i].pontos = 0;
        team[i].sofridos = 0;
    }

    p = (n*(n-1)) / 2;

    for(i=0; i<p; i++){
        printf("Digite o primeiro time: ");
        scanf("%d", &x);
        printf("Digite os pontos do primeiro time: ");
        scanf("%d", &y);
        printf("Digite o segundo time: ");
        scanf("%d", &z);
        printf("Digite os pontos do segundo time: ");
        scanf("%d", &w);
        team[x-1].pontos += y;
        team[x-1].sofridos += w;
        team[z-1].pontos += w;
        team[z-1].sofridos += y;
        if (y > w){
            team[x-1].vitorias +=2;
            team[z-1].vitorias += 1;
        }
        else {
            team[x-1].vitorias += 1;
            team[z-1].vitorias += 2;
        }
    }

    for(i=0; i<n; i++){
            if (team[i].sofridos == 0){
                team[i].sofridos = 1;
            }
        team[i].media = (float)team[i].pontos / team[i].sofridos;
    }

    for(i=0; i<n-1; i++){
        for(j=0; j<n-1; j++){
            if((team[j].vitorias < team[j+1].vitorias) ||
               (team[j].vitorias == team[j+1].vitorias && team[j].media < team[j+1].media) ||
               (team[j].vitorias == team[j+1].vitorias && team[j].media == team[j+1].media && team[j].pontos < team[j+1].pontos )||
               (team[j].vitorias == team[j+1].vitorias && team[j].media == team[j+1].media && team[j].pontos == team[j+1].pontos && team[j].time > team[j+1].time )){
                aux = team[j];
                team[j] = team[j+1];
                team[j+1] = aux;
               }
        }
    }
    printf("Instancia %d\n", h);
    for(i=0; i<n; i++){
        if (i==n-1){
            printf("%d\n", team[i].time);
        }
        else{
        printf("%d ", team[i].time);
        }
    }
    h++;

    free(team);

    printf("Digite o numero de times: ");
    scanf("%d", &n);
    }
}
