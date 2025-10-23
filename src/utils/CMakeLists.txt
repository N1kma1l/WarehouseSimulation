add_library(WarehouseUtils
    RandomGenerator.cpp
)

target_include_directories(WarehouseUtils PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)

set_target_properties(WarehouseUtils PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)