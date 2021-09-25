#include "Rotation.hpp"
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> create(unsigned height, unsigned width){
  return vector<vector<int>>(height, vector<int>(width, 0));
}
int main() {  
  float p1[] = {5,-2,7};
  float x1[] = {2,-2,7};

  float gba[] {45,25,52};
  Rotation r(gba); 
  r.getERMDataless();
  //r.print();
  r.rotate(p1);
  
}