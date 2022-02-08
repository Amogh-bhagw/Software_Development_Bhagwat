#include "point2.h"
#include <cmath>
#include <iostream>
using namespace std;

float Point2::DistanceBetween(Point2 other_){
	float x_distance = (other_.x_ - this->x_)*(other_.x_ - this->x_);
	float y_distance = (other_.y_ - this->y_)*(other_.y_-this->y_);
	return sqrtf(x_distance + y_distance);
}

int Point2::Quadrant(){
	if(x_ == 0 && y_ == 0){
		return 0;
	}

	if(x_ > 0){
		if(y_ > 0){
			return 1;
			}
		else{
			return 4;
			}
		}
		
  else{
			if(y_ > 0){
				return 2;
			}
			else{
				return 3;
			}
		}

	return 0;
}

void Point2::Print(){
	cout << "Point X is: "<< x_ << " Point Y is: "<< y_ << endl;
}

Point2::Point2() {
	x_ = 0.0;
	y_ = 0.0;
}

Point2::Point2(float a, float b) {
	x_ = a;
	y_ = b;
}
