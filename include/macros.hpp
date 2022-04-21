#ifndef __libcee_MACROS_H__
#define __libcee_MACROS_H__

/**
 *  _____   _______ ______ _______ _______ _______ 
 * |     |_|_     _|   __ \     __|    ___|    ___|
 * |       |_|   |_|   __ <__     |    ___|    ___|
 * |_______|_______|______/_______|_______|_______|
 *                                               
 *
 * @file macros.hpp
 * @author Benjamin Blundell - me@benjamin.computer
 * @date 26/04/2021
 * @brief Some useful macros
 *
 */

#ifndef NDEBUG
#   define ASSERT(condition, message) \
    do { \
        if (! (condition)) { \
            std::cerr << "Assertion `" #condition "` failed in " << __FILE__ \
                      << " line " << __LINE__ << ": " << message << std::endl; \
            std::terminate(); \
        } \
    } while (false)
#else
#   define ASSERT(condition, message) do { } while (false)
#endif

#endif