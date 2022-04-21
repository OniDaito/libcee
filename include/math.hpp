#ifndef __libcee_MATH_H__
#define __libcee_MATH_H__

/**
 *  _____   _______ ______ _______ _______ _______ 
 * |     |_|_     _|   __ \     __|    ___|    ___|
 * |       |_|   |_|   __ <__     |    ___|    ___|
 * |_______|_______|______/_______|_______|_______|
 *                                               
 * @file util_math.h
 * @author Benjamin Blundell - me@benjamin.computer
 * @date 26/04/2021
 * @brief Basic maths utilities.
 *
 */

namespace libcee {
static const double PI = M_PI;

inline static double RadToDeg(const double &x) { return x * 180.0 / PI; }
inline static double DegToRad(const double &x) { return x * PI / 180.0; }

inline static float RadToDeg(const float &x) { return x * 180.0 / PI; }
inline static float DegToRad(const float &x) { return x * PI / 180.0; }
}

#endif