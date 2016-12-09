#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"
#include "Math.h"

class Player {
public:
	Vector2 m_Position;
	bool m_Shooting;
	float m_size = 75;
	bool m_userHit = false;
	bool m_enemyHit = false;
	int m_userHP;
	int m_enemyHP;
};

class Shoot {
public:
	Vector2 m_Position;
	int m_bulletSpeed;
};
class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Texture*		m_texture;
	aie::Texture*		m_shipTexture;
	aie::Texture*		m_shipTexture1;
	aie::Texture*		m_grass;
	aie::Texture*		m_grassball;
	aie::Font*			m_font;
	aie::Audio*			m_shooting;
	aie::Audio*			m_audio;
	aie::Audio*			m_pain;
	
	Player User;
	Player Enemy;

	Shoot Bullet;
	Shoot Bullet2;

	bool m_GameOver;

	int count = 0;

	int m_healthBarCompensator; // Since you are taking HP away you need something that is moving upwards to get
	//my enemy health bar moving right

	float m_cameraX, m_cameraY;
	float m_timer;
};

