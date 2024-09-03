#include "GameObject.h"



GameObject::GameObject() {
}


GameObject::~GameObject() {
}

void GameObject::UpdateArea() {

	ObjectArea = {
		(int)(PosX - (Width / 2)),
		(int)(PosY - (Height / 2)),
		(int)(PosX + (Width / 2)),
		(int)(PosY + (Height / 2)) };


}

void GameObject::InitializeData(int x, int y, int w, int h) {
	PosX = x;
	PosY = y;
	Width = w;
	Height = h;

	//  > ������Ʈ ���� ������Ʈ
	UpdateArea();
}

void GameObject::SetCropSize(int w, int h)
{
	PosX = w;
	PosY = h;

}
