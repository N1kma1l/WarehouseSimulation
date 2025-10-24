add_library(WarehouseCore
    DataManager.cpp
    Config.cpp
    Simulation.cpp
    Warehouse.cpp
    WarehouseController.cpp
)

target_include_directories(WarehouseCore PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)

set_target_properties(WarehouseCore PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)