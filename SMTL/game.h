#include <string>
#include <sstream>
#include "player.h"
#include "Enemy.h"
#include "eat_potins.h"
#include "Enemy_dead.h"

class game
{
private:
	//�}�l�I��
	sf::Sprite Beginningsprite;
	sf::Texture BeginningTexture;

	sf::Sprite Startsprite;
	sf::Texture StartTexture;

	sf::Sprite Endsprite;
	sf::Texture EndTexture;

	sf::Vector2i mousePos;
	int start_tpye;
	//�}�l�I��

	//���ʬ���
	float movespeed; 
	float player_move_speed; 
	//���ʬ���

	//����
	int soundplayed; //���ĬO�_�Q����

	sf::Music backgroundSound;

	sf::SoundBuffer die_lost;
	sf::SoundBuffer cant_move;
	sf::SoundBuffer heal;
	sf::SoundBuffer loseheart;
	sf::SoundBuffer teleport;

	sf::Sound Die_lostSound;
	sf::Sound Cant_moveSound;
	sf::Sound HealSound;
	sf::Sound LoseheartSound;
	sf::Sound TeleportSound;
	//����
	//����
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	//����
	//�ɶ�
	sf::Clock timeclock;
	sf::Time gametime;
	int time;
	int nowtime;
	//�ɶ�
	//��r
	sf::Font font;
	sf::Text pointText;
	sf::Text hptext;
	sf::Text gameovertext;
	sf::Text timetext;
	sf::Text combotext;
	//��r
	//�I�Ƭ���
	std::vector<eat_potins*> Eat_potines;
	eat_potins* Eat_potins;
	int points;
	unsigned combo;
	//�I�Ƭ���
	//���a����
	player* Player;
	sf::Texture heart_T;
	sf::Sprite heart_S;
	sf::Texture heart_lost_T;
	sf::Sprite heart_lost_S;
	int H_conts;
	std::vector<sf::Sprite> V_heart_lost_S;
	std::vector<sf::Sprite> V_heart_S;
	//���a����
	//�ͦ��ɶ�����
	float EnemiesspawnTimer;
	float EnemiesspawnTimerMax;

	float enemy_deadsspawnTimer;
	float enemy_deadsspawnTimerMax;

	float Eat_potinesspawnTimer;
	float Eat_potinesspawnTimerMax;
	//�ͦ��ɶ�����
	//�ĤH����
	std::vector<Enemy*> enemies;
	std::vector<Enemy_dead*> enemy_deads;

	Enemy* enemy;
	Enemy_dead* enemy_dead;
	//�ĤH����
	//�I������
	sf::Texture background;
	sf::Sprite sprite;
	sf::Texture gameoverbackground_T;
	sf::Sprite gameoverbackground_S;
	//�I������
	//type
	int statustype;
	int tempstatustype;
	//type
	void initWindow(); //��l�Ƶ���
	void initsystem(); //��l�ƨt��
	void initGUI(); //��l��GUI
	void initEat_potins(); //��l���I��
	void initenemy_dead(); //��l�Ƥp�ߦa��
	void initPlayer(); //��l�ƪ��a
	void initEnemy(); //��l�ƶªo
	void initplayheart(); //��l�ƷR��
	void initsoundbuffer(); //��l�ƭ���
	void initsound(); //��l�ƭ���
	void initgamestart(); //��l�ƶ}�l�I��
	void gameoverbackground(); //��l�Ƶ����I��
public:
	game(); //��l�ƫغc
	virtual ~game(); //�Ѻc
	void run(); //�C������֤�
	void backupdate(); //�I����s
	void updateGUI(); //GUI��s

	void updatecollision(); //��t������s

	void updateEnemies(); //�ªo��s
	void updateEnemy_dead(); //�p�ߦa�Ƨ�s
	void updateEat_potins(); //��������s
	void updatetime(); //�ɶ���s
	void updatestatus(); //���⪬�A��s
	void update(); //��s�禡
	void render(); //�ظm���ب禡

	void updatePollEvents(); //������������
	void updateInput(); //���Ⲿ��

	const int& getpoints() const; //�����I��
};

