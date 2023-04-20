struct player{
	int x;
	int y;
	int hp; //health points
};

struct block{
	int type;
};

struct map{
	int rows;
	int collumns;
	struct block blocks[rows][collumns];
};

// type = 2 -> caverna, = 1 -> parede, = 0 -> chao


//funcao drawBlock -> fucao que consoante o type do block desenha os diferentes carateres: -> Dinis
//parede -> #
//jogador -> @
//caverna -> -
//chao -> .


//funcao drawPlayer -> desenha o jogador consoante é chamada a funcao moveJogador -> João
//funcao moveJogador -> consoante o clique das teclas, as coordenadas do jogador devem ser atualizadas. Ter em conta a deteção dos obstáculos: -> João
//Usar as setas para a movimentação


//funcao geraMapa
//funcao estabelece bordas -> ocupar dois blocos de borda - Tomás
//fucao enche % do mapa


//criar janela no main -> Tomás

