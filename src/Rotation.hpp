#ifndef Rotation_hpp
#define Rotation_hpp

#include <vector>
using namespace std; 

class Rotation{
  vector<vector<float>> data;
  float gamma, beta, alpha;
  
  public:
  float yaw, pitch, roll;
  Rotation(float yaw, float pitch, float roll);
  Rotation(float gba[3]);
  // Calculate rotation matrix R.M
  // Calculate inverse rotation matrix I.R.M
  // Printing rotation matrix (vector)
  void print();
  void getERMDataless();
  void rotate(float point[3]);
  // radians
  float rad(float x) const {return x * (3.141592653589793 / 180);}
  // Testing methods
  void populate();

};

#endif