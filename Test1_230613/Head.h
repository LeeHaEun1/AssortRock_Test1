#pragma once
#include "Part.h"

class Body;
// Ό³Έν :
class Head : public Part
{
public:
	// constrcuter destructer
	Head();
	~Head();

	// delete Function
	Head(const Head& _Other) = delete;
	Head(Head&& _Other) noexcept = delete;
	Head& operator=(const Head& _Other) = delete;
	Head& operator=(Head&& _Other) noexcept = delete;

	void IsBodyCheck(Body* _Body);
	//bool isBody = false;

	//void AddBody();

protected:
	void Tick(float _Time);

private:
	char lastSelect = '0';
};

