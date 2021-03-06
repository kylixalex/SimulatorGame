#include <random>
#include "Forest.h"

Forest::Forest()
{
	std::mt19937	rng(std::random_device{}());
	std::uniform_int_distribution<int> gen(20, 40);
	trees = gen(rng);
}

void Forest::growTrees(const int day)
{
  if (trees < 100 && getBuilding() == nullptr)
  {
    if((day + 1) % 2 == 0)
    {
      trees++;
    }
  }
}

void Forest::handleBuildingExistence()
{
  if (getBuilding())
  {
    trees--;
  }
}

void Forest::work(Resources& resources, int day)
{
  wood += getNumberOfWorkers('L');
  growTrees(day);
  handleBuildingExistence();

  if(getBuilding() != nullptr)
  {
    std::string building_type = getBuilding()->getType();
    if(building_type == "mnF")
    {
      getBuilding()->work(resources, day, getNumberOfWorkers('M'));
    }
    else if (building_type == "mnC")
    {
      getBuilding()->work(resources, day, getNumberOfWorkers('M'));
    }
    else if (building_type == "bat")
    {
      getBuilding()->work(resources, day, 0);
    }
    else if (building_type == "edX")
    {
      getBuilding()->work(resources, day, 0);
    }
    else if (building_type == "fun")
    {
      getBuilding()->work(resources, day, getNumberOfWorkers('O'));
    }
    else if (building_type == "cen")
    {
      getBuilding()->work(resources, day, getNumberOfWorkers('O'));
    }else if (building_type == "ser")
    {
      getBuilding()->work(resources, day, getNumberOfWorkers('O'));
    }
  }
}