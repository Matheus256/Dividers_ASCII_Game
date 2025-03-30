#include "FaseLevel2.hpp"

void FaseLevel2::init(){
    //=================== Objetos de Jogo =====================================================

	objs.push_back(new ObjetoDeJogo("Ceu", SpriteAnimado("rsc/ceu.anm", 7, COR::AZUL), 1, 1));

    comeia = new Grafo("Comeia", Sprite("rsc/comeia1.txt", COR::AMARELA), 4, 48, nullptr);
    objs.push_back(comeia);

	objs.push_back(new ObjetoDeJogo("Grama", Sprite("rsc/gama2.txt", COR::VERDE), 17, 18));
	objs.push_back(new ObjetoDeJogo("Controles", Sprite("rsc/controles.txt"), 17, 4));
	objs.push_back(new ObjetoDeJogo("Sair", TextSprite("Desistir: q"), 22, 6));
	objs.push_back(new ObjetoDeJogo("Grama", Sprite("rsc/grama.txt", COR::VERDE), 18, 58));

    cursor = new Cursor("Cursor", Sprite("rsc/Cursor.txt"), 6, 65, nullptr);
    objs.push_back(cursor);

	lisa = new AjudanteMotivacional("Lisa", SpriteAnimado("rsc/lisa.anm",3, COR::AMARELA), 4, 2);
	objs.push_back(lisa);

	caixa = new ObjetoDeJogo("Caixa", Sprite("rsc/caixa.txt"), 4 + 1, 5 + 10);
	objs.push_back(caixa);

	frase = new Texto("frase", TextSprite(""), 4 + 3, 5 + 14);
	objs.push_back(frase);
	
}

unsigned FaseLevel2::run(SpriteBuffer &screen){
    //========== Criação dos nos e das adjacencias entre cada no ==========================
    Node noA{"A", TextSprite(" ", COR::AMARELA), 0, 4, 48}, noB{"B", TextSprite(" ", COR::AMARELA)};
	Node noC{"C", TextSprite(" ", COR::AMARELA)}, noD{"D",TextSprite(" ", COR::AMARELA)};
	Node noE{"E", TextSprite(" ", COR::AMARELA)}, noF{"F", TextSprite(" ", COR::AMARELA)};
	Node noG{"G", TextSprite(" ", COR::AMARELA)}, noH{"H", TextSprite(" ", COR::AMARELA)};
	Node noJ{"J",TextSprite(" ", COR::AMARELA)};

	noA.inserir_no_adjacente(&noB, abaixo);

	noB.inserir_no_adjacente(&noC, abaixo);
	noB.inserir_no_adjacente(&noA, acima);

	noC.inserir_no_adjacente(&noF, abaixo_esquerda);
	noC.inserir_no_adjacente(&noG, abaixo_direita);
	noC.inserir_no_adjacente(&noB, acima);

	noF.inserir_no_adjacente(&noC, acima_direita);
	noF.inserir_no_adjacente(&noD, acima_esquerda);
	noF.inserir_no_adjacente(&noH, abaixo_esquerda);

	noD.inserir_no_adjacente(&noH, abaixo);
	noD.inserir_no_adjacente(&noF, abaixo_direita);

	noH.inserir_no_adjacente(&noD, acima);
	noH.inserir_no_adjacente(&noF, acima_direita);

	noG.inserir_no_adjacente(&noC, acima_esquerda);
	noG.inserir_no_adjacente(&noE, acima_direita);
	noG.inserir_no_adjacente(&noJ, abaixo_direita);

	noE.inserir_no_adjacente(&noJ, abaixo);
	noE.inserir_no_adjacente(&noG, abaixo_esquerda);

	noJ.inserir_no_adjacente(&noE, acima);
	noJ.inserir_no_adjacente(&noG, acima_esquerda);

    //=================== Fim definição dos nos e das adjacencia ==============================
    //--------- Colocando os nos na comeia -------------//
    comeia->inserirNo(&noA);
	comeia->inserirNo(&noB);
	comeia->inserirNo(&noC);
	comeia->inserirNo(&noD);
	comeia->inserirNo(&noE);
	comeia->inserirNo(&noF);
	comeia->inserirNo(&noG);
	comeia->inserirNo(&noH);
	comeia->inserirNo(&noJ);
    //---------- Nos colocados na comeia ---------------//

    cursor->setNoAtual(&noA);

	lisa->carregarFalas("");

    //std::string ent;
    int num;
	long int contador = 0;
	bool passou = false;

	//caixa->desativarObj();
	//frase->desativarObj();

	Sound sucesso("rsc/sounds/success.mp3");
	Sound backMusic("rsc/sounds/guitar-v32.mp3");
	backMusic.playloop();

	frase->colocarFrase("Com a mesma disposicao de comeias, mas   desta vez voce nao podera usar numeros   maiores do que 12. Que comece o desafio!");
	
	Keyboard::setMode(Keyboard::NONBLOCKING);

	//padrão
	screen.clear();
	draw(screen);
	system("clear");
	show(screen);
	
	while (true){

		//lendo entrada
		//getline(std::cin,ent);
		char ent=Keyboard::read();
		

		//processando entradas
		if(ent == 's'){
			cursor->descer();
		} else if (ent == 'w'){
			cursor->subir();
		} else if (ent == 'a'){
			cursor->esquerda();
		} else if (ent == 'd'){
			cursor->direita();
		} else if(ent == 'k'){
			Keyboard::setMode(Keyboard::BLOCKING);

			std::cout << "Qual numero deseja inserir? ";
			std::cin >> num;
			cursor->getNoAtual()->setValor(num);

			Keyboard::setMode(Keyboard::NONBLOCKING);

		} else if(ent == 'c'){
			contador = 0;
			Node *node = comeia->checagem();
        	if(!(node)){
				frase->colocarFrase("Parabens voce venceu!                    Fico muito feliz com o resultado...      Precione ENTER para continuar.");
				caixa->ativarObj();
				passou =  true;
				sucesso.play();
				break;
			} else{
				caixa->ativarObj();
				//frase->ativarObj();
					
				std::string fala{lisa->falaSorteada()};
				std::replace(fala.begin(), fala.end(), '@', node->getRotulo()[0]);
				frase->colocarFrase(fala);
			}
		} else if(ent == 'q'){
			frase->colocarFrase("Fim de jogo!                             Que pena, eu estava torcendo por voce    Precione ENTER para voltar ao menu.");
			caixa->ativarObj();
			//frase->ativarObj();
			break;
		} else if(isdigit(ent)){
			int num{ent - '0'}, val{cursor->getNoAtual()->getValor()};
			if(val<10 && val > 0){
				num = val*10 + num;
                if (num > 12){
                    num = ent - '0';
					contador = 0;
                    frase->colocarFrase("Lembre-se que a regra mudou, para ser    mais dificil, agora nao vale usar numerosmaiores do que 12.");
					caixa->ativarObj();
                }
			}

			cursor->getNoAtual()->setValor(num);
		} else if(ent == ' '){
			cursor->getNoAtual()->setValor(0);
		}
		
		if(contador> 80){
			caixa->desativarObj();
			frase->colocarFrase("");
			//frase->desativarObj();
		}

		if(contador>150){
			frase->colocarFrase("Tudo bem demorar um pouco...             Estou aqui para te ajudar a conseguir");
			caixa->ativarObj();
			//frase->ativarObj();
		}

		//padrão
		update();
		screen.clear();
		draw(screen);
		system("clear");
		show(screen);

		contador++;

		system("sleep 0.3");
	}

	//padrão
	update();
	screen.clear();
	draw(screen);
	system("clear");
	show(screen);
	
	Keyboard::setMode(Keyboard::BLOCKING);
	std::string str;
	getline(std::cin,str);
	Keyboard::setMode(Keyboard::NONBLOCKING);

	backMusic.stop();
	
	if(passou)
		return Fase::LEVEL_COMPLETE;

	//return Fase::MENU;
	return Fase::GAME_OVER;
}