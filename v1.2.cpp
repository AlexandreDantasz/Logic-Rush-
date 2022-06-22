#include <iostream>
#include <vector>
#include <locale>
#include <string.h>

using namespace std;

int main(){
    // LOGIC RUSH! V1.3
    setlocale(LC_ALL, "portuguese");
    vector <int> empates;
    int Qtde_Jogadores, num, maior, indice, i, desafiado, rods, tam, cont;
    char desafio, txt[10002];
    string points;
    printf("---------- LOGIC RUSH! V1.2 ----------\n\n");
    printf("DIGITE A QUANTIDADE DE JOGADORES: ");
    scanf("%d", &Qtde_Jogadores);
    while (Qtde_Jogadores > 3 || Qtde_Jogadores < 2){
		if (Qtde_Jogadores < 2){
			printf("!!!!! A QUANTIDADE DE JOGADORES É INSUFICIENTE !!!!!\n");
		}
		else{
			printf("\n!!!!! A QUANTIDADE MÁXIMA DE JOGADORES FOI ULTRAPASSADA !!!!!\n\n");
		}
		printf("DIGITE A QUANTIDADE DE JOGADORES: ");
		scanf("%d", &Qtde_Jogadores);
	}
    int Jogadores[Qtde_Jogadores] = {0}, Rodadas[Qtde_Jogadores] = {0};
    printf("\nOBS: SE O JOGADOR PERDER PONTOS, BASTA DIGITAR O NÚMERO NEGATIVO\n\n");
    printf("NÍVEL FÁCIL: 5 PONTOS\nNÍVEL MÉDIO: 10 PONTOS\nNÍVEL DIFÍCIL: 20 PONTOS\n\n");
    bool ver = true, emp;
    while (ver == true){
		for (i = 0; i < Qtde_Jogadores; i++){
			printf("\n---------- VEZ DO JOGADOR %d ----------\n\n", i + 1);
			cin.ignore();
			printf("OCORREU UM DESAFIO? S/N: ");
			scanf("%s", txt);
			desafio = txt[0];
			while (strlen(txt) > 1 || (desafio != 's' && desafio != 'S' && desafio != 'n' && desafio != 'N')){
				printf("\n!!!!! RESPOSTA INVÁLIDA !!!!!\n\n");
				cin.ignore();
				printf("OCORREU UM DESAFIO? S/N: ");
				scanf("%s", txt);
				desafio = txt[0];
			}
			if (desafio == 'S' || desafio == 's'){
				printf("DIGITE O NÚMERO DO JOGADOR ESCOLHIDO PARA O DESAFIO: ");
				cin.ignore();
				scanf("%s", txt);
				desafiado = txt[0] - 48;
				while (strlen(txt) > 1 || desafiado > 3 || desafiado < 0 || desafiado == i + 1){
					printf("\n!!!!! NÚMERO DE JOGADOR INVÁLIDO !!!!!\n\n");
					printf("DIGITE O NÚMERO DO JOGADOR ESCOLHIDO PARA O DESAFIO: ");
					cin.ignore();
					scanf("%s", txt);
					desafiado = txt[0] - 48;
				}
				printf("DIGITE A QUANTIDADE DE PONTOS QUE O JOGADOR %d GANHOU/PERDEU: ", i + 1);
				scanf("%d", &num);
				while (num != 0 && num != 5 && num != 10 && num != 20 && num != -5 && num != -10 && num != -20){
					printf("\n!!!!! PONTUAÇÃO INEXISTENTE !!!!!\n\n");
					printf("DIGITE A QUANTIDADE DE PONTOS QUE O JOGADOR %d GANHOU/PERDEU: ", i + 1);
					scanf("%d", &num);
				}
				Jogadores[i] += num;
				cin.ignore();
				printf("DIGITE A QUANTIDADE DE RODADAS QUE O JOGADOR %d TEM: ", i + 1);
				scanf("%s", txt);
				rods = txt[0] - 48;
				while (strlen(txt) > 1 || rods < 0 || rods > 3){
					printf("\n!!!!! NÚMERO DE RODADA INEXISTENTE !!!!!\n\n");
					cin.ignore();
					printf("DIGITE A QUANTIDADE DE RODADAS QUE O JOGADOR %d TEM: ", i + 1);
					scanf("%s", txt);
					rods = txt[0] - 48;
				}
				Rodadas[i] = rods;
				if (Rodadas[i] == 3){
					ver = false;
					break;
				}
				printf("DIGITE A QUANTIDADE DE PONTOS QUE O JOGADOR %d GANHOU/PERDEU: ", desafiado);
				scanf("%d", &num);
				while (num != 0 && num != 5 && num != 10 && num != 20 && num != -5 && num != -10 && num != -20){
					printf("\n!!!!! PONTUAÇÃO INEXISTENTE !!!!!\n\n");
					printf("DIGITE A QUANTIDADE DE PONTOS QUE O JOGADOR %d GANHOU/PERDEU: ", desafiado);
					scanf("%d", &num);
				}
				Jogadores[desafiado - 1] += num;
				printf("DIGITE A QUANTIDADE DE RODADAS QUE O JOGADOR %d TEM: ", desafiado);
				scanf("%s", txt);
				rods = txt[0] - 48;
				while (strlen(txt) > 1 || rods < 0 || rods > 3){
					printf("\n!!!!! NÚMERO DE RODADA INEXISTENTE !!!!!\n\n");
					cin.ignore();
					printf("DIGITE A QUANTIDADE DE RODADAS QUE O JOGADOR %d TEM: ", desafiado);
					scanf("%s", txt);
					rods = txt[0] - 48;
				}
				Rodadas[desafiado - 1] = rods;
				if (Rodadas[desafiado - 1] == 3){
					ver = false;
					break;
				}
			}
			else{
				printf("DIGITE A QUANTIDADE DE RODADAS QUE O JOGADOR %d TEM: ", i + 1);
				cin.ignore();
				scanf("%s", txt);
				rods = txt[0] - 48;
				while (strlen(txt) > 1 || rods < 0 || rods > 3){
					printf("\n!!!!! NÚMERO DE RODADA INEXISTENTE !!!!!\n\n");
					cin.ignore();
					printf("DIGITE A QUANTIDADE DE RODADAS QUE O JOGADOR %d TEM: ", i + 1);
					scanf("%s", txt);
					rods = txt[0] - 48;
				}
				Rodadas[i] = rods;
				if (Rodadas[i] == 3){
					ver = false;
					break;
				}
				printf("DIGITE A QUANTIDADE DE PONTOS QUE O JOGADOR %d GANHOU/PERDEU: ", i + 1);
				scanf("%d", &num);
				while (num != 0 && num != 5 && num != 10 && num != 20 && num != -5 && num != -10 && num != -20){
					printf("\n!!!!! PONTUAÇÃO INEXISTENTE !!!!!\n\n");
					cin.ignore();
					printf("DIGITE A QUANTIDADE DE PONTOS QUE O JOGADOR %d GANHOU/PERDEU: ", i + 1);
					scanf("%d", &num);
				}
				Jogadores[i] += num;
			}
		}
		printf("\n---------- PLACAR ATUAL! ----------\n\n");
		for (i = 0; i < Qtde_Jogadores; i++){
			printf("JOGADOR %d: %d PONTOS E %d RODADAS\n", i + 1, Jogadores[i], Rodadas[i]);
		}
	}
	printf("\n---------- RESULTADO! ----------\n");
	emp = false;
	maior = Jogadores[0];
	cont = Jogadores[0];
	for (i = 0; i < Qtde_Jogadores && Jogadores[i] == cont; i++);
	if (i == Qtde_Jogadores){
		printf("\nOS JOGADORES EMPATARAM!\n");
	}
	else{
		for (i = 0; i < Qtde_Jogadores; i++){
			if (Jogadores[i] > maior){
				maior = Jogadores[i];
				rods = Rodadas[i];
				indice = i + 1;
				emp = false;
			}
			else{
				if (Jogadores[i] == maior){
					empates.push_back(i);
					empates.push_back(i + 1);
					emp = true;
				}
			}
		}
		if (emp == true){
			tam = empates.size();
			printf("\nS JOGADORES ");
			for (i = 0; i < tam - 1; i++){
				printf("%d, ", empates[i]);
			}
			printf("%d EMPATARAM!\n", empates[i]);
		}
		else{
			printf("\nO JOGADOR %d GANHOU O JOGO!\n", indice);
		}
	}
}
