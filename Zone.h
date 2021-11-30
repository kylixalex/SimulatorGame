#ifndef ZONE_H
#define ZONE_H

#include <vector>
#include <string>
#include "Building.h"
#include "Worker.h"

class Zone {
	public:
		virtual std::string getType() const = 0;
		virtual ~Zone();
		std::string	getWorkers() const;
		int	getNumberOfWorkers() const;
		Building	*getBuilding() const;
		void	setBuilding(std::string &buildingType);
	private:
		std::vector<Worker*>	workers;
		Building	*building;
};

class Desert : public Zone {
	public:
		std::string getType() const override {return "dsr";};
};

class Pasture : public Zone {
	public:
		std::string getType() const override {return "pas";};
};

class Forest : public Zone {
	public:
		std::string getType() const override {return "flr";};
};

class Mountain : public Zone {
	public:
		std::string getType() const override {return "mnt";};
};

class Swamp : public Zone {
	public:
		std::string getType() const override {return "pnt";};
};

class ZoneX : public Zone{
	public:
		std::string getType() const override {return "znZ";};
};

Zone	*createZone(const std::string &zoneType);

#endif
