add_library(WarehouseServices
    DiscountService.cpp
    ExpirationService.cpp
    OrderGenerator.cpp
    OrderProcessor.cpp
    StatisticsService.cpp
    SupplierService.cpp
)

target_include_directories(WarehouseServices PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)

set_target_properties(WarehouseServices PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)