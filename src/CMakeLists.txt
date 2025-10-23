add_executable(WarehouseSimulation
    models/Product.cpp
    models/Order.cpp
)

set_target_properties(WarehouseSimulation PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)