/*******************************************************************************
 * @brief		Smart pointer in modern C++
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0
 * @history
 * 		2018.12.20	Created.
 ******************************************************************************/

/* Include Headers -----------------------------------------------------------*/
#include <iostream>
#include <memory>

/* Structures ----------------------------------------------------------------*/
struct BodyMass {
	int id;
	float weight;

	BodyMass(int id, float weight) : id(id), weight(weight) {
		std::cout << "BodyMass is constructed" << std::endl;
		std::cout << "ID = " << id << std::endl;
		std::cout << "Weight = " << weight << std::endl;
	}

	BodyMass(const BodyMass &other) : id(other.id), weight(other.weight) {
		std::cout << "BodyMass is copy constructed" << std::endl;
		std::cout << "ID = " << id << std::endl;
		std::cout << "Weight = " << weight << std::endl;
	}

	~BodyMass(void) {
		std::cout << "BodyMass is destructed" << std::endl;
	}
};

/* Private Functions ---------------------------------------------------------*/
std::unique_ptr<BodyMass> GetBodyMass(void) {
	return std::make_unique<BodyMass>(2, 123.4f);
}

std::unique_ptr<BodyMass> UpdateBodyMass(std::unique_ptr<BodyMass> body_mass) {
	body_mass->weight += 1.0f;
	return body_mass;
}

/* Main Routine --------------------------------------------------------------*/
auto main() -> int {
	std::cout << "[smart-pointer.cpp]" << std::endl;

	// unique_ptr
	auto my_weight = std::make_unique<BodyMass>(1, 165.3f);
	// unique_ptr: copy
	auto copy_weight = *my_weight;
	// unique_ptr: move
	auto your_weight = GetBodyMass();
	std::cout << "Current weight = " << your_weight->weight << std::endl;
	your_weight = UpdateBodyMass(std::move(your_weight));
	std::cout << "Updated weight = " << your_weight->weight << std::endl << std::endl;

	// shared_ptr
	auto sp1 = std::shared_ptr<int>{};
	if (sp1) {
		std::cout << "sp1 is initialized" << std::endl;
	} else {
		std::cout << "sp1 is not initialized" << std::endl;
	}
	std::cout << "sp1 pointing counter = " << sp1.use_count() << std::endl;
	if (sp1.unique()) {
		std::cout << "sp1 is unique" << std::endl;
	} else {
		std::cout << "sp1 is not unique" << std::endl;
	}

	sp1 = std::make_shared<int>(1234);
	if (sp1) {
		std::cout << "sp1 is initialized" << std::endl;
	} else {
		std::cout << "sp1 is not initialized" << std::endl;
	}
	std::cout << "sp1 pointing counter = " << sp1.use_count() << std::endl;
	if (sp1.unique()) {
		std::cout << "sp1 is unique" << std::endl;
	} else {
		std::cout << "sp1 is not unique" << std::endl;
	}

	auto sp2 = sp1;
	std::cout << "sp1 pointing counter = " << sp1.use_count() << std::endl;
	if (sp1.unique()) {
		std::cout << "sp1 is unique" << std::endl;
	} else {
		std::cout << "sp1 is not unique" << std::endl;
	}

	std::cout << "sp2 pointing counter = " << sp2.use_count() << std::endl;
	if (sp2.unique()) {
		std::cout << "sp2 is unique" << std::endl;
	} else {
		std::cout << "sp2 is not unique" << std::endl;
	}

	sp2.reset();
	std::cout << "sp1 pointing counter = " << sp1.use_count() << std::endl;
	if (sp1.unique()) {
		std::cout << "sp1 is unique" << std::endl;
	} else {
		std::cout << "sp1 is not unique" << std::endl;
	}
	std::cout << std::endl;

	// weak_ptr
	auto sp = std::make_shared<int>(1234);
	auto wp = std::weak_ptr<int>{ sp };
	if (wp.expired()) {
		std::cout << "wp is expired" << std::endl;
	} else {
		std::cout << "wp is not expired" << std::endl;
	}
	std::cout << "wp pointing counter = " << wp.use_count() << std::endl;
	if (auto locked = wp.lock()) {
		std::cout << "wp is locked. Value = " << *locked << std::endl;
	} else {
		std::cout << "wp is unlocked" << std::endl;
		wp.reset();
	}

	sp = nullptr;
	if (wp.expired()) {
		std::cout << "wp is expired" << std::endl;
	} else {
		std::cout << "wp is not expired" << std::endl;
	}
	std::cout << "wp pointing counter = " << wp.use_count() << std::endl;
	if (auto locked = wp.lock()) {
		std::cout << "wp is locked. Value = " << *locked << std::endl;
	} else {
		std::cout << "wp is unlocked" << std::endl;
		wp.reset();
	}

	return 0;
}
