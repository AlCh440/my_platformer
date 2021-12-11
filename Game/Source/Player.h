#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Module.h"
#include "App.h"
#include "Animation.h"

#include "Point.h"
#include "SDL/include/SDL.h"



class Player : public Module
{
public:
	Player();

	virtual ~Player();

	bool Start();
	bool Awake(pugi::xml_node&);
	bool PreUpdate();
	bool Update(float dt);
	bool PostUpdate();

	void gravity();

	void OnCollision(Collider* c1, Collider* c2) override;
	
	// Load / Save
	bool LoadState(pugi::xml_node&);
	bool SaveState(pugi::xml_node&) const;

	bool CleanUp();

	void StartLvl();

	SDL_Rect player;

private:

	SDL_Texture *idle_player;
	Animation right_idle;
	Animation left_idle;
	Animation right_running;
	Animation left_running;

	Animation* current_animation;
	int direction;
	bool is_moving;

	
	iPoint momentum;
	iPoint max_momentum;

	int gravity_;


	Collider* hit_player;
	Collider* near_up;
	Collider* near_down;
	Collider* near_right;
	Collider* near_left;

	bool can_move_right;
	bool can_move_left;
	bool can_move_down;
	bool can_jump;

	int playerframescounter;
};

#endif