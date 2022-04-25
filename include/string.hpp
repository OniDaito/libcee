#ifndef __libcee_STRING_H__
#define __libcee_STRING_H__

/**
 *  _____   _______ ______ _______ _______ _______ 
 * |     |_|_     _|   __ \     __|    ___|    ___|
 * |       |_|   |_|   __ <__     |    ___|    ___|
 * |_______|_______|______/_______|_______|_______|
 *                                               
 * @file util_string.h
 * @author Benjamin Blundell - me@benjamin.computer
 * @date 26/04/2021
 * @brief String utilities.
 *
 */

#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include <fstream>

#include <algorithm>
#include <functional>
#include <cctype>
#include <cmath>
#include <locale>

#include <stdlib.h>
#include <cstdlib>
#include <stddef.h>
#include <stdint.h>
#include <limits.h>

#ifdef _USE_GLM
#include <glm/glm.hpp>
#include <glm/mat4x4.hpp>
#endif


namespace libcee {

template<class T> inline std::string ToString(const T& t) {
  std::ostringstream stream;
  stream << t;
  return stream.str();
}

template<class T> inline T FromString(const std::string& s) {
  std::istringstream stream (s);
  T t;
  stream >> t;
  return t;
}

static inline std::string ToLower(const std::string input) {
  std::string tt = input;
  std::transform(tt.begin(), tt.end(), tt.begin(), ::tolower);
  return tt;
}


static inline std::string FilenameFromPath(const std::string &input) {
  return input.substr(input.find_last_of("\\/")+1);
}

static inline std::string PathFromPath(const std::string &input) {
  return input.substr(0, input.find_last_of("\\/"));
}

static inline std::string GetFileExtension(const std::string &input) {
  return input.substr(input.find_last_of(".") + 1) ;
}

static inline bool IsAsciiString(std::string &input) {
  for(std::string::iterator it = input.begin(); it != input.end(); ++it) {
    int c = static_cast<int>(*it);
    if (c > 127){ return false; }
  }
  return true;
}

static inline bool IsAsciiPrintableString(std::string &input) {
  for(std::string::iterator it = input.begin(); it != input.end(); ++it) {
    char c = static_cast<char>(*it);
    if (c > 126 || c < 32){ return false; }
  }
  return true;
}

inline std::string ToPrecision(float num, int n) {

  if(num == 0) {
    return "0";
  }

  float d = ceil(log10(num < 0 ? -num : num));
  int power = n - (int)d;
  float magnitude = pow(10., power);
  long shifted = ::round(num*magnitude);

  std::ostringstream oss;
  oss << shifted/magnitude;
  return oss.str();
}

inline std::string ToPrecision(double num, int n) {

  if(num == 0) {
    return "0";
  }

  double d = ceil(log10(num < 0 ? -num : num));
  int power = n - (int)d;
  double magnitude = pow(10., power);
  long shifted = ::round(num*magnitude);

  std::ostringstream oss;
  oss << shifted/magnitude;
  return oss.str();
}


/**
* String tokenize with STL
* http://www.cplusplus.com/faq/sequences/strings/split/
* \todo test split
*/

static inline std::vector<std::string> SplitStringChars(const std::string& input, const std::string& delimiters) {
  size_t current;
  size_t next = -1;
  std::vector<std::string> tokens;
  do {
    current = next + 1;
    next = input.find_first_of( delimiters, current );
    tokens.push_back(input.substr( current, next - current ));
  } while (next != std::string::npos);
  return tokens;
}


/**
 * Convert a string representation of a hex digit into hex
 */

static inline unsigned int HexStringToUnsigned(const std::string& input){
  unsigned int x;   
  std::stringstream ss;
  ss << std::hex << input;
  ss >> x;
  return x;
}

// http://en.cppreference.com/w/cpp/string/byte/isspace

static inline std::vector<std::string> SplitStringWhitespace(const std::string& input ) { 
  size_t start = 0;
  size_t end = 0;
  std::vector<std::string> tokens;
  
  auto w = []( char ch ) { return isspace( ch ); };

  while (end < input.length()) {
        
    if (start != end && w(input.at(end))){
      tokens.push_back(input.substr( start, end-start ));
      start = end;
    }

    if (w(input.at(start))){
      start++;
    }
    end++;
  }
  
  if (start != end) {
    tokens.push_back(input.substr( start, end-start ));
  }
  
  return tokens;
}


static inline std::vector<std::string> SplitStringString(const std::string& input, const std::string& delimiter) {
  size_t current = 0;
  size_t next = -1;
  std::vector<std::string> tokens;
  do {
    next = input.find( delimiter, current );
    tokens.push_back(input.substr(current, next - current));
    current = next + delimiter.size();
  } while (next != std::string::npos);
  return tokens;
}


static inline std::vector<std::string> SplitStringNewline(const std::string& input) {
  size_t current;
  size_t next = -1;
  size_t next0, next1;
  std::vector<std::string> tokens;
  do {
    current = next + 1;
    next0 = input.find('\n', current);
    next1 = input.find('\r', current);
    
    next = next0 < next1 ? next0 : next1;
    
    tokens.push_back(input.substr( current, next - current ));
  } while (next != std::string::npos);
  return tokens;

}

static inline bool StringContains(const std::string& input, const std::string& contains){
  size_t found = input.find(contains);
  return found != std::string::npos;
}

static inline bool StringBeginsWith(const std::string& input, const std::string& contains){
  size_t found = input.find(contains);
  return found != std::string::npos && found == 0;
}

/**
 * Integer to string but with leading zeroes.
 */
static inline std::string IntToStringLeadingZeroes(int i, int num_zeroes) {
  std::stringstream s;
  s << std::setw(num_zeroes) << std::setfill('0') << i;
  return s.str();
}

/**
* Remove a char from a string - returns a copy
*/

static inline std::string RemoveChar(const std::string s, const char c) {
  std::string str (s);
  str.erase (std::remove(str.begin(), str.end(), c), str.end());
  return str;
}

/**
 * Remove a string from another string, returning a copy
 */

static inline std::string StringRemove(const std::string s, const std::string r) {
  std::string b(s);
  size_t found = s.find(r);
  
  if (found != std::string::npos){
    b.replace(found, found + r.length(),"");  
  }

  return b;
}

/*
* Basic text file reading
*/

std::string inline TextFileRead(std::string filename) {
  std::string line;
  std::string rval;
  std::ifstream myfile (filename.c_str());
  if (myfile.is_open()){
    while ( myfile.good() ) {
      getline (myfile,line);
      rval += line +"\n";
    }
    myfile.close();
  } else 
    std::cerr << "SEBURO - Unable to open text file " << filename << std::endl;
  return rval;
}

/*
* Print Binary Data
*/

inline char *itob(long x) {
  static char buff[sizeof(int) * CHAR_BIT + 1];
  unsigned long i;
  unsigned long j = sizeof(int) * CHAR_BIT - 1;
  buff[j] = 0;
  for(i = 0;i < sizeof(int) * CHAR_BIT; i++) {
    if(x & (1 << i))
    buff[j] = '1';
  else
    buff[j] = '0';
    j--;
  }
  return buff;
}


/*
* String Trimming functions
*/
// trim from start

static inline std::string &ltrim(std::string const &in_str) {
  std::string s = in_str;
  s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
  return s;
}

// trim from end
static inline std::string &rtrim(std::string const &in_str) {
  std::string s = in_str;
  s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
  return s;
}

// trim from both ends
static inline std::string &trim(std::string &s) {
  return ltrim(rtrim(s));
}


static inline std::string StringReplace(std::string& str, const std::string& from, const std::string& to) {
    size_t start_pos = str.find(from);
    if(start_pos == std::string::npos) {
        return str;
    }
    std::string final = str;
    final.replace(start_pos, from.length(), to);
    return final;
}

#ifdef _USE_GLM
/**
* Print out a GLM Matrix
*/

static inline std::string MatrixToString(const glm::mat4 &mat){
  std::stringstream s;
  int i,j;
  for (j=0; j<4; ++j){
    for (i=0; i<4; ++i){
      s << std::setprecision(2) << std::setfill('0') << std::setw(5) << mat[i][j] << " ";
    }
    s << std::endl;
  }
  return s.str();
}

/// return a string from a GLM Vector 2
static inline std::string VecToString (const glm::vec2 &vec) {
  std::stringstream s;
  s << vec.x << ", " << vec.y;
  return s.str();
}

/// return a string from a GLM Vector 3
static inline std::string VecToString (const glm::vec3 &vec) {
  std::stringstream s;
  s << vec.x << ", " << vec.y << ", " << vec.z;
  return s.str();
}

/// return a string from a GLM Vector 4
static inline std::string VecToString (const glm::vec4 &vec) {
  std::stringstream s;
  s << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w;
  return s.str();
}
#endif
}
#endif
