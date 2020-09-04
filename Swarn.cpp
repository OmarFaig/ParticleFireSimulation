#include "Swarn.h"
namespace game1 {


	Swarn::Swarn():lastTime(0)
	{
		m_pParticles = new Particle[NPARTICLES];
	}


	Swarn::~Swarn()
	{
		delete [] m_pParticles;
	}
	void Swarn::update(int elapsed) {
		int interval = elapsed - lastTime;
		for (int i = 0; i < Swarn::NPARTICLES; i++) {
			m_pParticles[i].update(interval);
		}
		lastTime = elapsed;
	}
}
