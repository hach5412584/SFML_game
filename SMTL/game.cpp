#include "game.h"
void game::initWindow()	//視窗建置
{
	this->videoMode.height = 600;
	this->videoMode.width = 400;
	this->window = new sf::RenderWindow(this->videoMode, "1 die 1 die");
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
}

void game::initsystem()//系統函數建置
{
	this->points = 0;
	this->gametime = timeclock.restart();;
	this->statustype = -1;
	this->player_move_speed = 1.5f;
	this->combo = 0;
	this->tempstatustype = -1;
	this->soundplayed = 0;
	this->start_tpye = 0;
	this->H_conts = 3;
}

void game::initGUI() //遊戲GUI文字建置
{
	if (!this->font.loadFromFile("Fonts/kaiu.ttf"))
	{
		std::cout << "錯誤：文字檔讀取失敗(Fonts/kaiu.ttf)" << std::endl;
	}
	this->pointText.setFont(this->font);
	this->pointText.setCharacterSize(20);
	this->pointText.setFillColor(sf::Color::Black);
	this->pointText.setString("0");

	this->hptext.setFont(this->font);
	this->hptext.setCharacterSize(20);
	this->hptext.setFillColor(sf::Color::Black);
	this->hptext.setString("HP:");
	this->hptext.setPosition(0.0f, 40.0f);

	this->timetext.setFont(this->font);
	this->timetext.setCharacterSize(20);
	this->timetext.setFillColor(sf::Color::Black);
	this->timetext.setString("Time:");
	this->timetext.setPosition(315.0f, 0.0f);

	this->combotext.setFont(this->font);
	this->combotext.setCharacterSize(20);
	this->combotext.setFillColor(sf::Color::Black);
	this->combotext.setString("Combo:");
	this->combotext.setPosition(315.0f, 40.0f);

	this->gameovertext.setFont(this->font);
	this->gameovertext.setCharacterSize(80);
	this->gameovertext.setFillColor(sf::Color::Red);
	this->gameovertext.setString("GameOver!");

	this->gameovertext.setPosition(
		this->window->getSize().x / 2.0f - this->gameovertext.getGlobalBounds().width/ 2.0f,
		this->window->getSize().y / 2.0f - this->gameovertext.getGlobalBounds().height / 2.0f);
}

void game::initEat_potins() //遊戲分數生成速度
{
	this->Eat_potinesspawnTimerMax = 50.0f;
	this->Eat_potinesspawnTimer = this->Eat_potinesspawnTimerMax;
}

void game::initenemy_dead() //遊戲敵人2生成速度
{
	this->enemy_deadsspawnTimerMax = 50.0f;
	this->enemy_deadsspawnTimer = this->enemy_deadsspawnTimerMax;
}

void game::initPlayer() //遊戲玩家建置
{
	this->Player = new player();
}

void game::initEnemy() //遊戲敵人生成速度
{
	this->EnemiesspawnTimerMax = 50.0f;
	this->EnemiesspawnTimer = this->EnemiesspawnTimerMax;
}

void game::initplayheart() //遊戲玩家生命
{
	if (!this->heart_T.loadFromFile("Textures/heart.png"))
	{
		std::cout << "錯誤：背景圖片讀取失敗(Textures/heart.png)" << std::endl;
	}
	this->heart_S.setTexture(this->heart_T);
	for (int i = 0; i < 3; i++) //建置玩家紅心生命
	{
		this->V_heart_S.push_back(heart_S);
		this->V_heart_S[i].scale(0.65f, 0.65f);
		this->V_heart_S[i].setPosition(40.0f  *(1 + i), 37.0f);
	}
	/*this->heart_S.scale(0.65f, 0.65f);
	this->heart_S2 = this->heart_S1 = this->heart_S;
	this->heart_S.setPosition(35.0f, 37.0f);
	this->heart_S1.setPosition(72.5f, 37.0f);
	this->heart_S2.setPosition(110.0f, 37.0f);*/

	if (!this->heart_lost_T.loadFromFile("Textures/heart_lost.png"))
	{
		std::cout << "錯誤：背景圖片讀取失敗(Textures/heart_lost.png)" << std::endl;
	}
	this->heart_lost_S.setTexture(this->heart_lost_T);
	for (int i = 0; i < 3 ; i++) //建置玩家灰心生命
	{
		this->V_heart_lost_S.push_back(heart_lost_S);
		this->V_heart_lost_S[i].scale(0.65f, 0.65f);
		this->V_heart_lost_S[i].setPosition(40.0f *(3 - i), 37.0f);
	}
	/*this->heart_lost_S.scale(0.65f, 0.65f);
	this->heart_lost_S2 = this->heart_lost_S1 = this->heart_lost_S;
	this->heart_lost_S.setPosition(35.0f, 37.0f);
	this->heart_lost_S1.setPosition(72.5f, 37.0f);
	this->heart_lost_S2.setPosition(110.0f, 37.0f);*/
}

void game::initsoundbuffer() //遊戲音效建置
{
	if (!die_lost.loadFromFile("sound/1die1die(lose.wav"))
	{
		std::cout << "錯誤：角色音效未載入位置(sound/1die1die(lose.wav)" << std::endl;
	}
	if (!backgroundSound.openFromFile("sound/backgroundsound.ogg"))
	{
		std::cout << "錯誤：角色音效未載入位置(sound/backgroundsound.ogg)" << std::endl;
	}
	if (!cant_move.loadFromFile("sound/cantmove.wav"))
	{
		std::cout << "錯誤：角色音效未載入位置(sound/cantmove.wav)" << std::endl;
	}
	if (!heal.loadFromFile("sound/heal.wav"))
	{
		std::cout << "錯誤：角色音效未載入位置(sound/heal.wav)" << std::endl;
	}
	if (!loseheart.loadFromFile("sound/loseheart.wav"))
	{
		std::cout << "錯誤：角色音效未載入位置(sound/loseheart.wav)" << std::endl;
	}
	if (!teleport.loadFromFile("sound/teleport.wav"))
	{
		std::cout << "錯誤：角色音效未載入位置(sound/teleport.wav)" << std::endl;
	}
}

void game::initsound() //遊戲音效建置
{	
	Die_lostSound.setBuffer(die_lost);
	Cant_moveSound.setBuffer(cant_move);
	HealSound.setBuffer(heal);
	LoseheartSound.setBuffer(loseheart);
	TeleportSound.setBuffer(teleport);
}

void game::initgamestart() //遊戲開始背景建置
{
	if (!this->BeginningTexture.loadFromFile("Textures/beginning.png"))
	{
		std::cout << "錯誤：背景圖片讀取失敗(Textures/beginning.png)" << std::endl;
	}
	if (!this->StartTexture.loadFromFile("Textures/start.png"))
	{
		std::cout << "錯誤：背景圖片讀取失敗(Textures/start.png)" << std::endl;
	}
	if (!this->EndTexture.loadFromFile("Textures/End.png"))
	{
		std::cout << "錯誤：背景圖片讀取失敗(Textures/End.png)" << std::endl;
	}
	this->Beginningsprite.setTexture(this->BeginningTexture);

	this->Startsprite.setTexture(this->StartTexture);
	this->Startsprite.setPosition(0.0f, 550.0f);

	this->Endsprite.setTexture(this->EndTexture);
	this->Endsprite.setPosition(240.0f, 550.0f);
}

void game::gameoverbackground() //遊戲結束背景建置
{
	if (!this->gameoverbackground_T.loadFromFile("Textures/gameover.png"))
	{
		std::cout << "錯誤：背景圖片讀取失敗(Textures/gameover.png)" << std::endl;
	}
	this->gameoverbackground_S.setTexture(this->gameoverbackground_T);
}

game::game() //遊戲建置
{
	this->initgamestart();
	this->initWindow();
	this->initsystem();
	this->initGUI();
	this->initPlayer();
	this->initEnemy();
	this->initEat_potins();
	this->initenemy_dead();
	this->initplayheart();
	this->initsoundbuffer();
	this->initsound();
	this->gameoverbackground();
}

game::~game() //遊戲卸載
{
	delete this->window;
	delete this->Player;

	for (auto *i : this->enemies) 
	{
		delete i;
	}
	for (auto *i : this->enemy_deads)
	{
		delete i;
	}
	for (auto *i : this->Eat_potines)
	{
		delete i;
	}
}

void game::backupdate() //遊戲背景
{
	this->background.setRepeated(true);
	this->sprite.setTexture(background);
	this->sprite.setTextureRect(sf::IntRect(0, 0, 400, 600));
	this->background.loadFromFile("Textures/backgd.jpg");
}

void game::updateGUI() //GUI更新
{
	std::stringstream sspoint,sstime,sscombo;

	sspoint << "Points:" << this->points;
	this->pointText.setString(sspoint.str());
	sstime << "Time:" << this->time;
	this->timetext.setString(sstime.str());
	sscombo << "Combo:" << this->combo;
	this->combotext.setString(sscombo.str());

	if (this->V_heart_S.empty() == true)
	{
		this->Die_lostSound.play();
		this->backgroundSound.stop();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		if (points >= 100 && V_heart_S.size() != 3 && H_conts > 0)
		{
			if (V_heart_S.size() == 1)
			{
				this->V_heart_S.push_back(heart_S);
				this->V_heart_S[1].setPosition(80.0f, 37.0f);
				this->V_heart_S[1].scale(0.65f, 0.65f);
				points = points - 100;
				H_conts--;
			}
			else if (V_heart_S.size() == 2)
			{
				this->V_heart_S.push_back(heart_S);
				this->V_heart_S[2].setPosition(120.0f, 37.0f);
				this->V_heart_S[2].scale(0.65f, 0.65f);
				points = points - 100;
				H_conts--;
			}
		}
	}
}

void game::updatecollision() //防止腳色衝出視窗
{
	if (this->Player->playergetBounds().left < 0.f) //左
	{
		this->Player->setposition(0.f, this->Player->playergetBounds().top);
	}
	else if (this->Player->playergetBounds().left + this->Player->playergetBounds().width >= this->window->getSize().x) //右
	{
		this->Player->setposition(this->window->getSize().x - this->Player->playergetBounds().width, this->Player->playergetBounds().top);
	}
	if (this->Player->playergetBounds().top < 0.f) //上
	{
		this->Player->setposition(this->Player->playergetBounds().left, 0.f); //下
	}
	else if (this->Player->playergetBounds().top + this->Player->playergetBounds().height >= this->window->getSize().y)
	{
		this->Player->setposition(this->Player->playergetBounds().left, this->window->getSize().y - this->Player->playergetBounds().height);
	}
}

void game::updateEnemies() //敵人更新
{
	this->EnemiesspawnTimer += 0.015f * (time + 20); //敵人生成時間
	if (this->EnemiesspawnTimer >= this->EnemiesspawnTimerMax) //敵人生成計算
	{
		this->enemies.push_back(new Enemy(rand() % this->window->getSize().x - 40.f, -100.f)); //敵人生成後加入陣列
		this->EnemiesspawnTimer = 0.0f; //生成時間歸0
	}

	for (int i = 0; i < this->enemies.size(); i++)
	{
		this->enemies[i]->update(); //敵人移動
		if (this->enemies[i]->EnemygetBounds().top > this->window->getSize().y)
		{
			this->enemies.erase(this->enemies.begin() + i);
		}
		else if (this->enemies[i]->EnemygetBounds().intersects(this->Player->playergetBounds()))
		{
			this->enemies.erase(this->enemies.begin() + i);
			this->statustype = (rand() % 100) + 1;
			std::cout << statustype << std::endl;
			this->nowtime = this->time;
			//std::cout << statustype << std::endl;
		}
	}
}

void game::updateEnemy_dead()
{
	this->enemy_deadsspawnTimer += 0.01f * (time + 20);
	if (this->enemy_deadsspawnTimer >= this->enemy_deadsspawnTimerMax)
	{
		this->enemy_deads.push_back(new Enemy_dead(rand() % this->window->getSize().x - 40.f, -100.f));
		this->enemy_deadsspawnTimer = 0.0f;
	}

	for (int i = 0; i < this->enemy_deads.size(); i++)
	{
		this->enemy_deads[i]->update();
		if (this->enemy_deads[i]->Enemy_deadBounds().top > this->window->getSize().y)
		{
			this->enemy_deads.erase(this->enemy_deads.begin() + i);
		}
		else if (this->enemy_deads[i]->Enemy_deadBounds().intersects(this->Player->playergetBounds()))
		{
			this->enemy_deads.erase(this->enemy_deads.begin() + i);
			if (V_heart_S.empty() == true)
			{
			}
			else 
			{
				this->LoseheartSound.play();
				this->V_heart_S.pop_back();
			}
		}
	}
}

void game::updateEat_potins()
{
	this->Eat_potinesspawnTimer += 0.02f * (time + 20);
	if (this->Eat_potinesspawnTimer >= this->Eat_potinesspawnTimerMax)
	{
		this->Eat_potines.push_back(new eat_potins(rand() % this->window->getSize().x - 40.f, -100.f));
		this->Eat_potinesspawnTimer = 0.0f;
	}

	for (int i = 0; i < this->Eat_potines.size(); i++)
	{
		this->Eat_potines[i]->update();
		if (this->Eat_potines[i]->eat_potinsBounds().top > this->window->getSize().y)
		{
			this->Eat_potines.erase(this->Eat_potines.begin() + i);
			combo = 0;
		}
		else if (this->Eat_potines[i]->eat_potinsBounds().intersects(this->Player->playergetBounds()))
		{
			this->HealSound.play();
			this->combo++;
			this->points += this->Eat_potines[i]->getpoints() * combo;
			this->Eat_potines.erase(this->Eat_potines.begin() + i);
		}
	}
}

void game::updatetime()
{
	gametime = timeclock.getElapsedTime();
	time = gametime.asSeconds();
}

void game::updatestatus()
{
	if (statustype >= 0 && statustype <= 5 && statustype != -1)
	{
		if (V_heart_S.size() == 1)
		{
			this->HealSound.play();
			this->V_heart_S.push_back(heart_S);
			this->V_heart_S[1].setPosition(80.0f, 37.0f);
			this->V_heart_S[1].scale(0.65f, 0.65f);
			this->statustype = -1;
		}
		else if(V_heart_S.size() == 2)
		{
			this->HealSound.play();
			this->V_heart_S.push_back(heart_S);
			this->V_heart_S[2].setPosition(120.0f, 37.0f);
			this->V_heart_S[2].scale(0.65f, 0.65f);
			this->statustype = -1;
		}
		else if (V_heart_S.size() == 3)
		{
			this->statustype = -1;
		}
	}
	if ((statustype >= 6 && statustype <= 15) || tempstatustype == 1)
	{
		if (soundplayed == 0)
		{
			this->Cant_moveSound.play();
			soundplayed = -1;
		}
		if (this->nowtime + 2 > this->time)
		{
			this->player_move_speed = 0.0f;
			this->tempstatustype = 1;
		}
		else if (this->nowtime + 2 == this->time)
		{
			this->player_move_speed = 1.5f;
			this->statustype = this->tempstatustype = -1;
			soundplayed = 0;
		}
	}
	if (statustype >= 16 && statustype <= 50)
	{
		this->points -= 10;
		this->statustype = -1;
	}
	if ((statustype >= 51 && statustype <= 89) || tempstatustype == 0)
	{
		if (soundplayed == 0)
		{
			this->Cant_moveSound.play();
			soundplayed = -1;
		}
		if (this->nowtime + 3 > this->time)
		{
			this->player_move_speed = 0.75f;
			this->tempstatustype = 0;
		}
		else if (this->nowtime + 3 == this->time)
		{
			this->player_move_speed = 1.5f;
			this->statustype = this->tempstatustype = -1;
			soundplayed = 0;
		}
	}
	if (statustype >= 90 && statustype <= 99)
	{
		this->TeleportSound.play();
		this->Player->setposition(rand() % 300 + 50, rand() % 500 + 50);
		this->statustype = -1;
	}
	if (statustype == 100)
	{
		if (V_heart_S.empty() == true)
		{
		}
		else
		{
			this->LoseheartSound.play();
			this->V_heart_S.pop_back();
			this->statustype = -1;
		}
	}
}
void game::run()
{
	this->backgroundSound.play();
	this->backgroundSound.getLoop();
	while (this->window->isOpen()) 
	{
		this->updatePollEvents();
		if (this->V_heart_S.empty() == false)
		{
			if (start_tpye == 0)
			{
				this->window->clear();
				this->window->draw(Beginningsprite);
				this->window->draw(Startsprite);
				this->window->draw(Endsprite);
				this->window->display();
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					mousePos = sf::Mouse::getPosition(*window);
					if (Startsprite.getGlobalBounds().top <= mousePos.y && Startsprite.getGlobalBounds().width >= mousePos.x)
					{
						this->start_tpye = 1;
					}
					else if (Endsprite.getGlobalBounds().top <= mousePos.y && Endsprite.getGlobalBounds().left <= mousePos.x)
					{
						exit(0);
					}
				}
			}
			if (start_tpye == 1)
			{
				this->update();
				this->render();
			}
		}
		else if (this->V_heart_S.empty() == true)
		{
			this->window->clear();
			this->window->draw(this->gameoverbackground_S);
			this->window->draw(this->gameovertext);
			this->window->display();
		}
	}
}
void game::update()
{
	this->backupdate();

	this->updatetime();

	this->updateInput();

	this->updatecollision();

	this->updateEnemies();

	this->updatestatus();

	this->updateEnemy_dead();

	this->updateEat_potins();

	this->updateGUI();
}
void game::render()
{
	this->window->clear();
	this->window->draw(this->sprite);
	this->window->draw(this->pointText);
	this->window->draw(this->hptext);
	this->window->draw(this->timetext);
	this->window->draw(this->combotext);
	this->Player->render(*this->window);
	for (int i = 0; i < V_heart_lost_S.size(); i++)
	{
		this->window->draw(this->V_heart_lost_S[i]);
	}
	for (int i = 0; i < V_heart_S.size(); i++)
	{
		this->window->draw(this->V_heart_S[i]);
	}
	for (auto *enemy : this->enemies)
	{
		enemy->render(this->window);
	}
	for (auto *enemy_dead : this->enemy_deads)
	{
		enemy_dead->render(this->window);
	}
	for (auto *Eat_potins : this->Eat_potines)
	{
		Eat_potins->render(this->window);
	}
	this->window->display();
}

void game::updatePollEvents()
{
	sf::Event e;
	while (this->window->pollEvent(e))
	{
		if (e.Event::type == sf::Event::Closed)
		{
			this->window->close();
		}
	}
}

void game::updateInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->Player->move(-player_move_speed, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->Player->move(player_move_speed, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->Player->move(0.0f, -player_move_speed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->Player->move(0.0f, player_move_speed);
	}
}

const int& game::getpoints() const
{
	return this->points;
}
