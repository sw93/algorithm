#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache;
    if (cacheSize == 0) {
        return cities.size() * 5;
    }
    
    for (int i=0; i<cities.size(); i++) {
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
        vector<string>::iterator it = find(cache.begin(), cache.end(), cities[i]);
        if (it == cache.end()) {
            if (cache.size() >= cacheSize) cache.erase(cache.begin());
            cache.push_back(cities[i]);
            answer+=5;
        } else {
            cache.erase(it);
            cache.push_back(cities[i]);
            answer++;
        }
    }
    return answer;
}