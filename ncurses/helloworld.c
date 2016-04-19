#include <ncurses.h>

int main(void)
{
	initscr();				//init stuct window et autres

	mvprintw(LINES / 2, COLS / 2, "HelloWorld");	//ecrit Hello a la position du curseur logique
	refresh();				//rafraichi fenetre pour voir Hello
	getch();	//attend une saisie pour quitter
	clear();
	//	endwin();				//resteure terminal
	
	WINDOW *haut, *bas, *haut2;
    
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	attron(COLOR_PAIR(1));
	while(1) 
	{
        mvprintw(16, 0,  "i dont fuck with you\n");
    haut= subwin(stdscr, 20, 20, 10, 10);        // Créé une fenêtre de 'LINES / 2' lignes et de COLS colonnes en 0, 0
	haut2 = subwin(haut, 18, 18, 11 , 11);
		//bas= subwin(stdscr, LINES / 2, COLS, LINES / 2, 0); // Créé la même fenêtre que ci-dessus sauf que les coordonnées changent
	//	wborder(bas, '-', '-', '|', '|', '0', '0', '0', '0');
    box(haut, ACS_VLINE, ACS_HLINE);
        mvwprintw(haut2, 5, 5,  "Le terminal actuel haut comporte %d lignes et %d colonnes\n", LINES, COLS);
      //  mvwprintw(bas, LINES / 3, COLS / 2, "Le terminal actuel bas comporte %d lignes et %d colonnes\n", LINES, COLS);
		// wrefresh(bas);
		// wrefresh(haut2);
	    refresh();  // Rafraîchit la fenêtre par défaut (stdscr) afin d'afficher le message
       	if(getch() != 410)  // 410 est le code de la touche générée lorsqu'on redimensionne le terminal
			break;
		clear();
    }
	attroff(COLOR_PAIR(1));
    wrefresh(haut);
//    wrefresh(bas);
									    
    getch();
    endwin();
   
    free(haut);
    free(bas);



	return (0);
}


