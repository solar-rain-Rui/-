#pragma once
#include"Worker.h"

class Manager :public Worker
{
public:
	Manager(int id, string name, int dId);
	void Worker::showInfo();
	string Worker::getDeptName();
};
