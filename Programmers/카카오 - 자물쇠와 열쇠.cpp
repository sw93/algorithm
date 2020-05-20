#include <string>
#include <vector>
using namespace std;

void rotateKey(vector<vector<int>> &key) {
    int keySize = key.size();
    vector<vector<int>> temp = key;
    for (int y=0; y<keySize; y++) {
        for (int x=0; x<keySize; x++) {
            key[y][x] = temp[keySize-x-1][y];
        }
    }
}

bool isUnlock(int sy, int sx, vector<vector<int>> key, vector<vector<int>> map) {
    int keySize = key.size();
    int mapSize = map.size();
    
    for (int y=sy; y<sy+keySize; y++) {
        for (int x=sx; x<sx+keySize; x++) {
            map[y][x] += key[y-sy][x-sx];
        }
    }

    for (int y=keySize-1; y<mapSize-keySize+1; y++) {
        for (int x=keySize-1; x<mapSize-keySize+1; x++) {
            if (map[y][x] == 1) continue;
            return false;
        }
    }
    
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int keySize = key.size();  
    int lockSize = lock.size(); 
    int mapSize = lockSize + (keySize-1)*2; 

    // 작업할 map생성
    vector<vector<int>> map(mapSize, vector<int>(mapSize, 0));
    for (int y=0; y<lockSize; y++) {
        for (int x=0; x<lockSize; x++) {
            map[y+keySize-1][x+keySize-1] = lock[y][x];
        }
    }
    
    // 90도씩 4번 회전
    for (int i=0; i<4; i++) {
        // key를 전체 map에 대해 탐색
        for (int y=0; y<mapSize-keySize+1; y++) {
            for (int x=0; x<mapSize-keySize+1; x++) {
                if (isUnlock(y, x, key, map)) {
                    return true;
                }
            }
        }
        rotateKey(key);
    }
    
    return false;
}