#include "errors.h"

namespace GameEngine {
	void fatalError(std::string message) {
		fprintf(stderr, "A fatal error occured: \n %s", message.c_str());
		getchar();
		exit(1);
	}

	void glfwError(int error, const char* message)
	{
		fprintf(stderr, "Error: %s\n", message);
	}
}