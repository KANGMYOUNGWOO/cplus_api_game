#include "ManagerClassBase.h"



ManagerClassBase::ManagerClassBase() {
	GmInstance = null;
}


ManagerClassBase::~ManagerClassBase() {
}

void ManagerClassBase::SetGameInstance(GameInstance * gameInstance) {
	if (!GmInstance) GmInstance = gameInstance;
}

GameInstance * ManagerClassBase::GetGameInstance() {
	return GmInstance;
}
