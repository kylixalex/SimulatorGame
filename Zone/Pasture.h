#ifndef PASTURE_H
#define PASTURE_H

#include "Zone.h"

class Pasture : public Zone {
	public:

    std::string getType() const override {return "pas";};
		~Pasture () override = default;
    void work(Resources& resources, int day) override;

};

#endif
