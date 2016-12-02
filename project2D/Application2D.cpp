#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"

Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {

	m_2dRenderer = new aie::Renderer2D();

	m_texture = new aie::Texture("./textures/numbered_grid.tga");
	m_shipTexture = new aie::Texture("./textures/ship.png");
	m_shipTexture1 = new aie::Texture("./textures/frown.png");

	m_Rock = new aie::Texture("./textures/rock_large.png");
	m_Rock1 = new aie::Texture("./textures/rock_small.png");

	m_font = new aie::Font("./font/consolas.ttf", 32);

	m_shooting = new aie::Audio("./audio/powerup.wav");

	m_audio = new aie::Audio("./audio/music.wav");

	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 1;

	Donray.m_Position = Vector2(50, 370);
	Teacher.m_Position = Vector2(80, 370);

	Rock.m_Position = Vector2(600, 370);
	Rock1.m_Position = Vector2(500, 470);

	Bullet.m_Position = Vector2(0, 370);
	Donray.m_Shooting = false;
	return true;
}

void Application2D::shutdown() {

	delete m_shooting;
	delete m_audio;
	delete m_font;
	delete m_texture;
	delete m_shipTexture;
	delete m_shipTexture1;
	delete m_Rock;
	delete m_Rock1;
	delete m_2dRenderer;
}

void Application2D::update(float deltaTime) {

	m_timer += deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();

	// play old school music whole time 
	m_audio->play();

	// use arrow keys to move player
	if (input->isKeyDown(aie::INPUT_KEY_UP) && Donray.m_Position.y < 680) //To not go out of range of windows size 
		Donray.m_Position = Donray.m_Position + Vector2(0, 10);

	if (input->isKeyDown(aie::INPUT_KEY_DOWN) && Donray.m_Position.y > 40)
		Donray.m_Position = Donray.m_Position - Vector2(0, 10);

	//if (input->isKeyDown(aie::INPUT_KEY_LEFT))
		//m_cameraX -= 500.0f * deltaTime;

	//if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
		//m_cameraX += 500.0f * deltaTime;

	// example of audio
	if (input->isKeyDown(aie::INPUT_KEY_SPACE) && Donray.m_Shooting == false)
	{
		Bullet.m_Position.y = Donray.m_Position.y;
		Bullet.m_bulletSpeed = 0;
		m_shooting->play();
		Donray.m_Shooting = true;
	}  
	if (Donray.m_Shooting == true)
	{
		Bullet.m_bulletSpeed += 3;
	}
	if (Bullet.m_Position.x > 1280)
	{
		Donray.m_Shooting = false;
		Bullet.m_Position.x = 0;
	}

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// begin drawing sprites
	m_2dRenderer->begin();

	// demonstrate animation
	//m_2dRenderer->setUVRect(int(m_timer) % 8 / 8.0f, 0, 1.f / 8, 1.f / 8);
	//m_2dRenderer->drawSprite(m_texture, 200, 200, 100, 100);

	// demonstrate spinning playable character
	m_2dRenderer->setUVRect(0, 0, 1, 1);
	m_2dRenderer->drawSprite(m_shipTexture, Donray.m_Position.x, Donray.m_Position.y, 75, 75, m_timer);

	// draw a rotating rock in the center of scren
	m_2dRenderer->drawSprite(m_Rock, 600, sin(m_timer) * 500 + 600, 100, 100, m_timer, 1);
	m_2dRenderer->drawSprite(m_Rock1, 500, sin(m_timer) * -300 + 600, 50, 50, m_timer, 1);

	// draw a thin line
	//m_2dRenderer->drawLine(0, 637, 800, 635, 2, 1);

	// draw a moving frowny face
	m_2dRenderer->setRenderColour(1, 0, 1, 1);
	m_2dRenderer->drawSprite(m_shipTexture1, 1240, sin(m_timer) * 900 + 600, 75, 75, m_timer);

	// draw a rotating red box
	//m_2dRenderer->setRenderColour(1, 0, 0, 1);
	//m_2dRenderer->drawBox(600, 500, 60, 20, m_timer);

	// output some text, uses the last used colour
	char fps[32];
	m_2dRenderer->setRenderColour(1, 1, 0, 1);
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
	m_2dRenderer->drawText(m_font, "Press Space to Shoot!", 0, 720 - 64);
	m_2dRenderer->drawText(m_font, "Arrow Keys to Move!", 0, 690 - 64);
	m_2dRenderer->drawText(m_font, "Press ESC to Exit!", 0, 660 - 64);

	if (Donray.m_Shooting == true)
	{
		m_2dRenderer->setRenderColour(0, 1, 0, 1);
		Bullet.m_Position.x += Bullet.m_bulletSpeed;
		m_2dRenderer->drawBox(Bullet.m_Position.x, Bullet.m_Position.y, 20, 5, 0, 0);
	}

	// done drawing sprites
	m_2dRenderer->end();
}