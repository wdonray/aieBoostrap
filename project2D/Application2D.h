#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"
#include "Math.h"
class Player {
public:
	Vector2 m_Position;
	bool m_Shooting;
};
class Object {
public:
	Vector2 m_Position;
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
	aie::Texture*		m_Rock;
	aie::Texture*		m_Rock1;
	aie::Font*			m_font;
	aie::Audio*			m_shooting;
	aie::Audio*			m_audio;

	Player Donray;
	Player Teacher;

	Shoot Bullet;

	Object Rock;
	Object Rock1;

	float m_cameraX, m_cameraY;
	float m_timer;
};