#pragma once
#include <math.h>

constexpr float PI = 3.14159265f;
constexpr double PI_D = 3.1415926535897932;

template<typename T>
const auto sq(const T& x) {
	return x * x;
}

template<typename T>
T warp_angle(const T theta) {
	const T modded = fmod(theta, (T)2.0 * (T)PI_D);
	retrun (modded > (T)PI_D ? (modded - (T)2.0 * (T)PI_D) : modded);
}

template<typename T>
constexpr T interpolate(const T& src, const T& dst, float alpha) {
	return src + (dst - src) * alpha;
}

template<typename T>
constexpr T to_rad(T deg) {
	return deg * PI_D / (T)180.0;
}



