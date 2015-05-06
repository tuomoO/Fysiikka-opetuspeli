#include "GameObject.h"

using namespace std;

GameObject::GameObject()
	: mIsDeleted(false)
{

}


GameObject::~GameObject()
{
	for (CompIt i = mComponents.begin(); i != mComponents.end(); i++)
	{
		delete (*i).second;
	}
	mComponents.clear();
}


void GameObject::add(Component* component)
{
	mComponents.insert(make_pair(&typeid(*component), component));
}

