#ifndef MATH_UTILITIES_VECTOR
#define MATH_UTILITIES_VECTOR

#define DOT |
#include "matrix.h" 
#include <math.h>

namespace MathUtilities::DataStructure {
    template<int size, typename T> class Vector : public Matrix<1,size,T> {
        public:
            T& operator [] (int i) {
                return this->values[0][i];
            };
            Vector() : Matrix<1,size,T>() {
                for(int i = 0; i < size; i++) {
                    this->values[0][i] = (T)0; 
                }
            };
            T length() {
                T sum = (T)0;

                for(int i = 0; i < size; i++) {
                    sum += std::pow(this->values[0][i], 2);
                }

                return std::sqrt(sum);
            }

            Vector<size,T> operator + (Vector<size,T>& vec) {
                Vector<size,T> returnVector;
                for(int i = 0; i < size; i++) {
                    returnVector.values[0][i] = vec.values[0][i] + this->values[0][i]; 
                }
                return returnVector; 
            };
            Vector<size,T> operator - (Vector<size,T>& vec) {

                Vector<size,T> returnVector;
                for(int i = 0; i < size; i++) {
                    returnVector.values[0][i] = this->values[0][i] - vec.values[0][i]; 
                }
                return returnVector;
            };
            template<typename M> Vector<size, T> operator * (M factor) {
                Vector<4,T> returnVector; 

                for(int i = 0; i < size; i++) {
                    returnVector[i] = this[i] * factor; 
                }

                return returnVector; 
            };
            T operator | (Vector<size, T>& vec) {
                T sum = (T)0;
                
                for(int i = 0; i < size; i++) {
                    sum += this->values[0][i] * vec[i];      
                }
                return sum; 
            };
            Vector<size, T> operator = (Matrix<size,1,T>& mat) {
                Vector<size, T> returnVector; 

                for(int i = 0; i < size; i++) {
                    returnVector.values[0][i] = mat[0][i];
                }
                return returnVector; 
            };
            Matrix<1, size, T> operator = (Vector<size,T>& vec) {
                Matrix<1, size, T> returnMatrix; 

                for(int i = 0; i  < size; i++) {
                    returnMatrix.values[0][i] = vec.values[0][i]; 
                }

                return returnMatrix; 
            };
    };
    template <typename T> class Vector<4,T> : public Matrix<1, 4, T> {
        public: 
            T& x = this->values[0][0];
            T& y = this->values[0][1]; 
            T& z = this->values[0][2]; 
            T& w = this->values[0][3];

            Vector(T x, T y, T z, T w) : Matrix<1,4,T>() {
                this->values[0][0] = x; 
                this->values[0][1] = y; 
                this->values[0][2] = z;
                this->values[0][3] = w;
            };
            Vector() : Matrix<1,4,T>() {
                this->values[0][0] = (T)0; 
                this->values[0][1] = (T)0; 
                this->values[0][2] = (T)0; 
                this->values[0][3] = (T)0;
            };
            T length() {
                return std::sqrt((std::pow(x,2) + std::pow(y,2) + std::pow(z,2) + std::pow(w,2)));
            };
            Vector<4,T> operator + (Vector<4,T>& vec) {
                Vector<4,T> returnVector;
                for(int i = 0; i < 4; i++) {
                    returnVector.values[0][i] = vec.values[0][i] + this->values[0][i]; 
                }
                return returnVector; 
            };
            Vector<4,T> operator - (Vector<4,T>& vec) {

                Vector<4,T> returnVector;
                for(int i = 0; i < 4; i++) {
                    returnVector.values[0][i] = this->values[0][i] - vec.values[0][i]; 
                }
                return returnVector;
            };
            template<typename M> Vector<4, T> operator * (M factor) {
                Vector<4,T> returnVector; 
                returnVector.x = this->x * factor;
                returnVector.y = this->y * factor; 
                returnVector.z = this->z * factor; 
                returnVector.w = this->w * factor; 

                return returnVector; 
            };
            T operator | (Vector<4, T>& vec) {
                T sum = (T)0;
                
                for(int i = 0; i < 4; i++) {
                    sum += this->values[0][i] * vec.values[0][i];      
                }
                return sum; 
            };
            Vector<4, T> operator = (Matrix<1,4,T>& mat) {
                Vector<4, T> returnVector; 

                for(int i = 0; i < 4; i++) {
                    returnVector.values[0][i] = mat[0][i];
                }
                return returnVector; 
            };
            Matrix<1, 4, T> operator = (Vector<4,T>& vec) {
                Matrix<1, 4, T> returnMatrix; 

                for(int i = 0; i  < 4; i++) {
                    returnMatrix.values[0][i] = vec.values[0][i]; 
                }

                return returnMatrix; 
            };
    };
    template <typename T> class Vector<3,T> : public Matrix<1, 3, T> {
        public: 
            T& x = this->values[0][0]; 
            T& y = this->values[0][1]; 
            T& z = this->values[0][2]; 
    
            Vector(T x, T y, T z) : Matrix<1,3,T>() {
                this->values[0][0] = x; 
                this->values[0][1] = y; 
                this->values[0][2] = z;
            };
            Vector() : Matrix<1,3,T>() {
                this->values[0][0] = (T)0; 
                this->values[0][1] = (T)0; 
                this->values[0][2] = (T)0; 
            };
            T length() {
                return std::sqrt((std::pow(x,2) + std::pow(y,2) + std::pow(z,2)));
            }
            Vector<3,T> operator + (Vector<3,T>& vec) {
                Vector<4,T> returnVector;
                for(int i = 0; i < 3; i++) {
                    returnVector.values[0][i] = vec.values[0][i] + this->values[0][i]; 
                }
                return returnVector; 
            };
            Vector<3,T> operator - (Vector<3,T>& vec) {

                Vector<3,T> returnVector;
                for(int i = 0; i < 3; i++) {
                    returnVector.values[0][i] = this->values[0][i] - vec.values[0][i]; 
                }
                return returnVector;
            };
            template<typename M> Vector<3, T> operator * (M factor) {
                Vector<3,T> returnVector; 
                returnVector.x = this->x * factor;
                returnVector.y = this->y * factor; 
                returnVector.z = this->z * factor; 
                returnVector.w = this->w * factor; 

                return returnVector; 
            };
            T operator | (Vector<3, T>& vec) {
                T sum = (T)0;
                
                for(int i = 0; i < 3; i++) {
                    sum += this->values[0][i] * vec[i];      
                }
                return sum; 
            };
            Vector<3, T> operator = (Matrix<1,3,T>& mat) {
                Vector<3, T> returnVector; 

                for(int i = 0; i < 3; i++) {
                    returnVector.values[0][i] = mat[0][i];
                }
                return returnVector; 
            };
            Matrix<1, 3, T> operator = (Vector<3,T>& vec) {
                Matrix<1, 3, T> returnMatrix; 

                for(int i = 0; i  < 2; i++) {
                    returnMatrix.values[0][i] = vec.values[0][i]; 
                }

                return returnMatrix; 
            };
    };
    template <typename T> class Vector<2,T> : public Matrix<1, 2, T> {
        public: 
            T& x = this->values[0][0]; 
            T& y = this->values[0][1]; 
    
            Vector(T x, T y) : Matrix<1,2,T>() {
                this->values[0][0] = x; 
                this->values[0][1] = y; 
            };
            Vector() : Matrix<1,2,T>() {
                this->values[0][0] = (T)0; 
                this->values[0][1] = (T)0; 
            };
            T length() {
                return std::sqrt((std::pow(x,2) + std::pow(y,2)));
            } 
            Vector<2,T> operator + (Vector<2,T>& vec) {

                Vector<2,T> returnVector;

                for(int i = 0; i < 4; i++) {
                    returnVector.values[0][i] = vec.values[0][i] + this->values[0][i]; 
                }

                return returnVector; 
            };
            Vector<2,T> operator - (Vector<2,T>& vec) {

                Vector<2,T> returnVector;
                for(int i = 0; i < 4; i++) {
                    returnVector.values[0][i] = this->values[0][i] - vec.values[0][i]; 
                }
                return returnVector;
            };
            template<typename M> Vector<2, T> operator * (M factor) {

                Vector<2,T> returnVector; 
                returnVector.x = this->x * factor;
                returnVector.y = this->y * factor; 
                returnVector.z = this->z * factor; 
                returnVector.w = this->w * factor; 

                return returnVector; 
            };
            T operator | (Vector<2, T>& vec) {

                T sum = (T)0;
                
                for(int i = 0; i < 2; i++) {
                    sum += this->values[0][i] * vec[i];      
                }
                return sum; 
            };
            Vector<2, T> operator = (Matrix<1,2,T>& mat) {
                Vector<2, T> returnVector; 

                for(int i = 0; i < 2; i++) {
                    returnVector.values[0][i] = mat[0][i];
                }
                return returnVector; 
            };
            Matrix<1, 2, T> operator = (Vector<2,T>& vec) {
                Matrix<1, 2, T> returnMatrix; 

                for(int i = 0; i  < 2; i++) {
                    returnMatrix.values[0][i] = vec.values[0][i]; 
                }

                return returnMatrix; 
            };
    };
};
#endif