#pragma once
#include "ManagerClassBase.h"

class SceneManager : public ManagerClassBase
{
public:
	SceneManager();
	virtual ~SceneManager();

private :
	//  > ���� �÷������� ���� ������ ����
	class Scene * CurrentScene;

	// ���� ���� �̸��� ������ ����
	LPCTSTR NextSceneName;

public :
	//  > ���� �ε��մϴ�.
	void SetNextScene(LPCTSTR sceneName);

	void Initialize();
	void Tick();
	void Render(HDC hdc);
	void Release();

private:
	void UpdateScene();

	




};

