# Find necessary packages
find_package(Boost 1.74.0 REQUIRED)
find_package(spdlog 1.9.0 REQUIRED)

# Add a cmake binary taget (in this case, a library)
add_library(BoostDeadlineTimer boost-deadline-timer.cpp boost-deadline-timer.hpp)
# Make the directory known
target_include_directories(BoostDeadlineTimer PUBLIC ${Boost_INCLUDE_DIR})
# Link library to a binary target
target_link_libraries(BoostDeadlineTimer PUBLIC ${Boost_LIBRARIES})
# Link library to a binary target
target_link_libraries(BoostDeadlineTimer PRIVATE spdlog::spdlog)


# Add a cmake binary taget (in this case, an executable)
add_executable(main main.cpp)
# Link library to a binary target
target_link_libraries(main PUBLIC BoostDeadlineTimer)