#pragma once
#include"Particle.h"
namespace game1{
class Swarn
{ public:
	const static int NPARTICLES = 3000;

private :
	Particle *  m_pParticles;
	int lastTime;
public:
	Swarn();
	~Swarn();
	void update(int elapsed);
	const Particle * const getParticles() { return m_pParticles; };
};
}

