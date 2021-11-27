#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

/* Prototype */
void tampilTabel(char tab[9]);
void resetTabel(char tab[9]);

/* Variabel Boolean */
enum boolean {false, true};

int main(){
	/* Kamus */
	int i, row, col, win, err, empty;
	char ulang;
	char turn = 'X';
	char errMessage[100];
	
	// Tic Tac Toe Board
	char tabel[9] = {
		' ', ' ', ' ',
		' ', ' ', ' ',
		' ', ' ', ' '
	};
	
	// Tic Tac Toe Valid Win
	int valid[8][3] = {
		{0, 1, 2},
		{3, 4, 5},
		{6, 7, 8},
		
		{0, 3, 6},
		{1, 4, 7},
		{2, 5, 8},
		
		{0, 4, 8},
		{2, 4, 6}
	};
	
	/* Algoritma */
	newGame:
	resetTabel(tabel);
	err = false;
	
	start:
	system("cls");
	empty = 0;
	
	// Cek apakah masih tersedia kolom yang kosong
	for(i = 0; i < 9; i++){
		if(tabel[i] == ' ') empty++;
	}
	
	if(empty == 0){
		turn = ' ';
		goto end;
	}
	
	tampilTabel(tabel);
	
	printf("\n  -----------\n");
	printf("  | %c  TURN |\n", turn);
	printf("  -----------\n");
	printf("%s\n", err ? errMessage : "");
	printf("Masukkan kolom (1 ~ 9)");
	col = getch() - '1';
	
	err = false;
	
	if(col < 0 || col > 8){
		err = true;
		strcpy(errMessage, "\n[ Input kolom salah! ]\n");
		goto start;
	}
	
	if(tabel[col] == ' ') tabel[col] = turn;
	else{
		err = true;
		strcpy(errMessage, "\n[ Kolom telah diisi! ]\n");
		goto start;
	}
	
	i = 0;
	
	// Validasi Tic Tac Toe
	while(i < 8){
		if(tabel[valid[i][0]] == turn &&
			tabel[valid[i][1]] == turn &&
			tabel[valid[i][2]] == turn){
			goto end;
		}
		
		i++;
	}
	
	// Mengubah giliran
	if(turn == 'X') turn = 'O';
	else turn = 'X';
	
	goto start;
	
	end:
	system("cls");
	tampilTabel(tabel);
	
	printf("\n\n------------------------\n");
	printf("|  Permainan Selesai!  |\n");
	
	if(turn != ' ') printf("| Pemenangnya adalah %c |\n", turn);
	else {
		turn = 'X';
		printf("|  Pertandingan Seri!  |\n");
	}
	
	printf("------------------------\n\n");
	
	restart:
	printf("Ulangi Permainan? (y/n)");
	ulang = getch();
	
	if(ulang == 'y') goto newGame;
	else if(ulang == 'n'){
		printf("\n=================================\n");
		printf("| Terima kasih telah bermain ^^ |\n");
		printf("=================================\n");
	}
	else{
		printf("\n[ Masukkan y atau n! ]\n\n");
		goto restart;
	}
	
	return 0;
}

/* Fungsi dan Prosedur */
void tampilTabel(char tab[9]){
	int i;
	
	printf("===============\n");
	printf("| Tic Tac Toe |\n");
	printf("===============\n\n");
	
	printf(" +---+---+---+\n");
	
	for(i = 0; i < 9; i++){
		switch(i){
			case 0: 
			case 3:
			case 6:
				printf(" |");
				break;
		}
	
		printf(" %c |", tab[i]);
		
		if((i + 1) % 3 == 0){
			printf("\n");
			printf(" +---+---+---+\n");
		}
	}
}

void resetTabel(char tab[9]){
	int i;
	
	for(i = 0; i < 9; i++){
		tab[i] = ' ';
	}
}
