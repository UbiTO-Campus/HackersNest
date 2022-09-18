#include "TypedTextRenderComponent.h"

#include <assert.h>
#include <algorithm>

#include "GameEngine/GameEngineMain.h"

using namespace GameEngine;

TypedTextRenderComponent::TypedTextRenderComponent():
    m_typingCount(0),
    m_fullText(""),
    m_typingDelay(100),
    m_typingCountdownTimer(0.2f)
{
}

TypedTextRenderComponent::~TypedTextRenderComponent()
{
}

void TypedTextRenderComponent::Render(sf::RenderTarget* target)
{
    RenderComponent::Render(target);

    if (!target)
    {
        return;
    }

    m_typedText.setPosition(GetEntity()->GetPos());
    m_typedText.setRotation(GetEntity()->GetRot());
    target->draw(m_typedText);
}

void TypedTextRenderComponent::Update()
{
    float dt = GameEngine::GameEngineMain::GetInstance()->GetTimeDelta();
    m_typingCountdownTimer -= dt;
    if (m_typingCountdownTimer <= 0.f)
    {
        m_typingCount = std::min(m_typingCount + 1, (int)m_fullText.length());
        m_typedText.setString(m_fullText.substr(0, m_typingCount));
        m_typingCountdownTimer = m_typingDelay;
    }
}

void TypedTextRenderComponent::SetString(std::string displayString)
{
    m_fullText = displayString;
    m_typingCount = 0;
    m_typedText.setString("");
}

void TypedTextRenderComponent::SetFont(std::string fontFile)
{
    std::string filePath;
    filePath.append("Resources/fonts/");
    filePath.append(fontFile);
    if (!m_font.loadFromFile(filePath))
    {
        assert(false);  // Drop an assert if we are loading a font that doesn't exist;
    }

    m_typedText.setFont(m_font);
}

void TypedTextRenderComponent::SetColor(sf::Color color)
{
    m_typedText.setFillColor(color);
}

void TypedTextRenderComponent::SetCharacterSizePixels(int characterSize)
{
    // This sets the character size in pixels not points!
    m_typedText.setCharacterSize(characterSize);
}

void TypedTextRenderComponent::SetStyle(int styleBitField)
{
    m_typedText.setStyle(styleBitField);
}

void TypedTextRenderComponent::SetStyle(sf::Text::Style style, bool value)
{
    int styleBitField = m_typedText.getStyle();
    if (value)
    {
        styleBitField |= 1 << style;
    }
    else
    {
        styleBitField &= 0 << style;
    }
    m_typedText.setStyle(styleBitField);
}
