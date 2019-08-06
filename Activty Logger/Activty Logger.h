#pragma once
#ifndef HEADER_H
#define HEADER_H
#include <string>
#include <vector>
#include "activity.h"

extern std::vector<activity> list;
extern std::vector<std::string> names;
extern std::vector<std::string> categories;

std::string names_string(std::vector<std::string> name);
std::string categories_string(std::vector<std::string> cat);
std::string duration_string(int length);

#endif