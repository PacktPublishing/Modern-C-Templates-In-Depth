#include "utils.h"

void CallTemplate() {

}

template<>
float Max(float a, float b) {
	return a > b ? a : b ;
}