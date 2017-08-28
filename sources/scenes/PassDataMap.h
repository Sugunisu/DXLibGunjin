#ifndef _PASS_DATA_MAP_H_
#define _PASS_DATA_MAP_H_

#include <map>
#include <string>

using namespace std;

class PassDataMap
{
	private:
	    map<string, int> dataMap;
    
	public:
    	void set(string key, int val);
    	int  get(string key);

};

#endif
