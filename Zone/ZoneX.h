#ifndef ZONEX_H
#define ZONEX_H

#include "Zone.h"

class ZoneX : public Zone{
	public:
		std::string getType() const override {return "znZ";};
		~ZoneX() override = default;
    void work(Resources& resources, int day) override;
};

#endif
