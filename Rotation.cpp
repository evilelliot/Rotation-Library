#include "Rotation.hpp"
#include <math.h>
#include <vector>
#include <iostream>
using namespace std;


Rotation::Rotation(float y, float p, float r): gamma(rad(y)), beta(rad(p)), alpha(rad(r)){
  data = vector<vector<float>>(3, vector<float>(3, 0));
}
Rotation::Rotation(float gba[3]): gamma(rad(gba[0])), beta(rad(gba[1])), alpha(rad(gba[2])){
  data = vector<vector<float>>(3, vector<float>(3, 0));
}
// Euler Rotation Matrix
void Rotation::getERMDataless(){
  // Calculate first row
  data[0][0] = cos(gamma) * cos(beta);
  data[0][1] = sin(beta) * sin(alpha) - sin(gamma) * cos(alpha);
  data[0][2] = cos(gamma) * sin(beta) * cos(alpha) + sin(gamma) * sin(alpha);

  // Calculate second row
  data[1][0] = sin(gamma) * cos(beta);
  data[1][1] = sin(gamma) * sin(beta) * sin(alpha) + cos(gamma) * cos(alpha);
  data[1][2] = sin(gamma) * sin(beta) * cos(alpha) - cos(gamma) * sin(alpha);

  // Calculate third row
  data[2][0] = -sin(beta);
  data[2][1] = cos(beta) * sin(alpha);
  data[2][2] = cos(beta) * cos(alpha);
}
// Rotate
void Rotation::rotate(float p[3]){
  
  cout << (data[0][0]*p[0])+(data[0][1]*p[1])+(data[0][2]*p[2])<<endl;
  cout << (data[1][0]*p[0])+(data[1][1]*p[1])+(data[1][2]*p[2])<<endl;
  cout << (data[2][0]*p[0])+(data[2][1]*p[1])+(data[2][2]*p[2])<<endl;

  yaw   = (data[0][0]*gamma)+(data[0][1]*-beta)+(data[0][2]*alpha);
  pitch = (data[1][0]*gamma)+(data[1][1]*-beta)+(data[1][2]*alpha);
  roll  = (data[2][0]*gamma)+(data[2][1]*-beta)+(data[2][2]*alpha);
}
// Printing matrix
void Rotation::print(){
  for(int j = 0; j < 3; j++){
    for(int i = 0; i < 3; i++){
      cout << data[j][i] << " ";
    }
    cout << endl;
  }
}