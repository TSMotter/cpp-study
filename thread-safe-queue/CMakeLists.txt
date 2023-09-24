# Find necessary packages
find_package(spdlog 1.9.0 REQUIRED)

# Add a cmake binary taget (in this case, a library)
add_library(ThreadSafeQueue thread-safe-queue.cpp thread-safe-queue.hpp)
# Link library to a binary target
target_link_libraries(ThreadSafeQueue PRIVATE spdlog::spdlog)


# Add a cmake binary taget (in this case, an executable)
add_executable(main main.cpp)
# Link library to a binary target
target_link_libraries(main PUBLIC ThreadSafeQueue)