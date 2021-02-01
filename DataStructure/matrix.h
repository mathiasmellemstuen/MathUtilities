#ifndef MATH_UTILITIES_MATRIX
#define MATH_UTILITIES_MATRIX

#define X *
#include <string>
#include <iostream>
#include <math.h>

namespace MathUtilities::DataStructure {
    template<int x, int y, typename T> class Matrix {
        protected: 
            T** values;
            T* matrixBuffer = new T[x*y];//Saving the returned buffer from the buffer() function here and deleting it in the destructor to prevent memory leaks. 

            T determinantRecursive(Matrix<x,y,T>& matrix, int n) {
                T det = 0;
                Matrix<x,y,T> submatrix;

                if (n == 2) {
                    return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
                }
                else {
                    for (int xx = 0; xx < n; xx++) {
                        int subi = 0;
                        for (int i = 1; i < n; i++) {
                            int subj = 0;
                            for (int j = 0; j < n; j++) {
                                if (j == xx)
                                    continue;
                                submatrix[subi][subj] = matrix[i][j];
                                subj++;
                            }
                            subi++;
                        }
                        det = det + (std::pow(-1, xx) * matrix[0][xx] * determinantRecursive( submatrix, n - 1 ));
                    }
                }
                return det;
            }
        public: 
            Matrix() {
                values = new T*[x];
                for(int i = 0; i < x; i++) {
                    values[i] = new T[y];
                }
            };
            ~Matrix() {


                for(int i = 0; i < y; ++i) {
                    delete[] values[i];
                }
                delete[] values; 
                delete[] matrixBuffer; 
            };
            T* buffer() {
                int i = 0;  
                for(int j = 0; j < x; j++) {
                    for(int i = 0; i < y; i++) {
                        matrixBuffer[i] = values[j][i]; 
                        i++;
                    }
                }
                return matrixBuffer; 
            };
            void print() {
                
                int longestElement[x]; 

                for(int i = 0; i < x; i++) {
                    longestElement[i] = 1; 
                }
                for(int j = 0; j < x; j++) {
                    for(int i = 0; i < y; i++) {
                        
                        std::string valueString = std::to_string(values[j][i]);

                        if(valueString.find(".") != std::string::npos)
                            for(int i = valueString.length(); i > 0; i--) {
                                if(valueString[i] == '.') {
                                    valueString = valueString.substr(0, i);
                                    break; 
                                }
                                if(valueString[i] != '0' && valueString[i] != '\0') {
                                    valueString = valueString.substr(0, i  + 1 );
                                    break; 
                                }
                            }
                        int characterLength = valueString.length(); 
                        
                        if(characterLength > longestElement[j]) {
                            longestElement[j] = characterLength;  
                        }
                    }
                }

                std::cout << "\033[4m";

                for(int i = 0; i < x; i++) {
                    std::cout << "  ";

                        for(int j = 0; j < longestElement[i] - 1; j++) {

                            std::cout << " "; 
                        }
                }
                std::cout << " " << std::endl; 

                for(int i = 0; i < y; i++) {
                    std::cout << "|";
                    for(int j = 0; j < x; j++) {

                        std::string valueString = std::to_string(values[j][i]);

                        if(valueString.find(".") != std::string::npos)
                            for(int i = valueString.length(); i > 0; i--) {
                                if(valueString[i] == '.') {
                                    valueString = valueString.substr(0, i);
                                    break; 
                                }
                                if(valueString[i] != '0' && valueString[i] != '\0') {
                                    valueString = valueString.substr(0, i  + 1 );
                                    break; 
                                }
                            }
                        int characterLength = valueString.length(); 

                        int spaces = longestElement[j] - characterLength;
                        
                        for(int l = 0; l < spaces; l++) {
                            std::cout << " "; 
                        }

                        std::cout << values[j][i] << "|";
                    }
                    std::cout << std::endl;
                }

                std::cout << "\033[0m" << std::endl; 
            };
            void printDescription() {
                std::cout << "Matrix information:" << std::endl << "x size: " << x << std::endl << "y size: " << y << std::endl << "Type: " << typeid(T).name() << " (may be a mangled name)" << std::endl; 
            };
            void empty() {

                for(int i = 0; i < y; i++) {
                    for(int j = 0; j < x; j++) { 
                        values[j][i] = 0; 
                    }
                }
            };
            void identity() {

                empty(); 

            for(int i = 0; i < x; i++) {
                    values[i][i] = 1;  
            }             
            };
            T determinant() {
                return determinantRecursive(*this, x); 
            }
            Matrix<y,x,T> transpose() {
                Matrix<y, x, T> transposeMatrix;

                    for(int i = 0; i  < y; i++) {
                        for(int j = 0; j < x; j++) {
                        transposeMatrix[i][j] = values[j][i]; 
                    }
                }
                return transposeMatrix; 
            };
            Matrix<x, y, T> operator + (const Matrix<x, y, T>& matrix) {

                Matrix<x, y, T> added;

                for(int i = 0; i < y; i++) {
                    for(int j = 0; j < x; j++) {
                        added.values[j][i] = values[j][i] + matrix.values[j][i]; 
                    }
                } 
                return added; 
            };
            Matrix<x, y, T>& operator = (const Matrix<x, y, T>& matrix) {

                for(int i = 0; i < y; i++) {
                    for(int j = 0; j < x; j++) { 
                        this->values[j][i] = matrix.values[j][i]; 
                    }
                }

                return *this; 
            };
            Matrix<x, y, T> operator - (const Matrix<x, y, T>& matrix) {
                
                Matrix<x, y, T> sub;

                for(int i = 0; i < y; i++) {
                    for(int j = 0; j < x; j++) {
                        sub.values[j][i] = values[j][i] - matrix.values[j][i]; 
                    }
                } 
                return sub; 
            };
            template<typename M> Matrix<x, y, M> operator * (M factor) {

                Matrix<x, y, M> mul;

                for(int i = 0; i < y; i++) {
                    for(int j = 0; j < x; j++) {
                        mul.values[j][i] = (M)values[j][i] * factor; 
                    }
                } 
                return mul; 
            };
            T*& operator [] (int i) {
                return values[i]; 
            };

            template <int x2, int y2> Matrix<x, y, T> operator * (Matrix<x2, y2, T>& matrix) {

                Matrix<x, y, T> returnMatrix;

                for(int i = 0; i < x; i++) {
                    for(int j = 0; j < x; j++) {
                        for(int k = 0; k < y; k++) {
                            returnMatrix[i][k] += matrix[i][j] * values[j][k]; 
                        }
                    }
                } 
                return returnMatrix; 
            };
            template <typename M> operator Matrix<x,y,M>() {
            
                Matrix<x,y,M> returnMatrix; 

                for(int i = 0; i < y; i++) {
                    for(int j = 0; j < x; j++) {
                        returnMatrix.values[j][i] = (M)values[j][i];                     
                    }
                }
                return returnMatrix; 
            }
    };
};
#endif