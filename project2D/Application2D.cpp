#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <time.h>
#include <Windows.h>
#include <fstream>
#define True true
#define False false

Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {

	m_2dRenderer = new aie::Renderer2D();

	m_texture = new aie::Texture("./textures/numbered_grid.tga");
	m_shipTexture = new aie::Texture("./textures/ship.png");
	m_shipTexture1 = new aie::Texture("./textures/frown.png");
	m_grass = new aie::Texture("./textures/tallgrass.png");
	m_grassball = new aie::Texture("./textures/grassball.png");

	m_font = new aie::Font("./font/consolas.ttf", 32);

	m_shooting = new aie::Audio("./audio/powerup.wav");
	m_audio = new aie::Audio("./audio/music.wav");
	m_pain = new aie::Audio("./audio/pain.wav");

	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 1;

	User.m_Position = Vector2(50, 370);
	Enemy.m_Position = Vector2(1240, 370);

	Bullet.m_Position = Vector2(40, 370);
	Bullet2.m_Position = Vector2(1240, 370);

	User.m_Shooting = False;
	Enemy.m_Shooting = False;
	User.m_userHit = False;
	Enemy.m_enemyHit = False;
	User.m_userHP = 5;
	Enemy.m_enemyHP = 5;

	m_healthBarCompensator = 0;
	m_GameOver = False;

	return true;
}

void Application2D::shutdown() {

	delete m_shooting;
	delete m_audio;
	delete m_pain;
	delete m_font;
	delete m_texture;
	delete m_shipTexture;
	delete m_shipTexture1;
	delete m_grass;
	delete m_grassball;
	delete m_2dRenderer;
}

void Application2D::update(float deltaTime) {

	m_timer += deltaTime;

	for (int i = 0; i++;)
	{
		count++;
	}

	aie::Input* input = aie::Input::getInstance();

	// play old school music whole time 
	m_audio->play(); 

	// use arrow keys to move player
	if (input->isKeyDown(aie::INPUT_KEY_W) && User.m_Position.y < 680) //To not go out of range of windows size 
		User.m_Position = User.m_Position + Vector2(0, 10);

	if (input->isKeyDown(aie::INPUT_KEY_S) && User.m_Position.y > 40)
		User.m_Position = User.m_Position - Vector2(0, 10);

	if (input->isKeyDown(aie::INPUT_KEY_UP) && Enemy.m_Position.y < 680) //To not go out of range of windows size 
		Enemy.m_Position = Enemy.m_Position + Vector2(0, 10);

	if (input->isKeyDown(aie::INPUT_KEY_DOWN) && Enemy.m_Position.y > 40)
		Enemy.m_Position = Enemy.m_Position - Vector2(0, 10);

	// Player movement
	(input->isKeyDown(aie::INPUT_KEY_SPACE) && User.m_Shooting == False) ?
	(Bullet.m_Position.y = User.m_Position.y,
	Bullet.m_bulletSpeed = 0,
	m_shooting->play(), 
	User.m_Shooting = True) : 0;
	// Second player movement
	(input->isKeyDown(aie::INPUT_KEY_RIGHT_CONTROL) && Enemy.m_Shooting == False) ?
	(Bullet2.m_Position.y = Enemy.m_Position.y, 
	Bullet2.m_bulletSpeed = 0,
	m_shooting->play(),
	Enemy.m_Shooting = True) : 0;

	//Bullet Speed in a direction
	(User.m_Shooting == True) ? Bullet.m_bulletSpeed += 3 : 0;
	(Enemy.m_Shooting == True) ? Bullet2.m_bulletSpeed -= 3 : 0;

	// End of Bullet				// Reset the position to shoot from middle of face
	(Bullet.m_Position.x > 1280) ? (Bullet.m_Position.x = 40, User.m_Shooting = False) : 0;
	(Bullet2.m_Position.x < 0) ? (Bullet2.m_Position.x = 1240, Enemy.m_Shooting = False) : 0;

	// Update the position 
	(User.m_Shooting == True) ? Bullet.m_Position.x += Bullet.m_bulletSpeed: 0;
	(Enemy.m_Shooting == True)? Bullet2.m_Position.x += Bullet2.m_bulletSpeed: 0;


	// Collision check for User bullet on enemy 
	if (Enemy.m_Position.x - Enemy.m_size / 2 < Bullet.m_Position.x && Enemy.m_Position.x + Enemy.m_size / 2 > Bullet.m_Position.x
		&& Enemy.m_Position.y - Enemy.m_size / 2 < Bullet.m_Position.y && Enemy.m_Position.y + Enemy.m_size / 2 > Bullet.m_Position.y)
	{
		m_pain->stop(); // Stops sound each time to so sound can play every time
		m_pain->play();
		Enemy.m_enemyHit = True; // Set this bool to true to be used later
		Enemy.m_enemyHP -= 1; // Reduce hp by one each time 
		m_healthBarCompensator++; // To compensate for HP bar moving right instead of left 
	}
	// Collision check for enemy bullet on user
	if (User.m_Position.x - User.m_size / 2 < Bullet2.m_Position.x && User.m_Position.x + User.m_size / 2 > Bullet2.m_Position.x
		&&User.m_Position.y - User.m_size / 2 < Bullet2.m_Position.y && User.m_Position.y + User.m_size / 2 > Bullet2.m_Position.y)
	{
		m_pain->stop();
		m_pain->play();
		User.m_userHit = True;
		User.m_userHP -= 1;
	}
	// Game Reset in any state 
	(input->isKeyDown(aie::INPUT_KEY_R) && m_GameOver == False) ? (shutdown(), startup()) : 0;
	
	// If HP gets to 0 close game 
	(User.m_userHP == 0 || Enemy.m_enemyHP == 0) ? quit() : 0; 

	// Exit the application
	(input->isKeyDown(aie::INPUT_KEY_ESCAPE)) ? quit() : 0;
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// begin drawing sprites
	m_2dRenderer->begin();

	m_2dRenderer->drawSprite(m_grass, 640, 360, 0, 0, 0, 1);
	//m_2dRenderer->drawSprite(m_grassball, 640, 360, 0, 0, m_timer, 0);

	// demonstrate spinning playable character
	m_2dRenderer->setUVRect(0, 0, 1, 1);
	m_2dRenderer->drawSprite(m_shipTexture, User.m_Position.x, User.m_Position.y, User.m_size, User.m_size, m_timer);

	// draw a moving frowny face
	m_2dRenderer->setRenderColour(1, 0, 1, 1);
	m_2dRenderer->drawSprite(m_shipTexture1, Enemy.m_Position.x, Enemy.m_Position.y, Enemy.m_size, Enemy.m_size, m_timer);

	// output some text, uses the last used colour
	char fps[32];
	m_2dRenderer->setRenderColour(1, 1, 0, 1);
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);

	m_2dRenderer->drawText(m_font, "Press Space to Shoot! / Press ESC to Exit! / Press R to Restart!", 0, 720 - 64);
	m_2dRenderer->drawText(m_font, "Arrow Keys to Move Teacher and W and S to Move Donray!", 0, 690 - 64);

	m_2dRenderer->drawText(m_font, "Your HP", 0, 55);
	m_2dRenderer->drawText(m_font, "His HP", 1170, 55);

	// Draws intergers that get lowered on each hit
	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	char test[16];
	sprintf_s(test, 16, "%i", User.m_userHP);
	m_2dRenderer->drawText(m_font, test, 0, 0);

	char test2[16];
	sprintf_s(test2, 16, "%i", Enemy.m_enemyHP);
	m_2dRenderer->drawText(m_font, test2, 1260, 0);

	// Game counter 
	char counter[15];
	sprintf_s(counter, 15, "%i", count);
	m_2dRenderer->drawText(m_font, counter,300,0);

	// Draw HP bars that lower on each hit 
	m_2dRenderer->setRenderColour(0, 1, 0, 1);
	m_2dRenderer->drawBox(0 + (User.m_userHP * 50) / 2, 10, User.m_userHP * 50, 20, 0, 0);
	m_2dRenderer->setRenderColour(1, 0, 0, 1);
	m_2dRenderer->drawBox(1160 + (m_healthBarCompensator * 50) / 2, 10, Enemy.m_enemyHP * 50, 20, 0, 0);

	// Draw Bullet to screen following the X and Y of the faces
	if (User.m_Shooting == True)
	{
		m_2dRenderer->setRenderColour(0, 1, 0, 1);
		m_2dRenderer->drawBox(Bullet.m_Position.x, Bullet.m_Position.y, 20, 5, 0, 0);
	}
	if (Enemy.m_Shooting == True)
	{
		m_2dRenderer->setRenderColour(0, 0, 1, 1);
		m_2dRenderer->drawBox(Bullet2.m_Position.x, Bullet2.m_Position.y, 20, 5, 0, 0);
	}

	// done drawing sprites
	m_2dRenderer->end();
}