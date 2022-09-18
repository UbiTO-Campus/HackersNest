#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "Game/GameComponents/TypedTextRenderComponent.h"

#include <string.h>

namespace Game
{			

	class TextboxEntity : public GameEngine::Entity
	{
	public:
		TextboxEntity();
		~TextboxEntity();

		void SetText(std::string text);

		virtual void OnAddToWorld() override;
		virtual void OnRemoveFromWorld() override;

	protected:
		GameEngine::SpriteRenderComponent* m_spriteRC;
		GameEngine::TypedTextRenderComponent* m_textRC;
	};
}

