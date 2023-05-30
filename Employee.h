#pragma once

#include"Worker.h"


class Employee :public Worker
{
public:
	Employee(int id, string name, int dId);
	void Worker::showInfo();
	string Worker::getDeptName();
};
