#include "GameBoard.h"

#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Components/TextRenderComponent.h"


using namespace Game;

GameBoard::GameBoard()
{

	m_text = new GameEngine::Entity();
	m_text->SetParent(m_backGround);
	GameEngine::TextRenderComponent* textRenderComponent = m_text->AddComponent<GameEngine::TextRenderComponent>();
    textRenderComponent->SetFont("arial.ttf");

	CreateBackGround();
}


GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{	
	
}

void GameBoard::CreateBackGround()
{
	GameEngine::Entity* bgEntity = new GameEngine::Entity();
	GameEngine::SpriteRenderComponent* render = bgEntity->AddComponent<GameEngine::SpriteRenderComponent>();
	render->SetTexture(GameEngine::eTexture::BG);
	render->SetZLevel(0);
	bgEntity->SetPos(sf::Vector2f(250.f, 250.f));
	bgEntity->SetSize(sf::Vector2f(500.f, 500.f));
	GameEngine::GameEngineMain::GetInstance()->AddEntity(bgEntity);

	m_backGround = bgEntity;
}


void GameBoard::UpdateBackGround()
{
	if (!m_backGround || !m_player)
		return;
		
	m_backGround->SetPos(sf::Vector2f(250.f, 250.f));
	m_backGround->SetSize(sf::Vector2f(500.f, 500.f));
}