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
	float x_Point =  x_;
	float y_Point = y_;
	if(x_Point == 0 && y_Point == 0){
		return 0;
	}
	if (x_Point < 0){
		if(y_Point > 0){
			return 2;
		}
		else{
			return 3;
		}
	}
	else{
		if(y_Point > 0){
			return 1;
		}
		else{
			return 4;
		}
	}
	return 0;
}

void Point2::Print(){
	cout << "Point x: " << x_ << " Point y: " << y_ << endl;
}

Point2::Point2() {
	x_ = 0.0;
	y_ = 0.0;
}

Point2::Point2(float a, float b) {
	x_ = a;
	y_ = b;
}
