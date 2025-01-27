#ifndef _VEC_MATH_H_
#define _VEC_MATH_H_

#include "SystemDimension.hh"

/* special case for the most common 3d 
inline double vecmag(double x[3]) {
	return std::sqrt(x[0]*x[0] + x[1]*x[1] + x[2]*x[2]);
}

inline double vecmag2(double x[3]) {
	return x[0]*x[0] + x[1]*x[1] + x[2]*x[2];
}

inline double vecdot(double a[3], double b[3]) {
	return a[0]*b[0] + a[1]*b[1] + a[2]*b[2];
}

inline bool vecequal(double a[3], double b[3]) {
	return (a[0] == b[0] && a[1] == b[1] && a[2] == b[2]);
}

inline void veccpy(double a[3], double b[3]) {
	a[0] = b[0];
	a[1] = b[1];
	a[2] = b[2];
}
*/

inline double vecdot(double *a, double *b) {
	double dot = a[0]*b[0];
	for(unsigned int i = 1u; i<CARTDIM; ++i) {
		dot += a[i]*b[i];
	}
	return dot;
}

inline double vecmag2(double *x) {
	return vecdot(x,x);
}

inline double vecmag(double *x) {
	return std::sqrt(vecmag2(x));
}

inline bool vecequal(double *a, double *b) {
	bool ret = (a[0] == b[0]);
	for(unsigned int i = 1u; ret && i<CARTDIM; ++i) {
		ret = ret && (a[i] == b[i]);
	}
	return ret;
}

/* a = b */
inline void veccpy(double *a, double *b) {
	for(unsigned int i = 0u; i<CARTDIM; ++i) {
		a[i] = b[i];
	}
}

inline void vecadd(double *a, double *b) {
	for(unsigned int i = 0u; i<CARTDIM; ++i) {
		a[i] += b[i];
	}
}

/* n = t x m , only useful in 3d */
inline void crossprod(double t[3], double m[3], double n[3]) {
	n[0] = t[1]*m[2] - t[2]*m[1];
	n[1] = t[2]*m[0] - t[0]*m[2];
	n[2] = t[0]*m[1] - t[1]*m[0];
}

#endif
