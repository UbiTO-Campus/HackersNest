#include "GameBoard.h"

#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Components/TextRenderComponent.h"
#include "Game/GameEntities/TextboxEntity.h"


using namespace Game;

GameBoard::GameBoard()
{

	m_text = new GameEngine::Entity();
	m_textbox = new TextboxEntity();
	m_text->SetParent(m_textbox);
	GameEngine::TextRenderComponent* textRenderComponent = m_text->AddComponent<GameEngine::TextRenderComponent>();
    textRenderComponent->SetFont("arial.ttf");

	CreateBackGround();
}


GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{	
	UpdateBackGround();
}

void GameBoard::CreateBackGround()
{
	GameEngine::Entity* m_backGround = new GameEngine::Entity();
	GameEngine::SpriteRenderComponent* render = m_backGround->AddComponent<GameEngine::SpriteRenderComponent>();
	render->SetTexture(GameEngine::eTexture::BG);
	render->SetZLevel(0);
	m_backGround->SetPos(sf::Vector2f(250.f, 250.f));
	m_backGround->SetSize(sf::Vector2f(500.f, 500.f));
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_backGround);
}


void GameBoard::UpdateBackGround()
{
	if (!m_backGround || true) {
		return;
	}
		
	m_backGround->SetPos(sf::Vector2f(250.f, 250.f));
	m_backGround->SetSize(sf::Vector2f(500.f, 500.f));
}