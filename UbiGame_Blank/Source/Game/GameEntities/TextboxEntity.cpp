#include "TextboxEntity.h"


using namespace Game;

TextboxEntity::TextboxEntity()
{
	//Render 
	m_spriteRC = AddComponent<GameEngine::SpriteRenderComponent>();
	m_spriteRC->SetTexture(GameEngine::eTexture::Textbox);
	m_spriteRC->SetZLevel(2);

	m_textRC = AddComponent<GameEngine::TypedTextRenderComponent>();
	m_textRC->SetFont("arial.ttf");
	m_textRC->SetZLevel(3);
}


TextboxEntity::~TextboxEntity()
{
	
}


void TextboxEntity::SetText(std::string text) {
	m_textRC->SetString(text);
}


void TextboxEntity::OnAddToWorld()
{
	Entity::OnAddToWorld();
	SetEntityTag("Textbox");
}


void TextboxEntity::OnRemoveFromWorld()
{
	Entity::OnRemoveFromWorld();
}
