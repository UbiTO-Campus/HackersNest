#pragma once
#include "GameEngine/EntitySystem/Components/RenderComponent.h"

namespace GameEngine
{
    class TypedTextRenderComponent : public RenderComponent
    {
    public:
        TypedTextRenderComponent();
        ~TypedTextRenderComponent();

        virtual void Render(sf::RenderTarget* target) override;
        virtual void Update() override;

        void SetString(std::string displayString);
        void SetFont(std::string fontFile);
        void SetColor(sf::Color color);
        void SetCharacterSizePixels(int characterSize);

        void SetStyle(int styleBitField);
        void SetStyle(sf::Text::Style style, bool value);

    private:
        std::string m_fullText;
        int m_typingCount;
        int m_typingDelay;
        float m_typingCountdownTimer;
        sf::Text m_typedText;
        sf::Font m_font;
    };
}  // namespace GameEngine
