#pragma once
#include "ManagerClassBase.h"

class SceneManager : public ManagerClassBase
{
public:
	SceneManager();
	virtual ~SceneManager();

private :
	//  > 현재 플레이중인 씬을 참조할 변수
	class Scene * CurrentScene;

	// 다음 씬의 이름을 저장할 변수
	LPCTSTR NextSceneName;

public :
	//  > 씬을 로드합니다.
	void SetNextScene(LPCTSTR sceneName);

	void Initialize();
	void Tick();
	void Render(HDC hdc);
	void Release();

private:
	void UpdateScene();

	




};

