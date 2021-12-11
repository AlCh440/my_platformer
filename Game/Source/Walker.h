#pragma once

#include "Enemy.h"
#include "App.h"
#include "Animation.h"

#include "Point.h"
#include "SDL/include/SDL.h"


class Walker : public Enemy
{
public:
	Walker(int x, int y);

	virtual ~Walker();
	bool Start();

	bool PreUpdate();
	bool Update(float dt);
	bool PostUpdate();

	void gravity();

	bool CleanUp();

	void SolveColl();

	SDL_Rect player;

	Collider* hit_bat;
private:

	SDL_Texture* walker_sprite;
	Animation formation;
	Animation walking_rigth;
	Animation walking_left;
	Animation death;


	Animation* current_animation;

	int walker_state;
	int direction;
	bool is_moving;

	iPoint position;
	iPoint momentum;
	iPoint max_momentum;

	int gravity_;





};
#pragma once
