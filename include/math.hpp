#ifndef __libcee_MATH_H__
#define __libcee_MATH_H__

/**
 *  (     (                           
 *  )\ )  )\ )   (     (              
 * (()/( (()/( ( )\    )\   (    (    
 *  /(_)) /(_)))((_) (((_)  )\   )\   
 * (_))  (_)) ((_)_  )\___ ((_) ((_)  
 * | |   |_ _| | _ )((/ __|| __|| __| 
 * | |__  | |  | _ \ | (__ | _| | _|  
 * |____||___| |___/  \___||___||___| 
 *                                               
 * @file util_math.h
 * @author Benjamin Blundell - me@benjamin.computer
 * @date 26/04/2021
 * @brief Basic maths utilities.
 *
 */

#include <iostream>
#include "macros.hpp"

namespace libcee {
static const double PI = M_PI;

inline static double RadToDeg(const double &x) { return x * 180.0 / PI; }
inline static double DegToRad(const double &x) { return x * PI / 180.0; }

inline static float RadToDeg(const float &x) { return x * 180.0 / PI; }
inline static float DegToRad(const float &x) { return x * PI / 180.0; }

/**
 * @brief Mix linearly between two values, given a value between 0 and 1
 * 
 * @param x 
 * @param y 
 * @param v 
 * @return float 
 */
inline static float Mix(const float &x, const float &y, const float &v) {
    if (v < 0.0) { return x;}
    else if (v > 1.0) { return y;}
    return x * (1.0 - v) + y * v;
}

}

#endif