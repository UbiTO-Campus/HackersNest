#include "TextboxEntity.h"


using namespace Game;

TextboxEntity::TextboxEntity()
{
	//Render 
	m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();	
	m_renderComponent->SetTexture(GameEngine::eTexture::Textbox);
	m_renderComponent->SetZLevel(2);

}

 
TextboxEntity::~TextboxEntity()
{

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
