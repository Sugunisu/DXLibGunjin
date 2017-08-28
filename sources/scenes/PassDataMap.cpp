#include "PassDataMap.h"

void PassDataMap::set(string key,int val){
	dataMap[key] = val;
}

int PassDataMap::get(string key){
	return dataMap.find(key)->second;
}
