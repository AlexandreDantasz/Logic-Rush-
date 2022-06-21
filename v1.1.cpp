#include <iostream>
#include <vector>
#include <locale>

using namespace std;

int main(){
    // LOGIC RUSH! V1.1
    setlocale(LC_ALL, "portuguese");
    vector <int> empates;
    int Qtde_Jogadores, num, maior, indice, i, desafiado, rods, tam;
    char desafio;
    printf("---------- LOGIC RUSH! V1.1 ----------\n");
    printf("Digite a quantidade de jogadores: ");
    scanf("%d", &Qtde_Jogadores);
    while (Qtde_Jogadores > 3 || Qtde_Jogadores < 2){
		if (Qtde_Jogadores < 2){
			printf("A QUANTIDADE DE JOGADORES É INSUFICIENTE\n");
		}
		else{
			printf("A QUANTIDADE MÁXIMA DE JOGADORES FOI ULTRAPASSADA\n");
		}
		printf("Digite a quantidade de jogadores: ");
		scanf("%d", &Qtde_Jogadores);
	}
    int Jogadores[Qtde_Jogadores] = {0}, Rodadas[Qtde_Jogadores] = {0};
    printf("\nOBS: SE O JOGADOR PERDER PONTOS, BASTA DIGITAR O NÚMERO NEGATIVO\n\n");
    printf("---------- COMEÇOU ----------\n\n");
    bool ver = true, emp;
    while (ver == true){
		for (i = 0; i < Qtde_Jogadores; i++){
			printf("VEZ DO JOGADOR %d\n", i + 1);
			cin.ignore();
			printf("Ocorreu um desafio? S/N: ");
			scanf("%c", &desafio);
			while (desafio != 's' && desafio != 'S' && desafio != 'n' && desafio != 'N'){
				printf("RESPOSTA INVÁLIDA\n");
				cin.ignore();
				printf("Ocorreu um desafio? S/N: ");
				scanf("%c", &desafio);
			}
			if (desafio == 'S' || desafio == 's'){
				printf("Digite o número do jogador escolhido para o desafio: ");
				scanf("%d", &desafiado);
				while (desafiado > 3 || desafiado < 0 || desafiado == i + 1){
					printf("NÚMERO DE JOGADOR INVÁLIDO\n");
					printf("Digite o número do jogador escolhido para o desafio: ");
					scanf("%d", &desafiado);
				}
				printf("Digite a quantidade de pontos que o jogador %d ganhou/perdeu: ", i + 1);
				scanf("%d", &num);
				while (num != 5 && num != 10 && num != 20 && num != -5 && num != -10 && num != -20){
					printf("PONTUAÇÃO INEXISTENTE\n");
					printf("Digite a quantidade de pontos que o jogador %d ganhou/perdeu: ", i + 1);
					scanf("%d", &num);
				}
				Jogadores[i] += num;
				printf("Digite a quantidade de rodadas que o jogador %d tem: ", i + 1);
				scanf("%d", &rods);
				while (rods < 0 || rods > 3){
					printf("NÚMERO DE RODADA INEXISTE\n");
					printf("Digite a quantidade de rodadas que o jogador %d tem: ", i + 1);
					scanf("%d", &rods);
				}
				Rodadas[i] = rods;
				if (Rodadas[i] == 3){
					ver = false;
					break;
				}
				else{
					printf("Digite a quantidade de pontos que o jogador %d ganhou/perdeu: ", desafiado);
					scanf("%d", &num);
					while (num != 5 && num != 10 && num != 20 && num != -5 && num != -10 && num != -20){
						printf("PONTUAÇÃO INEXISTENTE\n");
						printf("Digite a quantidade de pontos que o jogador %d ganhou/perdeu: ", desafiado);
						scanf("%d", &num);
					}
					Jogadores[desafiado - 1] += num;
					printf("Digite a quantidade de rodadas que o jogador %d tem: ", desafiado);
					scanf("%d", &rods);
					while (rods < 0 || rods > 3){
						printf("NÚMERO DE RODADA INEXISTE\n");
						printf("Digite a quantidade de rodadas que o jogador %d tem: ", desafiado);
						scanf("%d", &rods);
					}
					Rodadas[desafiado - 1] = rods;
					if (Rodadas[desafiado - 1] == 3){
						ver = false;
						break;
					}
				}
			}
			else{
				printf("Digite a quantidade de pontos que o jogador %d ganhou/perdeu: ", i + 1);
				scanf("%d", &num);
				while (num != 5 && num != 10 && num != 20 && num != -5 && num != -10 && num != -20){
					printf("PONTUAÇÃO INEXISTENTE\n");
					printf("Digite a quantidade de pontos que o jogador %d ganhou/perdeu: ", i + 1);
					scanf("%d", &num);
				}
				Jogadores[i] += num;
				printf("Digite a quantidade de rodadas que o jogador %d tem: ", i + 1);
				scanf("%d", &rods);
				while (rods < 0 || rods > 3){
					printf("NÚMERO DE RODADA INEXISTE\n");
					printf("Digite a quantidade de rodadas que o jogador %d tem: ", i + 1);
					scanf("%d", &rods);
				}
				Rodadas[i] = rods;
				if (Rodadas[i] == 3){
					ver = false;
					break;
				}
			}
			printf("\n");
		}
		printf("\n---------- PLACAR ATUAL ----------\n");
		for (i = 0; i < Qtde_Jogadores; i++){
			printf("JOGADOR %d: %d PONTOS E %d RODADAS\n", i + 1, Jogadores[i], Rodadas[i]);
		}
		printf("\n");
	}
	printf("---------- COMPLETARAM AS RODADAS ----------\n");
	emp = false;
	maior = -58320;
	for (i = 0; i < Qtde_Jogadores; i++){
		if (Jogadores[i] > maior){
			maior = Jogadores[i];
			rods = Rodadas[i];
			indice = i + 1;
			emp = false;
		}
		else{
			if (Jogadores[i] == maior){
				if (Rodadas[i] > rods){
					indice = i + 1;
					rods = Rodadas[i];
					emp = false;
				}
				else{
					if (Rodadas[i] == rods){
						empates.push_back(i);
						empates.push_back(i + 1);
						emp = true;
					}
				}
			}
		}
	}
	if (emp == true){
		tam = empates.size();
		printf("Os jogadores ");
		for (i = 0; i < tam - 1; i++){
			printf("%d, ", empates[i]);
		}
		printf("%d empataram!\n", empates[i]);
	}
	else{
		printf("\nO jogador %d ganhou o jogo!\n", indice);
	}
}
