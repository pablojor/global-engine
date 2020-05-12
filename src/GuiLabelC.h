#pragma once

#include "Component.h"
#include "Factory.h"
#include <glm/glm.hpp>
#include <string>

namespace CEGUI {
    class Window;
}

// FACTORY INFRASTRUCTURE DECLARATION
DECLARE_FACTORY(GuiLabelComponent);

class GuiLabelComponent : public Component {
  private:
    CEGUI::Window* myself;

    std::string text;
    glm::vec2 position;
    glm::vec2 size;
    std::string name;

  public:
    virtual void create();

    virtual void destroy();

    // Setters
    virtual void setText(std::string t);
    virtual void setPosition(glm::vec2 p);
    virtual void setSize(glm::vec2 s);
    virtual void setName(std::string n);
    void changeText(std::string newText);
    void setAlpha(float alpha);
    float getAlpha();
};
