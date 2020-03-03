#include "Scene.h"
#include "Game.h"
#include "Entity.h"
#include "FactoriesFactory.h"
#include "Loader.h"
#include "TransformComponent.h"
#include "ComponentsManager.h"

#include <iostream>

Scene::Scene() {
	componentManager = new ComponentsManager();
}

Scene::~Scene() {}

void Scene::load(std::string name) {  
    Loader loader;
    loader.readEntities(name, entities, componentManager);
    
}

void Scene::update()
{
	while (!exit) {
		componentManager->update();
		componentManager->handleInput();
		componentManager->render();
		componentManager->updateSound();
	}
}

Entity* Scene::getEntitybyId(std::string id)
{
    return new Entity();
}