#include <string>
#include <sstream>
#include "player.h"
#include "Enemy.h"
#include "eat_potins.h"
#include "Enemy_dead.h"

class game
{
private:
	//開始背景
	sf::Sprite Beginningsprite;
	sf::Texture BeginningTexture;

	sf::Sprite Startsprite;
	sf::Texture StartTexture;

	sf::Sprite Endsprite;
	sf::Texture EndTexture;

	sf::Vector2i mousePos;
	int start_tpye;
	//開始背景

	//移動相關
	float movespeed; 
	float player_move_speed; 
	//移動相關

	//音效
	int soundplayed; //音效是否被撥放

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
	//音效
	//視窗
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	//視窗
	//時間
	sf::Clock timeclock;
	sf::Time gametime;
	int time;
	int nowtime;
	//時間
	//文字
	sf::Font font;
	sf::Text pointText;
	sf::Text hptext;
	sf::Text gameovertext;
	sf::Text timetext;
	sf::Text combotext;
	//文字
	//點數相關
	std::vector<eat_potins*> Eat_potines;
	eat_potins* Eat_potins;
	int points;
	unsigned combo;
	//點數相關
	//玩家相關
	player* Player;
	sf::Texture heart_T;
	sf::Sprite heart_S;
	sf::Texture heart_lost_T;
	sf::Sprite heart_lost_S;
	int H_conts;
	std::vector<sf::Sprite> V_heart_lost_S;
	std::vector<sf::Sprite> V_heart_S;
	//玩家相關
	//生成時間相關
	float EnemiesspawnTimer;
	float EnemiesspawnTimerMax;

	float enemy_deadsspawnTimer;
	float enemy_deadsspawnTimerMax;

	float Eat_potinesspawnTimer;
	float Eat_potinesspawnTimerMax;
	//生成時間相關
	//敵人相關
	std::vector<Enemy*> enemies;
	std::vector<Enemy_dead*> enemy_deads;

	Enemy* enemy;
	Enemy_dead* enemy_dead;
	//敵人相關
	//背景相關
	sf::Texture background;
	sf::Sprite sprite;
	sf::Texture gameoverbackground_T;
	sf::Sprite gameoverbackground_S;
	//背景相關
	//type
	int statustype;
	int tempstatustype;
	//type
	void initWindow(); //初始化視窗
	void initsystem(); //初始化系統
	void initGUI(); //初始化GUI
	void initEat_potins(); //初始化點數
	void initenemy_dead(); //初始化小心地滑
	void initPlayer(); //初始化玩家
	void initEnemy(); //初始化黑油
	void initplayheart(); //初始化愛心
	void initsoundbuffer(); //初始化音效
	void initsound(); //初始化音效
	void initgamestart(); //初始化開始背景
	void gameoverbackground(); //初始化結束背景
public:
	game(); //初始化建構
	virtual ~game(); //解構
	void run(); //遊戲執行核心
	void backupdate(); //背景更新
	void updateGUI(); //GUI更新

	void updatecollision(); //邊緣偵測更新

	void updateEnemies(); //黑油更新
	void updateEnemy_dead(); //小心地滑更新
	void updateEat_potins(); //墨西哥粽更新
	void updatetime(); //時間更新
	void updatestatus(); //角色狀態更新
	void update(); //更新函式
	void render(); //建置物建函式

	void updatePollEvents(); //視窗關閉偵測
	void updateInput(); //角色移動

	const int& getpoints() const; //取用點數
};

