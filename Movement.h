#ifndef MOVEMENT_H_
#define MOVEMENT_H_

#include <math.h>
#include <mbed.h>

class Movement
{
public:
	Movement();
	virtual ~Movement() {};

	// 各ホイールの出力の比率を保ちながら、limitまで底上げ
	void up_limit_balance(double duty[], double units_num, double limit);

	// 各ホイールの出力の比率を保ちながら、limitまで抑制
	void down_limit_balance(double duty[], double units_num, double limit);

	virtual void move(double x, double y, double yaw) = 0;
};

#endif
