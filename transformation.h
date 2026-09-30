#ifndef BLOKUS_TRANSFORMATION_H
#define BLOKUS_TRANSFORMATION_H

#include <array>

enum class Transformation {
	None,
	OneQuarter,
	Half,
	ThreeQuarters,
	VMirrorNone,
	VMirrorOneQuarter,
	VMirrorHalf,
	VMirrorThreeQuarters,
};

constexpr static std::array<Transformation, 8> TRANSFORMATIONS{
		Transformation::None,
		Transformation::OneQuarter,
		Transformation::Half,
		Transformation::ThreeQuarters,
		Transformation::VMirrorNone,
		Transformation::VMirrorOneQuarter,
		Transformation::VMirrorHalf,
		Transformation::VMirrorThreeQuarters
};

#endif //BLOKUS_TRANSFORMATION_H
