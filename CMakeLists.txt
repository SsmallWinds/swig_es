cmake_minimum_required(VERSION 2.8)
project(EsWrap)
SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0")
MESSAGE(STATUS "This is BINARY dir " ${PROJECT_BINARY_DIR})
MESSAGE(STATUS "This is SOURCE dir " ${PROJECT_SOURCE_DIR})

include_directories(${PROJECT_SOURCE_DIR}/Quote/include)
include_directories(${PROJECT_SOURCE_DIR}/Foreign3.0tradeapi/API/3.0.1.52)
include_directories(/usr/lib/jvm/java-8-openjdk-amd64/include)
include_directories(/usr/lib/jvm/java-8-openjdk-amd64/include/linux)
LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/Quote)
LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/Foreign3.0tradeapi/API/3.0.1.52)


set(QUOTE_SRC es_quote_wrap.cxx)
set(TRADE_SRC es_trade_wrap.cxx)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
add_library(EsQuoteWrap SHARED ${QUOTE_SRC})
target_link_libraries(EsQuoteWrap TapQuoteAPI)

add_library(EsTradeWrap SHARED ${TRADE_SRC})
target_link_libraries(EsTradeWrap ForeignTradeApi)


