add_library(WarehouseModels
    Product.cpp
    Order.cpp
)

target_include_directories(WarehouseModels PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)

set_target_properties(WarehouseModels PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)