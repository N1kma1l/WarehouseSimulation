add_executable(WarehouseSimulation
    main.cpp
)

target_link_libraries(WarehouseSimulation WarehouseModels WarehouseCore)

set_target_properties(WarehouseSimulation PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)