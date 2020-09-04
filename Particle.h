#pragma once
namespace game1 {
	struct Particle
	{
	
		double m_x;
		double m_y;
		double m_speed;
		double m_direction;
		void init();

	public:
		Particle();
		virtual ~Particle();
		void update(int interval);
	};
}

