#include "SoundTestIC.h"
#include "ComponentsManager.h"
#include "Entity.h"
#include "FactoriesFactory.h"
#include "Scene.h"

void SoundTestIC::handleInput(const SDL_Event& event) {
    if (soundComponent_ == nullptr)
        soundComponent_ = reinterpret_cast<SoundComponent*>(
            father_->getComponent("SoundComponent"));

    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_p)
        soundComponent_->playSound("test");
    else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_o)
        soundComponent_->stopSound("test");
}

// FACTORY INFRASTRUCTURE
SoundTestICFactory::SoundTestICFactory() = default;

Component* SoundTestICFactory::create(Entity* _father, Json::Value& _data,
                                      Scene* _scene) {
    SoundTestIC* soundTestIC = new SoundTestIC();
    _scene->getComponentsManager()->addIC(soundTestIC);

    soundTestIC->setFather(_father);
    soundTestIC->setScene(_scene);

    return soundTestIC;
};

DEFINE_FACTORY(SoundTestIC);
