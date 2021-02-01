#ifndef MATH_UTILITIES_VECTOR
#define MATH_UTILITIES_VECTOR

#define DOT |
#include "matrix.h" 
#include <math.h>

namespace MathUtilities::DataStructure {
    template<int size, typename T> class Vector : public Matrix<size,1,T> {
        public:
            T& operator [] (int i) {
                return this->values[i][0];
            };
            Vector() : Matrix<size,1,T>() {
                for(int i = 0; i < size; i++) {
                    this->values[i][0] = (T)0; 
                }
            };
            T length() {
                T sum = (T)0;

                for(int i = 0; i < size; i++) {
                    sum += std::pow(this->values[i][0], 2);
                }

                return std::sqrt(sum);
            }

            Vector<size,T> operator + (Vector<size,T>& vec) {
                Vector<size,T> returnVector;
                for(int i = 0; i < size; i++) {
                    returnVector.values[i][0] = vec.values[i][0] + this->values[i][0]; 
                }
                return returnVector; 
            };
            Vector<size,T> operator - (Vector<size,T>& vec) {

                Vector<size,T> returnVector;
                for(int i = 0; i < size; i++) {
                    returnVector.values[i][0] = this->values[i][0] - vec.values[i][0]; 
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
                    sum += this->values[i][0] * vec[i];      
                }
                return sum; 
            };
            Vector<size, T> operator = (Matrix<size,1,T>& mat) {
                Vector<size, T> returnVector; 

                for(int i = 0; i < size; i++) {
                    returnVector.values[i][0] = mat[i][0];
                }
                return returnVector; 
            };
            Matrix<size, 1, T> operator = (Vector<size,T>& vec) {
                Matrix<size, 1, T> returnMatrix; 

                for(int i = 0; i  < size; i++) {
                    returnMatrix.values[i][0] = vec.values[i][0]; 
                }

                return returnMatrix; 
            };
    };
    template <typename T> class Vector<4,T> : public Matrix<4, 1, T> {
        public: 
            T& x = this->values[0][0]; 
            T& y = this->values[1][0]; 
            T& z = this->values[2][0]; 
            T& w = this->values[3][0];

            Vector(T x, T y, T z, T w) : Matrix<4,1,T>() {
                this->values[0][0] = x; 
                this->values[1][0] = y; 
                this->values[2][0] = z;
                this->values[3][0] = w;
            };
            Vector() : Matrix<4,1,T>() {
                this->values[0][0] = (T)0; 
                this->values[1][0] = (T)0; 
                this->values[2][0] = (T)0; 
                this->values[3][0] = (T)0;
            };
            T length() {
                return std::sqrt((std::pow(x,2) + std::pow(y,2) + std::pow(z,2) + std::pow(w,2)));
            };
            Vector<4,T> operator + (Vector<4,T>& vec) {
                Vector<4,T> returnVector;
                for(int i = 0; i < 4; i++) {
                    returnVector.values[i][0] = vec.values[i][0] + this->values[i][0]; 
                }
                return returnVector; 
            };
            Vector<4,T> operator - (Vector<4,T>& vec) {

                Vector<4,T> returnVector;
                for(int i = 0; i < 4; i++) {
                    returnVector.values[i][0] = this->values[i][0] - vec.values[i][0]; 
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
                    sum += this->values[i][0] * vec.values[i][0];      
                }
                return sum; 
            };
            Vector<4, T> operator = (Matrix<4,1,T>& mat) {
                Vector<4, T> returnVector; 

                for(int i = 0; i < 4; i++) {
                    returnVector.values[i][0] = mat[i][0];
                }
                return returnVector; 
            };
            Matrix<4, 1, T> operator = (Vector<4,T>& vec) {
                Matrix<4, 1, T> returnMatrix; 

                for(int i = 0; i  < 4; i++) {
                    returnMatrix.values[i][0] = vec.values[i][0]; 
                }

                return returnMatrix; 
            };
    };
    template <typename T> class Vector<3,T> : public Matrix<3, 1, T> {
        public: 
            T& x = this->values[0][0]; 
            T& y = this->values[1][0]; 
            T& z = this->values[2][0]; 
    
            Vector(T x, T y, T z) : Matrix<3,1,T>() {
                this->values[0][0] = x; 
                this->values[1][0] = y; 
                this->values[2][0] = z;
            };
            Vector() : Matrix<3,1,T>() {
                this->values[0][0] = (T)0; 
                this->values[1][0] = (T)0; 
                this->values[2][0] = (T)0; 
            };
            T length() {
                return std::sqrt((std::pow(x,2) + std::pow(y,2) + std::pow(z,2)));
            }
            Vector<3,T> operator + (Vector<3,T>& vec) {
                Vector<4,T> returnVector;
                for(int i = 0; i < 3; i++) {
                    returnVector.values[i][0] = vec.values[i][0] + this->values[i][0]; 
                }
                return returnVector; 
            };
            Vector<3,T> operator - (Vector<3,T>& vec) {

                Vector<3,T> returnVector;
                for(int i = 0; i < 3; i++) {
                    returnVector.values[i][0] = this->values[i][0] - vec.values[i][0]; 
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
                    sum += this->values[i][0] * vec[i];      
                }
                return sum; 
            };
            Vector<3, T> operator = (Matrix<3,1,T>& mat) {
                Vector<3, T> returnVector; 

                for(int i = 0; i < 3; i++) {
                    returnVector.values[i][0] = mat[i][0];
                }
                return returnVector; 
            };
            Matrix<3, 1, T> operator = (Vector<3,T>& vec) {
                Matrix<3, 1, T> returnMatrix; 

                for(int i = 0; i  < 2; i++) {
                    returnMatrix.values[i][0] = vec.values[i][0]; 
                }

                return returnMatrix; 
            };
    };
    template <typename T> class Vector<2,T> : public Matrix<2, 1, T> {
        public: 
            T& x = this->values[0][0]; 
            T& y = this->values[1][0]; 
    
            Vector(T x, T y) : Matrix<2,1,T>() {
                this->values[0][0] = x; 
                this->values[1][0] = y; 
            };
            Vector() : Matrix<2,1,T>() {
                this->values[0][0] = (T)0; 
                this->values[1][0] = (T)0; 
            };
            T length() {
                return std::sqrt((std::pow(x,2) + std::pow(y,2)));
            } 
            Vector<2,T> operator + (Vector<2,T>& vec) {

                Vector<2,T> returnVector;

                for(int i = 0; i < 4; i++) {
                    returnVector.values[i][0] = vec.values[i][0] + this->values[i][0]; 
                }

                return returnVector; 
            };
            Vector<2,T> operator - (Vector<2,T>& vec) {

                Vector<2,T> returnVector;
                for(int i = 0; i < 4; i++) {
                    returnVector.values[i][0] = this->values[i][0] - vec.values[i][0]; 
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
                    sum += this->values[i][0] * vec[i];      
                }
                return sum; 
            };
            Vector<2, T> operator = (Matrix<2,1,T>& mat) {
                Vector<2, T> returnVector; 

                for(int i = 0; i < 2; i++) {
                    returnVector.values[i][0] = mat[i][0];
                }
                return returnVector; 
            };
            Matrix<2, 1, T> operator = (Vector<2,T>& vec) {
                Matrix<2, 1, T> returnMatrix; 

                for(int i = 0; i  < 2; i++) {
                    returnMatrix.values[i][0] = vec.values[i][0]; 
                }

                return returnMatrix; 
            };
    };
};
#endif